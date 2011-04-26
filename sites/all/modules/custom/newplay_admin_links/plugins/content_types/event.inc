<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
function newplay_admin_links_event_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t('Add Event'),
      'icon' => 'icon_node.png',
      'description' => t('Link to add an event from an organization or play'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function newplay_admin_links_event_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $items = array();
  $output = '';
  $block = new stdClass();


  $link_options = array( 
    'attributes' => array( 
      // 'class' => 'view-blog',
      // 'id' => 'blog-link' 
    ),
    // 'query' => 'destination=node/' . arg(1) // This isn't working in the overlay because arg(1) is the menu callback. Could be set up again but not necessary
  );
  
  
  $items[] = l('Add Event', 'node/add/event/' . $context->argument, $link_options);
  // $items[] = l('Add Play', 'node/add/play/' . $context->argument, $link_options);
  
  $output .= theme('item_list', $items);
      
  $block->module = 'newplay_admin_links';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function newplay_admin_links_event_content_type_admin_title($subtype, $conf, $context) {
  return t('Event Add Link');
}

function newplay_admin_links_event_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
