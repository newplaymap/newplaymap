<?php

/**
 * Implementation of hook_strongarm().
 */
function newplay_mapping_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_default_preset';
  $strongarm->value = 'new_play_map';

  $export['openlayers_default_preset'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_layers_cloudmade_api';
  $strongarm->value = '1a5668a5d77041ed909538bcbc88ba53';

  $export['openlayers_layers_cloudmade_api'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_layers_cloudmade_js';
  $strongarm->value = 'sites/all/themes/newplay/js/cloudmade.js';

  $export['openlayers_layers_cloudmade_js'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_source';
  $strongarm->value = 'sites/all/libraries/openlayers-2.9.1/lib/OpenLayers.js';

  $export['openlayers_source'] = $strongarm;
  return $export;
}
