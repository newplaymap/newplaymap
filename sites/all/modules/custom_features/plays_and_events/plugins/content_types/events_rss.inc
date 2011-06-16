<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
function plays_and_events_events_rss_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t('Events Today RSS'),
      'icon' => 'icon_node.png',
      'description' => t('Link to RSS Feed of Events happening today'),
      'category' => t('Custom'),
    );
}

function plays_and_events_events_rss_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $output = '';
  $block = new stdClass();

  $feed_url = 'events-today/feed';

  drupal_add_feed($feed_url);

  $output .= l(
    '<img src="' . drupal_get_path('theme', 'newplay') . '/images/feed.png" alt="' . t('RSS Feed') . '" />', 
    $feed_url, 
    array(
    'attributes' => array(
      'class' => 'feed-icon'
    ),
    'html' => TRUE
  ));
      
  $block->module = 'plays_and_events';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function plays_and_events_events_rss_content_type_admin_title($subtype, $conf, $context) {
  return t('Events today RSS');
}

function plays_and_events_events_rss_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
