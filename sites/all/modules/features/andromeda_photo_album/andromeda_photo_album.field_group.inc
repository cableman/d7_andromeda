<?php
/**
 * @file
 * andromeda_photo_album.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function andromeda_photo_album_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|photo_album|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'photo_album';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_lead',
      1 => 'field_album_images',
      2 => 'title',
      3 => 'field_content',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-fieldset',
        'required_fields' => 1,
        'id' => 'node_photo_album_form_group_content',
      ),
    ),
  );
  $field_groups['group_content|node|photo_album|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|node|photo_album|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'photo_album';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '1',
    'children' => array(
      0 => 'field_list_image',
      1 => 'field_frontpage_slider',
      2 => 'field_flicker',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-other field-group-fieldset',
        'required_fields' => 1,
        'id' => 'node_photo_album_form_group_other',
      ),
    ),
  );
  $field_groups['group_other|node|photo_album|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Other');

  return $field_groups;
}
