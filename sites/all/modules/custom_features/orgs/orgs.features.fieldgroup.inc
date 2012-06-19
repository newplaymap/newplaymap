<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function orgs_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_org_info
  $groups['organization-group_org_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'organization',
    'group_name' => 'group_org_info',
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
      '0' => 'field_org_logo',
      '1' => 'field_org_description',
      '2' => 'field_org_fouding_date',
      '3' => 'field_org_type',
      '4' => 'field_ensemble',
      '5' => 'field_location',
      '6' => 'field_org_website',
      '7' => 'field_org_art_leaders',
      '8' => 'field_user_contact',
      '9' => 'field_org_season',
    ),
  );

  // Exported group: group_org_production_stats
  $groups['organization-group_org_production_stats'] = array(
    'group_type' => 'standard',
    'type_name' => 'organization',
    'group_name' => 'group_org_production_stats',
    'label' => 'New play statistics',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '\'New work\' is how you define it.',
      ),
      'display' => array(
        'weight' => '6',
        'label' => 'above',
        'teaser' => array(
          'format' => 'simple',
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
    'weight' => '6',
    'fields' => array(
      '0' => 'field_org_current_new_play_count',
      '1' => 'field_org_new_play_avg',
      '2' => 'field_org_dev_activities',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic information');
  t('New play statistics');

  return $groups;
}
