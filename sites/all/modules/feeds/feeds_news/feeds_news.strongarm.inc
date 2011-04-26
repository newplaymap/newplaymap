<?php

/**
 * Implementation of hook_strongarm().
 */
function feeds_news_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_feed';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '-1',
    'comment_settings' => '1',
    'menu' => '-3',
    'path' => '0',
  );

  $export['content_extra_weights_feed'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_feed_item';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '-1',
    'comment_settings' => '1',
    'menu' => '-3',
    'path' => '0',
  );

  $export['content_extra_weights_feed_item'] = $strongarm;
  return $export;
}
