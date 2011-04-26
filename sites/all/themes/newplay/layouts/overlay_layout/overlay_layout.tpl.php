<?php
/**
 * @file
 *
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['info']: Content in the top row.
 *   - $content['feed_left']: Content in the left column.
 *   - $content['feed_middle']: Content in the middle column.
 *   - $content['feed_right']: Content in the right column.
 *   - $content['events']: Content in the bottom row.
 *   - $content['artists']
 *   - $content['plays']
 */
?>
<div class="panel-display panel-overlay clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  
  <?php if ($content['main']): ?>
    <div class="panel-panel panel-col-top panel-overlay-main">
      <div class="inside"><?php print $content['main']; ?></div>
    </div>    
  <?php endif ?>
  
  <?php if ($content['links']): ?>
    <div class="panel-panel panel-col-top panel-overlay-links">
      <div class="inside"><?php print $content['links']; ?></div>
    </div>    
  <?php endif ?>
  
  <div class="additional-info">
    <?php if ($content['info']): ?>
      <h2 class="additional-info-title additional-info-title-info">Info</h2>
      <div class="panel-panel panel-overlay-info panel-overlay-section">
        <div class="inside"><?php print $content['info']; ?></div>
      </div>    
    <?php endif ?>
  
    <?php if ($content['feed_left'] || $content['feed_middle'] || $content['feed_right'] || $content['feeds']): ?>
      <h2 class="additional-info-title additional-info-title-feeds">Feeds</h2>
      <div id="feeds-wrapper" class="panel-panel panel-col-top panel-overlay-feeds panel-overlay-section">
        <div class="inside"><?php print $content['feeds']; ?></div>
      </div>    
    <?php endif ?>
  
    <?php if ($content['events']): ?>
      <h2 class="additional-info-title additional-info-title-events">Related Events</h2>
      <div class="panel-panel panel-col-top panel-overlay-events panel-overlay-section">
        <div class="inside"><?php print $content['events']; ?></div>
      </div>    
    <?php endif ?>

    <?php if ($content['organizations']): ?>
      <h2 class="additional-info-title additional-info-title-organizations">Related Organizations</h2>
      <div class="panel-panel panel-col-top panel-overlay-orgs panel-overlay-section">
        <div class="inside"><?php print $content['organizations']; ?></div>
      </div>    
    <?php endif ?>
  
  
    <?php if ($content['artists']): ?>
      <h2 class="additional-info-title additional-info-title-artists">Artists</h2>
      <div class="panel-panel panel-overlay-artists panel-overlay-section">
        <div class="inside"><?php print $content['artists']; ?></div>
      </div>    
    <?php endif ?>

    <?php if ($content['plays']): ?>
      <h2 class="additional-info-title additional-info-title-plays">Related Plays</h2>
      <div class="panel-panel panel-col-bottom panel-overlay-plays panel-overlay-section">
        <div class="inside"><?php print $content['plays']; ?></div>
      </div>    
    <?php endif ?>


  </div>
</div>
