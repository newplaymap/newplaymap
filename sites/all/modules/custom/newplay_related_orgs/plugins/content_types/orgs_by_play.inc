<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
function newplay_related_orgs_orgs_by_play_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t('Related Organizations (by play)'),
      'icon' => 'icon_node.png',
      'description' => t('Other organizations that have hosted events related to this play'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function newplay_related_orgs_orgs_by_play_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $output = '';
  $items = array();
  $block = new stdClass();

  // dsm($context);
  
  // Figure out if we're starting with a play or with an artist
  if ($context->data->type == 'artist') {
    // If it's an artist, use a view to get all their plays
    // Make a comma seperated list and pass that instead
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
    
  } else {
    // If it's a play, pass the context arg directly
    $all_plays_arg = $context->argument;
  }    
  
  // Get all the events related to that play
  // View organization_listing views-tab-panel_pane_2
  $event_query = db_query("SELECT node.nid AS nid 
    FROM node node LEFT JOIN content_field_related_play node_data_field_related_play ON node.vid = node_data_field_related_play.vid 
    WHERE (node.status <> 0) AND (node.type in ('event')) AND (node_data_field_related_play.field_related_play_nid IN (%d))", $all_plays_arg);
    
  $all_event_ids = array();
  while ($event = db_fetch_object($event_query)) {
    $all_event_ids[] = $event->nid;
  }
    
  $all_org_ids = array();
  
  // Get the primary org for each event
  foreach ($all_event_ids as $each_event_id) {
    $org_query = db_query("SELECT node.nid AS nid, node_data_field_related_theater.field_related_theater_nid AS theater
     FROM node node 
     LEFT JOIN content_field_related_theater node_data_field_related_theater ON node.vid = node_data_field_related_theater.vid
     LEFT JOIN node node_node_data_field_related_theater ON node_data_field_related_theater.field_related_theater_nid = node_node_data_field_related_theater.nid
     WHERE (node.status <> 0) AND (node.nid = %d)", $each_event_id);
     
     while ($orgs = db_fetch_object($org_query)) {
       $all_org_ids[] = $orgs->theater;
     }
  }
  
  
  // Get the other related orgs for each event
  foreach ($all_event_ids as $each_event_id) {
    $org_query = db_query("SELECT node.nid AS nid, node_data_field_partner_org.field_partner_org_nid AS partner
     FROM node node 
     LEFT JOIN content_field_partner_org node_data_field_partner_org ON node.vid = node_data_field_partner_org.vid
     LEFT JOIN node node_node_data_field_partner_org ON node_data_field_partner_org.field_partner_org_nid = node_node_data_field_partner_org.nid
     WHERE (node.status <> 0) AND (node.nid = %d)", $each_event_id);
     
     while ($orgs = db_fetch_object($org_query)) {
       $all_org_ids[] = $orgs->partner;
     }
  }
  
  // Make sure each org only shows up once
  $all_org_ids = array_unique($all_org_ids);
  
  
  // Build the list
  $link_options = array(
    'attributes' => array( 
      // 'class' => 'view-blog',
      // 'id' => 'blog-link' 
    ) 
  );  
  foreach ($all_org_ids as $single_org) {
    if ($single_org != NULL) {
      $node = node_load($single_org);
      $items[] = l($node->title, 'node/' . $node->nid, $link_options);
    }
  }
  
  if (!empty($items)) {
    $output .= theme('item_list', $items);
  }
  
      
  $block->module = 'newplay_related_orgs';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function newplay_related_orgs_orgs_by_play_content_type_admin_title($subtype, $conf, $context) {
  return t('Related Organizations');
}

function newplay_related_orgs_orgs_by_play_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
