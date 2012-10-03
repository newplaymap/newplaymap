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

  return $permissions;
}
