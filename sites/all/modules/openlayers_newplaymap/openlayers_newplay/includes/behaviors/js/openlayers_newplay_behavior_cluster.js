// $Id: openlayers_behavior_cluster.js,v 1.1.2.3 2010/07/21 09:38:30 strk Exp $

/**
 * @file
 * OpenLayers Behavior implementation for clustering.
 */

/**
 * OpenLayers Cluster Behavior
 */
Drupal.behaviors.openlayers_newplay_behavior_cluster = function(context) {
  var data = $(context).data('openlayers');
  if (data && data.map.behaviors.openlayers_newplay_behavior_cluster) {
    var options = data.map.behaviors.openlayers_newplay_behavior_cluster;
    var map = data.openlayers;
    var distance = parseInt(options.distance, 10);
    var threshold = parseInt(options.threshold, 10);
    var layers = [];
    for (var i in options.clusterlayer) {
      var selectedLayer = map.getLayersBy('drupalID', options.clusterlayer[i]);
      if (typeof selectedLayer[0] != 'undefined') {
        layers.push(selectedLayer[0]);
      }
    }
    
    // Go through chosen layers
    for (var i in layers) {
      var layer = layers[i];
      // Ensure vector layer
      if (layer.CLASS_NAME == 'OpenLayers.Layer.Vector') {
        var cluster = new OpenLayers.Strategy.Cluster(options);
        layer.addOptions({ 'strategies': [cluster] }); 
        cluster.setLayer(layer);
        cluster.features = layer.features.slice();
        cluster.activate();
        cluster.cluster();

        var weights = {};
        weights['small'] =
          new OpenLayers.Style({
            'externalGraphic': '',
            'pointRadius': 30,
            'fillColor': '#666666',
            'strokeColor': '#666666',
            'strokeWidth': 1,
            'fillOpacity': 1,
            'strokeOpacity': 1,
            'strokeLinecap': 'round',
            'strokeDashstyle': 'solid',
            'graphicWidth': 30,
            'graphicHeight': 30,
            'graphicOpacity': 1,
            'graphicXOffset': 0,
            'graphicYOffset': 0,
            'graphicName': 'circle',
            'rotation': '0',
            'labelAlign': 'cm',
            'graphicZIndex': 1000,
          });
        weights["medium"] =
          new OpenLayers.Style({
            'externalGraphic': '',
            'pointRadius': 50,
            'fillColor': '#666666',
            'strokeColor': '#666666',
            'strokeWidth': 1,
            'fillOpacity': 1,
            'strokeOpacity': 1,
            'strokeLinecap': 'round',
            'strokeDashstyle': 'solid',
            'graphicWidth': 50,
            'graphicHeight': 50,
            'graphicOpacity': 1,
            'graphicXOffset': 0,
            'graphicYOffset': 0,
            'graphicName': 'circle',
            'rotation': '0',
            'labelAlign': 'cm',
            'graphicZIndex': 1000,
          });
        weights["large"] =
          new OpenLayers.Style({
            'externalGraphic': '',
            'pointRadius': 90,
            'fillColor': '#666666',
            'strokeColor': '#666666',
            'strokeWidth': 1,
            'fillOpacity': 1,
            'strokeOpacity': 1,
            'strokeLinecap': 'round',
            'strokeDashstyle': 'solid',
            'graphicWidth': 90,
            'graphicHeight': 90,
            'graphicOpacity': 1,
            'graphicXOffset': 0,
            'graphicYOffset': 0,
            'graphicName': 'circle',
            'rotation': '0',
            'labelAlign': 'cm',
            'graphicZIndex': 1000,
          });     


        // Set weight on clusters

        for (var i in layer.features) {
          var pf = layer.features[i];

          var count = pf.attributes.count;
          if (count < 5) {
            pf.attributes.weight = "small";
          }
          else if (count <= 20 && count >= 5) {
            pf.attributes.weight = "medium";

          }
          else {
            pf.attributes.weight = "large";

          }
          for (var j in pf.cluster) {
            if (count < 5) {
              pf.cluster[j].attributes.weight = "small";
            }
            else if (count <= 20 && count >= 5) {
              pf.cluster[j].attributes.weight = "medium";
            }
            else {
              pf.cluster[j].attributes.weight = "large";
            }
            pf.cluster[j].attributes.count = count;
            pf.cluster[j].attributes.state = "default";
          }
        }
/* pf.state = "default"; */
/*
        var styleMap = layer.styleMap;
        styleMap.addUniqueValueRules("default", "weight", weights);
        layer.styleMap = styleMap;
        console.log(layer);
        layer.redraw();
*/
      }
    }
  }
};
