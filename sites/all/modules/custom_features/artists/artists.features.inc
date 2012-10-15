<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function artists_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function artists_node_info() {
  $items = array(
    'agent' => array(
      'name' => t('Agent'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'artist' => array(
      'name' => t('Artist'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name (playwright\'s name or name of ensemble / collective)'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'artist_memberships' => array(
      'name' => t('Artist Memberships'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'artist_type' => array(
      'name' => t('Artist Type'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function artists_views_api() {
  return array(
    'api' => '2',
  );
}
