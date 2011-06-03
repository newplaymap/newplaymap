// $Id$

/**
 * Global variables to help with scope
 *
 * TODO: Move this to a better place, like the map data().
 */
Drupal.openlayers = Drupal.openlayers || {};
Drupal.openlayers.popup = Drupal.openlayers.popup || {};
Drupal.openlayers.popup.popupSelect = Drupal.openlayers.popup.popupSelect || {};
Drupal.openlayers.popup.selectedFeature = Drupal.openlayers.popup.selectedFeature || {};
Drupal.openlayers.loaded = 0;
/**
 * Javascript Drupal Theming function for inside of Popups
 *
 * To override
 *
 * @param feature
 *  OpenLayers feature object
 * @return
 *  Formatted HTML
 */
Drupal.theme.prototype.openlayersNewPlayPopup = function(feature) {
  var output =
    '<div class="popup-container">' + 
      '<div class="popup-inner"><div class="close-btn"></div>' + 
        '<div class="popup-content">' + 
          '<div class="openlayers-popup openlayers-popup-name">' + feature.attributes.name + '</div>' +
          '<div class="openlayers-popup openlayers-popup-description">' + feature.attributes.description + '</div>' + 
        '</div>' + 
      '</div>' + 
      '<div class="overlay"><div class="close-btn"></div><div class="node-content"></div></div>' + 
    '</div>';
  return output;
}

// Redoing the popup
/*
Drupal.theme.prototype.openlayersNewPlayPopup = function(feature) {
  var output =
    '<div class="popup-bubble-container">' + 
    '<div class="openlayers-popup openlayers-popup-name">' +
      feature.attributes.name +
    '</div>' +
    '<div class="openlayers-popup openlayers-popup-description">' +
      feature.attributes.description +
      '</div>' + 
    '</div>' +
    '<div class="popup-container"><div class="popup-inner">' + 
      '<div class="overlay"><div class="close-btn"></div><div class="node-content"></div></div></div>' 
    '</div>';

  return output;
}
*/




/**
 * OpenLayers New Play Map: Popup Interaction
 */
Drupal.behaviors.openlayers_newplay_behavior_popup_interaction = function(context) {
  // Only run this code on the first time the page loads.
  // Important because we trigger Drupal behaviors for the accordion, but
  // only want to do this once for map pages that load via ajax.
  
  // Activate close button for filter results.
  $('div#panel-default-overlay div.close-btn').click(function(){
    $('div#panel-default-overlay').hide();
    
    // Clear the page title
     Drupal.openlayers.popup.clearPageTitle()
  });

  if(Drupal.openlayers.loaded == 0) {
    // Store the context for later use.
    Drupal.openlayers.context = context;

    // From default OpenLayers popup functionality
    var layers, data = $(context).data('openlayers');
    if (data && data.map.behaviors['openlayers_newplay_behavior_popup_interaction']) {
      var map = data.openlayers;
      var options = data.map.behaviors['openlayers_newplay_behavior_popup_interaction'];
      var layers = new Array();
  
      // For backwards compatiability, if layers is not
      // defined, then include all vector layers
      if (typeof options.layers == 'undefined' || options.layers.length == 0) {
        layers = map.getLayersByClass('OpenLayers.Layer.Vector');
      }
      else {
        for (var i in options.layers) {
          var selectedLayer = map.getLayersBy('drupalID', options.layers[i]);
          if (typeof selectedLayer[0] != 'undefined') {
            layers.push(selectedLayer[0]);
          }
        }
      }  
      popupSelect = new OpenLayers.Control.SelectFeature(layers,
        {
          onSelect: function(feature) {Drupal.openlayers.popup.newPlayPopupSelect(feature, context); },
          onUnselect: function(feature) {Drupal.openlayers.popup.newPlayPopupUnSelect(feature, context); },
          clickout: false,
        }
      );
      map.addControl(popupSelect);
      popupSelect.activate();
      Drupal.openlayers.popup.popupSelect = popupSelect;

      // End default OpenLayers popup functionality.
      // On page load, if there is a hash path (from bookmarking, load the overlay.
      var hashPath = Drupal.openlayers.popup.jqueryAddressHashPath();
      if(hashPath !== '/') {
        // console.log("trying to load");
        //Drupal.openlayers.popup.loadMapNodePopup(hashPath);
      }

      // Adjust which elements are visible on page load.
      Drupal.openlayers.popup.homepageElementAdjust();

      // Setup jQuery Address.
      Drupal.openlayers.popup.setupjQueryAddress();

      // Add ajax processing to views results.
      Drupal.openlayers.popup.processViewsData();
    }
  }
  Drupal.openlayers.loaded++;
};
Drupal.openlayers.popup.processViewsData = function() {
  var processed = Drupal.openlayers.popup.ajaxLinks('ajax-popup-panel', 'div#panel-default-overlay a');
  if (processed == true) {
    // Whenever the popup is selected, read through all the links and load a new page.
    $('div#panel-default-overlay a.ajax-popup-panel').click(function() {
      Drupal.openlayers.popup.loadNewAddress($(this));
      return false;
    });
  }
};

/**
 * Adjust which elements are visible on page load.
 */
