<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function home_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'new_play_map_blank';
  $openlayers_presets->title = 'New Play Map: Blank';
  $openlayers_presets->description = 'Black and white blank map';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '600px',
    'image_path' => 'sites/all/themes/newplay/openlayers/img/',
    'css_path' => 'sites/all/themes/newplay/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-81.347291876235, 39.247360263328',
        'zoom' => '4',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '-19954847.843107,716398.936216,-1639312.876807,11674411.309216',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_fullscreen' => array(
        'activated' => 1,
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtomaxextent' => array(),
      'openlayers_behavior_multilinestring' => array(
        'multiLineStringLayers' => array(),
        'multiLineStringGroupZoom' => '9',
      ),
      'openlayers_newplay_behavior_popup_interaction' => array(
        'layers' => array(),
        'popup_fieldset' => array(
          'popup' => 1,
        ),
      ),
      'openlayers_plus_behavior_blockswitcher' => array(
        'map' => array(
          'enabled' => 0,
          'open' => 0,
          'overlay_style' => 'checkbox',
          'position' => 'se',
        ),
      ),
      'openlayers_plus_behavior_legend' => array(),
    ),
    'default_layer' => 'new_play_map',
    'layers' => array(
      'new_play_map' => 'new_play_map',
    ),
    'layer_styles' => array(
      'organizations_openlayers_1' => 'Organization Marker',
      'organizations_openlayers_2' => 'Event Markers',
      'organizations_openlayers_3' => 'Generative Artists Marker',
    ),
    'layer_activated' => array(),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );

  $export['new_play_map_blank'] = $openlayers_presets;
  return $export;
}
