<?php

/**
 * Implementation of hook_content_default_fields().
 */
function artists_content_default_fields() {
  $fields = array();

  // Exported field: field_artist_affiliations
  $fields['artist-field_artist_affiliations'] = array(
    'field_name' => 'field_artist_affiliations',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '6',
      'parent' => 'group_artist_detailed',
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
      'artist_memberships' => 'artist_memberships',
      'agent' => 0,
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist' => 0,
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
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist_affiliations][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Affiliations & Memberships',
      'weight' => '6',
      'description' => 'Enter multiple affiliations as a comma separated list.',
      'type' => 'noderefcreate_autocomplete',
      'module' => 'noderefcreate',
    ),
  );

  // Exported field: field_artist_agent
  $fields['artist-field_artist_agent'] = array(
    'field_name' => 'field_artist_agent',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '5',
      'parent' => 'group_artist_detailed',
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
      'agent' => 'agent',
      'blog_feed' => 0,
      'blog_post' => 0,
      'event' => 0,
      'event_type' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'artist' => 0,
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
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_artist_agent][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Representative',
      'weight' => '5',
      'description' => 'Name of the person folks should contact if they want to work with this Generative Artist. Could be the Artist, an Agent, Manager, etc.',
      'type' => 'noderefcreate_autocomplete',
      'module' => 'noderefcreate',
    ),
  );

  // Exported field: field_artist_alt_name
  $fields['artist-field_artist_alt_name'] = array(
    'field_name' => 'field_artist_alt_name',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '7',
      'parent' => 'group_artist_detailed',
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
          '_error_element' => 'default_value_widget][field_artist_alt_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Alternate names',
      'weight' => '7',
      'description' => 'Pseudonyms or variations of this Generative Artist\'s name.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_artist_bio
  $fields['artist-field_artist_bio'] = array(
    'field_name' => 'field_artist_bio',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => 0,
      'parent' => 'group_artist_info',
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
          '_error_element' => 'default_value_widget][field_artist_bio][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Bio',
      'weight' => 0,
      'description' => 'Biography or short description of this Generative Artist. Who is this Generative Artist in a nutshell?',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_artist_email
  $fields['artist-field_artist_email'] = array(
    'field_name' => 'field_artist_email',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '3',
      'parent' => 'group_artist_detailed',
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
    'type' => 'email',
    'required' => '0',
    'multiple' => '0',
    'module' => 'email',
    'active' => '1',
    'widget' => array(
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'email' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Email',
      'weight' => '3',
      'description' => 'Email folks should use to contact this Generative Artist. Could be for an agent or other representative. This will be publicly displayed.',
      'type' => 'email_textfield',
      'module' => 'email',
    ),
  );

  // Exported field: field_artist_facebook
  $fields['artist-field_artist_facebook'] = array(
    'field_name' => 'field_artist_facebook',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '7',
      'parent' => 'group_artist_find_on',
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
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => 'Facebook of [title-raw]',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'value',
    'title_value' => 'Facebook',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Facebook',
      'weight' => '7',
      'description' => 'Enter URL for this Generative Artist\'s Facebook page. Example: <em>http://facebook.com/yourname.</em>',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_artist_phone
  $fields['artist-field_artist_phone'] = array(
    'field_name' => 'field_artist_phone',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '4',
      'parent' => 'group_artist_detailed',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_artist_phone][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Phone number',
      'weight' => '4',
      'description' => 'The phone number folks should use to contact this Generative Artist. Could be for an agent or other representative. This will be publicly displayed if it\'s filled out.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_artist_photo
  $fields['artist-field_artist_photo'] = array(
    'field_name' => 'field_artist_photo',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => 'group_artist_info',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'org_standard_default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'org_standard_default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => array(
        'filename' => 'map-default-image.gif',
        'filepath' => 'sites/default/files/imagefield_default_images/map-default-image.gif',
        'filemime' => 'image/gif',
        'source' => 'default_image_upload',
        'destination' => 'sites/default/files/imagefield_default_images/map-default-image.gif',
        'filesize' => 14838,
        'uid' => '3',
        'status' => 1,
        'timestamp' => 1341962928,
        'fid' => '1478',
      ),
      'use_default_image' => 1,
      'insert' => 0,
      'insert_styles' => array(
        'auto' => 0,
        'link' => 0,
        'image' => 0,
        'imagecache_feed_thumbnail' => 0,
        'imagecache_org_full' => 0,
        'imagecache_org_icon' => 0,
        'imagecache_org_icon_small' => 0,
        'imagecache_org_standard' => 0,
      ),
      'insert_default' => 'auto',
      'insert_class' => '',
      'insert_width' => '',
      'label' => 'Photo',
      'weight' => '-1',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_artist_twitter
  $fields['artist-field_artist_twitter'] = array(
    'field_name' => 'field_artist_twitter',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '8',
      'parent' => 'group_artist_find_on',
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
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => 'Twitter of [title-raw]',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'value',
    'title_value' => 'Twitter',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Twitter',
      'weight' => '8',
      'description' => 'Enter URL for this Generative Artist\'s Twitter profile. Example: <em>http://twitter.com/yourname.</em>',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_artist_website
  $fields['artist-field_artist_website'] = array(
    'field_name' => 'field_artist_website',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '6',
      'parent' => 'group_artist_find_on',
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
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => 'Website of [title-raw]',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'value',
    'title_value' => 'Website',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Website',
      'weight' => '6',
      'description' => 'Enter URL for this Generative Artist\'s website. Example: <em>http://yourname.com.</em>',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_ensemble
  $fields['artist-field_ensemble'] = array(
    'field_name' => 'field_ensemble',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => 'group_artist_info',
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
    'allowed_values' => '0|Single Entity
1|Ensemble / Collective',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Ensemble / Collective',
      'weight' => '-2',
      'description' => 'Check this box if this Generative Artist Name is an Ensemble or Collective.',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_location
  $fields['artist-field_location'] = array(
    'field_name' => 'field_location',
    'type_name' => 'artist',
    'display_settings' => array(
      'weight' => '1',
      'parent' => 'group_artist_info',
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
                                'province_name' => 'province_name',
                                'country_name' => 'country_name',
                                'coords' => 'coords',
                                'street' => 0,
                                'city' => 0,
                                'province' => 0,
                                'postal_code' => 0,
                                'country' => 0,
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
                        'country_name' => 'country_name',
                        'coords' => 'coords',
                        'street' => 0,
                        'city' => 0,
                        'province' => 0,
                        'postal_code' => 0,
                        'country' => 0,
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
      'weight' => '1',
      'description' => 'Where this Generative Artist spends most of their time.  Note that whatever address information is entered will be displayed publicly.  If you don\'t want your full address known, just enter your city, state and/or zip code. ',
      'type' => 'location',
      'module' => 'location_cck',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Affiliations & Memberships');
  t('Alternate names');
  t('Bio');
  t('Email');
  t('Ensemble / Collective');
  t('Facebook');
  t('Location');
  t('Phone number');
  t('Photo');
  t('Representative');
  t('Twitter');
  t('Website');

  return $fields;
}
