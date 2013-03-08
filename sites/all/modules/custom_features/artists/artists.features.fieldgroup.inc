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
        'weight' => '-3',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
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
      ),
    ),
    'weight' => '-3',
    'fields' => array(
      '0' => 'field_artist_email',
      '1' => 'field_artist_affiliations',
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
        'weight' => '-2',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
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
        'weight' => '-4',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
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
      ),
    ),
    'weight' => '-4',
    'fields' => array(
      '0' => 'field_location',
      '1' => 'field_ensemble',
      '2' => 'field_artist_photo',
      '3' => 'field_artist_bio',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic information');
  t('Detailed information');
  t('Find me on...');

  return $groups;
}
