<?php
/**
 * @file
 * andromeda_slider.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function andromeda_slider_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'frontpage_slider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Front page Slider';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_lead']['id'] = 'field_lead';
  $handler->display->display_options['fields']['field_lead']['table'] = 'field_data_field_lead';
  $handler->display->display_options['fields']['field_lead']['field'] = 'field_lead';
  $handler->display->display_options['fields']['field_lead']['label'] = '';
  $handler->display->display_options['fields']['field_lead']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lead']['element_default_classes'] = FALSE;
  /* Field: Content: Front page */
  $handler->display->display_options['fields']['field_frontpage_slider']['id'] = 'field_frontpage_slider';
  $handler->display->display_options['fields']['field_frontpage_slider']['table'] = 'field_data_field_frontpage_slider';
  $handler->display->display_options['fields']['field_frontpage_slider']['field'] = 'field_frontpage_slider';
  $handler->display->display_options['fields']['field_frontpage_slider']['label'] = '';
  $handler->display->display_options['fields']['field_frontpage_slider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_frontpage_slider']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_frontpage_slider']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_frontpage_slider']['settings'] = array(
    'image_style' => 'front_page',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Front page slider */
  $handler = $view->new_display('block', 'Front page slider', 'block_1');
  $translatables['frontpage_slider'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Front page slider'),
  );
  $export['frontpage_slider'] = $view;

  return $export;
}
