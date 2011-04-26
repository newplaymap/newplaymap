/*
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Draw a line between marker points. Line will use style presets.
 */
Drupal.behaviors.openlayers_behavior_multilinestring = function(context) {
  var data = $(context).data('openlayers');
  if (data && data.map.behaviors['openlayers_behavior_multilinestring']) {
    var map = data.openlayers;
    layers = data.map.layers;
    // Only apply lines to selected layers.
    for (layerID in data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringLayers']) {
      if(data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringLayers'][layerID]) {
        var layer = data.map.layers[layerID];
        var labelLayer;
        if(data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringStyleGroup_' + layerID]['labelLayer_' + layerID]) {
          labelLayer = Drupal.t(data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringStyleGroup_' + layerID]['labelLayer_' + layerID]);
        }
        else {
          labelLayer = Drupal.t("Path");
        }

        // Load the default style for the layer if a custom style has not been set.
        var lineToStyle;
          // Get name of current data layer, if it has been set.
        if(data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringStyleGroup_' + layerID]['lineStyle_' + layerID] != 0) {
          lineToStyle = data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringStyleGroup_' + layerID]['lineStyle_' + layerID];
        }
        else {
          lineToStyle = 'default';
        }

        // Group features by an attribute.

        if(data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringStyleGroup_' + layerID]['groupingAttribute_' + layerID] !== '') {
          var groupingAttribute = data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringStyleGroup_' + layerID]['groupingAttribute_' + layerID];
          // Create array of similar features.
          var groupedFeatures = Array();
          for (var i in layer.features) {
            // If there is a value for the attribute, add the group to the array.
            if(typeof layer.features[i]["attributes"][groupingAttribute] == 'string') {
              groupedFeatures.push(layer.features[i]["attributes"][groupingAttribute]);
            }
          }
          // Remove duplicate groups.
          groupedFeatures = multipleArray(groupedFeatures);
          var vectorLayer;
          var points;
          var projection;
          var groupCounter;
          // For each group, draw a line connecting 2 or more features.


          for (var group in groupedFeatures) {
            groupCounter = 1;
            // Label group name here, make it available to popup controller.
            labelLayer = Drupal.t(groupedFeatures[group]);

            vectorLayer = new OpenLayers.Layer.Vector(labelLayer);
            // Layer will be visible by default.
            vectorLayer.visibility = true;
            // @TODO: Alternatively, use attribute as option in the layer name.
            vectorLayer.displayInLayerSwitcher = false;

            points = new Array();
            // Build array of all the features in this group.

            var groupFeatures = new Array();
            projection = layer.projection;
            for (var k in layer.features) {
              if(layer.features[k]["attributes"][groupingAttribute] == groupedFeatures[group]) {
                layer.features[k]["attributes"]["groupCounter"] = groupCounter;

                // Store information about the other items in the group.
                groupFeatures.push(layer.features[k]);

                var point = layer.features[k]['wkt'];
                var geometry = new OpenLayers.Geometry.fromWKT(point);
                geometry.transform(projection, map.getProjectionObject());
                points.push(geometry);

                // Store information about the other items in the group.
                groupFeatures.push(geometry);

                groupCounter++;
              }
            }
            // Once the list of all the features in the group is built,
            // add it to each feature in the group.
            k = 0;
            for (k in layer.features) {
              if(layer.features[k]["attributes"][groupingAttribute] == groupedFeatures[group]) {
                layer.features[k]["attributes"]["groupFeatures"] = groupFeatures;
              }
            }
            // Only draw lines if there is more than one point.
            if(points.length > 1) {
              var styleMap = Drupal.openlayers.getStyleMap(data.map, layerID);
              var lineString = new OpenLayers.Geometry.LineString(points);
              // @TODO See why lineToStyle isn't defaulting to default.
              if(styleMap.styles[lineToStyle] !== undefined) {
                var lineFeature = new OpenLayers.Feature.Vector(lineString, null, styleMap.styles[lineToStyle]['defaultStyle']);
                vectorLayer.addFeatures(lineFeature);
                vectorLayer.parentLayer = layerID;
                map.addLayer(vectorLayer);
              }
            }

          }
        }
        else {
          // @TODO Why this?
          var vectorLayer = new OpenLayers.Layer.Vector(labelLayer);
          // Suppress layer in layer switcher if field is left empty.
          if(labelLayer == Drupal.t('Path')) {
            vectorLayer.displayInLayerSwitcher = false;
          }
          var points = new Array();
          var projection = layer.projection;
          for (var i in layer.features) {
            var point = layer.features[i]['wkt'];
            var geometry = new OpenLayers.Geometry.fromWKT(point);
            geometry.transform(projection, map.getProjectionObject());
            points.push(geometry);
          }
          var styleMap = Drupal.openlayers.getStyleMap(data.map, layerID);
          var lineString = new OpenLayers.Geometry.LineString(points);
          var lineFeature = new OpenLayers.Feature.Vector(lineString, null, styleMap.styles[lineToStyle]['defaultStyle']);
          vectorLayer.addFeatures(lineFeature);
          //vectorLayer.parentLayer = layerID;
          map.addLayer(vectorLayer);
        }
      }
    }
  }

  // @TODO Strip out arrays that only had one element.
  // Adds new multipleArray values to a temporary array.
  // Snippet - http://www.developersnippets.com/2008/10/30/remove-duplicates-from-array-using-javascript/
  function multipleArray(a) {
    temp = new Array();
    for(i=0; i<a.length; i++) {
      if(!contains(temp, a[i])) {
        temp.length+=1;
        temp[temp.length-1] = a[i];
      }
    }
    return temp;
  }

  // Check for the Uniqueness
  function contains(a, e) {
    for (j=0; j < a.length; j++) {
      if (a[j] == e) {
        return true;
      }
    }
    return false;
  }
}
