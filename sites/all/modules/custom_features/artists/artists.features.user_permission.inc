<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function artists_user_default_permissions() {
  $permissions = array();

  // Exported permission: create agent content
  $permissions['create agent content'] = array(
    'name' => 'create agent content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create artist content
  $permissions['create artist content'] = array(
    'name' => 'create artist content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create artist_memberships content
  $permissions['create artist_memberships content'] = array(
    'name' => 'create artist_memberships content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create artist_type content
  $permissions['create artist_type content'] = array(
    'name' => 'create artist_type content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: delete any agent content
  $permissions['delete any agent content'] = array(
    'name' => 'delete any agent content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: delete any artist content
  $permissions['delete any artist content'] = array(
    'name' => 'delete any artist content',
    'roles' => array(),
  );

  // Exported permission: delete any artist_memberships content
  $permissions['delete any artist_memberships content'] = array(
    'name' => 'delete any artist_memberships content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: delete any artist_type content
  $permissions['delete any artist_type content'] = array(
    'name' => 'delete any artist_type content',
    'roles' => array(),
  );

  // Exported permission: delete own agent content
  $permissions['delete own agent content'] = array(
    'name' => 'delete own agent content',
    'roles' => array(),
  );

  // Exported permission: delete own artist content
  $permissions['delete own artist content'] = array(
    'name' => 'delete own artist content',
    'roles' => array(),
  );

  // Exported permission: delete own artist_memberships content
  $permissions['delete own artist_memberships content'] = array(
    'name' => 'delete own artist_memberships content',
    'roles' => array(),
  );

  // Exported permission: delete own artist_type content
  $permissions['delete own artist_type content'] = array(
    'name' => 'delete own artist_type content',
    'roles' => array(),
  );

  // Exported permission: edit any agent content
  $permissions['edit any agent content'] = array(
    'name' => 'edit any agent content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
      '2' => 'website developer',
    ),
  );

  // Exported permission: edit any artist content
  $permissions['edit any artist content'] = array(
    'name' => 'edit any artist content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit any artist_memberships content
  $permissions['edit any artist_memberships content'] = array(
    'name' => 'edit any artist_memberships content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any artist_type content
  $permissions['edit any artist_type content'] = array(
    'name' => 'edit any artist_type content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit own agent content
  $permissions['edit own agent content'] = array(
    'name' => 'edit own agent content',
    'roles' => array(),
  );

  // Exported permission: edit own artist content
  $permissions['edit own artist content'] = array(
    'name' => 'edit own artist content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own artist_memberships content
  $permissions['edit own artist_memberships content'] = array(
    'name' => 'edit own artist_memberships content',
    'roles' => array(),
  );

  // Exported permission: edit own artist_type content
  $permissions['edit own artist_type content'] = array(
    'name' => 'edit own artist_type content',
    'roles' => array(),
  );

  return $permissions;
}