Drupal.openlayers.popup.homepageElementAdjust = function() {
  // Change the layout of the page, hiding and moving certain elements.
  $('div.openlayers-blockswitcher').hide();
  $('div.olControlAttribution').css('position', 'absolute');
  $('div.olControlAttribution').css('bottom', '5px');
  $('div.olControlAttribution').css('right', '15px');
  $('div.openlayers_map_fullscreen').addClass('homepage');
}

/**
 * On page load, setup jQuery Address
 * Requires Jquery 1.4.2
 * We steal address function from regular jQuery, and assigned it to jQuery14.
 * Whenever the address changes, trigger popup markers & load node.
 */
Drupal.openlayers.popup.setupjQueryAddress = function() {
  // When jQuery address determines that the address has changed.
  jQuery14.address.change(function(event) {
    var path = event.value;
    if(path !== undefined && path !== '/') {
      Drupal.openlayers.popup.loadMapNodePopup(path);
    }
    return false;
  });
};

/**
 * Pass a proper address to jQuery address.
 */
Drupal.openlayers.popup.loadNewAddress = function(element) {
  jQuery14.address.value(element.attr('href'));
  return false;
};

Drupal.openlayers.popup.clearAddress = function() {
  jQuery14.address.value('');
  return false;
}

/**
 * Process ajax links
 *
 * Add ajax-processed link to tags in given paths in the document.
 * Excludes: 
 *   /
 *   http:
 *   node/add
 *   node/xxx/edit
 *   admin
 */
Drupal.openlayers.popup.ajaxLinks = function(className, target) {
  $(target).each(function(){
    var path = $(this).attr('href');
    
    var cleanPath = Drupal.openlayers.popup.cleanDestination(path);
    if (cleanPath) {
      $(this).attr('href', cleanPath);
    }
    
    if(path !== undefined) {
      if(path.substr(0,5) === '/node') {
      }
      else if(path.substr(0,4) === 'node') {
      }
      else if(path.substr(0,7) === '/admin/') {
      }
      else if((path.substr(0,4) === 'http') || (path.substr(0,5) === '/http')) {
      }
      else if(path.length == 1) {
      }
      else {
        $(this).addClass(className);
      }
    }
  });
  return true;
};

/**
 * Get path from the hash path generaged by jQueryAddress
 */
Drupal.openlayers.popup.jqueryAddressHashPath = function() {
  if (window.location.hash) {
    var hash = window.location.hash;
    var hashSplit = hash.split("/");
    if(hashSplit[0] == '#') {
      hashSplit.shift();
      var path = '/' + hashSplit.join("/");
    }
    return path;
  }
  return false;
};


/**
 * Remove extra callback arguments from the destination query for edit links
 */
Drupal.openlayers.popup.cleanDestination = function(path) {
  if (path) {
    var pathSplit = path
      .replace('openlayers_newplay/load_node/', '')
      .replace('openlayers_newplay%2Fload_node%2F', '');
    return pathSplit;
  }
  return false;
};


/**
 * Perform all the actions that should happen when a full popup overlay should load.
 */
Drupal.openlayers.popup.loadMapNodePopup = function(path) {
  // console.log("laoding map node " + path);
  if(path !== undefined) {
    // Trigger popup & markers (hides bubble in our case.)
    var featureState = Drupal.openlayers.popup.triggerPopup(path);
    //console.log(featureState);
    // Zoom to features.
    // @TODO Test this really escapes properly.
    if(featureState !== undefined) {
      Drupal.openlayers.popup.featuresZoom(featureState);
    }
    // Load node content (ajax gets the node path)
    Drupal.openlayers.popup.loadNode(path);
  }
  if (featureState.featureFound === false) {
    Drupal.openlayers.popup.nonLocatedFeaturePopup(path);    
    Drupal.openlayers.popup.reloadPageNode(path);
  }
  return false;
};

Drupal.openlayers.popup.reloadPageNode = function(path) {
  window.location = Drupal.settings.basePath + '#' + path;

};

Drupal.openlayers.popup.nonLocatedFeaturePopup = function(path) {

  Drupal.openlayers.popup.popupSelect.unselectAll();

  var output =
    '<div class="popup-container popup-container-no-location">' + 
      '<div class="popup-inner"><div class="close-btn"></div>' + 
        '<div class="popup-content">' + 
          '<div class="openlayers-popup openlayers-popup-name"></div>' +
          '<div class="openlayers-popup openlayers-popup-description"></div>' + 
        '</div>' + 
      '</div>' + 
      '<div class="overlay"><div class="close-btn"></div><div class="node-content"></div></div>' + 
    '</div>';

  if ($('div.popup-container').length < 1) {
    $('div.openlayers-views-map').append(output);
  } else {
    $('div.popup-container').addClass('popup-container-no-location');
  }
  
  
  // Swap popup backgrounds.
  $('div.popup-container div.popup-inner').show().html('<div class="loading-wrapper"><img src="/sites/all/themes/newplay/images/spinner-72x72.gif" alt="' + Drupal.t("Loading") + '"/></div>');

  var processed = Drupal.openlayers.popup.ajaxLinks('ajax-overlay', 'div.popup-container div.overlay a');
  if (processed === true) {
    $('div.popup-container div.overlay a.ajax-overlay').click(function() {
      Drupal.openlayers.popup.loadNewAddress($(this));
      return false;
    });
  }

  // Create a close_btn click event.
  $('div.popup-container div.close-btn').click(function(){
     $('div.overlay').remove();
     Drupal.openlayers.popup.clearAddress()
     
     // Clear the page title
     Drupal.openlayers.popup.clearPageTitle()
  });

  // Remove the views results.
  $('div#panel-default-overlay').hide();


  // If user is navigating map, and clicks another popup, and there is a hashPath,
  // retrigger the node load sequence.
  var hashPath = Drupal.openlayers.popup.jqueryAddressHashPath();
  $('div.popup-container div.popup-content').show();
  $('div.popup-container div.overlay').hide();
  $('div.popup-container').show();

  // Only clear the address if we are not loading a new node & if it is not in a group
  // @TODO /* || feature.attributes.groupCounter > 1 */ - this was removed, but if something
  // special needs to happen to a group, it might need to be handled here.
  // if(feature.context === "nodeLoad") { 
  // }
  // else {
  //   Drupal.openlayers.popup.clearAddress();
  // }

};

