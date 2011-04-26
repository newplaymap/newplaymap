<?php

/**
 * Implementation of hook_openlayers_layers().
 */
function newplay_mapping_openlayers_layers() {
  $export = array();
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'new_play_map';
  $openlayers_layers->title = 'New Play Map';
  $openlayers_layers->description = 'New play map layer';
  $openlayers_layers->data = array(
    'styleId' => '27185',
    'layer_type' => 'openlayers_layer_type_cloudmade',
  );

  $export['new_play_map'] = $openlayers_layers;
  return $export;
}
