<?php
// $Id: oauth.inc,v 1.1.2.12 2008/11/19 14:36:07 brmassa Exp $
/**
 * @author OAuth module Dev Team
 * @file
 *  OAuth module's main functions.
 */

class _oauth_auth {
  /**
   * Change the argument list for services.
   *
   * @param &$methods
   *   Array. The complete list of all methods, declared using
   *   hook_webservices_info().
   * @param &$key
   *   String. The current method name, like 'node.get' or 'user.save'.
   */
  public function fields(&$methods, &$key) {
    // Add OAuth fields in case the OAuth keys are required
    if (empty($methods[$key]['#no_auth'])) {
      array_unshift($methods[$key]['#args'],
        array(
          '#name'           => 'oauth_version',
          '#type'           => 'string',
          '#description'    => t('The OAuth version.'),
        ),
        array(
          '#name'           => 'oauth_timestamp',
          '#type'           => 'int',
          '#description'    => t('The timestamp of the request.'),
        ),
        array(
          '#name'           => 'oauth_nonce',
          '#type'           => 'string',
          '#description'    => t('The random 32 characters long string used on each request.'),
        ),
        array(
          '#name'         => 'oauth_consumer_key',
          '#type'         => 'string',
          '#description'  => t('OAuth consumer key.'),
        ),
        array(
          '#name'         => 'oauth_token',
          '#type'         => 'string',
          '#description'  => t('OAuth access token.'),
        ),
        array(
          '#name'         => 'oauth_signature_method',
          '#type'         => 'string',
          '#description'  => t('OAuth signature method.'),
        ),
        array(
          '#name'         => 'oauth_signature',
          '#type'         => 'string',
          '#description'  => t('OAuth signature.'),
        )
      );
    }
  }

