<?php
/**
 * @file
 * andromeda_static_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function andromeda_static_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function andromeda_static_page_node_info() {
  $items = array(
    'static_page' => array(
      'name' => t('Static page'),
      'base' => 'node_content',
      'description' => t('Add a new page to the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