/**
 * Based on a given path, search all the layers
 * and find features that have a url path 
 * (@TODO this would be the node path for the title because it is the name?)
 */
Drupal.openlayers.popup.triggerPopup  = function(path) {
  //console.log("trigger popup");
  var layers, data = $('div.openlayers-map').data('openlayers');
  var featureState = {featureFound: false};
  for (var layer in data.openlayers.layers) {
    var currentLayer = data.openlayers.layers[layer];
    // If popup has a counter_rendered value, have a look.
    // If the value is higher than any other value, close all the popups.
    var highestPopupNumber;
    highestPopupNumber = 0;
    var exactPopupMatch;

    popupSelect.unselectAll();

    // Read through features in this layer.
    for (var marker in currentLayer.features) {
      // If URL path for address matches the main path for the feature, select the feature.
      // @TODO Check in Chrome/Safari/IE
      var namePath = $(currentLayer.features[marker]["attributes"]["name"]).attr('href');

      // Ignore the queryString if it exists. Remove from namePath and path
      var namePathNoQuery = Drupal.openlayers.popup.groupPathRoot(namePath);
      var pathNoQuery = Drupal.openlayers.popup.groupPathRoot(path);

      if(currentLayer.features[marker]["attributes"] !== undefined) {
        if (namePathNoQuery === pathNoQuery) {
          var popupSelection;
          // Original path is an exact match
          if(namePath === path) {
            popupSelection = currentLayer.features[marker];
            featureState = Drupal.openlayers.popup.getFeatureState(featureState, popupSelection);
            return featureState;
          }
          else if (Number(highestPopupNumber) <= Number(marker)) {
            // @TODO This is triggering the ajax load sequence - which is good,
            // but we want it to wait to trigger that event until the very last one
            // so that multiple events are not called.
 
            popupSelection = currentLayer.features[marker];
            // Store the currently selected feature & layer.
            featureState = {
              layer: currentLayer,
              featureFound: true,
              data: data
            };
            highestPopupNumber = marker;
          }
        }
      }  // End location hash check.
    } // End features.
  } // End layers.
  featureState = Drupal.openlayers.popup.getFeatureState(featureState, popupSelection);
  return featureState;
};


/**
 * Given a selection, return an array of data about a feature.
 */
Drupal.openlayers.popup.getFeatureState = function(featureState, popupSelection){
  // Render the popup as selected after it has been found, if it exists.
  if (popupSelection !== undefined) {
    popupSelection.context = "nodeLoad";
    popupSelect.select(popupSelection);
    // Store the currently selected feature & layer.
    featureState.feature = popupSelection;
    featureState.featureFound = true;
  }
  return featureState;
}

Drupal.openlayers.popup.groupPathRoot = function(path){
  try {
    path = path.split('?');
    path = path[0];
  }
  catch (err) {
  }
  return path;
}

/**
 * Zoom to the features in a group.
 */
Drupal.openlayers.popup.featuresZoom = function(featureState) {
  if(featureState.data !== undefined) {
    var map = featureState.data.openlayers;
  }
  if(featureState.featureFound == true && featureState.feature !== undefined && featureState.layer !== undefined && featureState.data !== undefined) { 
    // If this feature belongs to a group
    if(featureState.feature.attributes.groupFeatures !== undefined) {
      var groupPointData = featureState.feature.attributes.groupFeatures;
      groupLayer = new OpenLayers.Layer.Vector(Drupal.t("groupFeatures"));
      // Layer will be visible by default.
      groupLayer.visibility = false;
      groupLayer.displayInLayerSwitcher = false;
      // Only draw lines if there are more than two points.
      if(groupPointData.length > 1) {
        var styleMap = Drupal.openlayers.getStyleMap(map, "groupFeatures");
        var lineString = new OpenLayers.Geometry.LineString(groupPointData);
        // @TODO See why lineToStyle isn't defaulting to default.
  
        var lineFeature = new OpenLayers.Feature.Vector(lineString);
        groupLayer.addFeatures(lineFeature);
        groupLayer.parentLayer = layerID;
        map.addLayer(groupLayer);
        groupExtent = groupLayer.getDataExtent();
        //console.log(groupExtent);
        if (groupExtent != null) {       
          //console.log(groupExtent.getWidth());
          // If unable to find width due to single point,
          // zoom in with point_zoom_level option.
          if (groupExtent.getWidth() == 0.0) {
           //console.log("zoom narrow");
            Drupal.openlayers.popup.groupZoomFeatures(featureState);
            return false;
          }
          else {
           // console.log("zoom group");
/*             groupExtent.right = groupExtent.right + 10000000; */
            Drupal.openlayers.popup.groupZoomFeatures(featureState);
/*             map.zoomToExtent(groupExtent); */
            return false;
          }
        }
      }
    }
  Drupal.openlayers.popup.groupZoomFeatures(featureState);
  } // data not empty
  return false;
};
/**
 * Center a point at a zoom level set in the settings.
 */
