<?php
/**
 * @file
 * andromeda_staff_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function andromeda_staff_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'staff';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'staff--row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'staff' => 'staff',
  );
  /* Field: Name (hidden) */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['ui_name'] = 'Name (hidden)';
  $handler->display->display_options['fields']['field_profile_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_profile_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_name']['element_default_classes'] = FALSE;
  /* Field: Position (hidden) */
  $handler->display->display_options['fields']['field_profile_position']['id'] = 'field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['table'] = 'field_data_field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['field'] = 'field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['ui_name'] = 'Position (hidden)';
  $handler->display->display_options['fields']['field_profile_position']['label'] = '';
  $handler->display->display_options['fields']['field_profile_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_position']['element_type'] = '0';
  $handler->display->display_options['fields']['field_profile_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_position']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h1><span class="staff--name">[field_profile_name]</span> (<span class="staff--position">[field_profile_position]</span>)</h1>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'staff--header';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_profile_image']['element_class'] = 'staff--image';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Content */
  $handler->display->display_options['fields']['field_profile_content']['id'] = 'field_profile_content';
  $handler->display->display_options['fields']['field_profile_content']['table'] = 'field_data_field_profile_content';
  $handler->display->display_options['fields']['field_profile_content']['field'] = 'field_profile_content';
  $handler->display->display_options['fields']['field_profile_content']['label'] = '';
  $handler->display->display_options['fields']['field_profile_content']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_profile_content']['element_class'] = 'staff--content';
  $handler->display->display_options['fields']['field_profile_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_content']['element_default_classes'] = FALSE;
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_profile_mail']['id'] = 'field_profile_mail';
  $handler->display->display_options['fields']['field_profile_mail']['table'] = 'field_data_field_profile_mail';
  $handler->display->display_options['fields']['field_profile_mail']['field'] = 'field_profile_mail';
  $handler->display->display_options['fields']['field_profile_mail']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_profile_mail']['element_class'] = 'staff--mail';
  $handler->display->display_options['fields']['field_profile_mail']['element_default_classes'] = FALSE;
  /* Field: Content: Telephone */
  $handler->display->display_options['fields']['field_profile_telephone']['id'] = 'field_profile_telephone';
  $handler->display->display_options['fields']['field_profile_telephone']['table'] = 'field_data_field_profile_telephone';
  $handler->display->display_options['fields']['field_profile_telephone']['field'] = 'field_profile_telephone';
  $handler->display->display_options['fields']['field_profile_telephone']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_profile_telephone']['element_class'] = 'staff--telephone';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Sort criterion: Nodequeue: Queue ID */
  $handler->display->display_options['sorts']['qid']['id'] = 'qid';
  $handler->display->display_options['sorts']['qid']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['qid']['field'] = 'qid';
  $handler->display->display_options['sorts']['qid']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff_profile' => 'staff_profile',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Staff page */
  $handler = $view->new_display('page', 'Staff page', 'page');
  $handler->display->display_options['display_description'] = 'List staff profiles based on nodequeue';
  $handler->display->display_options['path'] = 'personale';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Personale';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-secondary-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['staff'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('<h1><span class="staff--name">[field_profile_name]</span> (<span class="staff--position">[field_profile_position]</span>)</h1>'),
    t('E-mail'),
    t('Telephone'),
    t('Edit link'),
    t('Staff page'),
    t('List staff profiles based on nodequeue'),
  );
  $export['staff'] = $view;

  return $export;
}
