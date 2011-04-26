<?php
// $Id: threecol_25_50_25_stacked.inc,v 1.1.2.3 2010/06/22 15:54:24 merlinofchaos Exp $

// Plugin definition
$plugin = array(
  'title' => t('Overlay Sections for Organization'),
  'category' => t('Custom'),
  'icon' => 'overlay_org.png',
  'theme' => 'overlay_org',
  'panels' => array(
    'main' => t('Main'),
    'info' => t('Info Section'),
    'feed_left' => t('Left Feed column'),
    'feed_middle' => t('Middle Feed column'),
    'feed_right' => t('Right Feed column'),
    'events' => t('Events Section'),
    'organizations' => t('Related Organizations Section'),
    'artists' => t('Artists Section'),
  ),
);