  /**
   * Authentication method responsible for:
   *   - Check if the user and the agent (the external application) are
   *     who they are saying they are
   *   - Load the real user, which is gener
   *
   * @param &$method
   *   Array. The method information, like the one declared using
   *   hook_webservices_info(), plus any other modification.
   * @param &$args
   *   Array. The received list of arguments from the external application.
   */
  public function load(&$method, &$args) {
    // Check the OAuth authentication
    if (empty($method['#no_auth'])) {
      // Combine the values received with the arguemtn names
      foreach ($method['#args'] as $index => $arg) {
        $values[$arg['#name']] = $args[$index];
      }
      // Force using a given signature method
      $values['oauth_signature_method']  = variable_get('oauth_crypt', 'PLAINTEXT');

      $server = _oauth_server_init();
      try {
        $req = OAuthRequest::from_request(NULL, NULL, $values);
        list($consumer, $token) = $server->verify_request($req);
      }
      catch (OAuthException $e) {
        throw new Exception($e->getMessage());
        return '';
      }

      // Check if the consumer is allowed to access this given service
      // in behalf of the user, if, of course, they are not the same
      $webservices = db_fetch_array(db_query("SELECT c.uid AS consumer_uid, t.webservices, t.uid
        FROM {oauth_token} t
        INNER JOIN {oauth_consumer} c ON c.consumer_key = t.consumer_key
        WHERE t.token_key = '%s'", $token->key));
      if ($webservices['uid'] != $webservices['consumer_uid'] and empty($webservices['webservices'][$method_name])) {
        throw new Exception(t('Access denied to this service.'));
      }

      // Remove the authentication fields
      array_shift($args);
      array_shift($args);
      array_shift($args);
      array_shift($args);
      array_shift($args);
      array_shift($args);
      array_shift($args);

      // Load the user from the given token
      global $user;
      $user = user_load($webservices['uid']);
    }
    else {
      // Check if the needed keys are present
      $consumer_key = $args[0];
      if (empty($consumer_key)) {
        throw new Exception(t('Consumer key missing.'));
      }

      // Check if the consumer key and token are valid
      if (!$consumer_uid = db_result(db_query("SELECT uid FROM {oauth_consumer}
          WHERE consumer_key = '%s'",
          $consumer_key))) {
        throw new Exception(t('Invalid consumer key.'));
      }

      global $user;
      $user = user_load($consumer_uid);
    }
  }
}

/**
 * Implementation of hook_form_alter().
 *
 * Its placed on this file because it is only needed when
 * the
 */
function oauth_form_user_login_alter(&$form, &$form_state) {
  if (!empty($_GET['oauth_token'])) {
    $form['oauth_token'] = array(
      '#type'   => 'value',
      '#value'  => $_GET['oauth_token'],
    );
    $form['oauth_token_secret'] = array(
      '#type'   => 'value',
      '#value'  => $_GET['oauth_token_secret'],
    );
    $form['oauth_callback'] = array(
      '#type'   => 'value',
      '#value'  => $_GET['oauth_callback'],
    );
    $query = $_GET;
    unset($query['q']);
    $form['#redirect'] = url('webservice/token_auth', array('query' => $query, 'absolute' => TRUE));
  }
}

/**
 * Implementation of hook_form_alter().
 */
function oauth_form_user_login_block_alter(&$form, &$form_state) {
  oauth_form_user_login_alter($form, $form_state);
}

/**
 * Return consumer object related to a user. If the consumer
 * does not exist, it will be created.
 *
 * @param $uid
 *   Number. User ID to retrieve consumer object for.
 * @return
 *   Object. OAuth service consumer.
 */
function _oauth_consumer_get($uid) {
  module_load_include('lib.php', 'oauth');

  $result = db_query('SELECT * FROM {oauth_consumer} WHERE uid = %d', $uid);
  if ($object = db_fetch_array($result)) {
    return new OAuthConsumer($object['consumer_key'], $object['consumer_secret']);
  }
  else {
    $sql = array(
      'uid'             => $uid,
      'consumer_key'    => user_password(32),
      'consumer_secret' => user_password(32),
    );
    drupal_write_record('oauth_consumer', $sql);
    return new OAuthConsumer($sql['consumer_key'], $sql['consumer_secret']);
  }
}

/**
 * Initialize and store an OAuthServer object. It integrates the generic
 * OAuth-PHP implementation to Drupal.
 *
 * Its also included 3 signature objects: 'HMAC SHA1', 'PLAINTEXT'
 * and 'RSA SHA1'.
 */
function _oauth_server_init() {
  static $server;
  if (empty($server)) {
    module_load_include('lib.php', 'oauth');

    /**
    * Database abstraction class
    */
    class DrupalOAuthDataStore extends OAuthDataStore {
      /**
       * Check if consumer exists from a given consumer key.
       *
       * @param $consumer_key
       *   String. The consumer key.
       */
      function lookup_consumer($consumer_key) {
        $result = db_query("SELECT * FROM {oauth_consumer}
          WHERE consumer_key = '%s'", $consumer_key);
        if ($object = db_fetch_object($result)) {
          return new OAuthConsumer($object->consumer_key, $object->consumer_secret);
        }
        throw new OAuthException('Consumer not found');
      }

      /**
       * Check if the token exists.
       *
       * @param $consumer
       *   Object. The service consumer information.
       * @param $token_type
       *   Strint. The type of the token: 'request' or 'access'.
       * @param $token
       *   Strint. The token value.
       * @return
       *   String or NULL. The existing token or NULL in
       *   case it doesnt exist.
       */
      function lookup_token($consumer, $token_type, $token) {
        $result = db_query("SELECT * FROM {oauth_token}
          WHERE type = '%s' AND consumer_key = '%s' AND token_key = '%s'",
          $token_type, $consumer->key, $token);
        if ($object = db_fetch_object($result)) {
          return new OAuthToken($object->token_key, $object->token_secret);
        }
        throw new OAuthException('Token not found');
      }

      /**
       * Check if the nonce value exists. If not, generate one.
       *
       * @param $consumer
       *   Object. The service consumer information with both key
       *   and secret values.
       * @param $token
       *   Strint. The current token.
       * @param $nonce
       *   Strint. A new nonce value, in case a one doesnt current exit.
       * @param $timestamp
       *   Number. The current time.
       * @return
       *   String or NULL. The existing nonce value or NULL in
       *   case it doesnt exist.
       */
      function lookup_nonce($consumer, $token, $nonce, $timestamp) {
        if (!$nonce_1 = db_result(db_query("SELECT nonce FROM {oauth_nonce}
          WHERE timestamp <= %d and token = '%s'", $timestamp, $token))) {
          $sql = array(
            'nonce'     => $nonce,
            'timestamp' => $timestamp,
            'token'     => $token,
          );
          drupal_write_record('oauth_nonce', $sql);
          return NULL;
        }
        return $nonce_1;
      }

      /**
       * Generate a new request token.
       *
       * @param $consumer
       *   Object. The service consumer information.
       */
      function new_request_token($consumer) {
        $user_id = db_result(db_query("SELECT uid FROM {oauth_consumer}
          WHERE consumer_key = '%s'", $consumer->key));
        $token = new OAuthToken(user_password(32), user_password(32));
        $sql = array(
          'consumer_key'    => $consumer->key,
          'type'            => 'request',
          'token_key'       => $token->key,
          'token_secret'    => $token->secret,
          'uid'             => $user_id
        );
        drupal_write_record('oauth_token', $sql);
        return $token;
      }

      /**
       * Generate a new access token and delete the old request token.
       *
       * @param $token_old
       *   Strint. The old request token.
       * @param $consumer
       *   Object. The service consumer information.
       */
      function new_access_token($token_old, $consumer) {
        if ($object = db_fetch_array(db_query("SELECT * FROM {oauth_token}
          WHERE type = 'request' AND token_key = '%s'", $token_old->key))) {
          if ($object['authorized']) {
            $token_new = new OAuthToken(user_password(32), user_password(32));
            $sql = array(
              'consumer_key'    => $consumer->key,
              'type'            => 'access',
              'token_key'       => $token_new->key,
              'token_secret'    => $token_new->secret,
              'uid'             => $object['uid']
            );
            drupal_write_record('oauth_token', $sql, array('uid', 'consumer_key'));

            return $token_new;
          }
        }
        throw new OAuthException('Invalid request token');
      }
    }

    // Create the instance of Server
    $server = new OAuthServer(new DrupalOAuthDataStore());
    $server->add_signature_method(new OAuthSignatureMethod_HMAC_SHA1());
    $server->add_signature_method(new OAuthSignatureMethod_PLAINTEXT());
    $server->add_signature_method(new OAuthSignatureMethod_RSA_SHA1());
  }
  return $server;
}

/**
 * Access the OAuth services
 *
 * Note that this function can be called directly from Menu API. In this case,
 * all arguments will be NULL and the real values will come thru $_GET.
 *
 * @param $timestamp
 *   Number. The time when the request was made (in timestamp).
 * @param $nonce
 *   String. A randon 32-char long string that ensure that a request is
 *   unique: even 2 requests from the same consumer must have different
 *   nonce values.
 * @param $consumer_key
 *   String. The consumer key, which is linked to a Drupal user.
 * @param $token_key
 *   String. The request token, which will be replaced by the
 *   access token.
 * @param $signature
 *   String. Using the signature method, its the resulting HASH value of all
 *   content. It uses the consumer keys and secrets, so its unique accross each
 *   request and consumer.
 * @param $version
 *   String. The OAuth version used by the consumer: currently, its "1.0". Note
 *   that even its number, it will be treated as string.
 */
function _oauth_token_access($version, $timestamp, $nonce, $consumer_key, $token_key, $signature_method, $signature) {
  $server = _oauth_server_init();

  // Get the request values
  if ($timestamp === NULL) {
    $version          = $_GET['oauth_version'];
    $timestamp        = $_GET['oauth_timestamp'];
    $nonce            = $_GET['oauth_nonce'];
    $consumer_key     = $_GET['oauth_consumer_key'];
    $token_key        = $_GET['oauth_token'];
    $signature_method = $_GET['oauth_signature_method'];
    $signature        = $_GET['oauth_signature'];
  }
  $arguments = array(
    'oauth_token'             => $token_key,
    'oauth_consumer_key'      => $consumer_key,
    'oauth_version'           => $version,
    'oauth_timestamp'         => $timestamp,
    'oauth_nonce'             => $nonce,
    'oauth_signature_method'  => variable_get('oauth_crypt', 'PLAINTEXT'),
    'oauth_signature'         => $signature,
  );

  try {
    $req = OAuthRequest::from_request(NULL, NULL, $arguments);
    $token = $server->fetch_access_token($req);
    return $token;
  }
  catch (OAuthException $e) {
    module_load_include('inc', 'webservices');
    return webservices_error($e->getMessage());
  }
}

/**
 * Authorize a request token.
 *
 * Redirects to login form if not logged in, and displays the grant access form once logged in.
 */
function _oauth_token_auth() {
  // Check some important arguments
  if (empty($_GET['oauth_token'])) {
    drupal_set_message(t('Please include a valid OAuth token in your request.'), 'error');
    return drupal_access_denied();
  }
  elseif (empty($_GET['oauth_callback'])) {
    drupal_set_message(t('Please include a valid callback url in your request.'), 'error');
    return drupal_access_denied();
  }

  // Redirect to the right form, or present an error.
  global $user;
  if ($user->uid != 0) {
    if (!user_access('access webservices')) {
      drupal_set_message( t('You are not authorized to allow external services access to this system.'), 'error');
      return drupal_access_denied();
    }
    return drupal_get_form('_oauth_token_auth_form');
  }
  else {
    return drupal_get_form('user_login');
  }
}

/**
 * Form for granting access to the consumer
 *
 * Here user is asked to issue access/deny permission to
 * specific services as demanded by calling server
 *
 * @ingroup $form
 */
function _oauth_token_auth_form() {
  $_GET['oauth_callback'] = urldecode($_GET['oauth_callback']);
  $form['oauth_callback'] = array(
    '#type'   => 'hidden',
    '#value'  => $_GET['oauth_callback']
  );
  $form['oauth_token'] = array(
    '#type'   => 'hidden',
    '#value'  => $_GET['oauth_token']
  );
  $form['oauth_consumer_key'] = array(
    '#type'   => 'hidden',
    '#value'  => $_GET['oauth_consumer_key'],
  );
  $form['oauth_nonce'] = array(
    '#type'   => 'hidden',
    '#value'  => $_GET['oauth_nonce'],
  );
  $form['oauth_nonce_timestamp'] = array(
    '#type'   => 'hidden',
    '#value'  => $_GET['oauth_timestamp'],
  );

  // Display all services available that the user might access
  module_load_include('inc', 'webservices');
  $form['webservices'] = array(
    '#description'  => t('Select which services you will allow %consumer use in your behalf',
      array('%consumer' => $_GET['oauth_callback'])
    ),
    '#title'        => t('Services'),
    '#tree'         => TRUE,
    '#type'         => 'fieldset',
  );
  foreach (webservices_service_get_all() as $service) {
    $access_arguments = isset($service['#access arguments']) ? $service['#access arguments'] : array();
    // Call default or custom access callback
    if (!empty($service['#access callback'])
        and ($service['#access callback'] == TRUE
        or (function_exists($service['#access callback'])
        and call_user_func_array($service['#access callback'], $access_arguments) == TRUE))) {
      $form['webservices'][$service['#method']] = array(
        '#title'          => $service['#method'],
        '#type'           => 'checkbox',
        '#default_value'  => 0,
      );
    }
  }

  $form['confirm'] = array(
    '#type'   => 'submit',
    '#value'  => t('Grant access'),
  );
  return $form;
}

/**
 * Asks users for granting proper access/deny permissions for different services
 * Authorizes an existing oauth request token and redirects to sender.
 *
 * @ingroup form
 */
function _oauth_token_auth_form_submit(&$form, &$form_state) {
  module_load_include('inc', 'webservices');
  foreach (webservices_service_get_all() as $service) {
    $method_name = $service['#method'];
    if (!empty($form_state['values']['webservices'][$method_name])) {
      $services[$method_name] = TRUE;
    }
  }

  // Save the list of all services that the user allowed the
  // consumer to do
  global $user;
  $sql = array(
    'authorized'  => 1,
    'uid'         => $user->uid,
    'token_key'   => $form_state['values']['oauth_token'],
    'webservices' => serialize($services),
  );
  drupal_write_record('oauth_token', $sql, 'token_key');

  // Return to the consumer site
  drupal_goto($form_state['values']['oauth_callback']);
}

/**
 * Generate a request token from the request.
 *
 * Note that this function can be called directly from Menu API. In this case,
 * all arguments will be NULL and the real values will come thru $_GET.
 *
 * @param $timestamp
 *   Number. The time when the request was made (in timestamp).
 * @param $nonce
 *   String. A randon 32-char long string that ensure that a request is
 *   unique: even 2 requests from the same consumer must have different
 *   nonce values.
 * @param $consumer_key
 *   String. The consumer key, which is linked to a Drupal user.
 * @param $signature
 *   String. Using the signature method, its the resulting HASH value of all
 *   content. It uses the consumer keys and secrets, so its unique accross each
 *   request and consumer.
 * @param $version
 *   String. The OAuth version used by the consumer: currently, its "1.0". Note
 *   that even its number, it will be treated as string.
 */
function _oauth_token_request($version, $timestamp, $nonce, $consumer_key, $signature_method, $signature) {
  $server = _oauth_server_init();

  // Get the request values
  if ($timestamp === NULL) {
    $version          = $_GET['oauth_version'];
    $timestamp        = $_GET['oauth_timestamp'];
    $nonce            = $_GET['oauth_nonce'];
    $consumer_key     = $_GET['oauth_consumer_key'];
    $signature_method = $_GET['oauth_signature_method'];
    $signature        = $_GET['oauth_signature'];
  }
  $arguments = array(
    'oauth_consumer_key'      => $consumer_key,
    'oauth_timestamp'         => $timestamp,
    'oauth_nonce'             => $nonce,
    'oauth_signature_method'  => variable_get('oauth_crypt', 'PLAINTEXT'),
    'oauth_signature'         => $signature,
    'oauth_version'           => $version,
  );

  try {
    $req = OAuthRequest::from_request(NULL, NULL, $arguments);
    $token = $server->fetch_request_token($req);
    return $token;
  }
  catch (OAuthException $e) {
    module_load_include('inc', 'webservices');
    return webservices_error($e->getMessage());
  }
}