Drupal.openlayers.popup.groupZoomFeatures = function(featureState) {
  var map = featureState.data.openlayers;
  var groupZoom = featureState.data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringGroupZoom'];
  if (groupZoom !== undefined) {
    groupZoom = Number(groupZoom);
    var zoomCenter = featureState.feature.geometry.bounds.getCenterLonLat();
    map.setCenter(zoomCenter);
    //map.setCenter(zoomCenter, groupZoom, false, true);
  }
  return false;
}

/**
 * Load Node via ajax.
 * Uses the path from the click event.
 */
Drupal.openlayers.popup.loadNode = function(path) {
  // Add address to browser history.
  // $.address.value(link);
  $.ajax({
      url: Drupal.settings.basePath + "openlayers_newplay/load_node" + path,
      beforeSend: Drupal.openlayers.popup.nodeLoading,
      context: document.body,
      success: Drupal.openlayers.popup.displayNode,
      complete: Drupal.openlayers.popup.loadNodeComplete
    });
  return false;
};

/**
 * Display loading graphic.
 */
Drupal.openlayers.popup.nodeLoading = function (data) {
//console.log("nodeloading");
  // Remove feeds-wrapper on all pages except homepage when the node has been loaded.
  // (Tip: if we just hide it, then the accordion triggers the feeds wrapper & reopens feeds wrapper.)
  $('div#content-area > div.panel-1col-with-feeds > div#feeds-wrapper').remove();

  // Remove the views results.
  $('div#panel-default-overlay').hide();

  // Set fullscreen back to 80% height.
  $('div.openlayers_map_fullscreen').removeClass('homepage');

  // Swap popup backgrounds.
  $('div.popup-container div.popup-inner').html('<div class="loading-wrapper"><img src="/sites/all/themes/newplay/images/spinner-72x72.gif" alt="' + Drupal.t("Loading") + '"/></div>');
};

/**
 * Load ajax data.
 */
Drupal.openlayers.popup.displayNode = function(data) {
  // Control which part of the popup appears.
  $('div.popup-container div.popup-inner').hide();
  $('div.popup-container div.overlay').show();

  // Load data into correct region.
  $('div.popup-container div.overlay div.node-content').html(data);

  // Set the page title based on the new content
  Drupal.openlayers.popup.setPageTitle(data);

  // Customize layout.
  $('div.popup-container').css('height', 'auto');
  $('div.popup-container div.overlay').css('height', '100%');
  $('div.popup-container').css('overflow', 'auto');
  return false;
};

/**
 * On Node complete, do something.
 */
Drupal.openlayers.popup.loadNodeComplete = function (data) {
  // Execute Drupal attachBehaviors again after the node content
  // has been rendered in the node-content region of the popup.
  Drupal.attachBehaviors();
  //console.log("complete");
  var processed = Drupal.openlayers.popup.ajaxLinks('ajax-overlay', 'div.popup-container div.overlay a');
  if (processed === true) {
    $('div.popup-container div.overlay a.ajax-overlay').click(function() {
      Drupal.openlayers.popup.loadNewAddress($(this));
      return false;
    });
  }
  $('div.ui-widget-content').css('background', 'none');
  $('div.ui-widget-content').css('border', 'none');
};

/**
 * Popup selection. Implements & extends the main OpenLayers popup behavior.
 * Adds node loading & interactive markers & lines.
 */
