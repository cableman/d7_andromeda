<?php

/**
 * @file
 * Page callbacks for the Checklist API module.
 */

/**
 * Page callback: Form constructor for "Clear saved progress" confirmation form.
 *
 * @param string $id
 *   The checklist ID.
 *
 * @see checklistapi_menu()
 *
 * @ingroup forms
 */
function checklistapi_checklist_clear_confirm($form, &$form_state, $id) {
  $checklist = checklistapi_checklist_load($id);
  $form['#checklist'] = $checklist;
  $question = t('Are you sure you want to clear %title saved progress?', [
    '%title' => $checklist->title,
  ]);
  $description = t('All progress details will be erased. This action cannot be undone.');
  $yes = t('Clear');
  $no = t('Cancel');
  return confirm_form($form, $question, $checklist->path, $description, $yes, $no);
}

/**
 * Form submission handler for checklistapi_checklist_clear_confirm().
 */
function checklistapi_checklist_clear_confirm_submit($form, &$form_state) {
  // If user confirmed, clear saved progress.
  if ($form_state['values']['confirm']) {
    $form['#checklist']->clearSavedProgress();
  }

  // Redirect back to checklist.
  $form_state['redirect'] = $form['#checklist']->path;
}

/**
 * Page callback: Form constructor for the checklist form.
 *
 * @param string $id
 *   The checklist ID.
 *
 * @see checklistapi_checklist_form_submit()
 * @see checklistapi_menu()
 *
 * @ingroup forms
 */
function checklistapi_checklist_form($form, &$form_state, $id) {
  $form['#checklist'] = $checklist = checklistapi_checklist_load($id);

  $form['progress_bar'] = [
    '#type' => 'markup',
    '#markup' => theme('checklistapi_progress_bar', [
      'message' => ($checklist->hasSavedProgress()) ? t('Last updated @date by !user', [
        '@date' => $checklist->getLastUpdatedDate(),
        '!user' => $checklist->getLastUpdatedUser(),
      ]) : '&nbsp;',
      'number_complete' => $checklist->getNumberCompleted(),
      'number_of_items' => $checklist->getNumberOfItems(),
      'percent_complete' => round($checklist->getPercentComplete()),
    ]),
  ];
  if (checklistapi_compact_mode()) {
    $form['#attributes']['class'] = ['compact-mode'];
  }
  $form['compact_mode_link'] = [
    '#markup' => theme('checklistapi_compact_link'),
  ];

  $form['checklistapi'] = [
    '#attached' => [
      'css' => [drupal_get_path('module', 'checklistapi') . '/checklistapi.css'],
      'js' => [drupal_get_path('module', 'checklistapi') . '/checklistapi.js'],
    ],
    '#tree' => TRUE,
    '#type' => 'vertical_tabs',
  ];

  // Loop through groups.
  $num_autochecked_items = 0;
  $groups = $checklist->items;
  foreach (element_children($groups) as $group_key) {
    $group = &$groups[$group_key];
    $form['checklistapi'][$group_key] = [
      '#title' => filter_xss($group['#title']),
      '#type' => 'fieldset',
    ];
    if (!empty($group['#description'])) {
      $form['checklistapi'][$group_key]['#description'] = filter_xss_admin($group['#description']);
    }

    // Loop through items.
    foreach (element_children($group) as $item_key) {
      $item = &$group[$item_key];
      $saved_item = !empty($checklist->savedProgress[$item_key]) ? $checklist->savedProgress[$item_key] : 0;
      // Build title.
      $title = filter_xss($item['#title']);
      if ($saved_item) {
        // Append completion details.
        $user = user_load($saved_item['#uid']);
        $title .= t(
          '<span class="completion-details"> - Completed @time by !user</a>',
          [
            '@time' => format_date($saved_item['#completed'], 'short'),
            '!user' => theme('username', ['account' => $user]),
          ]
        );
      }
      // Set default value.
      $default_value = FALSE;
      if ($saved_item) {
        $default_value = TRUE;
      }
      elseif (!empty($item['#default_value'])) {
        if ($default_value = $item['#default_value']) {
          $num_autochecked_items++;
        }
      }
      // Get description.
      $description = (isset($item['#description'])) ? '<p>' . filter_xss_admin($item['#description']) . '</p>' : '';
      // Append links.
      $links = [];
      foreach (element_children($item) as $link_key) {
        $link = &$item[$link_key];
        $options = (!empty($link['#options']) && is_array($link['#options'])) ? $link['#options'] : [];
        $links[] = l($link['#text'], $link['#path'], $options);
      }
      if (count($links)) {
        $description .= '<div class="links">' . implode(' | ', $links) . '</div>';
      }
      // Compile the list item.
      $form['checklistapi'][$group_key][$item_key] = [
        '#attributes' => ['class' => ['checklistapi-item']],
        '#default_value' => $default_value,
        '#description' => filter_xss_admin($description),
        '#disabled' => !($user_has_edit_access = $checklist->userHasAccess('edit')),
        '#title' => filter_xss_admin($title),
        '#type' => 'checkbox',
      ];
    }
  }

  $form['actions'] = [
    '#access' => $user_has_edit_access,
    '#type' => 'actions',
    '#weight' => 100,
    'save' => [
      '#submit' => ['checklistapi_checklist_form_submit'],
      '#type' => 'submit',
      '#value' => t('Save'),
    ],
    'clear' => [
      '#access' => $checklist->hasSavedProgress(),
      '#attributes' => ['class' => ['clear-saved-progress']],
      '#href' => $checklist->path . '/clear',
      '#title' => t('Clear saved progress'),
      '#type' => 'link',
    ],
  ];

  // Alert the user of autochecked items. Only set the message on GET requests
  // to prevent it from reappearing after saving the form. (Testing the request
  // method may not be the "correct" way to accomplish this.)
  if ($num_autochecked_items && $_SERVER['REQUEST_METHOD'] == 'GET') {
    $args = [
      '%checklist' => $checklist->title,
      '@num' => $num_autochecked_items,
    ];
    $message = format_plural(
      $num_autochecked_items,
      t('%checklist found 1 unchecked item that was already completed and checked it for you. Save the form to record the change.', $args),
      t('%checklist found @num unchecked items that were already completed and checked them for you. Save the form to record the changes.', $args)
    );
    drupal_set_message($message, 'status');
  }

  return $form;
}

