<?php

/**
 * Implementation of hook_views_handlers().
 *
 * @return array
 */
function npm_datasource_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'npm_datasource') .'/includes',
    ),
    'handlers' => array(
      'views_handler_partner_organizations' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 *
 * @return array
 */
function npm_datasource_views_data() {
  $data['npm_datasource']['table']['group'] = t('New Play Map Custom Data');
  $data['npm_datasource']['table']['join'] = array(
    '#global' => array(),
  );
  
  $data['npm_datasource']['partner_organizations'] = array(
    'title' => t('Partner Organizations Data'),
    'help' => t('Display Partner Organizations for data export.'),
    'field' => array(
      'handler' => 'views_handler_partner_organizations',
      'click sortable' => FALSE,
      'notafield' => TRUE,
    ),
  );
  
  return $data;
}