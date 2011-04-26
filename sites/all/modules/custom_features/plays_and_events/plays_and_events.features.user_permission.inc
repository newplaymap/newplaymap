<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function plays_and_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: create event content
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create event_type content
  $permissions['create event_type content'] = array(
    'name' => 'create event_type content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: create play content
  $permissions['create play content'] = array(
    'name' => 'create play content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any event content
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(),
  );

  // Exported permission: delete any event_type content
  $permissions['delete any event_type content'] = array(
    'name' => 'delete any event_type content',
    'roles' => array(),
  );

  // Exported permission: delete any play content
  $permissions['delete any play content'] = array(
    'name' => 'delete any play content',
    'roles' => array(),
  );

  // Exported permission: delete own event content
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(),
  );

  // Exported permission: delete own event_type content
  $permissions['delete own event_type content'] = array(
    'name' => 'delete own event_type content',
    'roles' => array(),
  );

  // Exported permission: delete own play content
  $permissions['delete own play content'] = array(
    'name' => 'delete own play content',
    'roles' => array(),
  );

  // Exported permission: edit any event content
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
      '2' => 'website developer',
    ),
  );

  // Exported permission: edit any event_type content
  $permissions['edit any event_type content'] = array(
    'name' => 'edit any event_type content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any play content
  $permissions['edit any play content'] = array(
    'name' => 'edit any play content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own event content
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(),
  );

  // Exported permission: edit own event_type content
  $permissions['edit own event_type content'] = array(
    'name' => 'edit own event_type content',
    'roles' => array(),
  );

  // Exported permission: edit own play content
  $permissions['edit own play content'] = array(
    'name' => 'edit own play content',
    'roles' => array(),
  );

  return $permissions;
}
