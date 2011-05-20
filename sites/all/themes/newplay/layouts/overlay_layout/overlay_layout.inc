<?php
// $Id: threecol_25_50_25_stacked.inc,v 1.1.2.3 2010/06/22 15:54:24 merlinofchaos Exp $

// Plugin definition
$plugin = array(
  'title' => t('Overlay Sections'),
  'category' => t('Custom'),
  'icon' => 'overlay_layout.png',
  'theme' => 'overlay_layout',
  'panels' => array(
    'title' => t('Title'),
    'main' => t('Main'),
    'links' => t('Links'),
    'info' => t('Info Section'),
    'feeds' => t('Main Feed column'),
    'events' => t('Events Section'),
    'organizations' => t('Related Organizations Section'),
    'artists' => t('Artists Section'),
    'plays' => t('Plays Section'),
  ),
);
