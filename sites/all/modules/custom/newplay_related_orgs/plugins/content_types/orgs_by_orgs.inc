<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
function newplay_related_orgs_orgs_by_orgs_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t('Related Organizations (by organization)'),
      'icon' => 'icon_node.png',
      'description' => t('Other organizations that have hosted events together'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function newplay_related_orgs_orgs_by_orgs_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $output = '';
  $items = array();
  $block = new stdClass();


  $link_options = array( 'attributes' => array( 
    // 'class' => 'view-blog',
    // 'id' => 'blog-link' 
  ) );
  
  // $output = l('Add Event', 'node/' . $context->argument, $link_options);
  
  
  
  
  // get any events that list this org as a lead developer
  $event_id_primary = db_query("SELECT node.nid AS nid FROM node node 
  LEFT JOIN content_field_related_theater node_data_field_related_theater ON node.vid = node_data_field_related_theater.vid
  WHERE (node.status <> 0) AND (node.type in ('event')) AND (node_data_field_related_theater.field_related_theater_nid = %d)", $context->argument);

  // get any events that list this org as a partner org
  $event_id_partner = db_query("SELECT node.nid AS nid FROM node node 
  LEFT JOIN content_field_partner_org node_data_field_partner_org ON node.vid = node_data_field_partner_org.vid
  WHERE (node.status <> 0) AND (node.type in ('event')) AND (node_data_field_partner_org.field_partner_org_nid = %d)", $context->argument);

  $event_ids = array();
  while ($event = db_fetch_object($event_id_primary)) {
    $event_ids[] = $event->nid;
  }

  while ($event = db_fetch_object($event_id_partner)) {
    $event_ids[] = $event->nid;
  }



  $related_org_ids = array();
  foreach ($event_ids as $event_node_id) {
    $event_node = node_load($event_node_id);
  
    $event_primary_and_partner = array_merge($event_node->field_related_theater, $event_node->field_partner_org);
  
    foreach ($event_primary_and_partner as $event_org) {
      if (($event_org['nid'] != $context->argument) && ($event_org['nid'] != NULL)) {
        $related_org_ids[] = $event_org['nid'];
      }
    
    }
  
  }
  
  // Make sure each org only shows up once
  $related_org_ids = array_unique($related_org_ids);
    
  foreach ($related_org_ids as $related_orgs) {
    $node = node_load($related_orgs);
    $items[] = l($node->title, 'node/' . $node->nid, $link_options);
  }
  
  if (!empty($items)) {
    $output .= theme('item_list', $items);
  }
  
      
  $block->module = 'newplay_related_orgs';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function newplay_related_orgs_orgs_by_orgs_content_type_admin_title($subtype, $conf, $context) {
  return t('Related Organizations');
}

function newplay_related_orgs_orgs_by_orgs_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
