<?php
/**
 * Implementation of specially named hook_ctools_content_types()
 */
function newplay_admin_links_embed_badge_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t("I'm on the New Play Map"),
      'icon' => 'icon_node.png',
      'description' => t('Embedable graphic to link to specific pages on the site'),
      'required context' => new ctools_context_optional(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function newplay_admin_links_embed_badge_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $items = array();
  $output = '';
  $block = new stdClass();
  

  // Set up some variables
  $current_node = $context->argument;
  // TODO: figure out how to not hard code the main domain
  $domain = (isset($_SERVER['HTTP_HOST'])) ? 'http://' . preg_replace('`^www.`', '', $_SERVER['HTTP_HOST']) : 'http://newplaymap.org';
  
  
  $current_path = ($current_node) ? '#' . base_path() . drupal_get_path_alias('node/' . $current_node) : '';
  $embedded_link = '';
  $embedded_link .= '<a href="' . $domain . base_path() . $current_path . '">';
    $embedded_link .= '<img src="' . $domain . base_path() . file_directory_path() . '/images/badge_embed.png" />';
  $embedded_link .= '</a>';
  
  
  $embed_image_path = base_path() . file_directory_path() . '/images/badge_embed.png';
  
  $output .= '<div id="embed-badge-block">';
    $output .= '<div id="embed-badge-image">';
      $output .= '<img src="' . $embed_image_path . '" />';
    $output .= '</div>';
    $output .= '<div id="embed-badge-link">';
      $output .= '<form>';
        $output .= '<label for="embed-code">Embed a link to this page on your site</label>';
        $output .= '<input id="embed-code" type="text" value=\'' . $embedded_link . '\'></input>';
      $output .= '</form>';
    $output .= '</div>';
  $output .= '</div>';
      
  $block->module = 'newplay_admin_links';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function newplay_admin_links_embed_badge_content_type_admin_title($subtype, $conf, $context) {
  return t("I'm on the map embed");
}

function newplay_admin_links_embed_badge_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
