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
class openlayers_newplay_behavior_popup_interaction extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layers' => array(),
      'popup_fieldset' => array(
        'popup' => FALSE,
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
      '#description' => t('Select layer to apply node loading to.'),
      '#default_value' => isset($defaults['layers']) ? 
        $defaults['layers'] : array(),
    );
    
    // Popup
    $form['popup_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Popup'),
      '#description' => t('Creates popup behavior.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['popup_fieldset']['popup'] = array(
      '#title' => t('Enable Popup'),
      '#type' => 'checkbox',
      '#default_value' => isset($defaults['popup_fieldset']['popup']) ? 
        $defaults['popup_fieldset']['popup'] : FALSE,
    );
    
    return $form;
  }

  /**
   * Render.
   */
  function render(&$map) {
    // http://drupal.org/node/578712 (Load jQuery 1.4.2 only for address, use noconflict.
    // Wrap jQuery 1.4.2 loading script in some scripts that will store the original jQuery.

    // Load up the noconflict. This might be an excessive call to a script, but it works.
    // This stores the original jQuery object as jQuery 13, before loading a different version of jQuery.
    drupal_add_js(drupal_get_path('module', 'openlayers_newplay') . 
      '/includes/behaviors/js/jquery.noconflict.js');
    drupal_add_js('sites/all/libraries/jquery-1.4.2/jquery-1.4.2.min.js');
    // Also load any jQuery 1.4.2 specific plugins. They attach to the $/jQuery object when loaded.
    // -- Add jQuery address plugin: http://www.asual.com/jquery/address/
    drupal_add_js('sites/all/libraries/jquery.address-1.3/jquery.address-1.3.js');
    // Now load up the postconflict, which will assign the jQuery14 variable and reinstate the original jQuery object.
    drupal_add_js(drupal_get_path('module', 'openlayers_newplay') . 
      '/includes/behaviors/js/jquery.postconflict.js');

    // Add custom popup interaction.
    drupal_add_js(drupal_get_path('module', 'openlayers_newplay') . 
      '/includes/behaviors/js/openlayers_newplay_behavior_popup_interaction.js');

    // Temporary while themeing: css file that only loads when map loads.
    drupal_add_css(drupal_get_path('module', 'openlayers_newplay') .
      '/includes/behaviors/openlayers_newplay.css');

    return $this->options;
  }
}
