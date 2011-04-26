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
 *   - $content['artists']: Content in the bottom row.
 */
?>
<div class="panel-display panel-overlay panel-overlay-orgs clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  
  <?php if ($content['main']): ?>
    <div class="panel-panel panel-col-top panel-overlay-main">
      <div class="inside"><?php print $content['main']; ?></div>
    </div>    
  <?php endif ?>
  
  <div class="additional-info">
    <?php if ($content['info']): ?>
      <h2>Info</h2>
      <div class="panel-panel panel-overlay-info panel-overlay-section">
        <div class="inside"><?php print $content['info']; ?></div>
      </div>    
    <?php endif ?>
  
    <?php if ($content['feed_left'] || $content['feed_middle'] || $content['feed_right']): ?>
      <h2>Feeds</h2>
      <div id="feeds-wrapper" class="panel-panel panel-col-top panel-overlay-feeds panel-overlay-section">
        <div class="panel-panel panel-col-first">
          <div class="inside"><?php print $content['feed_left']; ?></div>
        </div>

        <div class="panel-panel panel-col">
          <div class="inside"><?php print $content['feed_middle']; ?></div>
        </div>

        <div class="panel-panel panel-col-last">
          <div class="inside"><?php print $content['feed_right']; ?></div>
        </div>
      </div>    
    <?php endif ?>
  
    <?php if ($content['events']): ?>
      <h2>Events</h2>
      <div class="panel-panel panel-col-top panel-overlay-events panel-overlay-section">
        <div class="inside"><?php print $content['events']; ?></div>
      </div>    
    <?php endif ?>

    <?php if ($content['organizations']): ?>
      <h2>Related Organizations</h2>
      <div class="panel-panel panel-col-top panel-overlay-orgs panel-overlay-section">
        <div class="inside"><?php print $content['organizations']; ?></div>
      </div>    
    <?php endif ?>
  
  
    <?php if ($content['artists']): ?>
      <h3>Artists</h3>
      <div class="panel-panel panel-col-bottom panel-overlay-artists panel-overlay-section">
        <div class="inside"><?php print $content['artists']; ?></div>
      </div>    
    <?php endif ?>
  </div>
</div>
