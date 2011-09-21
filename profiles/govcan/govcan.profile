<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function govcan_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the configuration form
  $form['site_information']['site_name']['#default_value'] = 'Government of Canada Prototype';
  $form['site_information']['site_mail']['#default_value'] = 'first.last@department.gc.ca';
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'first.last@deptartment.gc.ca';
  $form['server_settings']['site_default_country']['#default_value'] = 'CA';
}

function govcan_install_tasks() {
  // Here, we define a variable to allow tasks to indicate that a particular,
  // processor-intensive batch process needs to be triggered later on in the
  // installation.
  $govcan_needs_batch_processing = variable_get('govcan_needs_batch_processing', TRUE);
  $tasks = array(
    // This is an example of a task that defines a form which the user who is
    // installing the site will be asked to fill out. To implement this task,
    // your profile would define a function named myprofile_data_import_form()
    // as a normal form API callback function, with associated validation and
    // submit handlers. In the submit handler, in addition to saving whatever
    // other data you have collected from the user, you might also call
    // variable_set('myprofile_needs_batch_processing', TRUE) if the user has
    // entered data which requires that batch processing will need to occur
    // later on.
    // Similarly, to implement this task, your profile would define a function
    // named myprofile_settings_form() with associated validation and submit
    // handlers. This form might be used to collect and save additional
    // information from the user that your profile needs. There are no extra
    // steps required for your profile to act as an "installation wizard"; you
    // can simply define as many tasks of type 'form' as you wish to execute,
    // and the forms will be presented to the user, one after another. 
    'govcan_setup_form' => array(
      'display_name' => st('Government of Canada: Configuration'), 
      'type' => 'form',
    ),    
    // This is an example of a task that performs batch operations. To
    // implement this task, your profile would define a function named
    // myprofile_batch_processing() which returns a batch API array definition
    // that the installer will use to execute your batch operations. Due to the
    // 'myprofile_needs_batch_processing' variable used here, this task will be
    // hidden and skipped unless your profile set it to TRUE in one of the
    // previous tasks. 
    'govcan_batch_processing' => array(
      'display_name' => st('Import French Language'), 
      'display' => $govcan_needs_batch_processing, 
      'type' => 'batch', 
      'run' => $govcan_needs_batch_processing ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
    ),
    // This is an example of a task that will not be displayed in the list that
    // the user sees. To implement this task, your profile would define a
    // function named myprofile_final_site_setup(), in which additional,
    // automated site setup operations would be performed. Since this is the
    // last task defined by your profile, you should also use this function to
    // call variable_del('myprofile_needs_batch_processing') and clean up the
    // variable that was used above. If you want the user to pass to the final
    // Drupal installation tasks uninterrupted, return no output from this
    // function. Otherwise, return themed output that the user will see (for
    // example, a confirmation page explaining that your profile's tasks are
    // complete, with a link to reload the current page and therefore pass on
    // to the final Drupal installation tasks when the user is ready to do so). 
    'govcan_final_site_setup' => array(
    ),
  );
  return $tasks;
}

