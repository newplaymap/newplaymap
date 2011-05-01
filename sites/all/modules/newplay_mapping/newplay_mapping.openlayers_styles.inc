<?php

/**
 * Implementation of hook_openlayers_styles().
 */
function newplay_mapping_openlayers_styles() {
  $export = array();
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Event Markers';
  $openlayers_styles->title = 'Event Markers';
  $openlayers_styles->description = 'Markers for events';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/medium/pin-event.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 26,
    'graphicHeight' => 26,
    'graphicOpacity' => 1,
    'graphicXOffset' => -13,
    'graphicYOffset' => -26,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 1000,
  );

  $export['Event Markers'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Event Markers Dimmed';
  $openlayers_styles->title = 'Event Markers Dimmed';
  $openlayers_styles->description = 'Markers for events (dimmed)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/medium/pin-event-dim.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 26,
    'graphicHeight' => 26,
    'graphicOpacity' => 1,
    'graphicXOffset' => -13,
    'graphicYOffset' => -26,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 998,
  );

  $export['Event Markers Dimmed'] = $openlayers_styles;


  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Event Markers Tiny';
  $openlayers_styles->title = 'Event Markers Tiny';
  $openlayers_styles->description = 'Markers for events (tiny)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-simple/event.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 7,
    'graphicHeight' => 7,
    'graphicOpacity' => 1,
    'graphicXOffset' => 0,
    'graphicYOffset' => 0,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 1000,
  );

  $export['Event Markers Tiny'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Event Markers Dimmed Tiny';
  $openlayers_styles->title = 'Event Markers Dimmed Tiny';
  $openlayers_styles->description = 'Markers for events (dimmed tiny)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-simple/dimmed.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 7,
    'graphicHeight' => 7,
    'graphicOpacity' => 1,
    'graphicXOffset' => 0,
    'graphicYOffset' => 0,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 998,
  );

  $export['Event Markers Dimmed Tiny'] = $openlayers_styles;

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Event Markers Clustered';
  $openlayers_styles->title = 'Event Markers Clustered';
  $openlayers_styles->description = 'Markers for events (clustered)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-simple/event-cluster.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 20,
    'graphicHeight' => 20,
    'graphicOpacity' => 1,
    'graphicXOffset' => 0,
    'graphicYOffset' => 0,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 998,
  );

  $export['Event Markers Clustered'] = $openlayers_styles;

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Event Markers Featured';
  $openlayers_styles->title = 'Event Markers Featured';
  $openlayers_styles->description = 'Markers for events (featured)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/large/pin-event-active.png',
    'pointRadius' => 18,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 37,
    'graphicHeight' => 37,
    'graphicOpacity' => 1,
    'graphicXOffset' => -18,
    'graphicYOffset' => -37,
    'graphicName' => 'square',
    'rotation' => '0',
    'label' => '${groupCounter}. ${field_event_type_nid_rendered}',
    'labelAlign' => 'cm',
    'labelYOffset' => '-10',
    'fontColor' => '#000000',
    'fontSize' => '10px',
    'fontFamily' => 'Arial',
    'fontWeight' => 'bold',
    'graphicZIndex' => 1010,
  );

  $export['Event Markers Featured'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Event Markers Selected';
  $openlayers_styles->title = 'Event Markers Selected';
  $openlayers_styles->description = 'Markers for events (selected)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/medium/pin-event-active-unfeatured.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 26,
    'graphicHeight' => 26,
    'graphicOpacity' => 1,
    'graphicXOffset' => -13,
    'graphicYOffset' => -26,
    'graphicName' => 'square',
    'rotation' => '0',
    'label' => '${groupCounter}. ${field_event_type_nid_rendered}',
    'labelAlign' => 'cm',
    'labelYOffset' => '-10',
    'fontColor' => '#000000',
    'fontSize' => '10px',
    'fontFamily' => 'Arial',
    'fontWeight' => 'bold',
    'graphicZIndex' => 1010,
  );

  $export['Event Markers Selected'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Generative Artists Marker';
  $openlayers_styles->title = 'Generative Artists Marker';
  $openlayers_styles->description = 'Marker for Artists';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/large/pin-artist.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 26,
    'graphicHeight' => 26,
    'graphicOpacity' => 1,
    'graphicXOffset' => -13,
    'graphicYOffset' => -26,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 1000,
  );

  $export['Generative Artists Marker'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Generative Artists Marker Dimmed';
  $openlayers_styles->title = 'Generative Artists Marker Dimmed';
  $openlayers_styles->description = 'Marker for Artists (Dimmed)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/large/pin-artist-dim.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 26,
    'graphicHeight' => 26,
    'graphicOpacity' => 1,
    'graphicXOffset' => -13,
    'graphicYOffset' => -26,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 998,
  );

  $export['Generative Artists Marker Dimmed'] = $openlayers_styles;

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Generative Artists Clustered';
  $openlayers_styles->title = 'Generative Artists Clustered';
  $openlayers_styles->description = 'Markers for artists (clustered)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-simple/event-artist.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 20,
    'graphicHeight' => 20,
    'graphicOpacity' => 1,
    'graphicXOffset' => 0,
    'graphicYOffset' => 0,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 998,
  );

  $export['Generative Artists Clustered'] = $openlayers_styles;

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Generative Artists Marker Tiny';
  $openlayers_styles->title = 'Generative Artists Marker Tiny';
  $openlayers_styles->description = 'Marker for Artists Tiny';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-simple/artist.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 7,
    'graphicHeight' => 7,
    'graphicOpacity' => 1,
    'graphicXOffset' => 0,
    'graphicYOffset' => 0,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 1000,
  );

  $export['Generative Artists Marker Tiny'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Generative Artists Marker Dimmed Tiny';
  $openlayers_styles->title = 'Generative Artists Marker Dimmed Tiny';
  $openlayers_styles->description = 'Marker for Artists (Dimmed Tiny)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-simple/dimmed.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 7,
    'graphicHeight' => 7,
    'graphicOpacity' => 1,
    'graphicXOffset' => 0,
    'graphicYOffset' => 0,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 998,
  );

  $export['Generative Artists Marker Dimmed Tiny'] = $openlayers_styles;



  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Generative Artists Marker Selected';
  $openlayers_styles->title = 'Generative Artists Marker Selected';
  $openlayers_styles->description = 'Marker for Artists (Selected)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/large/pin-artist-active.png',
    'pointRadius' => 18,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 37,
    'graphicHeight' => 37,
    'graphicOpacity' => 1,
    'graphicXOffset' => -18,
    'graphicYOffset' => -37,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 1002,
  );

  $export['Generative Artists Marker Selected'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'No Path';
  $openlayers_styles->title = 'No Path';
  $openlayers_styles->description = 'Invisible path for non lines.';
  $openlayers_styles->data = array(
    'pointRadius' => 1,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 0,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );

  $export['No Path'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Organization Marker';
  $openlayers_styles->title = 'Organization Marker';
  $openlayers_styles->description = 'The marker for an organization.';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/large/pin-org.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 26,
    'graphicHeight' => 26,
    'graphicOpacity' => 1,
    'graphicXOffset' => -13,
    'graphicYOffset' => -26,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 1000,
  );

  $export['Organization Marker'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Organization Marker Dimmed';
  $openlayers_styles->title = 'Organization Marker Dimmed';
  $openlayers_styles->description = 'The marker for an organization, dimmed.';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/large/pin-org-dim.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 26,
    'graphicHeight' => 26,
    'graphicOpacity' => 1,
    'graphicXOffset' => -13,
    'graphicYOffset' => -26,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 998,
  );

  $export['Organization Marker Dimmed'] = $openlayers_styles;

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Organization Marker Tiny';
  $openlayers_styles->title = 'Organization Marker Tiny';
  $openlayers_styles->description = 'The marker for an organization.  Tiny';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-simple/org.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 7,
    'graphicHeight' => 7,
    'graphicOpacity' => 1,
    'graphicXOffset' => 0,
    'graphicYOffset' => 0,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 1000,
  );

  $export['Organization Marker Tiny'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Organization Marker Dimmed Tiny';
  $openlayers_styles->title = 'Organization Marker Dimmed Tiny';
  $openlayers_styles->description = 'The marker for an organization, dimmed, tiny.';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-simple/dimmed.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 7,
    'graphicHeight' => 7,
    'graphicOpacity' => 1,
    'graphicXOffset' => 0,
    'graphicYOffset' => 0,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 998,
  );

  $export['Organization Marker Dimmed Tiny'] = $openlayers_styles;


  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Organization Clustered';
  $openlayers_styles->title = 'Organization Clustered';
  $openlayers_styles->description = 'Markers for organizations (clustered)';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-simple/event-org.png',
    'pointRadius' => 13,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 20,
    'graphicHeight' => 20,
    'graphicOpacity' => 1,
    'graphicXOffset' => 0,
    'graphicYOffset' => 0,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 998,
  );

  $export['Organization Clustered'] = $openlayers_styles;

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'Organization Marker Selected';
  $openlayers_styles->title = 'Organization Marker Selected';
  $openlayers_styles->description = 'The marker for an organization.';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/themes/newplay/images/pins-naked/large/pin-org-active.png',
    'pointRadius' => 18,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#FFFFFF',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 37,
    'graphicHeight' => 37,
    'graphicOpacity' => 1,
    'graphicXOffset' => -18,
    'graphicYOffset' => -37,
    'graphicName' => 'square',
    'rotation' => '0',
    'labelAlign' => 'cm',
    'graphicZIndex' => 1002,
  );

  $export['Organization Marker Selected'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'play_path';
  $openlayers_styles->title = 'Play Path';
  $openlayers_styles->description = 'The linear path an a play takes.';
  $openlayers_styles->data = array(
    'pointRadius' => 1,
    'fillColor' => '#FFCC00',
    'strokeColor' => '#FFCC00',
    'strokeWidth' => 0,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );

  $export['play_path'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'play_path_selected';
  $openlayers_styles->title = 'Play Path Selected';
  $openlayers_styles->description = 'The linear path an a play takes (selected)';
  $openlayers_styles->data = array(
    'pointRadius' => 1,
    'fillColor' => '#ea0941',
    'strokeColor' => '#ea0941',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'dash',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
    'graphicZIndex' => 1001,
  );

  $export['play_path_selected'] = $openlayers_styles;
  return $export;
}
