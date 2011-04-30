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

    $form = array();
    $form['layers'] = array(
      '#title' => t('Layers'),
      '#type' => 'checkboxes',
      '#options' => $vector_layers,
      '#description' => t('Select layer to apply clustering to.'),
      '#default_value' => isset($defaults['layers']) ? 
        $defaults['layers'] : array(),
    );
    
    // Popup
    $form['cluster_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Clustering'),
      '#description' => t('Creates cluster behavior.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['cluster_fieldset']['cluster'] = array(
      '#title' => t('Enable Clustering'),
      '#type' => 'checkbox',
      '#default_value' => isset($defaults['cluster_fieldset']['cluster']) ? 
        $defaults['cluster_fieldset']['cluster'] : FALSE,
    );
    
    return $form;
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
