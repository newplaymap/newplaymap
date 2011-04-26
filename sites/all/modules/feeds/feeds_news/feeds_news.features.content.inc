<?php

/**
 * Implementation of hook_content_default_fields().
 */
function feeds_news_content_default_fields() {
  $fields = array();

  // Exported field: field_related_theater
  $fields['feed-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'feed',
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
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'organization' => 'organization',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist' => 0,
      'page' => 0,
      'panel' => 0,
      'photo' => 0,
      'photo_feed' => 0,
      'play' => 0,
      'story' => 0,
      'twitter_feed' => 0,
      'twitter_item' => 0,
      'video' => 0,
      'video_feed' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_related_theater][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Related Theater',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_related_theater
  $fields['feed_item-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'feed_item',
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
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'organization' => 'organization',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist' => 0,
      'page' => 0,
      'panel' => 0,
      'photo' => 0,
      'photo_feed' => 0,
      'play' => 0,
      'story' => 0,
      'twitter_feed' => 0,
      'twitter_item' => 0,
      'video' => 0,
      'video_feed' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_related_theater][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Related Theater',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Related Theater');

  return $fields;
}
