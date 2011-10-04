<?php
/**
 * @file
 * global_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function global_search_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search';
  $context->description = 'Search Context for finding applicable content';
  $context->tag = 'Search';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'apachesolr-sort' => array(
          'module' => 'apachesolr',
          'delta' => 'sort',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'apachesolr-mlt-001' => array(
          'module' => 'apachesolr',
          'delta' => 'mlt-001',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-apachesolr@solr:current_search' => array(
          'module' => 'facetapi',
          'delta' => 'apachesolr@solr:current_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-apachesolr@solr:block:changed' => array(
          'module' => 'facetapi',
          'delta' => 'apachesolr@solr:block:changed',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-apachesolr@solr:block:language' => array(
          'module' => 'facetapi',
          'delta' => 'apachesolr@solr:block:language',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-apachesolr@solr:block:hash' => array(
          'module' => 'facetapi',
          'delta' => 'apachesolr@solr:block:hash',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-apachesolr@solr:block:bundle' => array(
          'module' => 'facetapi',
          'delta' => 'apachesolr@solr:block:bundle',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-KhTzYpxNHBKh0LUpiWTs8MkA7DuJq7Oj' => array(
          'module' => 'facetapi',
          'delta' => 'KhTzYpxNHBKh0LUpiWTs8MkA7DuJq7Oj',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  t('Search Context for finding applicable content');
  $export['search'] = $context;

  return $export;
}
