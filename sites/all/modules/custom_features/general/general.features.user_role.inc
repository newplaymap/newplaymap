<?php

/**
 * Implementation of hook_user_default_roles().
 */
function general_user_default_roles() {
  $roles = array();

  // Exported role: Play Lab Director
  $roles['Play Lab Director'] = array(
    'name' => 'Play Lab Director',
  );

  // Exported role: Producing Theater Staffer
  $roles['Producing Theater Staffer'] = array(
    'name' => 'Producing Theater Staffer',
  );

  // Exported role: anonymous user
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
  );

  // Exported role: authenticated user
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
  );

  // Exported role: site admin
  $roles['site admin'] = array(
    'name' => 'site admin',
  );

  // Exported role: test user
  $roles['test user'] = array(
    'name' => 'test user',
  );

  // Exported role: website developer
  $roles['website developer'] = array(
    'name' => 'website developer',
  );

  return $roles;
}
