<?php

/**
 * Implementation of hook_content_default_fields().
 */
function plays_and_events_content_default_fields() {
  $fields = array();

  // Exported field: field_event_date
  $fields['event-field_event_date'] = array(
    'field_name' => 'field_event_date',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => 'group_event_info',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
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
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => 'optional',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'blank',
      'default_value_code2' => '',
      'input_format' => 'M j Y',
      'input_format_custom' => '',
      'increment' => '30',
      'text_parts' => array(),
      'year_range' => '-10:+1',
      'label_position' => 'above',
      'label' => 'Date',
      'weight' => '-1',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_event_desc
  $fields['event-field_event_desc'] = array(
    'field_name' => 'field_event_desc',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '3',
      'parent' => 'group_event_info',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
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
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_event_desc][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Event description',
      'weight' => '3',
      'description' => 'Example: This is a weeklong workshop focusing on choreography and integrating dance into the piece.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_event_type
  $fields['event-field_event_type'] = array(
    'field_name' => 'field_event_type',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => 'group_event_info',
      '4' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
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
      'event_type' => 'event_type',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist' => 0,
      'organization' => 0,
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
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Event type',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_location
  $fields['event-field_location'] = array(
    'field_name' => 'field_location',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '2',
      'parent' => 'group_event_info',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
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
    'type' => 'location',
    'required' => '1',
    'multiple' => '0',
    'module' => 'location_cck',
    'active' => '1',
    'location_settings' => array(
      'form' => array(
        'fields' => array(
          'name' => array(
            'collect' => '0',
            'default' => '',
            'weight' => '2',
          ),
          'street' => array(
            'collect' => '2',
            'default' => '',
            'weight' => '4',
          ),
          'additional' => array(
            'collect' => '0',
            'default' => '',
            'weight' => '6',
          ),
          'city' => array(
            'collect' => '2',
            'default' => '',
            'weight' => '8',
          ),
          'province' => array(
            'collect' => '2',
            'default' => '',
            'weight' => '10',
          ),
          'postal_code' => array(
            'collect' => '2',
            'default' => '',
            'weight' => '12',
          ),
          'country' => array(
            'collect' => '2',
            'default' => 'us',
            'weight' => '14',
          ),
          'locpick' => array(
            'collect' => '0',
            'weight' => '20',
          ),
        ),
      ),
      'display' => array(
        'hide' => array(
          'name' => 'name',
          'additional' => 'additional',
          'locpick' => 'locpick',
          'province_name' => 'province_name',
          'coords' => 'coords',
          'street' => 0,
          'city' => 0,
          'province' => 0,
          'postal_code' => 0,
          'country' => 0,
          'country_name' => 0,
          'map_link' => 0,
        ),
      ),
    ),
    'gmap_macro' => '[gmap ]',
    'gmap_marker' => 'blue',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'street' => '',
          'city' => '',
          'province' => '',
          'postal_code' => '',
          'country' => 'us',
          'cck_preview_in_progress' => TRUE,
          'location_settings' => array(
            'form' => array(
              'fields' => array(
                'name' => array(
                  'default' => '',
                  'collect' => '0',
                  'weight' => '2',
                ),
                'street' => array(
                  'default' => '',
                  'collect' => '1',
                  'weight' => '4',
                ),
                'additional' => array(
                  'default' => '',
                  'collect' => '0',
                  'weight' => '6',
                ),
                'city' => array(
                  'default' => '',
                  'collect' => '1',
                  'weight' => '8',
                ),
                'province' => array(
                  'default' => '',
                  'collect' => '1',
                  'weight' => '10',
                ),
                'postal_code' => array(
                  'default' => '',
                  'collect' => '1',
                  'weight' => '12',
                ),
                'country' => array(
                  'default' => 'us',
                  'collect' => '1',
                  'weight' => '14',
                ),
                'locpick' => array(
                  'default' => FALSE,
                  'collect' => '0',
                  'weight' => '20',
                  'nodiff' => TRUE,
                ),
                'cck_preview_in_progress' => array(
                  'default' => TRUE,
                ),
                'location_settings' => array(
                  'default' => array(
                    'form' => array(
                      'fields' => array(
                        'name' => array(
                          'default' => '',
                          'collect' => '0',
                          'weight' => '2',
                        ),
                        'street' => array(
                          'default' => '',
                          'collect' => '1',
                          'weight' => '4',
                        ),
                        'additional' => array(
                          'default' => '',
                          'collect' => '0',
                          'weight' => '6',
                        ),
                        'city' => array(
                          'default' => '',
                          'collect' => '1',
                          'weight' => '8',
                        ),
                        'province' => array(
                          'default' => '',
                          'collect' => '1',
                          'weight' => '10',
                        ),
                        'postal_code' => array(
                          'default' => '',
                          'collect' => '1',
                          'weight' => '12',
                        ),
                        'country' => array(
                          'default' => 'us',
                          'collect' => '1',
                          'weight' => '14',
                        ),
                        'locpick' => array(
                          'default' => FALSE,
                          'collect' => '0',
                          'weight' => '20',
                          'nodiff' => TRUE,
                        ),
                        'cck_preview_in_progress' => array(
                          'default' => TRUE,
                        ),
                        'location_settings' => array(
                          'default' => array(
                            'form' => array(
                              'fields' => array(
                                'name' => array(
                                  'default' => '',
                                  'collect' => '0',
                                  'weight' => '2',
                                ),
                                'street' => array(
                                  'default' => '',
                                  'collect' => '1',
                                  'weight' => '4',
                                ),
                                'additional' => array(
                                  'default' => '',
                                  'collect' => '0',
                                  'weight' => '6',
                                ),
                                'city' => array(
                                  'default' => '',
                                  'collect' => '1',
                                  'weight' => '8',
                                ),
                                'province' => array(
                                  'default' => '',
                                  'collect' => '1',
                                  'weight' => '10',
                                ),
                                'postal_code' => array(
                                  'default' => '',
                                  'collect' => '1',
                                  'weight' => '12',
                                ),
                                'country' => array(
                                  'default' => 'us',
                                  'collect' => '1',
                                  'weight' => '14',
                                ),
                                'locpick' => array(
                                  'default' => array(
                                    'user_latitude' => '',
                                    'user_longitude' => '',
                                  ),
                                  'collect' => '0',
                                  'weight' => '20',
                                  'nodiff' => TRUE,
                                ),
                                'cck_preview_in_progress' => array(
                                  'default' => TRUE,
                                ),
                                'location_settings' => array(
                                  'default' => array(
                                    'form' => array(
                                      'fields' => array(
                                        'lid' => array(
                                          'default' => FALSE,
                                        ),
                                        'name' => array(
                                          'default' => '',
                                          'collect' => 1,
                                          'weight' => 2,
                                        ),
                                        'street' => array(
                                          'default' => '',
                                          'collect' => 1,
                                          'weight' => 4,
                                        ),
                                        'additional' => array(
                                          'default' => '',
                                          'collect' => 1,
                                          'weight' => 6,
                                        ),
                                        'city' => array(
                                          'default' => '',
                                          'collect' => 0,
                                          'weight' => 8,
                                        ),
                                        'province' => array(
                                          'default' => '',
                                          'collect' => 0,
                                          'weight' => 10,
                                        ),
                                        'postal_code' => array(
                                          'default' => '',
                                          'collect' => 0,
                                          'weight' => 12,
                                        ),
                                        'country' => array(
                                          'default' => 'us',
                                          'collect' => 1,
                                          'weight' => 14,
                                        ),
                                        'locpick' => array(
                                          'default' => FALSE,
                                          'collect' => 1,
                                          'weight' => 20,
                                          'nodiff' => TRUE,
                                        ),
                                        'latitude' => array(
                                          'default' => 0,
                                        ),
                                        'longitude' => array(
                                          'default' => 0,
                                        ),
                                        'source' => array(
                                          'default' => 0,
                                        ),
                                        'is_primary' => array(
                                          'default' => 0,
                                        ),
                                        'delete_location' => array(
                                          'default' => FALSE,
                                          'nodiff' => TRUE,
                                        ),
                                      ),
                                    ),
                                  ),
                                ),
                                'lid' => array(
                                  'default' => FALSE,
                                ),
                                'latitude' => array(
                                  'default' => 0,
                                ),
                                'longitude' => array(
                                  'default' => 0,
                                ),
                                'source' => array(
                                  'default' => 0,
                                ),
                                'is_primary' => array(
                                  'default' => 0,
                                ),
                                'delete_location' => array(
                                  'default' => FALSE,
                                  'nodiff' => TRUE,
                                ),
                              ),
                            ),
                            'display' => array(
                              'hide' => array(
                                'name' => 'name',
                                'additional' => 'additional',
                                'locpick' => 'locpick',
                                'coords' => 'coords',
                                'street' => 0,
                                'city' => 0,
                                'province' => 0,
                                'postal_code' => 0,
                                'country' => 0,
                                'province_name' => 0,
                                'country_name' => 0,
                                'map_link' => 0,
                              ),
                            ),
                          ),
                        ),
                        'lid' => array(
                          'default' => FALSE,
                        ),
                        'latitude' => array(
                          'default' => 0,
                        ),
                        'longitude' => array(
                          'default' => 0,
                        ),
                        'source' => array(
                          'default' => 0,
                        ),
                        'is_primary' => array(
                          'default' => 0,
                        ),
                        'delete_location' => array(
                          'default' => FALSE,
                          'nodiff' => TRUE,
                        ),
                      ),
                    ),
                    'display' => array(
                      'hide' => array(
                        'name' => 'name',
                        'additional' => 'additional',
                        'locpick' => 'locpick',
                        'coords' => 'coords',
                        'street' => 0,
                        'city' => 0,
                        'province' => 0,
                        'postal_code' => 0,
                        'country' => 0,
                        'province_name' => 0,
                        'country_name' => 0,
                        'map_link' => 0,
                      ),
                    ),
                  ),
                ),
                'lid' => array(
                  'default' => FALSE,
                ),
                'latitude' => array(
                  'default' => 0,
                ),
                'longitude' => array(
                  'default' => 0,
                ),
                'source' => array(
                  'default' => 0,
                ),
                'is_primary' => array(
                  'default' => 0,
                ),
                'delete_location' => array(
                  'default' => FALSE,
                  'nodiff' => TRUE,
                ),
              ),
            ),
            'display' => array(
              'hide' => array(
                'name' => 'name',
                'additional' => 'additional',
                'locpick' => 'locpick',
                'province_name' => 'province_name',
                'coords' => 'coords',
                'street' => 0,
                'city' => 0,
                'province' => 0,
                'postal_code' => 0,
                'country' => 0,
                'country_name' => 0,
                'map_link' => 0,
              ),
            ),
          ),
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Location',
      'weight' => '2',
      'description' => '',
      'type' => 'location',
      'module' => 'location_cck',
    ),
  );

  // Exported field: field_partner_org
  $fields['event-field_partner_org'] = array(
    'field_name' => 'field_partner_org',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '1',
      'parent' => 'group_event_info',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
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
    'required' => '0',
    'multiple' => '1',
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
      'artist_type' => 0,
      'org_type' => 0,
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
          '_error_element' => 'default_value_widget][field_partner_org][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Partner Organization',
      'weight' => '1',
      'description' => '',
      'type' => 'noderefcreate_autocomplete',
      'module' => 'noderefcreate',
    ),
  );

  // Exported field: field_related_play
  $fields['event-field_related_play'] = array(
    'field_name' => 'field_related_play',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
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
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'play' => 'play',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist' => 0,
      'organization' => 0,
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
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_related_play][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'default',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'label' => 'Play title',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_theater
  $fields['event-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => 0,
      'parent' => 'group_event_info',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
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
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'default',
      ),
      'fallback' => 'noderefcreate',
      'edit_fallback' => 1,
      'label' => 'Lead Organization',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_artist
  $fields['play-field_artist'] = array(
    'field_name' => 'field_artist',
    'type_name' => 'play',
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
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'artist' => 'artist',
      'agent' => 0,
      'artist_memberships' => 0,
      'blog_feed' => 0,
      'blog_post' => 0,
      'delete_request' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
      'organization' => 0,
      'org_type' => 0,
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
    'advanced_view' => 'artist_list',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'default',
      ),
      'fallback' => 'noderefcreate',
      'edit_fallback' => 1,
      'label' => 'Generative Artist',
      'weight' => '-4',
      'description' => 'Playwright or Ensemble / Collective name.',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_play_alt_titles
  $fields['play-field_play_alt_titles'] = array(
    'field_name' => 'field_play_alt_titles',
    'type_name' => 'play',
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
    'required' => '0',
    'multiple' => '1',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_play_alt_titles][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Alternate titles',
      'weight' => '-2',
      'description' => 'If this play has had other titles, enter them here.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_play_referrers
  $fields['play-field_play_referrers'] = array(
    'field_name' => 'field_play_referrers',
    'type_name' => 'play',
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
    'type' => 'nodereferrer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereferrer',
    'active' => '1',
    'referrer_types' => array(
      'event' => 'event',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist' => 0,
      'organization' => 0,
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
    'referrer_fields' => array(
      'field_related_play' => 'field_related_play',
      'field_related_theater' => 0,
      'field_event_type' => 0,
      'field_partner_org' => 0,
      'field_artist' => 0,
    ),
    'referrer_nodes_per_page' => '0',
    'referrer_pager_element' => '0',
    'referrer_order' => 'TITLE_ASC',
    'widget' => array(
      'label' => 'Related Events',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereferrer_list',
      'module' => 'nodereferrer',
    ),
  );

  // Exported field: field_play_synopsis
  $fields['play-field_play_synopsis'] = array(
    'field_name' => 'field_play_synopsis',
    'type_name' => 'play',
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
    'required' => '0',
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
          '_error_element' => 'default_value_widget][field_play_synopsis][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Synopsis',
      'weight' => '-3',
      'description' => 'Describe the play, and add links to specific information about this play.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alternate titles');
  t('Date');
  t('Event description');
  t('Event type');
  t('Generative Artist');
  t('Lead Organization');
  t('Location');
  t('Partner Organization');
  t('Play title');
  t('Related Events');
  t('Synopsis');

  return $fields;
}
