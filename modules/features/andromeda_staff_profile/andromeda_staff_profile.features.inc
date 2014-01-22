<?php
/**
 * @file
 * andromeda_staff_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function andromeda_staff_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function andromeda_staff_profile_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function andromeda_staff_profile_node_info() {
  $items = array(
    'staff_profile' => array(
      'name' => t('Personale profile'),
      'base' => 'node_content',
      'description' => t('Add new staff profile.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
