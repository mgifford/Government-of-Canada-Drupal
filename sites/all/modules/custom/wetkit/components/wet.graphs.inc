<?php

/**
* Form builder; Create and display the User Warn configuration
* settings form.
*/
/**
* Form builder; Create and display the User Warn configuration
* settings form.
*/
function wetkit_graphs_form($form, &$form_state) {
  $form = array();
  $form['wetkit_graphs_settings'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Graph Settings'), 
    '#weight' => 0, 
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );
  $form['wetkit_graphs_settings']['wetkit_graphs_enable'] = array(
  '#type' => 'checkbox',
  '#default_value' => variable_get('wetkit_graphs_enable', FALSE),
  '#title' => t('Enable Graphs Display Enhancement'),
  '#description' => t('Indicates whether to Enable the Graphs Display Enhancement Featureset'),
  );
  // Textarea for the body of the e-mail.
  $form['wetkit_graphs_settings']['wetkit_graphs_javascript'] = array(
  '#type' => 'textarea',
  '#rows' => 10,
  '#columns' => 40,
  '#default_value' => variable_get('wetkit_graphs_javascript', NULL),
  '#title' => t('Enter Graph Javascript Parameters'),
  '#required' => TRUE,
  '#description' => t(
  'Enter the Parameters for the Graph Javascript'),
  );
  $form['wetkit_graphs_example'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Graph Example'), 
    '#weight' => 1, 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
  $form['wetkit_graphs_example']['wetkit_graph_example'] = array(
    '#theme' => 'webkit_graph',
    '#title' => t('WetKit Graph Example'),
  );
  // Submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
    '#weight' => 2,
  );
  return $form;
}

/**
* Save configuration settings for User Warn module.
*/
function wetkit_graphs_form_submit($form, &$form_state) {
  variable_set('wetkit_graphs_enable',$form_state['values']['wetkit_graphs_enable']);
  variable_set('wetkit_graphs_javascript',$form_state['values']['wetkit_graphs_javascript']);
  drupal_set_message(t('The settings have been saved'));
}