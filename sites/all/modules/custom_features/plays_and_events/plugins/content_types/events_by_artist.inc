<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
function plays_and_events_events_by_artist_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t('Related Events (by artist)'),
      'icon' => 'icon_node.png',
      'description' => t('Events of plays written by this artist'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function plays_and_events_events_by_artist_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $output = '';
  $items = array();
  $block = new stdClass();


  // Start with Artist NID
  $generative_artist = $context->argument;
  
  // Find all the plays that have the related gen artist
  $view = views_get_view('plays');
  $view->init_display('ctools_context_1');
  $plays = $view->execute_display('ctools_context_1', array($generative_artist));
  
  $all_plays = array();
  foreach($plays['view']->result as $each_play) {
    $all_plays[] = $each_play->nid;
  }
  
  $all_plays_arg = implode(',', $all_plays); 
  
  // Find all the events for all of those plays and put them chronologically
  $view2 = views_get_view('events');
  $view2->set_display('panel_pane_3');
  $view2->set_arguments(array($all_plays_arg));
  $events = $view2->preview();
  
  // Only show results if the view returns something
  $view2->init_display('ctools_context_1');
  $events_results = $view2->execute_display('ctools_context_1', array($all_plays_arg));
  
  if (!empty($events_results['view']->result)) {
    $output .= $events;
  }
  
  
  // $output .= theme('item_list', $items);
      
  $block->module = 'plays_and_events';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function plays_and_events_events_by_artist_content_type_admin_title($subtype, $conf, $context) {
  return t('Related Events');
}

function plays_and_events_events_by_artist_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