function govcan_setup_form() {
  //Continue configuration
  drupal_set_title(st('Government of Canada: Value Added Services'));
  drupal_set_message('This section will assist in adding various value added services to assist with your experience using the Government of Canada Drupal platform.','status');  
  
  $options = array('1' => t('Enabled'), '0' => t('Disabled'));
  
  //Start setting up the form
  $form = array();
  $form['govcan_import_banner'] = array(
    '#type' => 'managed_file',
    '#title' => st('Upload Image Banner'),
    '#description' => st('The uploaded image will be displayed on the main banner and will reflect your department'),
    '#default_value' => variable_get('govcan_import_banner', NULL),
    '#upload_location' => 'public://custom_department_images/',
  );
  $form['govcan_radioval1'] = array(
    '#type' => 'radios',
    '#title' => st('Enable Development Module(s)?'),
    '#default_value' =>  variable_get('radio_val1', 0),
    '#options' => $options,
    '#description' => st('Modules that will assist with Development for the Government of Canada websites.'),
  );
  $form['govcan_radioval2'] = array(
    '#type' => 'radios',
    '#title' => st('Enable Workflow Module(s)?'),
    '#default_value' =>  variable_get('radio_val2', 0),
    '#options' => $options,
    '#description' => st('Modules that will assist with Workflows for the Government of Canada websites.'),
  );
  $form['govcan_radioval3'] = array(
    '#type' => 'radios',
    '#title' => st('Enable CKEditor Module(s)?'),
    '#default_value' =>  variable_get('radio_val3', 0),
    '#options' => $options,
    '#description' => st('Modules that relate to a WYSIWYG Editor (CKEditor).'),
  );
  $form['govcan_radioval4'] = array(
    '#type' => 'radios',
    '#title' => st('Enable Apache Solr Module(s)?'),
    '#default_value' =>  variable_get('radio_val4', 0),
    '#options' => $options,
    '#description' => st('Modules that deal with Apache Solr Integration.'),
  );
  $form['govcan_radioval5'] = array(
    '#type' => 'radios',
    '#title' => st('Automatically Revert Features?'),
    '#default_value' =>  variable_get('radio_val5', 0),
    '#options' => $options,
    '#description' => st('Revert already installed Features Automatically.'),
  );
  $form[] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
  );
  //Return the form back to parent
  return $form;
}

function govcan_setup_form_submit($form, &$form_state) {
    //Set variables in the drupal variable table
    variable_set('radio_val1', $form_state['values']['govcan_radioval1']);
    variable_set('radio_val2', $form_state['values']['govcan_radioval2']);
    variable_set('radio_val3', $form_state['values']['govcan_radioval3']);
    variable_set('radio_val4', $form_state['values']['govcan_radioval4']);
    variable_set('radio_val5', $form_state['values']['govcan_radioval5']);
    
    // Load the file via file.fid
    //$file = file_load($form_state['values']['govcan_import_banner']);
    // Change status to permanent
    //$file->filename = 'banner-dept.jpg';
    //$file->status = FILE_STATUS_PERMANENT;
    // Save the file
    //file_save($file);
}

function govcan_batch_processing() {
  //Import the French po file and translate the interface;
  //Require once is only added here because too early in the bootstrap
  require_once 'includes/locale.inc';
	require_once 'includes/form.inc';
  //Call funtion locale_add_language in locale.inc
	locale_add_language('fr');
	//Batch up the process + import existing po files
	$batch = locale_batch_by_language('fr');
  return $batch;
}

function govcan_final_site_setup() {
  //Based on selected configuration install modules
  govcan_addmodules();
  //Delete all of the variables inside the variables table
  variable_del('govcan_needs_batch_processing');
  variable_del('radio_val1');
  variable_del('radio_val2');
  variable_del('radio_val3');
  variable_del('radio_val4');
  variable_del('radio_val5');
  features_revert(array('global_initial_settings' => array('variable')));
}

function govcan_addmodules() {
  //Module Selection Screen
  if (variable_get('radio_val1', 0) == 1)
  {
    $module_list = array('devel','devel_generate','devel_node_access','global_development');
    module_enable($module_list, TRUE);
  }
  if (variable_get('radio_val2', 0) == 1)
  {
    $module_list = array('workbench','workbench_access','workbench_files','workbench_moderation');
    module_enable($module_list, TRUE);
  }
  if (variable_get('radio_val3', 0) == 1)
  {
    $module_list = array('ckeditor','ckeditor_link','imce','global_ckeditor');
    module_enable($module_list, TRUE);
  }
  if (variable_get('radio_val4', 0) == 1)
  {
    $module_list = array('apachesolr','apachesolr_search','apachesolr_access','apachesolr_taxonomy','facetapi');
    module_enable($module_list, TRUE);
  }
  if (variable_get('radio_val5', 0) == 1)
  {
    //features_revert(array('global_initial_settings' => array('variable')));
  }
}

function govcan_install_tasks_alter(&$tasks, $install_state) {
  // Replace the "Install Finished" installation task provided by Drupal core
  //$tasks['install_finished']['function'] = 'govcan_locale_addition';
}


