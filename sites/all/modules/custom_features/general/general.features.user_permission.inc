<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function general_user_default_permissions() {
  $permissions = array();

  // Exported permission: access site-wide contact form
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: administer site-wide contact form
  $permissions['administer site-wide contact form'] = array(
    'name' => 'administer site-wide contact form',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: create delete_request content
  $permissions['create delete_request content'] = array(
    'name' => 'create delete_request content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any delete_request content
  $permissions['delete any delete_request content'] = array(
    'name' => 'delete any delete_request content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: delete own delete_request content
  $permissions['delete own delete_request content'] = array(
    'name' => 'delete own delete_request content',
    'roles' => array(),
  );

  // Exported permission: edit any delete_request content
  $permissions['edit any delete_request content'] = array(
    'name' => 'edit any delete_request content',
    'roles' => array(),
  );

  // Exported permission: edit own delete_request content
  $permissions['edit own delete_request content'] = array(
    'name' => 'edit own delete_request content',
    'roles' => array(),
  );

  return $permissions;
}
