<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function orgs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function orgs_imagecache_default_presets() {
  $items = array(
    'org_full' => array(
      'presetname' => 'org_full',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '200',
            'height' => '200',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'org_icon' => array(
      'presetname' => 'org_icon',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '33',
            'height' => '33',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'org_icon_small' => array(
      'presetname' => 'org_icon_small',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '18',
            'height' => '18',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'org_standard' => array(
      'presetname' => 'org_standard',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '85',
            'height' => '85',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function orgs_node_info() {
  $items = array(
    'org_type' => array(
      'name' => t('Organization Type'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'organization' => array(
      'name' => t('Organization'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Organization Name'),
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
function orgs_views_api() {
  return array(
    'api' => '2',
  );
}