Drupal.openlayers.popup.newPlayPopupSelect = function(feature, context) {

  // Remove extra div created for content without a corresponding map feature.
  $('div.openlayers-views-map div.popup-container-no-location').remove();

  var layers, data = $(context).data('openlayers');
  // Create FramedCloud popup.
  popup = new OpenLayers.Popup.FramedCloud(
    'popup',
    feature.geometry.getBounds().getCenterLonLat(),
    null,
    Drupal.theme('openlayersNewPlayPopup', feature),
    null,
    true,
    function (evt) {
      Drupal.openlayers.popup.popupSelect.unselect(
        Drupal.openlayers.popup.selectedFeature
      );
    }
  );


  // Assign popup to feature and map.
  feature.popup = popup;
  feature.layer.map.addPopup(popup);
  Drupal.openlayers.popup.selectedFeature = feature;
  // End normal popup behavior.

  // We have moved away from the normal OpenLayers popups to the point that it doesn't make sense to use them.
  // Creating new markup for popup.
  $('div.openlayers-views-map').prepend(Drupal.theme('openlayersNewPlayPopup', feature));
  // Create a close_btn click event.
  $('div.popup-container div.close-btn').click(function(){
    Drupal.openlayers.popup.popupSelect.unselect(Drupal.openlayers.popup.selectedFeature);
    Drupal.openlayers.popup.clearAddress();
    
    // Clear the page title
    Drupal.openlayers.popup.clearPageTitle()
  });
  // Hide original popup.
  $('div#popup').hide();
  // Remove the views results.
  $('div#panel-default-overlay').hide();
  // Process node content and add clickable ajax links.
  // Drupal.openlayers.popup.ajaxLinks('ajax-popup', 'div.popup-container div.popup-content a');
  var processed = Drupal.openlayers.popup.ajaxLinks('ajax-popup', 'div.popup-container div.popup-content a');
  if (processed == true) {
    // Whenever the popup is selected, read through all the links and load a new page.
    $('div.popup-container a.ajax-popup').click(function() {
      Drupal.openlayers.popup.loadNewAddress($(this));
      return false;
    });
  }

  // Read through each layer to reimplement all the styles.
  for (var layer in data.openlayers.layers) {
    Drupal.openlayers.popup.newPlayLayerStyle(data, feature, layer, true);
  }

  // If user is navigating map, and clicks another popup, and there is a hashPath,
  // retrigger the node load sequence.
  var hashPath = Drupal.openlayers.popup.jqueryAddressHashPath();
  $('div.popup-container div.popup-content').show();
  $('div.popup-container div.overlay').hide();
  $('div.popup-container').show();

  // Only clear the address if we are not loading a new node & if it is not in a group
  // @TODO /* || feature.attributes.groupCounter > 1 */ - this was removed, but if something
  // special needs to happen to a group, it might need to be handled here.
  if(feature.context === "nodeLoad") { 
  }
  else {
    Drupal.openlayers.popup.clearAddress();
  }

};

/**
 * This function is not quite right.
 */
Drupal.openlayers.popup.newPlayRedrawLayer = function(layer, layerOrder) {

  // Store the context for later use.
  var context = Drupal.openlayers.context;  
  var data = $(context).data('openlayers');
  
  // Read through each layer to reimplement all the styles.

  // Create & load styleMap options.
  var currentLayerID = layer["drupalID"];
  var currentStyleMap = Drupal.openlayers.getStyleMap(data.map, data.map.layer_styles[currentLayerID]);

  var newStyle = {};
  var newStyle = {
    'data': data,
    'currentLayer': layer,
    'currentStyleMap': currentStyleMap,
    'feature': feature,
    'currentLayerID': currentLayerID,
    'layer': layerOrder,
    'select': false
  };


  newStyle = Drupal.openlayers.popup.newPlayLineStylesSetup(newStyle);
  console.log(newStyle);
  
  if(newStyle.newStyleMapping !== undefined) {
    // http://dev.openlayers.org/releases/OpenLayers-2.6/doc/devdocs/files/OpenLayers/StyleMap-js.html
    newStyle["newStyleMapping"].addUniqueValueRules("default", "state", newStyle["lookup"]);
    newStyle["newStyleMapping"].addUniqueValueRules("select", "state", newStyle["lookup"]);
    layer.styleMap = newStyle["newStyleMapping"];
  }
    

  var multilineStyles = {};          
  multilineStyles.defaultFeatureStyle = data.map.layer_styles[currentLayerID];
  currentStyleMap = Drupal.openlayers.getStyleMap(data.map, multilineStyles.defaultFeatureStyle);
  var newStyleMap = new OpenLayers.StyleMap(currentStyleMap);
  // http://dev.openlayers.org/releases/OpenLayers-2.6/doc/devdocs/files/OpenLayers/StyleMap-js.html
  layer.styleMap = newStyleMap;
  layer.redraw();
};

Drupal.openlayers.popup.newPlayPopupUnSelect = function(feature, context) {
  //console.log("unselect");
  var layers, data = $(context).data('openlayers');
  // Remove popup if feature is unselected.
  feature.layer.map.removePopup(feature.popup); 
  feature.popup.destroy();
  feature.popup = null;
  // End normal popup behavior.

  // Remove extra div created for content without a corresponding map feature.
  $('div.openlayers-views-map div.popup-container-no-location').remove();

  // Remove any content from the popup.
  $('div.popup-container').remove();

  // Read through each layer to reimplement all the styles.
  for (var layer in data.openlayers.layers) {
    Drupal.openlayers.popup.newPlayLayerStyle(data, feature, layer, false);
  }
};


/**
 * For each layer, build interactive line style for the layer, and grouped elements in the layer.
 * select: Boolean
 *   This is true of the popup is selected, false if popup is unselected.
 */
