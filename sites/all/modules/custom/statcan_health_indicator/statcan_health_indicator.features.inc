<?php
/**
 * @file
 * statcan_health_indicator.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function statcan_health_indicator_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function statcan_health_indicator_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function statcan_health_indicator_node_info() {
  $items = array(
    'health_indicators' => array(
      'name' => t('Health Indicators'),
      'base' => 'node_content',
      'description' => t('Health Indicators Content Type which features Tabbed Data (Definition, Data, Maps, Factsheet), Summary Tables, and various other Chart Items.'),
      'has_title' => '1',
      'title_label' => t('Health Indicator Title'),
      'help' => t('All of Statistics Canada publishing guidelines must be followed when submitting content for this section.'),
    ),
  );
  return $items;
}
