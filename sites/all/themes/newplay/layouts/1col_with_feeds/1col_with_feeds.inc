<?php
// $Id: threecol_25_50_25_stacked.inc,v 1.1.2.3 2010/06/22 15:54:24 merlinofchaos Exp $

// Plugin definition
$plugin = array(
  'title' => t('One Column wih Feeds area'),
  'category' => t('Custom'),
  'icon' => '1col_with_feeds.png',
  'theme' => '1col_with_feeds',
  // 'css' => '1col_with_feeds.css',
  'panels' => array(
    'top' => t('Top'),
    'middle' => t('Middle column'),
    'feed_left' => t('Left Feed column'),
    'feed_middle' => t('Middle Feed column'),
    'feed_right' => t('Right Feed column'),
    'bottom' => t('Bottom'),
  ),
);
