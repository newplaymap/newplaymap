<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function feed_system_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function feed_system_imagecache_default_presets() {
  $items = array(
    'feed_thumbnail' => array(
      'presetname' => 'feed_thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '228',
            'height' => '165',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function feed_system_node_info() {
  $items = array(
    'blog_feed' => array(
      'name' => t('Blog Feed'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => t('<ol>
<li>To get your blog feed URL, go to the web address for the blog.</li>
<li>If you\'re using Mozilla Firefox, you may click the blue feed icon in the left side of the browser\'s location bar to get the feed URL.</li>
<li>If you\'re using another browser, often there will be a link to the "RSS" feed or <strong>Subscribe to RSS</strong> link somewhere on the page
<li><strong>Click on this link</strong> and then <strong>copy the resulting URL from your browser\'s location bar</strong>. The URL should be something like http://yourblogaddress.com/feeds/posts/default or http://yourblogaddress.com/feed</li>
<li><strong>Paste this URL</strong> into the Feed URL field below</li>
</ol>'),
    ),
    'blog_post' => array(
      'name' => t('Blog Post'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'photo' => array(
      'name' => t('Photo'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'photo_feed' => array(
      'name' => t('Photo Feed'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => t('<ol>
<li><strong>For Flickr:</strong> To get your video feed URL on Flickr, go to the URL for your Flickr user, such as <strong>http://www.flickr.com/photos/myuser</strong></li>
<li>If you\'re using Mozilla Firefox, you may <strong>click the blue feed icon</strong> in the left side of the browser\'s location bar to get the feed URL<li>
<li>If you\'re using another browser, scroll to the bottom of the Flickr user page, then find the link to "Latest" where it says <strong>Subscribe to X\'s photostream</strong></li>
<li><strong>Click on this link</strong> and then <strong>copy the resulting URL from your browser\'s location bar</strong></li>
</li><strong>Paste this link</strong> into the Feed URL field below</li>
</ol>'),
    ),
    'twitter_feed' => array(
      'name' => t('Twitter Feed'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => t('<ol>
<li><strong>Enter feed URL.</strong> To get your Twitter feed URL go to <a href="http://search.twitter.com" title="Twitter Advanced Search">http://search.twitter.com</a> and type in your username or a relevant hashtag. You should get a list of results relating to the search term you entered.</li>
<li>In the upper right of the sidebar,look for a link entitled <strong>Feed for this query</strong></li>
<li>Right-click or Control-click on this link, select <strong>Copy this link</strong>, then <strong>Paste</strong> the URL into the URL field below</li>
</ol>'),
    ),
    'twitter_item' => array(
      'name' => t('Twitter Item'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'video' => array(
      'name' => t('Video'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'video_feed' => array(
      'name' => t('Video Feed'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => t('<h3>YouTube</h3>

<ol>
<li><strong>To get your video feed URL on YouTube,</strong> go to the URL for your YouTube user, such as <em>http://www.youtube.com/user/username</em></li>
<li>If you\'re using Mozilla Firefox, you may <strong>click the blue feed icon</strong> in the left side of the browser\'s location bar to get the feed URL. <strong>Click on this link</strong> and then <strong>copy the resulting URL from your browser\'s location bar</strong></li>
<li>If you\'re using another browser, you can replace <em>USERNAME</em> in the following URL with your YouTube username to build your feed URL: <em>http://gdata.youtube.com/feeds/base/users/USERNAME/uploads?alt=rss&v=2&orderby=published&client=ytapi-youtube-profile</em></li>
<li><strong>Paste this URL</strong> into the Feed URL field below</li>
</ol>

<h3>Vimeo</h3>

<ol>
<li><strong>To get your video feed URL on Vimeo,</strong> go to the URL for your Vimeo user, such as http://www.vimeo.com/user/myuser. 
<li>If you\'re using Mozilla Firefox, you may <strong>click the blue feed icon</strong> in the left side of the browser\'s location bar to get the feed URL. <strong>Click on this link</strong> and then <strong>copy the resulting URL from your browser\'s location bar</strong></li>
<li>If you\'re using another browser, you can replace <em>USERNAME</em> in the following URL with your Vimeo username to build your feed URL: <em>http://vimeo.com/USERNAME/videos/rss</em></li>
<li><strong>Paste this URL</strong> into the Feed URL field below</li>
</ol>'),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function feed_system_views_api() {
  return array(
    'api' => '2',
  );
}
