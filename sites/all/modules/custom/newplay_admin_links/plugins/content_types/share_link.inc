<?php
/**
 * Implementation of specially named hook_ctools_content_types()
 */
function newplay_admin_links_share_link_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t("Share link URL"),
      'icon' => 'icon_node.png',
      'description' => t('Embedable graphic to link to specific pages on the site'),
      'required context' => new ctools_context_optional(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function newplay_admin_links_share_link_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $items = array();
  $output = '';
  $block = new stdClass();
  

  // Set up some variables
  $current_node = $context->argument;
  // TODO: figure out how to not hard code the main domain
  $domain = (isset($_SERVER['HTTP_HOST'])) ? 'http://' . preg_replace('`^www.`', '', $_SERVER['HTTP_HOST']) : 'http://newplaymap.org';
  
  
  $current_path = ($current_node) ? '#' . base_path() . drupal_get_path_alias('node/' . $current_node) : '';  
    
  $output .= '<div id="share-link-block">';
    $output .= '<div id="share-link-link">';
      $output .= '<form>';
        $output .= '<label for="share-link">Copy & paste a link to this page to share it around</label>';
        $output .= '<input id="share-link" type="text" value=\'' . $domain . base_path() . $current_path . '\'></input>';
      $output .= '</form>';
    $output .= '</div>';
  $output .= '</div>';
      
  $block->module = 'newplay_admin_links';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function newplay_admin_links_share_link_content_type_admin_title($subtype, $conf, $context) {
  return t("Share URL");
}

function newplay_admin_links_share_link_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
