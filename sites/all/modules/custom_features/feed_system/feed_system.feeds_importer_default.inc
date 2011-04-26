<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function feed_system_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'blog_feed';
  $feeds_importer->config = array(
    'name' => 'Blog Feed',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'blog_post',
        'update_existing' => 0,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'title',
            'target' => 'field_feed_item_headline',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'tags',
            'target' => 'taxonomy:2',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'author_name',
            'target' => 'field_blog_author',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => 'blog_feed',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['blog_feed'] = $feeds_importer;
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'blog_feed_v2';
  $feeds_importer->config = array(
    'name' => 'Blog Feed v2',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'auto_detect_feeds' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'blog_post',
        'update_existing' => 0,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => TRUE,
          ),
          4 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => TRUE,
          ),
          5 => array(
            'source' => 'title',
            'target' => 'field_feed_item_headline',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'author_name',
            'target' => 'field_blog_author',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'tags',
            'target' => 'taxonomy:2',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'url',
            'target' => 'field_blog_orig_url:url',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'parent:uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 0,
        'author' => 0,
      ),
    ),
    'content_type' => 'blog_feed',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['blog_feed_v2'] = $feeds_importer;
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'photo_feed';
  $feeds_importer->config = array(
    'name' => 'Photo Feed',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'photo',
        'update_existing' => 0,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'title',
            'target' => 'field_feed_item_headline',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'url',
            'target' => 'field_photo_embed',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'parent:uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 0,
        'author' => 0,
      ),
    ),
    'content_type' => 'photo_feed',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['photo_feed'] = $feeds_importer;
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'twitter_feed';
  $feeds_importer->config = array(
    'name' => 'Twitter Feed',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'twitter_item',
        'update_existing' => 0,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => TRUE,
          ),
          4 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => TRUE,
          ),
          5 => array(
            'source' => 'description',
            'target' => 'field_feed_item_headline',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'author_name',
            'target' => 'field_feed_item_author',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'url',
            'target' => 'field_feed_item_orig_url:url',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'parent:uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 0,
        'author' => 0,
      ),
    ),
    'content_type' => 'twitter_feed',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['twitter_feed'] = $feeds_importer;
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'video_feed';
  $feeds_importer->config = array(
    'name' => 'Video Feed',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'video',
        'update_existing' => 0,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => TRUE,
          ),
          4 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => TRUE,
          ),
          5 => array(
            'source' => 'title',
            'target' => 'field_feed_item_headline',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'description',
            'target' => 'field_video_body',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'url',
            'target' => 'field_video_embed',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'parent:uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 0,
        'author' => 0,
      ),
    ),
    'content_type' => 'video_feed',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['video_feed'] = $feeds_importer;
  return $export;
}
