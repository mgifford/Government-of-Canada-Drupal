<?php
/**
 * @file
 * global_development.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function global_development_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
