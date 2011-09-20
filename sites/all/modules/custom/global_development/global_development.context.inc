<?php
/**
 * @file
 * global_development.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function global_development_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'Development Context';
  $context->description = 'Contexts related to Development';
  $context->tag = 'Development';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~heath-indicators/*/*' => '~heath-indicators/*/*',
        '~health-indicators/*' => '~health-indicators/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contexts related to Development');
  t('Development');
  $export['Development Context'] = $context;

  return $export;
}