Drupal.openlayers.popup.newPlayLayerStyle = function (data, feature, layer, select) {
  // Work with multilinestring behavior to show groups of nodes if selected.
  var currentLayer = data.openlayers.layers[layer];
  var currentLayerID = data.openlayers.layers[layer]["drupalID"];
  // Only apply styling to selected layers. If not selected, the layer will use the default Open Layers styles.
  var layerChecked = data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringLayers'][data.openlayers.layers[layer]["drupalID"]];

  // Create & load styleMap options.
  var currentStyleMap = Drupal.openlayers.getStyleMap(data.map, data.map.layer_styles[currentLayerID]);

  // Control the styles for grouped layers.
  // Custom styles
  var multilineStyles = {};

  // Load line styles for each layer selected in the Behavior settings.
  if(layerChecked == data.openlayers.layers[layer]["drupalID"] && layerChecked !== undefined) {
    var newStyle = {};
    var newStyle = {
      'data': data,
      'currentLayer': currentLayer,
      'currentStyleMap': currentStyleMap,
      'feature': feature,
      'currentLayerID': currentLayerID,
      'layer': layer,
      'select': select
    };

    // @TODO see if multiline settings are not already set up.
    if(multilineStyles.featuredStyle === undefined) {
    // Build style objects.
      newStyle = Drupal.openlayers.popup.newPlayLineStylesSetup(newStyle);
      // @TODO check pass by ref
      // Create new style states for markers.
      newStyle = Drupal.openlayers.popup.newPlayLineStylesMarkers(newStyle);
      newStyle = Drupal.openlayers.popup.newPlayLineStylesLines(newStyle);
    }
    if(newStyle.newStyleMapping !== undefined) {
      // http://dev.openlayers.org/releases/OpenLayers-2.6/doc/devdocs/files/OpenLayers/StyleMap-js.html
      newStyle["newStyleMapping"].addUniqueValueRules("default", "state", newStyle["lookup"]);
      newStyle["newStyleMapping"].addUniqueValueRules("select", "state", newStyle["lookup"]);
      currentLayer.styleMap = newStyle["newStyleMapping"];
      // If this layer includes selected elements, set it to top.
      var layerOnTop;

      if (feature.renderIntent == 'select' && feature.layer.drupalID == currentLayerID) {
        layerOnTop = true;
      }
      else {
        layerOnTop = false;
      }
      Drupal.openlayers.popup.reorderLayerFeatures(data, currentLayer, layerOnTop, select);
    }
  }
  else {
    Drupal.openlayers.popup.newPlayNormalStyles(data, currentLayer, currentLayerID, select);
  }
//Drupal.openlayers.popup.redrawLayers(data.openlayers.layers);
};

/**
 * Features can only change zIndex if they are rebuilt, you can't just change the stylemap.
 */
Drupal.openlayers.popup.reorderLayerFeatures = function(data, layer, layerOnTop, select) {
  /*
  console.log(layer);
  console.log(layerOnTop);
  console.log(select);
  */
  // Don't change the layer order on unselect.
  if (select === true) {
    // @TODO This is buggy.
    // For whatever reason, you can't set the layer with larger increments (or the lines will disappear.)
    // This does NOT always place correctly. If you click the popup or the overlay (especially loading
    // a group) it is triggering the popup, which figures out which popup should be loaded
    // and this doesn't agree with the code here. There's some piece of logic missing.
    // Right now this seems to reset, but then if you select the feature or the node load, it will adjust the layer.
    if(layerOnTop) {
      data.openlayers.setLayerIndex(layer, 1);
    }
    else {
      data.openlayers.setLayerIndex(layer, -1);
    } 
/*
    Option 2: Also doesn't quite work.
    data.openlayers.setLayerIndex(layer, 0);
    if(layerOnTop) {
      data.openlayers.raiseLayer(layer, 1);
    }
*/

  }
  else {
/*     data.openlayers.setLayerIndex(layer, -1); */
  }
  layer.redraw();
  return false;
};


/**
 * @TODO This function also doesn't need to be run everytime, the line styles need to be built for all features.
 * @TODO It also seems like this is a lot of redundant code, just to match up with Drupal settings.
 * The complication seems to mainly come from translating Drupal settings to OL style maps.
 *
 * And then on click, the state just needs to be set.
 *
 * currentLayerID: organizations_openlayers_2
 */
