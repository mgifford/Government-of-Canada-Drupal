<?php
/**
 * @file
 * global_initial_settings.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function global_initial_settings_user_default_roles() {
  $roles = array();

  // Exported role: author
  $roles['author'] = array(
    'name' => 'author',
    'weight' => '5',
  );

  // Exported role: cms administrator
  $roles['cms administrator'] = array(
    'name' => 'cms administrator',
    'weight' => '2',
  );

  // Exported role: information architect
  $roles['information architect'] = array(
    'name' => 'information architect',
    'weight' => '3',
  );

  // Exported role: information developer
  $roles['information developer'] = array(
    'name' => 'information developer',
    'weight' => '4',
  );

  // Exported role: module manager
  $roles['module manager'] = array(
    'name' => 'module manager',
    'weight' => '6',
  );

  // Exported role: stakeholder
  $roles['stakeholder'] = array(
    'name' => 'stakeholder',
    'weight' => '7',
  );

  return $roles;
}
