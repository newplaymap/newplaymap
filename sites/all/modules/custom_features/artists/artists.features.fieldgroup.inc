<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function artists_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_artist_detailed
  $groups['artist-group_artist_detailed'] = array(
    'group_type' => 'standard',
    'type_name' => 'artist',
    'group_name' => 'group_artist_detailed',
    'label' => 'Detailed information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '-3',
    'fields' => array(
      '0' => 'field_artist_email',
      '1' => 'field_artist_phone',
      '2' => 'field_artist_agent',
      '3' => 'field_artist_affiliations',
      '4' => 'field_artist_alt_name',
    ),
  );

  // Exported group: group_artist_find_on
  $groups['artist-group_artist_find_on'] = array(
    'group_type' => 'standard',
    'type_name' => 'artist',
    'group_name' => 'group_artist_find_on',
    'label' => 'Find me on...',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '-2',
    'fields' => array(
      '0' => 'field_artist_website',
      '1' => 'field_artist_facebook',
      '2' => 'field_artist_twitter',
    ),
  );

  // Exported group: group_artist_info
  $groups['artist-group_artist_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'artist',
    'group_name' => 'group_artist_info',
    'label' => 'Basic information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '-4',
    'fields' => array(
      '0' => 'field_ensemble',
      '1' => 'field_artist_photo',
      '2' => 'field_artist_bio',
      '3' => 'field_location',
      '4' => 'field_user_contact',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic information');
  t('Detailed information');
  t('Find me on...');

  return $groups;
}
