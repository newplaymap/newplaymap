<?php

/**
 * Implementation of hook_default_page_manager_handlers().
 */
function artists_default_page_manager_handlers() {
  $export = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Generative Artist Node',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'artist' => 'artist',
            ),
          ),
          'context' => 'argument_nid_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'overlay_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'middle' => NULL,
      'feed_left' => NULL,
      'feed_middle' => NULL,
      'feed_right' => NULL,
      'bottom' => NULL,
      'main' => NULL,
      'info' => NULL,
      'events' => NULL,
      'organizations' => NULL,
      'artists' => NULL,
      'plays' => NULL,
      'links' => NULL,
      'feeds' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'events';
    $pane->type = 'events_by_artist';
    $pane->subtype = 'events_by_artist';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_nid_1',
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
    $display->content['new-1'] = $pane;
    $display->panels['events'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'feeds';
    $pane->type = 'views_panes';
    $pane->subtype = 'feeds-panel_pane_11';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_nid_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'pane-feeds-video',
      'css_class' => 'pane-feeds-panel-pane',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-2'] = $pane;
    $display->panels['feeds'][0] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'feeds';
    $pane->type = 'views_panes';
    $pane->subtype = 'feeds-panel_pane_12';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_nid_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'pane-feeds-photo',
      'css_class' => 'pane-feeds-panel-pane',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-3'] = $pane;
    $display->panels['feeds'][1] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'feeds';
    $pane->type = 'views_panes';
    $pane->subtype = 'feeds-panel_pane_10';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_nid_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'pane-feeds-blog-twitter',
      'css_class' => 'pane-feeds-panel-pane',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-4'] = $pane;
    $display->panels['feeds'][2] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'info';
    $pane->type = 'content_field';
    $pane->subtype = 'field_artist_bio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'normal',
      'formatter' => 'default',
      'context' => 'argument_nid_1',
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
    $display->content['new-5'] = $pane;
    $display->panels['info'][0] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'info';
    $pane->type = 'views_panes';
    $pane->subtype = 'artist_info-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_nid_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-6'] = $pane;
    $display->panels['info'][1] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'info';
    $pane->type = 'content_fieldgroup';
    $pane->subtype = 'artist:group_artist_find_on';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'normal',
      'format' => 'simple',
      'empty' => 'This Generative Artist has not filled any social media links.',
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-7'] = $pane;
    $display->panels['info'][2] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'info';
    $pane->type = 'content_field';
    $pane->subtype = 'field_user_contact';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'normal',
      'formatter' => 'plain',
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-8'] = $pane;
    $display->panels['info'][3] = 'new-8';
    $pane = new stdClass;
    $pane->pid = 'new-9';
    $pane->panel = 'links';
    $pane->type = 'feed';
    $pane->subtype = 'feed';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'feed_links',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-9'] = $pane;
    $display->panels['links'][0] = 'new-9';
    $pane = new stdClass;
    $pane->pid = 'new-10';
    $pane->panel = 'links';
    $pane->type = 'edit_link';
    $pane->subtype = 'edit_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-10'] = $pane;
    $display->panels['links'][1] = 'new-10';
    $pane = new stdClass;
    $pane->pid = 'new-11';
    $pane->panel = 'links';
    $pane->type = 'embed_badge';
    $pane->subtype = 'embed_badge';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-11'] = $pane;
    $display->panels['links'][2] = 'new-11';
    $pane = new stdClass;
    $pane->pid = 'new-12';
    $pane->panel = 'links';
    $pane->type = 'share_link';
    $pane->subtype = 'share_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-12'] = $pane;
    $display->panels['links'][3] = 'new-12';
    $pane = new stdClass;
    $pane->pid = 'new-13';
    $pane->panel = 'main';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'context' => 'argument_nid_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-13'] = $pane;
    $display->panels['main'][0] = 'new-13';
    $pane = new stdClass;
    $pane->pid = 'new-14';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'ensemble_collective-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_nid_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-14'] = $pane;
    $display->panels['main'][1] = 'new-14';
    $pane = new stdClass;
    $pane->pid = 'new-15';
    $pane->panel = 'main';
    $pane->type = 'content_field';
    $pane->subtype = 'field_artist_photo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'normal',
      'formatter' => 'org_standard_default',
      'context' => 'argument_nid_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-15'] = $pane;
    $display->panels['main'][2] = 'new-15';
    $pane = new stdClass;
    $pane->pid = 'new-16';
    $pane->panel = 'main';
    $pane->type = 'content_field';
    $pane->subtype = 'field_location';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'normal',
      'formatter' => 'default',
      'context' => 'argument_nid_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-16'] = $pane;
    $display->panels['main'][3] = 'new-16';
    $pane = new stdClass;
    $pane->pid = 'new-17';
    $pane->panel = 'organizations';
    $pane->type = 'orgs_by_play';
    $pane->subtype = 'orgs_by_play';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_nid_1',
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
    $display->panels['organizations'][0] = 'new-17';
    $pane = new stdClass;
    $pane->pid = 'new-18';
    $pane->panel = 'plays';
    $pane->type = 'views_panes';
    $pane->subtype = 'plays-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_nid_1',
      ),
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
    $display->content['new-18'] = $pane;
    $display->panels['plays'][0] = 'new-18';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;

  $export['node_view_panel_context_4'] = $handler;
  return $export;
}
