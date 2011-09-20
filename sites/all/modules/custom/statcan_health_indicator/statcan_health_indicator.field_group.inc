<?php
/**
 * @file
 * statcan_health_indicator.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function statcan_health_indicator_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chart_desc|node|health_indicators|form';
  $field_group->group_name = 'group_chart_desc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_elements';
  $field_group->data = array(
    'label' => 'Chart Description(s)',
    'weight' => '7',
    'children' => array(
      0 => 'field_charts',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Chart Description(s)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'assistance',
        'description' => 'Content in this section is related to the Factsheet and provides description on various Charts',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_chart_desc|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_config_language|node|health_indicators|form';
  $field_group->group_name = 'group_config_language';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_config';
  $field_group->data = array(
    'label' => 'Language',
    'weight' => '27',
    'children' => array(
      0 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_config_language|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_config_taxonomy|node|health_indicators|form';
  $field_group->group_name = 'group_config_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_config';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '25',
    'children' => array(
      0 => 'field_taxonomy',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_config_taxonomy|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_config_workbench|node|health_indicators|form';
  $field_group->group_name = 'group_config_workbench';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_config';
  $field_group->data = array(
    'label' => 'Workbench',
    'weight' => '26',
    'children' => array(
      0 => 'workbench_access',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Workbench',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_config_workbench|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_config|node|health_indicators|form';
  $field_group->group_name = 'group_config';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group Config',
    'weight' => '1',
    'children' => array(
      0 => 'group_config_taxonomy',
      1 => 'group_config_workbench',
      2 => 'group_config_language',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'label' => 'Group Config',
      'instance_settings' => array(
        'classes' => 'configsettings',
      ),
    ),
  );
  $export['group_config|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|health_indicators|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_elements';
  $field_group->data = array(
    'label' => 'Definition',
    'weight' => '3',
    'children' => array(
      0 => 'field_definition',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Definition',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'assistance',
        'description' => 'Content in this section relates to the Definition Section',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_content|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dynamic|node|health_indicators|form';
  $field_group->group_name = 'group_dynamic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_elements';
  $field_group->data = array(
    'label' => 'Dynamic Section',
    'weight' => '8',
    'children' => array(
      0 => 'field_tables',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Dynamic Section',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'dynamic',
        'description' => 'Content in this section is driven dynamically; for most of the use cases you will not have to manually enter information into this area',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_dynamic|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elements|node|health_indicators|form';
  $field_group->group_name = 'group_elements';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group Elements',
    'weight' => '5',
    'children' => array(
      0 => 'group_content',
      1 => 'group_other',
      2 => 'group_dynamic',
      3 => 'group_factsheet',
      4 => 'group_maps',
      5 => 'group_chart_desc',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_elements|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_factsheet|node|health_indicators|form';
  $field_group->group_name = 'group_factsheet';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_elements';
  $field_group->data = array(
    'label' => 'Factsheet',
    'weight' => '4',
    'children' => array(
      0 => 'field_factsheet',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Factsheet',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'assistance',
        'description' => 'Content in this section relates to the Factsheet Section',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_factsheet|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_maps|node|health_indicators|form';
  $field_group->group_name = 'group_maps';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_elements';
  $field_group->data = array(
    'label' => 'Maps',
    'weight' => '6',
    'children' => array(
      0 => 'field_maps',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Maps',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'assistance',
        'description' => 'Content in this section relates to the Maps Section',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_maps|node|health_indicators|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|node|health_indicators|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_indicators';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_elements';
  $field_group->data = array(
    'label' => 'Summary Tables',
    'weight' => '5',
    'children' => array(
      0 => 'field_tables_key',
      1 => 'field_tables_title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Summary Tables',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'assistance',
        'description' => 'Content in this section relates to Summary Tables',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_other|node|health_indicators|form'] = $field_group;

  return $export;
}
