<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function plays_and_events_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_play_info
  $groups['play-group_play_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'play',
    'group_name' => 'group_play_info',
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
    'weight' => '-3',
    'fields' => array(
      '0' => 'field_artist',
      '1' => 'field_play_synopsis',
      '2' => 'field_play_alt_titles',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic information');

  return $groups;
}