Drupal.openlayers.popup.newPlayLineStylesSetup = function(newStyle){
  var data = newStyle.data;
  var currentLayer = newStyle.currentLayer;
  var currentStyleMap = newStyle.currentStyleMap;
  var feature = newStyle.feature;
  var currentLayerID = newStyle.currentLayerID;
  var layer = newStyle.layer;
  var select = newStyle.select;

  // Build styleOptions only if the current layer is a real layer (not lines)
  if(data.openlayers.layers[layer]["drupalID"] == currentLayerID && currentLayerID !== undefined) {

    // Load up the style settings for the style for the current layer.
    var styleOptions = data.map.behaviors['openlayers_behavior_multilinestring']['multiLineStringStyleGroup_' + currentLayerID];

    // Mapping for styles.
    var lookup = {};

    // Mapping for styles.
    var multilineStyles = {
      "featuredStyle" : "default",
      "groupSelectedStyle" : "default",
      "groupDimmedStyle" : "default",
      "lineStyle" : "default",
      "lineStyleSelected" : "default"
    };
    if(styleOptions !== undefined) {
      if(styleOptions['featureStyleSelectedFeature_' + currentLayerID] !== "undefined") {
        multilineStyles.featuredStyle = styleOptions['featureStyleSelectedFeature_' + currentLayerID];
        lookup.featured = currentStyleMap.styles[multilineStyles.featuredStyle]['defaultStyle'];
      }
      if(styleOptions['featureStyleSelectedGroup_' + currentLayerID] !== "undefined") {
        multilineStyles.groupSelectedStyle = styleOptions['featureStyleSelectedGroup_' + currentLayerID];
        lookup.groupSelect = currentStyleMap.styles[multilineStyles.groupSelectedStyle]['defaultStyle'];
      }
      if(styleOptions['featureStyleDimmed_' + currentLayerID] !== "undefined") {
        multilineStyles.groupDimmedStyle = styleOptions['featureStyleDimmed_' + currentLayerID];
        lookup.dimmed = currentStyleMap.styles[multilineStyles.groupDimmedStyle]['defaultStyle'];
      }
      if(styleOptions['lineStyle_' + currentLayerID] !== "undefined") {
        multilineStyles.lineStyle = styleOptions['lineStyle_' + currentLayerID];
        lookup.line = currentStyleMap.styles[multilineStyles.lineStyle]['defaultStyle'];
      }
      if(styleOptions['lineStyleSelected_' + currentLayerID] !== "undefined") {
        multilineStyles.lineStyleSelected = styleOptions['lineStyleSelected_' + currentLayerID];
        lookup.lineSelected = currentStyleMap.styles[multilineStyles.lineStyleSelected]['defaultStyle'];
      }

      // Store the objects in the 2 different layer locations.
      data.map.layers[currentLayerID].multilineStyles = data.openlayers.layers[layer].multilineStyles = multilineStyles;
      data.map.layers[currentLayerID].lookup = data.openlayers.layers[layer].lookup = lookup;
      data.map.layers[currentLayerID].styleOptions = data.openlayers.layers[layer].styleOptions = styleOptions;
      data.map.layers[currentLayerID].parentLayerNumber = data.openlayers.layers[layer].parentLayerNumber = layer;
    }
  }
  return newStyle;
};

/**
 * This function takes the current layers and sets up the markers.
 */
Drupal.openlayers.popup.newPlayLineStylesMarkers = function(newStyle){
  var data = newStyle.data;
  var currentLayer = newStyle.currentLayer;
  var currentStyleMap = newStyle.currentStyleMap;
  var feature = newStyle.feature;
  var currentLayerID = newStyle.currentLayerID;
  var layer = newStyle.layer;
  var select = newStyle.select;

  var multilineStyles = data.map.layers[currentLayerID].multilineStyles;
  var lookup = data.map.layers[currentLayerID].lookup;
  var styleOptions = data.map.layers[currentLayerID].styleOptions;

  // Get layer's grouping attribute. We are reading a layer, which has several groups.
  // And really we are only interested in the currently selected group.
  // Because here we are just reading markers.
  var groupingAttribute = styleOptions['groupingAttribute_' + currentLayerID];
  var group;
 
  if(groupingAttribute !== '') {
    // Feature has a grouping id, which means that the layer is a line layer (custom generated, but still a layer.)
    // Name of current group of markers.
    group = feature["attributes"][groupingAttribute]; // (Example: value of the nid. This is initially set on map load. We are just reading it here.)
  }

  newStyle.groupingAttribute = groupingAttribute;
  newStyle.group = group;

  // If we are looking at the layer NOT of a line (each line is a 'group' originally based on an attribute)
  // This is the current layer?
  if (data.openlayers.layers[layer]["name"] == feature.layer.name) {
    multilineStyles.defaultFeatureStyle = data.map.layer_styles[currentLayerID];
    currentStyleMap = Drupal.openlayers.getStyleMap(data.map, multilineStyles.defaultFeatureStyle);
    lookup["default"] = currentStyleMap.styles[multilineStyles.defaultFeatureStyle]['defaultStyle'];

    // Read through features in this layer.
    // @TODO really, the groupingAttribute should be set on a layer by layer basis.

    for (var marker in currentLayer.features) {
      // Show current group's features at full opacity.
      if(currentLayer.features[marker]["attributes"][groupingAttribute] == group && currentLayer.features[marker]["attributes"][groupingAttribute] !== undefined) {
        currentLayer.features[marker]["attributes"]["state"] = "groupSelect";
        // Set all other layers to be dimmed.
      }
      else if ( currentLayer.features[marker]["attributes"][groupingAttribute] === undefined) {
        currentLayer.features[marker]["attributes"]["state"] = "default"; 
      }
      else {
        // If the current layer has groups, dim all the other features in that layer
        currentLayer.features[marker]["attributes"]["state"] = "dimmed";

        // as well as all the other features on the map.
        // If the selected features doesn't have a group at all, don't do any dimming.
      }
      if(select === false) {
        currentLayer.features[marker]["attributes"]["state"] = "default";
      }
    }
    if(select === true) {
      feature.attributes.state = "featured";
    }
  }
  else {
    multilineStyles.defaultFeatureStyle = data.map.layer_styles[currentLayerID];
    currentStyleMap = Drupal.openlayers.getStyleMap(data.map, multilineStyles.defaultFeatureStyle);
    lookup["default"] = currentStyleMap.styles[multilineStyles.defaultFeatureStyle]['defaultStyle'];

    // Read through features in this layer.
    // @TODO really, the groupingAttribute should be set on a layer by layer basis.

    for (var marker in currentLayer.features) {
      // Show current group's features at full opacity.
      if(currentLayer.features[marker]["attributes"][groupingAttribute] == group) {
        currentLayer.features[marker]["attributes"]["state"] = "dimmed";

        // Set all other layers to be dimmed.
      }
      else if(currentLayer.features[marker]["attributes"][groupingAttribute] != group) {
        currentLayer.features[marker]["attributes"]["state"] = "dimmed";
        // Set all other layers to be dimmed.
      }
      // @TODO If the parent layer..???
      else {
        // If the current layer has groups, dim all the other features in that layer
        currentLayer.features[marker]["attributes"]["state"] = "dimmed";
        // as well as all the other features on the map.
        // If the selected features doesn't have a group at all, don't do any dimming.
      }
      if(select === false) {
        currentLayer.features[marker]["attributes"]["state"] = "default";
      }
    }
    if(select === true) {
      feature.attributes.state = "featured";
    }

  }
  // Create and return a newStyle object
  newStyle.newStyleMapping = new OpenLayers.StyleMap(currentStyleMap);
  newStyle.lookup = lookup;
  return newStyle;
};

