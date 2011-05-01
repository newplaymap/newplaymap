<?php
// $Id$

/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Behavior: New Play Map Popup Interaction
 * Will create popup function that will interact with interactive content region & vector layers.
 */
class openlayers_newplay_behavior_cluster extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layers' => array(),
      'cluster_fieldset' => array(
        'cluster' => FALSE,
      ),
    );
  }

  /**
   * Form defintion for per map customizations.
   */
  function options_form($defaults) {
    // Only prompt for vector layers
    $vector_layers = array();
    foreach ($this->map['layers'] as $id => $name) {
      $layer = openlayers_layer_load($id);
      if (isset($layer->data['vector']) && $layer->data['vector'] == TRUE) {
        $vector_layers[$id] = $name;
      }
    }

    return array(
      'clusterlayer' => array(
        '#title' => t('Layers'),
        '#type' => 'checkboxes',
        '#options' => $vector_layers,
        '#description' => t('Select layers to cluster.'),
        '#default_value' => isset($defaults['clusterlayer']) ? 
        $defaults['clusterlayer'] : array(),
      ),
      'distance' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['distance'])) ?
        $defaults['distance'] : 20,
        '#size' => 5,
        '#title' => t('Distance'),
        '#description' => t('Pixel distance between features that should ' .
        'be considered a single cluster'),
      ),
      'threshold' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['threshold'])) ?
        $defaults['threshold'] : NULL,
        '#size' => 5,
        '#title' => t('Threshold'),
        '#description' => t('Optional threshold below which original ' .
        'features will be added to the layer instead of clusters'),
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {

    // Add custom cluster interaction.
    drupal_add_js(drupal_get_path('module', 'openlayers_newplay') . 
      '/includes/behaviors/js/openlayers_newplay_behavior_cluster.js');

    return $this->options;
  }
}