/**
 * Form submission handler for checklistapi_checklist_form().
 */
function checklistapi_checklist_form_submit($form, &$form_state) {
  $form['#checklist']->saveProgress($form_state['values']['checklistapi']);
}

/**
 * Determines whether the current user is in compact mode.
 *
 * Compact mode shows checklist forms with less description text.
 *
 * Whether the user is in compact mode is determined by a cookie, which is set
 * for the user by checklistapi_compact_page().
 *
 * If the user does not have the cookie, the default value is given by the
 * system variable 'checklistapi_compact_mode', which itself defaults to FALSE.
 * This does not have a user interface to set it: it is a hidden variable which
 * can be set in the settings.php file.
 *
 * @return bool
 *   TRUE when in compact mode, or FALSE when in expanded mode.
 */
function checklistapi_compact_mode() {
  return $_COOKIE['Drupal_visitor_checklistapi_compact_mode'] ?? variable_get('checklistapi_compact_mode', FALSE);
}

/**
 * Menu callback: Sets whether the admin menu is in compact mode or not.
 *
 * @param string $mode
 *   (optional) The mode to set compact mode to. Accepted values are "on" and
 *   "off". Defaults to "off".
 */
function checklistapi_compact_page($mode = 'off') {
  user_cookie_save(['checklistapi_compact_mode' => ($mode == 'on')]);
  drupal_goto();
}

/**
 * Returns HTML for a link to show or hide inline item descriptions.
 *
 * @ingroup themeable
 */
function theme_checklistapi_compact_link() {
  $output = '<div class="compact-link">';
  if (checklistapi_compact_mode()) {
    $output .= l(
      t('Show item descriptions'),
      current_path() . '/compact/off',
      [
        'attributes' => [
          'title' => t('Expand layout to include item descriptions.'),
        ],
        'query' => drupal_get_destination(),
      ]
    );
  }
  else {
    $output .= l(
      t('Hide item descriptions'),
      current_path() . '/compact/on',
      [
        'attributes' => [
          'title' => t('Compress layout by hiding item descriptions.'),
        ],
        'query' => drupal_get_destination(),
      ]
    );
  }
  $output .= '</div>';
  return $output;
}
