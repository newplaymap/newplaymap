// $Id: openlayers_behavior_cluster.js,v 1.1.2.3 2010/07/21 09:38:30 strk Exp $

/**
 * @file
 * OpenLayers Behavior implementation for clustering.
 */

Drupal.openlayers = Drupal.openlayers || {};
Drupal.openlayers.popup = Drupal.openlayers.popup || {};

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
        Drupal.openlayers.popup.featureScale(layer);
      }
    }

    // Register a listener to update features on zoomend.
    map.events.register("zoomend", map, Drupal.openlayers.popup.clusterZoomChange);
  }
};


/* Update map features on zoom Change. */
Drupal.openlayers.popup.featureScale = function(layer) {
  // Set weight & scaling on clusters
  for (var i in layer.features) {
    var pf = layer.features[i];

    var count = pf.attributes.count;
    if (count < 10) {
      pf.attributes.weight = 10 + (2 * count);
    }
    else if (count <= 30 && count >= 10) {
      pf.attributes.weight = 15 + (2 * count);

    }
    else {
      pf.attributes.weight = 40 + (1.5 * count);
    }

    for (var j in pf.cluster) {
      if (count < 5) {
        pf.attributes.weight = 10 + (2 * count);
      }
      else if (count <= 20 && count >= 5) {
        pf.attributes.weight = 15 + (2 * count);
      }
      else {
        pf.attributes.weight = 40 + (1.5 * count);
      }
      pf.cluster[j].attributes.count = count;
      pf.cluster[j].attributes.state = pf.renderIntent;

      pf.attributes.state = pf.renderIntent;
console.log("-----");
console.log(pf);
    }
  layer.redraw();
  }

};

/* Update map features on zoom Change. */
Drupal.openlayers.popup.clusterZoomChange = function(event) {
  var context = Drupal.openlayers.context;
  var data = $(context).data('openlayers');
  if (data && data.map.behaviors.openlayers_newplay_behavior_cluster) {
    var options = data.map.behaviors.openlayers_newplay_behavior_cluster;
    var map = data.openlayers;
    for (var i in options.clusterlayer) {
      //var selectedLayer = map.getLayersBy('drupalID', options.clusterlayer[i]);
      for (var j in event.object.layers) {
        if(event.object.layers[j]["drupalID"] == options.clusterlayer[i]) {
          layer = event.object.layers[j];
          layer.redraw();
        }
      }
      Drupal.openlayers.popup.featureScale(layer);
    }
  }
console.log("zoom");
}

