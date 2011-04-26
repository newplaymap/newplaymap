<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function newplay_mapping_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer openlayers
  $permissions['administer openlayers'] = array(
    'name' => 'administer openlayers',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  return $permissions;
}
