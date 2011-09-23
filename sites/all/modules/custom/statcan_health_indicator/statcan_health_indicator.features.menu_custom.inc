<?php
/**
 * @file
 * statcan_health_indicator.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function statcan_health_indicator_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-health-indicators
  $menus['menu-health-indicators'] = array(
    'menu_name' => 'menu-health-indicators',
    'title' => 'Health Indicators',
    'description' => 'Menu Section related to Health Indicators',
    'language' => 'und',
    'i18n_mode' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Health Indicators');
  t('Menu Section related to Health Indicators');


  return $menus;
}
