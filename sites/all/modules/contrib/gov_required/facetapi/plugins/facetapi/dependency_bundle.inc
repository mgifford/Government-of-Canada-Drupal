<?php

/**
 * @file
 * Performs a dependency check against the passed content type.
 */

/**
 * Adds a dependency on content type.
 */
class FacetapiDependencyBundle extends FacetapiDependency {

  /**
   * Executes the dependency check.
   */
  public function execute() {
    switch ($this->settings['bundle']) {
      case 'referenced':
        // @todo Do we need defensive coding here?
        $field_info = field_info_field($this->facet['field api name']);

        // Gets the bundles the searcher indexing.
        $bundles = array();
        foreach ($this->adapter->getTypes() as $type) {
          if (isset($field_info['bundles'][$type])) {
            $bundles += $field_info['bundles'][$type];
          }
        }

        // Attempts to find a match.
        $matches = array_intersect_key(array_flip($bundles), $this->activeItems['bundle']);
        return ($matches) ? NULL : FALSE;

      case 'selected':
        $matches = array_intersect_key(
          array_filter($this->settings['bundle_selected']),
          $this->activeItems['bundle']
        );
        return ($matches) ? NULL : FALSE;
    }
  }

  /**
   * Adds dependency settings to the form.
   */
  public function settingsForm(&$form, &$form_state) {

    // Builds array of options.
    $options = array();
    $options['none'] = t('No dependencies.');
    if ($this->facet['field api name']) {
      $options['referenced'] = t('A content type this field is attached to must be active.');
    }
    $options['selected'] = t('At least one of the selected content types must be active.');

    $form[$this->id]['bundle'] = array(
      '#title' => t('Dependency settings'),
      '#type' => 'radios',
      '#options' => $options,
      '#default_value' => $this->settings['bundle'],
    );

    $form[$this->id]['bundle_selected'] = array(
      '#title' => t('Content types'),
      '#type' => 'checkboxes',
      '#options' => array_map('check_plain', node_type_get_names()),
      '#default_value' => $this->settings['bundle_selected'],
      '#states' => array(
        'visible' => array(
          'input[name="bundle"]' => array('value' => 'selected'),
        ),
      ),
    );
  }

  /**
   * Returns defaults for settings.
   */
  public function getDefaultSettings() {
    return array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    );
  }
}
