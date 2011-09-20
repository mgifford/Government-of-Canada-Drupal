<?php

/**
* Form builder; Create and display the User Warn configuration
* settings form.
*/
function wetkit_displayenhance_form($form, &$form_state) {
  $form = array();
  $form['wetkit_information'] = array(
    '#markup' => t('<p>This will be the main configuration page for all functionality related to the Form Interface Enhancements.</p>'),
  );
  // Submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );
  return $form;
}

/**
* Save configuration settings for User Warn module.
*/
function wetkit_displayenhance_form_submit($form, &$form_state) {
  variable_set('wetkit_display_enhancement',$form_state['values']['wetkit_display_enhancement']);
  drupal_set_message(t('The settings have been saved'));
}