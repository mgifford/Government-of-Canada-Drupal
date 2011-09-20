<?php
/**
 * @file
 * statcan_health_indicator.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function statcan_health_indicator_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'Health Indicators';
  $context->description = 'Context related to Health Indicators';
  $context->tag = 'Node';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'landing/data-tables-maps-and-fact-sheets' => 'landing/data-tables-maps-and-fact-sheets',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-health_indicators-block' => array(
          'module' => 'views',
          'delta' => 'health_indicators-block',
          'region' => 'content',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context related to Health Indicators');
  t('Node');
  $export['Health Indicators'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'Health Indicators Global';
  $context->description = 'Health Indicators Global Context for Content Type';
  $context->tag = 'Node';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'health_indicators' => 'health_indicators',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'landing/data-tables-maps-and-fact-sheets' => 'landing/data-tables-maps-and-fact-sheets',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-health-indicators' => array(
          'module' => 'menu',
          'delta' => 'menu-health-indicators',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Health Indicators Global Context for Content Type');
  t('Node');
  $export['Health Indicators Global'] = $context;

  return $export;
}
