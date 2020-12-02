<?php

/**
 * @file
 * andromeda_photo_album.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function andromeda_photo_album_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function andromeda_photo_album_node_info() {
  $items = array(
    'photo_album' => array(
      'name' => t('Photo album'),
      'base' => 'node_content',
      'description' => t('Add new photo album to the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
