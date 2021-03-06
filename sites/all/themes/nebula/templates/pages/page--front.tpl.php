<?php

/**
 * @file
 * Nebula's theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']
 * - $page['featured']
 * - $page['content']
 * - $page['secondary_content']
 * - $page['tertiary_content']
 * - $page['footer_firstcolumn']
 * - $page['footer_secondcolumn']
 * - $page['footer_thirdcolumn']
 * - $page['footer_fourthcolumn']
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 */
?>
<div id="page" class="<?php print $classes?>">
  <header>
    <div class="header--inner">
      <div class="logo">
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
          <img src="<?php print $logo; ?>" alt="Andromeda logo" title="Andromeda logo" />
        </a>
      </div>

      <div class="menu-wrapper">
        <?php print render($page['header']); ?>
      </div>
    </div>
  </header>

  <?php if ($page['featured']): ?>
    <div id="featured">
      <?php print render($page['featured']); ?>
    </div>
  <?php endif; ?>

  <div class="content-wrapper">
    <div class="content-inner">

      <?php if ($messages): ?>
        <div id="messages">
          <?php print $messages; ?>
        </div>
      <?php endif; ?>

      <div class="primary-content">
        <a id="primary-content"></a>

        <?php if ($tabs): ?>
          <div class="tabs">
            <?php print render($tabs); ?>
          </div>
        <?php endif; ?>

        <?php if ($action_links): ?>
          <ul class="action-links">
            <?php print render($action_links); ?>
          </ul>
        <?php endif; ?>

        <?php print render($page['content']); ?>
      </div>

      <?php if ($page['secondary_content']): ?>
        <aside class="secondary-content">
          <?php print render($page['secondary_content']); ?>
        </aside>
      <?php endif; ?>

      <?php if ($page['tertiary_content']): ?>
        <aside class="tertiary-content">
          <?php print render($page['tertiary_content']); ?>
        </aside>
      <?php endif; ?>

    </div> <!-- inner -->
  </div> <!-- content -->

  <footer>
    <div class="footer--outer">
      <div class="footer--inner">
        <?php print render($page['footer']); ?>
      </div>
    </div>
  </footer>
</div>
