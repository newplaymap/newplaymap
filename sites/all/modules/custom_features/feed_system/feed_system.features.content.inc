<?php

/**
 * Implementation of hook_content_default_fields().
 */
function feed_system_content_default_fields() {
  $fields = array();

  // Exported field: field_artist
  $fields['blog_feed-field_artist'] = array(
    'field_name' => 'field_artist',
    'type_name' => 'blog_feed',
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
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
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
    'advanced_view' => 'artist_list',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'source',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Generative Artist',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_play
  $fields['blog_feed-field_related_play'] = array(
    'field_name' => 'field_related_play',
    'type_name' => 'blog_feed',
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
      'label' => 'Related Play',
      'weight' => '-3',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_theater
  $fields['blog_feed-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'blog_feed',
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
      'agent' => 0,
      'artist_memberships' => 0,
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
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'label' => 'Related Theater',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_artist
  $fields['blog_post-field_artist'] = array(
    'field_name' => 'field_artist',
    'type_name' => 'blog_post',
    'display_settings' => array(
      'weight' => 0,
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
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'artist' => 'artist',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
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
    'advanced_view' => 'artist_list',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'source',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Generative Artist',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_blog_author
  $fields['blog_post-field_blog_author'] = array(
    'field_name' => 'field_blog_author',
    'type_name' => 'blog_post',
    'display_settings' => array(
      'weight' => '-3',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_blog_author][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Author',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_blog_body
  $fields['blog_post-field_blog_body'] = array(
    'field_name' => 'field_blog_body',
    'type_name' => 'blog_post',
    'display_settings' => array(
      'weight' => '4',
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
      'rows' => '10',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_blog_body][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Body',
      'weight' => '4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_blog_orig_url
  $fields['blog_post-field_blog_orig_url'] = array(
    'field_name' => 'field_blog_orig_url',
    'type_name' => 'blog_post',
    'display_settings' => array(
      'weight' => '3',
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
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => '_blank',
      'rel' => '',
      'class' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => '',
    'validate_url' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Original URL',
      'weight' => '3',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_feed_item_headline
  $fields['blog_post-field_feed_item_headline'] = array(
    'field_name' => 'field_feed_item_headline',
    'type_name' => 'blog_post',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      '4' => array(
        'format' => 'hidden',
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
      'rows' => '2',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_feed_item_headline][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Headline',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_related_play
  $fields['blog_post-field_related_play'] = array(
    'field_name' => 'field_related_play',
    'type_name' => 'blog_post',
    'display_settings' => array(
      'weight' => '-1',
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
      'label' => 'Related Play',
      'weight' => '-1',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_theater
  $fields['blog_post-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'blog_post',
    'display_settings' => array(
      'weight' => '-2',
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
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'organization' => 'organization',
      'agent' => 0,
      'artist_memberships' => 0,
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
          '_error_element' => 'default_value_widget][field_related_theater][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Related Theater',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_artist
  $fields['photo-field_artist'] = array(
    'field_name' => 'field_artist',
    'type_name' => 'photo',
    'display_settings' => array(
      'weight' => 0,
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
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'artist' => 'artist',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
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
    'advanced_view' => 'artist_list',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'source',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Generative Artist',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_feed_item_headline
  $fields['photo-field_feed_item_headline'] = array(
    'field_name' => 'field_feed_item_headline',
    'type_name' => 'photo',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      '4' => array(
        'format' => 'hidden',
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
      'rows' => '2',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_feed_item_headline][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Headline',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_photo_embed
  $fields['photo-field_photo_embed'] = array(
    'field_name' => 'field_photo_embed',
    'type_name' => 'photo',
    'display_settings' => array(
      'weight' => '-3',
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
    ),
    'widget_active' => '1',
    'type' => 'emimage',
    'required' => '0',
    'multiple' => '0',
    'module' => 'emimage',
    'active' => '1',
    'widget' => array(
      'full_width' => '1000',
      'full_height' => '',
      'full_link' => 'provider',
      'preview_width' => '',
      'preview_height' => '350',
      'preview_link' => 'node',
      'thumbnail_width' => '',
      'thumbnail_height' => '100',
      'thumbnail_link' => 'provider',
      'providers' => array(
        'custom_url' => 0,
        'flickr' => 0,
        'imageshack' => 0,
        'photobucket' => 0,
        'picasa' => 0,
      ),
      'emthumb' => 0,
      'emthumb_label' => 'Photo custom thumbnail',
      'emthumb_description' => 'If you upload a custom thumbnail, then this will be displayed when the Photo thumbnail is called for, overriding any automatic thumbnails by custom providers.',
      'emthumb_max_resolution' => '0',
      'emimport_image_path' => '',
      'emthumb_custom_alt' => 0,
      'emthumb_custom_title' => 0,
      'emthumb_store_local_thumbnail' => 1,
      'emthumb_start_collapsed' => 0,
      'default_value' => array(
        '0' => array(
          'embed' => '',
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Photo',
      'weight' => '-3',
      'description' => '',
      'type' => 'emimage_textfields',
      'module' => 'emimage',
    ),
  );

  // Exported field: field_related_play
  $fields['photo-field_related_play'] = array(
    'field_name' => 'field_related_play',
    'type_name' => 'photo',
    'display_settings' => array(
      'weight' => '-1',
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
      'label' => 'Related Play',
      'weight' => '-1',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_theater
  $fields['photo-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'photo',
    'display_settings' => array(
      'weight' => '-2',
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
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'organization' => 'organization',
      'agent' => 0,
      'artist_memberships' => 0,
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
          '_error_element' => 'default_value_widget][field_related_theater][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Related Theater',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_artist
  $fields['photo_feed-field_artist'] = array(
    'field_name' => 'field_artist',
    'type_name' => 'photo_feed',
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
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
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
    'advanced_view' => 'artist_list',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'source',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Generative Artist',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_play
  $fields['photo_feed-field_related_play'] = array(
    'field_name' => 'field_related_play',
    'type_name' => 'photo_feed',
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
      'label' => 'Related Play',
      'weight' => '-3',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_theater
  $fields['photo_feed-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'photo_feed',
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
      'agent' => 0,
      'artist_memberships' => 0,
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
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'label' => 'Related Theater',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_artist
  $fields['twitter_feed-field_artist'] = array(
    'field_name' => 'field_artist',
    'type_name' => 'twitter_feed',
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
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
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
    'advanced_view' => 'artist_list',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'source',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Generative Artist',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_play
  $fields['twitter_feed-field_related_play'] = array(
    'field_name' => 'field_related_play',
    'type_name' => 'twitter_feed',
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
      'label' => 'Related Play',
      'weight' => '-3',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_theater
  $fields['twitter_feed-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'twitter_feed',
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
      'agent' => 0,
      'artist_memberships' => 0,
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
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'label' => 'Related Theater',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_artist
  $fields['twitter_item-field_artist'] = array(
    'field_name' => 'field_artist',
    'type_name' => 'twitter_item',
    'display_settings' => array(
      'weight' => '-1',
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
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'artist' => 'artist',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
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
    'advanced_view' => 'artist_list',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'source',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Generative Artist',
      'weight' => '-1',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_feed_item_author
  $fields['twitter_item-field_feed_item_author'] = array(
    'field_name' => 'field_feed_item_author',
    'type_name' => 'twitter_item',
    'display_settings' => array(
      'weight' => '-3',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_feed_item_author][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Author',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_feed_item_headline
  $fields['twitter_item-field_feed_item_headline'] = array(
    'field_name' => 'field_feed_item_headline',
    'type_name' => 'twitter_item',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      '4' => array(
        'format' => 'hidden',
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
      'rows' => '2',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_feed_item_headline][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Headline',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_feed_item_orig_url
  $fields['twitter_item-field_feed_item_orig_url'] = array(
    'field_name' => 'field_feed_item_orig_url',
    'type_name' => 'twitter_item',
    'display_settings' => array(
      'weight' => '1',
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
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => '_blank',
      'rel' => '',
      'class' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => '',
    'validate_url' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Original URL',
      'weight' => '1',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_related_play
  $fields['twitter_item-field_related_play'] = array(
    'field_name' => 'field_related_play',
    'type_name' => 'twitter_item',
    'display_settings' => array(
      'weight' => 0,
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
      'label' => 'Related Play',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_theater
  $fields['twitter_item-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'twitter_item',
    'display_settings' => array(
      'weight' => '-2',
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
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'organization' => 'organization',
      'agent' => 0,
      'artist_memberships' => 0,
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
          '_error_element' => 'default_value_widget][field_related_theater][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Related Theater',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_artist
  $fields['video-field_artist'] = array(
    'field_name' => 'field_artist',
    'type_name' => 'video',
    'display_settings' => array(
      'weight' => '1',
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
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'artist' => 'artist',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
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
    'advanced_view' => 'artist_list',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'source',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Generative Artist',
      'weight' => '1',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_feed_item_author
  $fields['video-field_feed_item_author'] = array(
    'field_name' => 'field_feed_item_author',
    'type_name' => 'video',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_feed_item_author][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Author',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_feed_item_headline
  $fields['video-field_feed_item_headline'] = array(
    'field_name' => 'field_feed_item_headline',
    'type_name' => 'video',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      '4' => array(
        'format' => 'hidden',
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
      'rows' => '2',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_feed_item_headline][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Headline',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_related_play
  $fields['video-field_related_play'] = array(
    'field_name' => 'field_related_play',
    'type_name' => 'video',
    'display_settings' => array(
      'weight' => 0,
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
      'label' => 'Related Play',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_theater
  $fields['video-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'video',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'organization' => 'organization',
      'agent' => 0,
      'artist_memberships' => 0,
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
          '_error_element' => 'default_value_widget][field_related_theater][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Related Theater',
      'weight' => '-1',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_video_embed
  $fields['video-field_video_embed'] = array(
    'field_name' => 'field_video_embed',
    'type_name' => 'video',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'video_video',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'video_video',
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
    'type' => 'emvideo',
    'required' => '0',
    'multiple' => '0',
    'module' => 'emvideo',
    'active' => '1',
    'widget' => array(
      'video_width' => '425',
      'video_height' => '350',
      'video_autoplay' => 0,
      'preview_width' => '228',
      'preview_height' => '165',
      'preview_autoplay' => 0,
      'thumbnail_width' => '228',
      'thumbnail_height' => '165',
      'thumbnail_default_path' => '',
      'thumbnail_link_title' => 'See video',
      'providers' => array(
        'archive' => 'archive',
        'bliptv' => 'bliptv',
        'dailymotion' => 'dailymotion',
        'google' => 'google',
        'guba' => 'guba',
        'imeem' => 'imeem',
        'lastfm' => 'lastfm',
        'livevideo' => 'livevideo',
        'metacafe' => 'metacafe',
        'myspace' => 'myspace',
        'revver' => 'revver',
        'sevenload' => 'sevenload',
        'spike' => 'spike',
        'tudou' => 'tudou',
        'twistage' => 'twistage',
        'ustream' => 'ustream',
        'ustreamlive' => 'ustreamlive',
        'vimeo' => 'vimeo',
        'voicethread' => 'voicethread',
        'yahoomusic' => 'yahoomusic',
        'youtube' => 'youtube',
        'zzz_custom_url' => 'zzz_custom_url',
      ),
      'emthumb' => 0,
      'emthumb_label' => 'Video custom thumbnail',
      'emthumb_description' => 'If you upload a custom thumbnail, then this will be displayed when the Video thumbnail is called for, overriding any automatic thumbnails by custom providers.',
      'emthumb_max_resolution' => '0',
      'emimport_image_path' => '',
      'emthumb_custom_alt' => 0,
      'emthumb_custom_title' => 0,
      'emthumb_store_local_thumbnail' => 1,
      'emthumb_start_collapsed' => 0,
      'default_value' => array(
        '0' => array(
          'embed' => '',
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Video',
      'weight' => '-2',
      'description' => '',
      'type' => 'emvideo_textfields',
      'module' => 'emvideo',
    ),
  );

  // Exported field: field_artist
  $fields['video_feed-field_artist'] = array(
    'field_name' => 'field_artist',
    'type_name' => 'video_feed',
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
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist_type' => 0,
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
    'advanced_view' => 'artist_list',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => '',
        'hover_title' => '',
        'destination' => 'source',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Generative Artist',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_play
  $fields['video_feed-field_related_play'] = array(
    'field_name' => 'field_related_play',
    'type_name' => 'video_feed',
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
      'label' => 'Related Play',
      'weight' => '-3',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_related_theater
  $fields['video_feed-field_related_theater'] = array(
    'field_name' => 'field_related_theater',
    'type_name' => 'video_feed',
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
      'agent' => 0,
      'artist_memberships' => 0,
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
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'label' => 'Related Theater',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Author');
  t('Body');
  t('Generative Artist');
  t('Headline');
  t('Original URL');
  t('Photo');
  t('Related Play');
  t('Related Theater');
  t('Video');

  return $fields;
}