/**
 * This function rereads through all layers and sets up the lines.
 */
Drupal.openlayers.popup.newPlayLineStylesLines = function(newStyle){
  // @TODO - these are all just shortcuts for debugging.
  var data = newStyle.data;
  var currentLayer = newStyle.currentLayer;
  var currentStyleMap = newStyle.currentStyleMap;
  var feature = newStyle.feature;
  var currentLayerID = newStyle.currentLayerID;
  var layer = newStyle.layer;
  var select = newStyle.select;

  var multilineStyles = data.map.layers[currentLayerID].multilineStyles;
  var lookup = data.map.layers[currentLayerID].lookup;
  var styleOptions = data.map.layers[currentLayerID].styleOptions;
  var parentLayerNumber = data.map.layers[currentLayerID].parentLayerNumber;

  // Get layer's grouping attribute. We are reading a layer, which has several groups.
  // And really we are only interested in the currently selected group.
  // Because here we are just reading markers.
  var groupingAttribute = styleOptions['groupingAttribute_' + currentLayerID];
  var group;
 
  if(groupingAttribute !== ''){
    // Feature has a grouping id, which means that the layer is a line layer (custom generated, but still a layer.)
    // Name of current group of markers.
    group = feature["attributes"][groupingAttribute]; // (Example: value of the nid. This is initially set on map load. We are just reading it here.)
  }

  newStyle.groupingAttribute = groupingAttribute;
  newStyle.group = group;

  // Read through each layer
  for (var renderedLayer in data.openlayers.layers) {
    // If the layer says its parent's layer is the same as the current Layer being processed
    if(data.openlayers.layers[renderedLayer].parentLayer == currentLayerID) {
      // Read through each marker.
      for (var marker in data.openlayers.layers[renderedLayer]["features"]) {
        // data.openlayers.layers[renderedLayer]["features"][marker]["style"] = data.openlayers.layers[parentLayerNumber].lookup.lineSelected;
        // If we are selecting the line, and it is the current group, set the line styles
        if(select === true && data.openlayers.layers[renderedLayer].name == group) {
          data.openlayers.layers[renderedLayer]["features"][marker]["style"] = data.openlayers.layers[parentLayerNumber].lookup.lineSelected;
        }
        else if(select === false) {
          data.openlayers.layers[renderedLayer]["features"][marker]["style"] = data.openlayers.layers[parentLayerNumber].lookup.line;
        }
      }
    }
  }
  return newStyle;
};

/**
 * @TODO This is as a backup, I'm not sure this will still work properly.
 */
Drupal.openlayers.popup.newPlayNormalStyles = function(data, currentLayer, currentLayerID){
  var multilineStyles = {};
  multilineStyles.defaultFeatureStyle = data.map.layer_styles[currentLayerID];
  currentStyleMap = Drupal.openlayers.getStyleMap(data.map, multilineStyles.defaultFeatureStyle);
  var newStyleMap = new OpenLayers.StyleMap(currentStyleMap);
  // http://dev.openlayers.org/releases/OpenLayers-2.6/doc/devdocs/files/OpenLayers/StyleMap-js.html
  currentLayer.styleMap = newStyleMap;
  currentLayer.redraw();
};

/**
 * Helper function for setting the page title when content is loaded
 *
 * @param data
 *  string of html from ajax loaded content
 */
Drupal.openlayers.popup.setPageTitle = function(data) {
  var oldPageTitle = $('title').text();
  var newPageTitle = $('<span></span>').html($(data).get(0)); // @TODO: Figure out how to get the title without using this span
  newPageTitle = $(newPageTitle).find('.panel-overlay .pane-node-title .pane-content').html()
  
  $('meta[property="og:title"]').attr('content', newPageTitle + ' | ' + oldPageTitle);
  $('title').text(newPageTitle + ' | ' + oldPageTitle);
}
 
/**
 * Helper function to clear page title when popup is closed
 */
Drupal.openlayers.popup.clearPageTitle = function() {
  // Clear the page title
  $('meta[property="og:title"]').attr('content', 'New Play Map');
   $('title').text('New Play Map');
}
