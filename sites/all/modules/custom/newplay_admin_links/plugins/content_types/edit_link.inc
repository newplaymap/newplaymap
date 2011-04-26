<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
function newplay_admin_links_edit_link_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t('Edit Link'),
      'icon' => 'icon_node.png',
      'description' => t('Link to edit content'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function newplay_admin_links_edit_link_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $items = array();
  $output = '';
  $block = new stdClass();

  $alias = drupal_get_path_alias('node/' . $context->argument);
  $link_options = array( 
    'attributes' => array( 
      // 'class' => 'view-blog',
      // 'id' => 'blog-link' 
    ),
    // 'query' => 'destination=/#/' . $alias // @TODO: something like this should work to send you back to the same node?
    // 'query' => 'destination=#'
  );
  
  
  $items[] = l('Edit', 'node/' . $context->argument . '/edit', $link_options);
  
  $output .= theme('item_list', $items);
      
  $block->module = 'newplay_admin_links';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function newplay_admin_links_edit_link_content_type_admin_title($subtype, $conf, $context) {
  return t('Edit link');
}

function newplay_admin_links_edit_link_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
