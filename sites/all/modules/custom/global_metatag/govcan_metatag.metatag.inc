<?php

/**
 * @file
 * Metatag integration for the govcan_metatag module.
 */

/**
 * Implements hook_metatag_config_default_alter().
 */
function govcan_metatag_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array(
          'dc:title' => array('value' => '[current-page:title]'),
          'dc:site_name' => array('value' => '[site:name]'),
          'dc:url' => array('value' => '[current-page:url]'),
        );
        break;
      case 'global:frontpage':
        $config->config += array(
          'dc:title' => array('value' => '[site:name]'),
          'dc:url' => array('value' => '[site:url]'),
        );
        break;
      case 'node':
        $config->config += array(
          'dc:title' => array('value' => '[node:title]'),
          'dc:description' => array('value' => '[node:summary]'),
          'dc:url' => array('value' => '[current-page:url]'),
          'date' => array('value' => '[node:changed]'),
          'dcterms.issued' => array('value' => '[node:created]'),
          'dcterms.modified' => array('value' => '[node:changed]'),
          'author' => array('value' => '[node:author]'),
        );
        break;
      case 'taxonomy_term':
        $config->config += array(
          'dc:title' => array('value' => '[term:name]'),
          'dc:description' => array('value' => '[term:description]'),
        );
        break;
      case 'user':
        $config->config += array(
          'dc:type' => array('value' => 'profile'),
          'dc:title' => array('value' => '[user:name]'),
          'dc:image' => array('value' => '[user:picture:url]'),
        );
        break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function govcan_metatag_metatag_info() {
  $info['groups']['govcan-metadata'] = array(
    'label' => t('GovCan MetaData'),
  );
  
  $info['tags']['dc:title'] = array(
    'label' => t('GovCan MetaData title'),
    'description' => t('The title of your object as it should appear within the display.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'govcan-metadata',
    'element' => array(
      '#theme' => 'govcan_metatag',
    ),
  );
  
  $info['tags']['dc:site_name'] = array(
    'label' => t('GovCan MetaData site name'),
    'description' => t('A human-readable name for your site, e.g., <em>Government of Canada</em>.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'govcan-metadata',
    'context' => array('global'),
    'element' => array(
      '#theme' => 'govcan_metatag',
    ),
  );
  
  $info['tags']['dc:url'] = array(
    'label' => t('GovCan MetaData URL'),
    'description' => t('The canonical URL of your object that will be used as its permanent ID in the website, for example:, <em>http://www.govcan.gc.ca/policy/</em>.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'govcan-metadata',
    'element' => array(
      '#theme' => 'govcan_metatag',
    ),
  );
  
  $info['tags']['dc:description'] = array(
    'label' => t('GovCan MetaData description'),
    'description' => t('A one to two sentence description of your page.'),
    'group' => 'govcan-metadata',
    'class' => 'DrupalTextMetaTag',
    'element' => array(
      '#theme' => 'govcan_metatag',
    ),
  );
  
  $info['tags']['date'] = array(
    'label' => t('GovCan MetaData date'),
    'description' => t('The date of your object as it was most recently changed.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'govcan-metadata',
    'element' => array(
      '#theme' => 'govcan_metatag',
    ),
  );
   
  $info['tags']['dcterms.issued'] = array(
    'label' => t('GovCan MetaData Date Created'),
    'description' => t('The date of your object as it was created.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'govcan-metadata',
    'element' => array(
      '#theme' => 'govcan_metatag_scheme',
    ),
  );
  
  $info['tags']['dcterms.modified'] = array(
    'label' => t('GovCan MetaData Date Modified'),
    'description' => t('The date of your object as it was modified.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'govcan-metadata',
    'element' => array(
      '#theme' => 'govcan_metatag_scheme',
    ),
  );
    
  $info['tags']['author'] = array(
    'label' => t('GovCan MetaData Author'),
    'description' => t('The main Author of the page.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'govcan-metadata',
    'element' => array(
      '#theme' => 'govcan_metatag',
    ),
  );

  $info['tags']['dc:type'] = array(
    'label' => t('GovCan MetaData type'),
    'description' => t('The type of your object, for example:, <em>Graph</em>.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'govcan-metadata',
    'form' => array(
      '#type' => 'select',
      '#options' => _govcan_metatag_type_options(),
      '#empty_option' => t('- None -'),
    ),
    'element' => array(
      '#theme' => 'govcan_metatag',
    ),
  );
  
  $info['tags']['dc:image'] = array(
    'label' => t('GovCan MetaData image'),
    'description' => t('An image URL which should represent your object within the page. (PNG, JPEG and GIF formats)'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'govcan-metadata',
    'element' => array(
      '#theme' => 'govcan_metatag',
    ),
  );
  
  return $info;
}

function _govcan_metatag_type_options() {
  $options = array(
    t('Graph') => array(
      'bar' => t('bar'),
      'line' => t('line'),
    ),
    t('Media') => array(
      'image' => t('Image'),
      'video' => t('Video'),
      'diagram' => t('Diagram'),
      'audio' => t('Audio'),
      'text' => t('Text'),
    ),
  );
  return $options;
}
