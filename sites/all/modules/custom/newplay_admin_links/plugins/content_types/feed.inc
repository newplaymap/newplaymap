<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
function newplay_admin_links_feed_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t('Add Feed'),
      'icon' => 'icon_node.png',
      'description' => t('Link to add a feed from an organization'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function newplay_admin_links_feed_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $items = array();
  $output = '';
  $block = new stdClass();


  $link_options = array( 'attributes' => array( 
    // 'class' => 'view-blog',
    // 'id' => 'blog-link' 
  ) );
  
  
  $items[] = l('Twitter Feed', 'node/add/twitter-feed/' . $context->argument, $link_options);
  $items[] = l('Blog Feed', 'node/add/blog-feed/' . $context->argument, $link_options);
  $items[] = l('Photo Feed', 'node/add/photo-feed/' . $context->argument, $link_options);
  $items[] = l('Video Feed', 'node/add/video-feed/' . $context->argument, $link_options);
  
  $output .= theme_item_list($items, t('Add Feeds'), 'ul', array(
    'class' => 'content',
  ));   
  $block->module = 'newplay_admin_links';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function newplay_admin_links_feed_content_type_admin_title($subtype, $conf, $context) {
  return t('Feed Add Link');
}

function newplay_admin_links_feed_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
