<?php
/**
 * @file
 * andromeda_staff_profile.features.inc
 */

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
