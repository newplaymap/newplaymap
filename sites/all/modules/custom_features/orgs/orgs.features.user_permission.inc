<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function orgs_user_default_permissions() {
  $permissions = array();

  // Exported permission: create org_type content
  $permissions['create org_type content'] = array(
    'name' => 'create org_type content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: create organization content
  $permissions['create organization content'] = array(
    'name' => 'create organization content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any org_type content
  $permissions['delete any org_type content'] = array(
    'name' => 'delete any org_type content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: delete any organization content
  $permissions['delete any organization content'] = array(
    'name' => 'delete any organization content',
    'roles' => array(),
  );

  // Exported permission: delete own org_type content
  $permissions['delete own org_type content'] = array(
    'name' => 'delete own org_type content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: delete own organization content
  $permissions['delete own organization content'] = array(
    'name' => 'delete own organization content',
    'roles' => array(),
  );

  // Exported permission: edit any org_type content
  $permissions['edit any org_type content'] = array(
    'name' => 'edit any org_type content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any organization content
  $permissions['edit any organization content'] = array(
    'name' => 'edit any organization content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own org_type content
  $permissions['edit own org_type content'] = array(
    'name' => 'edit own org_type content',
    'roles' => array(),
  );

  // Exported permission: edit own organization content
  $permissions['edit own organization content'] = array(
    'name' => 'edit own organization content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache org_full
  $permissions['view imagecache org_full'] = array(
    'name' => 'view imagecache org_full',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache org_icon
  $permissions['view imagecache org_icon'] = array(
    'name' => 'view imagecache org_icon',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache org_icon_small
  $permissions['view imagecache org_icon_small'] = array(
    'name' => 'view imagecache org_icon_small',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache org_standard
  $permissions['view imagecache org_standard'] = array(
    'name' => 'view imagecache org_standard',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
