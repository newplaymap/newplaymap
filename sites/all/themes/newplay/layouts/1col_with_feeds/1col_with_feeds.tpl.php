<?php
/**
 * @file
 * Template for a 3 column panel layout.
 *
 * This template provides a three column 25%-50%-25% panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['feed_left']: Content in the left column.
 *   - $content['feed_middle']: Content in the middle column.
 *   - $content['feed_right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-display panel-1col-with-feeds clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-panel panel-col-top">
      <div class="inside"><?php print $content['top']; ?></div>
    </div>    
  <?php endif ?>
  
  <div class="panel-panel panel-col-middle">
    <div><?php print $content['middle']; ?></div>
  </div>

  <div id="feeds-wrapper">
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

  <?php if ($content['bottom']): ?>
    <div id="panel-default-overlay" class="panel-panel panel-col-bottom"><div class="close-btn"></div>
      <div class="inside"><?php print $content['bottom']; ?></div>
    </div>    
  <?php endif ?>
</div>
