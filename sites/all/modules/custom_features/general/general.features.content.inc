<?php

/**
 * Implementation of hook_content_default_fields().
 */
function general_content_default_fields() {
  $fields = array();

  // Exported field: field_delete_request_explanation
  $fields['delete_request-field_delete_request_explanation'] = array(
    'field_name' => 'field_delete_request_explanation',
    'type_name' => 'delete_request',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_delete_request_explanation][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Explanation',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_delete_request_reference
  $fields['delete_request-field_delete_request_reference'] = array(
    'field_name' => 'field_delete_request_reference',
    'type_name' => 'delete_request',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'event' => 'event',
      'artist' => 'artist',
      'organization' => 'organization',
      'play' => 'play',
      'agent' => 0,
      'artist_memberships' => 0,
      'blog_feed' => 0,
      'blog_post' => 0,
      'delete_request' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
      'org_type' => 0,
      'page' => 0,
      'panel' => 0,
      'photo' => 0,
      'photo_feed' => 0,
      'story' => 0,
      'twitter_feed' => 0,
      'twitter_item' => 0,
      'video' => 0,
      'video_feed' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'default',
      ),
      'fallback' => 'page_not_found',
      'edit_fallback' => 0,
      'label' => 'Content to Delete',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Content to Delete');
  t('Explanation');

  return $fields;
}
