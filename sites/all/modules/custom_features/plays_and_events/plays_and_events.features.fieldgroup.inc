<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function plays_and_events_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_event_info
  $groups['event-group_event_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'event',
    'group_name' => 'group_event_info',
    'label' => 'Basic information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-3',
        '4' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
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
      '0' => 'field_event_type',
      '1' => 'field_related_theater',
      '2' => 'field_partner_org',
      '3' => 'field_event_date',
      '4' => 'field_location',
      '5' => 'field_event_desc',
    ),
  );

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
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic information');

  return $groups;
}
