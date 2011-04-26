<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function feed_system_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer feeds
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: clear blog_feed_v2 feeds
  $permissions['clear blog_feed_v2 feeds'] = array(
    'name' => 'clear blog_feed_v2 feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: clear feed feeds
  $permissions['clear feed feeds'] = array(
    'name' => 'clear feed feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: clear photo_feed feeds
  $permissions['clear photo_feed feeds'] = array(
    'name' => 'clear photo_feed feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: clear twitter_feed feeds
  $permissions['clear twitter_feed feeds'] = array(
    'name' => 'clear twitter_feed feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: clear video_feed feeds
  $permissions['clear video_feed feeds'] = array(
    'name' => 'clear video_feed feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: create blog_feed content
  $permissions['create blog_feed content'] = array(
    'name' => 'create blog_feed content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create blog_post content
  $permissions['create blog_post content'] = array(
    'name' => 'create blog_post content',
    'roles' => array(),
  );

  // Exported permission: create photo content
  $permissions['create photo content'] = array(
    'name' => 'create photo content',
    'roles' => array(),
  );

  // Exported permission: create photo_feed content
  $permissions['create photo_feed content'] = array(
    'name' => 'create photo_feed content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create twitter_feed content
  $permissions['create twitter_feed content'] = array(
    'name' => 'create twitter_feed content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create twitter_item content
  $permissions['create twitter_item content'] = array(
    'name' => 'create twitter_item content',
    'roles' => array(),
  );

  // Exported permission: create video content
  $permissions['create video content'] = array(
    'name' => 'create video content',
    'roles' => array(),
  );

  // Exported permission: create video_feed content
  $permissions['create video_feed content'] = array(
    'name' => 'create video_feed content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any blog_feed content
  $permissions['delete any blog_feed content'] = array(
    'name' => 'delete any blog_feed content',
    'roles' => array(),
  );

  // Exported permission: delete any blog_post content
  $permissions['delete any blog_post content'] = array(
    'name' => 'delete any blog_post content',
    'roles' => array(),
  );

  // Exported permission: delete any photo content
  $permissions['delete any photo content'] = array(
    'name' => 'delete any photo content',
    'roles' => array(),
  );

  // Exported permission: delete any photo_feed content
  $permissions['delete any photo_feed content'] = array(
    'name' => 'delete any photo_feed content',
    'roles' => array(),
  );

  // Exported permission: delete any twitter_feed content
  $permissions['delete any twitter_feed content'] = array(
    'name' => 'delete any twitter_feed content',
    'roles' => array(),
  );

  // Exported permission: delete any twitter_item content
  $permissions['delete any twitter_item content'] = array(
    'name' => 'delete any twitter_item content',
    'roles' => array(),
  );

  // Exported permission: delete any video content
  $permissions['delete any video content'] = array(
    'name' => 'delete any video content',
    'roles' => array(),
  );

  // Exported permission: delete any video_feed content
  $permissions['delete any video_feed content'] = array(
    'name' => 'delete any video_feed content',
    'roles' => array(),
  );

  // Exported permission: delete own blog_feed content
  $permissions['delete own blog_feed content'] = array(
    'name' => 'delete own blog_feed content',
    'roles' => array(),
  );

  // Exported permission: delete own blog_post content
  $permissions['delete own blog_post content'] = array(
    'name' => 'delete own blog_post content',
    'roles' => array(),
  );

  // Exported permission: delete own photo content
  $permissions['delete own photo content'] = array(
    'name' => 'delete own photo content',
    'roles' => array(),
  );

  // Exported permission: delete own photo_feed content
  $permissions['delete own photo_feed content'] = array(
    'name' => 'delete own photo_feed content',
    'roles' => array(),
  );

  // Exported permission: delete own twitter_feed content
  $permissions['delete own twitter_feed content'] = array(
    'name' => 'delete own twitter_feed content',
    'roles' => array(),
  );

  // Exported permission: delete own twitter_item content
  $permissions['delete own twitter_item content'] = array(
    'name' => 'delete own twitter_item content',
    'roles' => array(),
  );

  // Exported permission: delete own video content
  $permissions['delete own video content'] = array(
    'name' => 'delete own video content',
    'roles' => array(),
  );

  // Exported permission: delete own video_feed content
  $permissions['delete own video_feed content'] = array(
    'name' => 'delete own video_feed content',
    'roles' => array(),
  );

  // Exported permission: edit any blog_feed content
  $permissions['edit any blog_feed content'] = array(
    'name' => 'edit any blog_feed content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any blog_post content
  $permissions['edit any blog_post content'] = array(
    'name' => 'edit any blog_post content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any photo content
  $permissions['edit any photo content'] = array(
    'name' => 'edit any photo content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any photo_feed content
  $permissions['edit any photo_feed content'] = array(
    'name' => 'edit any photo_feed content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any twitter_feed content
  $permissions['edit any twitter_feed content'] = array(
    'name' => 'edit any twitter_feed content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any twitter_item content
  $permissions['edit any twitter_item content'] = array(
    'name' => 'edit any twitter_item content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any video content
  $permissions['edit any video content'] = array(
    'name' => 'edit any video content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit any video_feed content
  $permissions['edit any video_feed content'] = array(
    'name' => 'edit any video_feed content',
    'roles' => array(
      '0' => 'site admin',
      '1' => 'website developer',
    ),
  );

  // Exported permission: edit own blog_feed content
  $permissions['edit own blog_feed content'] = array(
    'name' => 'edit own blog_feed content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own blog_post content
  $permissions['edit own blog_post content'] = array(
    'name' => 'edit own blog_post content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own photo content
  $permissions['edit own photo content'] = array(
    'name' => 'edit own photo content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own photo_feed content
  $permissions['edit own photo_feed content'] = array(
    'name' => 'edit own photo_feed content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own twitter_feed content
  $permissions['edit own twitter_feed content'] = array(
    'name' => 'edit own twitter_feed content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own twitter_item content
  $permissions['edit own twitter_item content'] = array(
    'name' => 'edit own twitter_item content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own video content
  $permissions['edit own video content'] = array(
    'name' => 'edit own video content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own video_feed content
  $permissions['edit own video_feed content'] = array(
    'name' => 'edit own video_feed content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: import blog_feed_v2 feeds
  $permissions['import blog_feed_v2 feeds'] = array(
    'name' => 'import blog_feed_v2 feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: import feed feeds
  $permissions['import feed feeds'] = array(
    'name' => 'import feed feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: import photo_feed feeds
  $permissions['import photo_feed feeds'] = array(
    'name' => 'import photo_feed feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: import twitter_feed feeds
  $permissions['import twitter_feed feeds'] = array(
    'name' => 'import twitter_feed feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: import video_feed feeds
  $permissions['import video_feed feeds'] = array(
    'name' => 'import video_feed feeds',
    'roles' => array(
      '0' => 'website developer',
    ),
  );

  // Exported permission: view imagecache feed_thumbnail
  $permissions['view imagecache feed_thumbnail'] = array(
    'name' => 'view imagecache feed_thumbnail',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
