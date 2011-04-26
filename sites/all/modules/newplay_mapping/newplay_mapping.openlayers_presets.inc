<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function newplay_mapping_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'new_play_map';
  $openlayers_presets->title = 'New Play Map';
  $openlayers_presets->description = 'Black and white map';
  $openlayers_presets->data = array(
    'width' => '720px',
    'height' => '480px',
    'image_path' => 'sites/all/themes/newplay/openlayers/img/',
    'css_path' => 'sites/all/themes/newplay/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-99.18908875037, 38.218981477263',
        'zoom' => '4',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-19961069.707609,1548033.803804,-6107011.207459,11331973.422554',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'events_map_openlayers_openlayers_1' => 'events_map_openlayers_openlayers_1',
        ),
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_multilinestring' => array(
        'multiLineStringLabelLayer' => 'Play Route',
        'multiLineStringStyle' => 'play_path',
      ),
    ),
    'default_layer' => 'new_play_map',
    'layers' => array(
      'new_play_map' => 'new_play_map',
      'events_map_openlayers_openlayers_1' => 'events_map_openlayers_openlayers_1',
      'events_map_openlayers_openlayers_2' => 'events_map_openlayers_openlayers_2',
    ),
    'layer_styles' => array(
      'events_map_openlayers_openlayers_1' => 'star_markers_labels',
      'organizations_openlayers_1' => 'star_markers',
    ),
    'layer_activated' => array(
      'events_map_openlayers_openlayers_1' => 'events_map_openlayers_openlayers_1',
      'events_map_openlayers_openlayers_2' => 'events_map_openlayers_openlayers_2',
    ),
    'layer_switcher' => array(
      'events_map_openlayers_openlayers_1' => 'events_map_openlayers_openlayers_1',
      'events_map_openlayers_openlayers_2' => 'events_map_openlayers_openlayers_2',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'star_markers_labels',
      'select' => 'star_markers_labels',
      'temporary' => 'star_markers_labels',
    ),
  );

  $export['new_play_map'] = $openlayers_presets;
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'new_play_map_organizations';
  $openlayers_presets->title = 'New Play Map: Organizations';
  $openlayers_presets->description = 'Black and white map of organizations';
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
        'multiLineStringLayers' => array(
          'organizations_openlayers_1' => 'organizations_openlayers_1',
          'organizations_openlayers_2' => 'organizations_openlayers_2',
          'organizations_openlayers_3' => 'organizations_openlayers_3',
        ),
        'multiLineStringStyleGroup_organizations_openlayers_1' => array(
          'labelLayer_organizations_openlayers_1' => '',
          'groupingAttribute_organizations_openlayers_1' => '',
          'lineStyle_organizations_openlayers_1' => 'No Path',
          'lineStyleSelected_organizations_openlayers_1' => 'No Path',
          'featureStyleSelectedGroup_organizations_openlayers_1' => 'Organization Marker Selected',
          'featureStyleSelectedFeature_organizations_openlayers_1' => 'Organization Marker Selected',
          'featureStyleDimmed_organizations_openlayers_1' => 'Organization Marker Dimmed',
        ),
        'multiLineStringStyleGroup_organizations_openlayers_2' => array(
          'labelLayer_organizations_openlayers_2' => '',
          'groupingAttribute_organizations_openlayers_2' => 'nid',
          'lineStyle_organizations_openlayers_2' => 'play_path',
          'lineStyleSelected_organizations_openlayers_2' => 'play_path_selected',
          'featureStyleSelectedGroup_organizations_openlayers_2' => 'Event Markers Selected',
          'featureStyleSelectedFeature_organizations_openlayers_2' => 'Event Markers Featured',
          'featureStyleDimmed_organizations_openlayers_2' => 'Event Markers Dimmed',
        ),
        'multiLineStringStyleGroup_organizations_openlayers_3' => array(
          'labelLayer_organizations_openlayers_3' => '',
          'groupingAttribute_organizations_openlayers_3' => '',
          'lineStyle_organizations_openlayers_3' => 'No Path',
          'lineStyleSelected_organizations_openlayers_3' => 'No Path',
          'featureStyleSelectedGroup_organizations_openlayers_3' => 'Generative Artists Marker Selected',
          'featureStyleSelectedFeature_organizations_openlayers_3' => 'Generative Artists Marker Selected',
          'featureStyleDimmed_organizations_openlayers_3' => 'Generative Artists Marker Dimmed',
        ),
        'multiLineStringGroupZoom' => '9',
      ),
      'openlayers_newplay_behavior_popup_interaction' => array(
        'layers' => array(
          'organizations_openlayers_1' => 'organizations_openlayers_1',
          'organizations_openlayers_2' => 'organizations_openlayers_2',
          'organizations_openlayers_3' => 'organizations_openlayers_3',
        ),
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
      'organizations_openlayers_1' => 'organizations_openlayers_1',
      'organizations_openlayers_2' => 'organizations_openlayers_2',
      'organizations_openlayers_3' => 'organizations_openlayers_3',
    ),
    'layer_styles' => array(
      'organizations_openlayers_1' => 'Organization Marker',
      'organizations_openlayers_2' => 'Event Markers',
      'organizations_openlayers_3' => 'Generative Artists Marker',
    ),
    'layer_activated' => array(
      'organizations_openlayers_1' => 'organizations_openlayers_1',
      'organizations_openlayers_2' => 'organizations_openlayers_2',
      'organizations_openlayers_3' => 'organizations_openlayers_3',
    ),
    'layer_switcher' => array(
      'organizations_openlayers_1' => 'organizations_openlayers_1',
      'organizations_openlayers_2' => 'organizations_openlayers_2',
      'organizations_openlayers_3' => 'organizations_openlayers_3',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );

  $export['new_play_map_organizations'] = $openlayers_presets;
  return $export;
}
