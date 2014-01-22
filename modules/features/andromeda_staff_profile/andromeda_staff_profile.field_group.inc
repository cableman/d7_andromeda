<?php
/**
 * @file
 * andromeda_staff_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function andromeda_staff_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_basic|node|staff_profile|form';
  $field_group->group_name = 'group_profile_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile',
    'weight' => '1',
    'children' => array(
      0 => 'field_profile_image',
      1 => 'field_profile_name',
      2 => 'field_profile_content',
      3 => 'field_profile_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profile-basic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile_basic|node|staff_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_contact|node|staff_profile|form';
  $field_group->group_name = 'group_profile_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '2',
    'children' => array(
      0 => 'field_profile_telephone',
      1 => 'field_profile_mail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profile-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile_contact|node|staff_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_staff_profile_left|node|staff_profile|staff_list';
  $field_group->group_name = 'group_staff_profile_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'staff_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '0',
    'children' => array(
      0 => 'field_profile_image',
      1 => 'field_profile_name',
      2 => 'field_profile_position',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'classes' => 'staff--left',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_staff_profile_left|node|staff_profile|staff_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_staff_profile_right|node|staff_profile|staff_list';
  $field_group->group_name = 'group_staff_profile_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'staff_profile';
  $field_group->mode = 'staff_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '1',
    'children' => array(
      0 => 'field_profile_content',
      1 => 'field_profile_telephone',
      2 => 'field_profile_mail',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'classes' => 'staff--right',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_staff_profile_right|node|staff_profile|staff_list'] = $field_group;

  return $export;
}
