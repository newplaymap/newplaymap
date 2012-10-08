<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function general_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function general_node_info() {
  $items = array(
    'delete_request' => array(
      'name' => t('Delete Request'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => t('Please let us know if you need assistance with adding or removing content on the map. Please fill out the form below or feel free to leave a message with Vijay Mathew at +1 617-800-9627.'),
    ),
    'page' => array(
      'name' => t('Page'),
      'module' => 'features',
      'description' => t('A <em>page</em>, similar in form to a <em>story</em>, is a simple method for creating and displaying information that rarely changes, such as an "About us" section of a website. By default, a <em>page</em> entry does not allow visitor comments and is not featured on the site\'s initial home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function general_rules_defaults() {
  return array(
    'rules' => array(
      'rules_email_delete_request' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Email Delete Request',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'Delete Request',
          'general' => 'general',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'delete_request' => 'delete_request',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Created content is Delete Request',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Send a mail to all users of a role',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_users_of_role',
            '#settings' => array(
              'recipients' => array(
                '0' => 4,
              ),
              'from' => '',
              'subject' => '[author:user] has submitted a delete request',
              'message' => '[node:title]


[node:field_delete_request_explanation-raw]


View content flagged for deletion: [node:field_delete_request_reference-url]

View original request here: [node:node-url]

View user who submitted request: [author:account-url]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'author',
                  ),
                  'message' => array(
                    '0' => 'node',
                    '1' => 'author',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
    'rule_sets' => array(
      'rules_delete_request_rules' => array(
        'arguments' => array(
          'node' => array(
            'label' => 'Content',
            'type' => 'node',
          ),
        ),
        'label' => 'Delete Request Rules',
        'status' => 'default',
        'categories' => array(
          '0' => 'Delete Request',
          'general' => 'general',
        ),
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function general_views_api() {
  return array(
    'api' => '2',
  );
}
