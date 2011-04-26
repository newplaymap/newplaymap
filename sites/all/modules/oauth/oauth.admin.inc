<?php
// $Id: oauth.admin.inc,v 1.1.2.3 2008/11/06 02:13:15 brmassa Exp $
/**
 * @author OAuth module Dev Team
 * @file
 *  OAuth module's admin pages.
 */

/**
 * Main module settings.
 */
function _oauth_admin() {
  $form['oauth_crypt'] = array(
    '#default_value'  => variable_get('oauth_crypt', 'PLAINTEXT'),
    '#description'    => t('When enabled, all method calls must include a valid OAuth access token and consumer token.'),
    '#options'        => array(
      'PLAINTEXT' => t('Plain text (UNSECURE)'),
      'HMAC-SHA1' => t('HMAC-SHA1'),
      'RSA-SHA1'  => t('RSA-SHA1'),
    ),
    '#title'          => t('OAuth cryptography'),
    '#type'           => 'radios',
  );

  return system_settings_form($form);
}

/**
 * Implementation of hook_user().
 */
function _oauth_user($op, &$edit, &$account, $category = NULL) {
  global $user;

  module_load_include('inc', 'oauth');
  $consumer = _oauth_consumer_get($account->uid);
  $account->content['oauth'] = array(
    '#attributes' => array('class' => 'user-member'),
    '#title'      => t('Web services'),
    '#type'       => 'user_profile_category',
    '#weight'     => 5,
  );
  $account->content['oauth']['consumer_key'] = array(
    '#title'      => t('Consumer key'),
    '#type'       => 'user_profile_item',
    '#value'      => $consumer->key,
    '#weight'     => 1,
  );
  $account->content['oauth']['consumer_secret'] = array(
    '#title'      => t('Consumer secret'),
    '#type'       => 'user_profile_item',
    '#value'      => $consumer->secret,
    '#weight'     => 2,
  );

  // Specially useful for developers, it will create and show
  // a Access Token for the own user. Remember that all services
  // are authorized when consumer and the user are the same.
  if (user_access('view own access token', $account)) {
    if (!$token = db_fetch_object(db_query("SELECT token_key, token_secret AS secret
        FROM {oauth_token}
        WHERE uid = %d AND consumer_key = '%s' AND type = 'access'",
        $account->uid, $consumer->key))) {
      $token = new OAuthToken(user_password(32), user_password(32));
      $sql = array(
        'consumer_key'    => $consumer->key,
        'type'            => 'access',
        'token_key'       => $token->key,
        'token_secret'    => $token->secret,
        'uid'             => $account->uid,
        'webservices'     => serialize(array())
      );
      drupal_write_record('oauth_token', $sql);
    }
    $account->content['oauth']['own_access_token_key'] = array(
      '#title'      => t('Access token key'),
      '#type'       => 'user_profile_item',
      '#value'      => empty($token->key) ? $token->token_key : $token->key,
      '#weight'     => 3,
    );
    $account->content['oauth']['own_access_token_secret'] = array(
      '#title'      => t('Access token secret'),
      '#type'       => 'user_profile_item',
      '#value'      => empty($token->secret) ? $token->token_secret : $token->secret,
      '#weight'     => 4,
    );
  }
}
