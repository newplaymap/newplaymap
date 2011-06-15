<?php

/**
 * Implementation of hook_default_page_manager_pages().
 */
function home_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home Page';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = '1col_with_feeds';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'feed_left' => NULL,
      'feed_middle' => NULL,
      'feed_right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if map has been filtered',
            'php' => 'if (!empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Generic Results Overlay title',
      'title' => '',
      'body' => '<h2 class="overlay-title">Results</h2>',
      'format' => '2',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-node-title',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['bottom'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_5';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if map has been filtered',
            'php' => 'if (!empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'filter-results-plays',
      'css_class' => 'filter-results-listing',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['bottom'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if map has been filtered',
            'php' => 'if (!empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'filter-results-events',
      'css_class' => 'filter-results-listing',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['bottom'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if map has been filtered',
            'php' => 'if (!empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'filter-results-organizations',
      'css_class' => 'filter-results-listing',
    );
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['bottom'][3] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_4';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if map has been filtered',
            'php' => 'if (!empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'filter-results-artists',
      'css_class' => 'filter-results-listing',
    );
    $pane->extras = array();
    $pane->position = 4;
    $display->content['new-5'] = $pane;
    $display->panels['bottom'][4] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'bottom';
    $pane->type = 'today_overlay_title';
    $pane->subtype = 'today_overlay_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Show when page has not been filtered',
            'php' => 'if (empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-node-title',
    );
    $pane->extras = array();
    $pane->position = 5;
    $display->content['new-6'] = $pane;
    $display->panels['bottom'][5] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_9';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if map has not been filtered',
            'php' => 'if (empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'filter-results-plays',
      'css_class' => 'filter-results-listing',
    );
    $pane->extras = array();
    $pane->position = 6;
    $display->content['new-7'] = $pane;
    $display->panels['bottom'][6] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_6';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Show if view has not been filtered',
            'php' => 'if (empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'filter-results-events',
      'css_class' => 'today-listing filter-results-listing',
    );
    $pane->extras = array();
    $pane->position = 7;
    $display->content['new-8'] = $pane;
    $display->panels['bottom'][7] = 'new-8';
    $pane = new stdClass;
    $pane->pid = 'new-9';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_7';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Show only if no filters have been selected',
            'php' => 'if (empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'filter-results-organizations',
      'css_class' => 'today-listing filter-results-listing',
    );
    $pane->extras = array();
    $pane->position = 8;
    $display->content['new-9'] = $pane;
    $display->panels['bottom'][8] = 'new-9';
    $pane = new stdClass;
    $pane->pid = 'new-10';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_8';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Show only if no filters have been selected',
            'php' => 'if (empty($_REQUEST[\'play\'])) { return TRUE; }',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'filter-results-artists',
      'css_class' => 'today-listing filter-results-listing',
    );
    $pane->extras = array();
    $pane->position = 9;
    $display->content['new-10'] = $pane;
    $display->panels['bottom'][9] = 'new-10';
    $pane = new stdClass;
    $pane->pid = 'new-11';
    $pane->panel = 'feed_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'feeds-panel_pane_5';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-11'] = $pane;
    $display->panels['feed_left'][0] = 'new-11';
    $pane = new stdClass;
    $pane->pid = 'new-12';
    $pane->panel = 'feed_middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'feeds-panel_pane_6';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-12'] = $pane;
    $display->panels['feed_middle'][0] = 'new-12';
    $pane = new stdClass;
    $pane->pid = 'new-13';
    $pane->panel = 'feed_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'feeds-panel_pane_4';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-13'] = $pane;
    $display->panels['feed_right'][0] = 'new-13';
    $pane = new stdClass;
    $pane->pid = 'new-14';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-14'] = $pane;
    $display->panels['middle'][0] = 'new-14';
    $pane = new stdClass;
    $pane->pid = 'new-15';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-panel_pane_5';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-15'] = $pane;
    $display->panels['middle'][1] = 'new-15';
    $pane = new stdClass;
    $pane->pid = 'new-16';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'feeds-panel_pane_1';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-pane-feed-firehose',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-16'] = $pane;
    $display->panels['middle'][2] = 'new-16';
    $pane = new stdClass;
    $pane->pid = 'new-17';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-organizations-panel_pane_1';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-17'] = $pane;
    $display->panels['top'][0] = 'new-17';
    $pane = new stdClass;
    $pane->pid = 'new-18';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'openlayers_plus-blockswitcher';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-18'] = $pane;
    $display->panels['top'][1] = 'new-18';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-14';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

 return $pages;

}
