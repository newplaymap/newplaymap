Cufon.replace('#site-name', { fontFamily: 'Feltpen' });
Cufon.replace('#content-header .title', { fontFamily: 'Feltpen' });
Cufon.replace('#explore-filters h2.overlay-title', { fontFamily: 'Feltpen' });

/**
 * Cufon declarations to be called whenever new content is added to the page
 * Especially helpful for styling the overlays
 */

Drupal.behaviors.newplayCufon = function() {
  Cufon.replace('.panel-overlay .pane-node-title', { fontFamily: 'Feltpen' });
  Cufon.replace('#panel-default-overlay h2.overlay-title', { fontFamily: 'Feltpen' });
}