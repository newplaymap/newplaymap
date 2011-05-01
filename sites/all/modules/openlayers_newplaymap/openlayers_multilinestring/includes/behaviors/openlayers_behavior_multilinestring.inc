<?php
// $Id$

/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Attribution Behavior
 */
class openlayers_behavior_multilinestring extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'multilinestring' => '',
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.ArgParser');
  }

  function options_form($defaults) {
    // Only prompt for vector layers
    $vector_layers = array();
    foreach ($this->map['layers'] as $id => $name) {
      $layer = openlayers_layer_load($id);
      if (isset($layer->data['vector']) && $layer->data['vector'] == TRUE) {
        $vector_layers[$id] = $name;
      }
    }
    $form['multiLineStringLayers'] = array(
      '#title' => t('Layers'),
      '#type' => 'checkboxes',
      '#options' => $vector_layers,
      '#description' => t('Select layers that will get custom lines & styles.<br />
        Then, select a setting for each option.<br />
        * Use "Invisible Style" to hide lines if necessary.<br />
        * Default style for markers are handled in the Layers & Styles.'),
      '#default_value' => isset($defaults['multiLineStringLayers']) ? 
        $defaults['multiLineStringLayers'] : array(),
    );

    // Load each data layer as an option to receive custom styles for each state.
    foreach($vector_layers as $layer_name) {
      
      $default_layer = $defaults['multiLineStringStyleGroup_' . $layer_name];
      
      $form['multiLineStringStyleGroup_' . $layer_name] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#tree' => TRUE,
        '#title' => t('Custom Styles for data layer markers & lines: ' . $layer_name),
        );

      $form['multiLineStringStyleGroup_' . $layer_name]['labelLayer_' . $layer_name] = array(
          '#type' => 'textfield',
          '#default_value' => isset($default_layer['labelLayer_' . $layer_name]) ?
            $default_layer['labelLayer_' . $layer_name] : NULL,
          '#description' => 'Enter a name for the layer. Leave blank to leave layer out of layer switcher.',
        );
      $form['multiLineStringStyleGroup_' . $layer_name]['groupingAttribute_' . $layer_name] = array(
          '#type' => 'textfield',
          '#default_value' => isset($default_layer['groupingAttribute_' . $layer_name]) ?
            $default_layer['groupingAttribute_' . $layer_name] : NULL,
          '#description' => 'Select an attribute to group lines. Leave blank to prevent grouping interactivity styles from happening on this layer.',
        );
      $form['multiLineStringStyleGroup_' . $layer_name]['lineStyle_' . $layer_name] = array(
          '#type' => 'select',
          '#options' => array( t('Default style') ) + openlayers_ui_get_style_options(),
          '#default_value' => isset($default_layer['lineStyle_' . $layer_name]) ?
            $default_layer['lineStyle_' . $layer_name] : NULL,
          '#description' => 'Select a style for the line. If not set, the line will appear using the default style for the layer.',
        );
      $form['multiLineStringStyleGroup_' . $layer_name]['lineStyleSelected_' . $layer_name] = array(
          '#type' => 'select',
          '#options' => array( t('Default style') ) + openlayers_ui_get_style_options(),
          '#default_value' => isset($default_layer['lineStyleSelected_' . $layer_name]) ?
            $default_layer['lineStyleSelected_' . $layer_name] : NULL,
          '#description' => 'Style for line, selected.',
        );
      $form['multiLineStringStyleGroup_' . $layer_name]['featureStyleSelectedGroup_' . $layer_name] = array(
           '#type' => 'select',
          '#options' => array( t('Default style') ) + openlayers_ui_get_style_options(),
          '#default_value' => isset($default_layer['featureStyleSelectedGroup_' . $layer_name]) ?
            $default_layer['featureStyleSelectedGroup_' . $layer_name] : NULL,
          '#description' => 'Style for selected features in this group.',
        );
      $form['multiLineStringStyleGroup_' . $layer_name]['featureStyleSelectedGroupTiny_' . $layer_name] = array(
           '#type' => 'select',
          '#options' => array( t('Default style') ) + openlayers_ui_get_style_options(),
          '#default_value' => isset($default_layer['featureStyleSelectedGroupTiny_' . $layer_name]) ?
            $default_layer['featureStyleSelectedGroupTiny_' . $layer_name] : NULL,
          '#description' => 'Style for selected tiny features in this group.',
        );
      $form['multiLineStringStyleGroup_' . $layer_name]['featureStyleSelectedFeature_' . $layer_name] = array(
           '#type' => 'select',
          '#options' => array( t('Default style') ) + openlayers_ui_get_style_options(),
          '#default_value' => isset($default_layer['featureStyleSelectedFeature_' . $layer_name]) ?
            $default_layer['featureStyleSelectedFeature_' . $layer_name] : NULL,
          '#description' => 'Style for main selected feature in this group.',
        );
      $form['multiLineStringStyleGroup_' . $layer_name]['featureStyleDimmed_' . $layer_name] = array(
          '#type' => 'select',
          '#options' => array( t('Default style') ) + openlayers_ui_get_style_options(),
          '#default_value' => isset($default_layer['featureStyleDimmed_' . $layer_name]) ?
            $default_layer['featureStyleDimmed_' . $layer_name] : NULL,
          '#description' => 'Style for dimmed features not in this group.',
        );
      $form['multiLineStringStyleGroup_' . $layer_name]['featureStyleDimmedTiny_' . $layer_name] = array(
          '#type' => 'select',
          '#options' => array( t('Default style') ) + openlayers_ui_get_style_options(),
          '#default_value' => isset($default_layer['featureStyleDimmedTiny_' . $layer_name]) ?
            $default_layer['featureStyleDimmedTiny_' . $layer_name] : NULL,
          '#description' => 'Style for tiny dimmed features not in this group.',
        );
      $form['multiLineStringStyleGroup_' . $layer_name]['featureStyleClustered_' . $layer_name] = array(
          '#type' => 'select',
          '#options' => array( t('Default style') ) + openlayers_ui_get_style_options(),
          '#default_value' => isset($default_layer['featureStyleClustered_' . $layer_name]) ?
            $default_layer['featureStyleClustered_' . $layer_name] : NULL,
          '#description' => 'Style for clusterd features in this group.',
        );
    }
    // Zoom to group enabled
    $form['multiLineStringGroupZoom'] = array(
      '#title' => t('Allow group zooming'),
      '#type' => 'select',
      '#options' => array(0,1,2,3,4,5,6,7,8,9,10),
      '#default_value' => isset($defaults['multiLineStringGroupZoom']) ?
        $defaults['multiLineStringGroupZoom'] : 0,
      '#description' => 'Allow group zooming.',
      );
    return $form;
  }

  /**
   * Render.
   */
  function render(&$map) {

    foreach($map['layer_styles'] as $layer => $value){
      $behavior_line_styles = array(
        $this->options['multiLineStringStyleGroup_' . $layer]['lineStyle_' . $layer],
        $this->options['multiLineStringStyleGroup_' . $layer]['lineStyleSelected_' . $layer],
        $this->options['multiLineStringStyleGroup_' . $layer]['featureStyleSelectedGroup_' . $layer],
        $this->options['multiLineStringStyleGroup_' . $layer]['featureStyleSelectedFeature_' . $layer],
        $this->options['multiLineStringStyleGroup_' . $layer]['featureStyleDimmed_' . $layer],
        $this->options['multiLineStringStyleGroup_' . $layer]['featureStyleDimmedTiny_' . $layer],
        $this->options['multiLineStringStyleGroup_' . $layer]['featureStyleClustered_' . $layer],
        $this->options['multiLineStringStyleGroup_' . $layer]['featureStyleSelectedGroupTiny_' . $layer],
      );
      foreach($behavior_line_styles as $line_style) {
        // Set a default style if none are selected.
        if($line_style == 0 || $line_style == null) {
          $style = 'default';
        }
        $style = openlayers_style_load($line_style);    
        // This loads and adds styles set in the behavior interface.
        // Adds the JSON encoded style from the database, making it available to JS.
        // @TODO The OpenLayers module is currently working on rearchitecting the module to 
        // support individual layer styles. Ideally, it would be possible to add the multilinestring
        // setting as an additional display option under the layers tab, and keep the
        // behavior as an option to turn on/off the lines showing at all.
        // Also, the way that the OL module currently works, it only allows you to 
        // chose styles for default & select, 'temporary' doesn't actually work correctly.
        // But for now, this is the simplest most user-friendly option.
    
        // This adds the setting in the footer to ensure that the map
        // layer JS setting has already been created.
        if (function_exists('json_encode')) {
          drupal_add_js('Drupal.settings.openlayers.maps["' . $map['id'] . 
            '"]["styles"]["' . $style->name . '"] = ' . json_encode($style->data) . ';', 'inline', 'footer', TRUE);
        }
      }
    }

    drupal_add_js(drupal_get_path('module', 'openlayers_multilinestring') .'/includes/behaviors/js/openlayers_behavior_multilinestring.js');
    return $this->options;
  }
}
