<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
function home_today_overlay_title_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t('Today overlay title'),
      'icon' => 'icon_node.png',
      'description' => t('Title for the overlay showing what\s on today'),
      'category' => t('Custom'),
    );
}

function home_today_overlay_title_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $output = '';
  $items = array();
  $block = new stdClass();

  $today = date('F j, o');
  $title_text = "What's Happening on";
  
  $output .= '<h2 class="overlay-title">' . $title_text . ' ' . $today . '</h2>';
      
  $block->module = 'home';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function home_today_overlay_title_content_type_admin_title($subtype, $conf, $context) {
  return t('Today overlay title');
}

function home_today_overlay_title_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
