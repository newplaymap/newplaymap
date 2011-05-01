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
      }
    }
  }
};
