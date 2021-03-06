<?php
/**
 * @file
 * andromeda_news.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function andromeda_news_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-news-field_billede'.
  $field_instances['node-news-field_billede'] = array(
    'bundle' => 'news',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_multivalue_index' => NULL,
          'colorbox_node_style' => 'photo_album',
          'colorbox_node_style_first' => '',
        ),
        'type' => 'colorbox',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_billede',
    'label' => 'Billede',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'news_photo',
      'file_extensions' => 'png jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'multiupload_imagefield_widget',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 0,
          'colorbox__content_images' => 0,
          'colorbox__content_images_wide' => 0,
          'colorbox__flexslider_full' => 0,
          'colorbox__flexslider_thumbnail' => 0,
          'colorbox__front_page' => 0,
          'colorbox__gallery' => 0,
          'colorbox__large' => 0,
          'colorbox__list_image' => 0,
          'colorbox__medium' => 0,
          'colorbox__personale' => 0,
          'colorbox__photo_album' => 0,
          'colorbox__photo_album_full' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_content_images' => 0,
          'image_content_images_wide' => 0,
          'image_flexslider_full' => 0,
          'image_flexslider_thumbnail' => 0,
          'image_front_page' => 0,
          'image_gallery' => 0,
          'image_large' => 0,
          'image_list_image' => 0,
          'image_medium' => 0,
          'image_personale' => 0,
          'image_photo_album' => 0,
          'image_photo_album_full' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_miw',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-news-field_content'.
  $field_instances['node-news-field_content'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_content',
    'label' => 'Content',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 15,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-news-field_content_images'.
  $field_instances['node-news-field_content_images'] = array(
    'bundle' => 'news',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_content_images',
    'label' => 'Images',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'content_images',
      'file_extensions' => 'png jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 1,
        'insert_absolute' => 0,
        'insert_class' => 'image--content',
        'insert_default' => 'image_content_images',
        'insert_styles' => array(
          'auto' => 0,
          'colorbox__content_images' => 0,
          'colorbox__content_images_wide' => 0,
          'colorbox__front_page' => 0,
          'colorbox__gallery' => 0,
          'colorbox__large' => 0,
          'colorbox__list_image' => 0,
          'colorbox__medium' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_content_images' => 'image_content_images',
          'image_content_images_wide' => 'image_content_images_wide',
          'image_front_page' => 0,
          'image_gallery' => 0,
          'image_large' => 0,
          'image_list_image' => 0,
          'image_medium' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-news-field_files'.
  $field_instances['node-news-field_files'] = array(
    'bundle' => 'news',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'attched',
      'file_extensions' => 'txt pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__content_images' => 0,
          'colorbox__content_images_wide' => 0,
          'colorbox__flexslider_full' => 0,
          'colorbox__flexslider_thumbnail' => 0,
          'colorbox__front_page' => 0,
          'colorbox__gallery' => 0,
          'colorbox__large' => 0,
          'colorbox__list_image' => 0,
          'colorbox__medium' => 0,
          'colorbox__personale' => 0,
          'colorbox__photo_album' => 0,
          'colorbox__photo_album_full' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_content_images' => 0,
          'image_content_images_wide' => 0,
          'image_flexslider_full' => 0,
          'image_flexslider_thumbnail' => 0,
          'image_front_page' => 0,
          'image_gallery' => 0,
          'image_large' => 0,
          'image_list_image' => 0,
          'image_medium' => 0,
          'image_personale' => 0,
          'image_photo_album' => 0,
          'image_photo_album_full' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-news-field_frontpage_slider'.
  $field_instances['node-news-field_frontpage_slider'] = array(
    'bundle' => 'news',
    'deleted' => 0,
    'description' => 'This image is used in the front page slider.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_frontpage_slider',
    'label' => 'Front page',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'frontpage_images',
      'file_extensions' => 'png jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__content_images' => 0,
          'colorbox__content_images_wide' => 0,
          'colorbox__flexslider_full' => 0,
          'colorbox__flexslider_thumbnail' => 0,
          'colorbox__front_page' => 0,
          'colorbox__gallery' => 0,
          'colorbox__large' => 0,
          'colorbox__list_image' => 0,
          'colorbox__medium' => 0,
          'colorbox__personale' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_content_images' => 0,
          'image_content_images_wide' => 0,
          'image_flexslider_full' => 0,
          'image_flexslider_thumbnail' => 0,
          'image_front_page' => 0,
          'image_gallery' => 0,
          'image_large' => 0,
          'image_list_image' => 0,
          'image_medium' => 0,
          'image_personale' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-news-field_lead'.
  $field_instances['node-news-field_lead'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lead',
    'label' => 'Lead',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-news-field_list_image'.
  $field_instances['node-news-field_list_image'] = array(
    'bundle' => 'news',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_list_image',
    'label' => 'List image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'list_images',
      'file_extensions' => 'png jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => 'image--list',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 0,
          'colorbox__content_images' => 0,
          'colorbox__content_images_wide' => 0,
          'colorbox__front_page' => 0,
          'colorbox__gallery' => 0,
          'colorbox__large' => 0,
          'colorbox__list_image' => 0,
          'colorbox__medium' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_content_images' => 0,
          'image_content_images_wide' => 0,
          'image_front_page' => 0,
          'image_gallery' => 0,
          'image_large' => 0,
          'image_list_image' => 0,
          'image_medium' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-news-meta_description'.
  $field_instances['node-news-meta_description'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'metatags_quick',
        'settings' => array(),
        'type' => 'metatags_quick_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'meta_description',
    'formatter' => 'metatags_quick_default',
    'label' => '(Meta)Description',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'metatags_quick',
      'settings' => array(),
      'type' => 'metatags_quick_textarea',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('(Meta)Description');
  t('Billede');
  t('Content');
  t('Files');
  t('Front page');
  t('Images');
  t('Lead');
  t('List image');
  t('This image is used in the front page slider.');

  return $field_instances;
}
