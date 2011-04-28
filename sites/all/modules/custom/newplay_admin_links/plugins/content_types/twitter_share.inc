<?php
/**
 * Implementation of specially named hook_ctools_content_types()
 */
function newplay_admin_links_twitter_share_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t("Twitter like button"),
      'icon' => 'icon_node.png',
      'description' => t('Embed code from twitter for like button'),
      'required context' => new ctools_context_optional(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function newplay_admin_links_twitter_share_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $items = array();
  $output = '';
  $block = new stdClass();
  
  // Set up some variables
  $current_node = $context->argument;
  // @TODO: figure out how to not hard code the main domain
  $domain = (isset($_SERVER['HTTP_HOST'])) ? 'http://' . preg_replace('`^www.`', '', $_SERVER['HTTP_HOST']) : 'http://newplaymap.org';
  
  // Get the path alias for the current node
  $current_path = ($current_node) ? '#' . base_path() . drupal_get_path_alias('node/' . $current_node) : '';
  // Add the domain and base path
  $share_link = $domain . base_path() . $current_path;
  
  $content_name = $context->title; // Get the content title from the context
  $content_short_name = (strlen($content_name) > 61) ? substr($content_name, 0, 60) . '…' : $content_name; // Shorten it for twitter
  $text = "Here's the profile for $content_short_name on the #NewPlay Map";
  $twitter_account = 'NewPlayMap'; // @TODO: pull this from the twitter module when that's working
    
  $output .= '<a href="http://twitter.com/share" '; // Url for twitter API
  $output .= 'class="twitter-share-button"'; // From twitter API
  $output .= 'data-url="' . $share_link . '" '; // What tweet should link to
  $output .= 'data-text="' . $text . '" '; // Text of tweet
  $output .= 'data-count="horizontal" '; // From twitter API
  $output .= 'data-via="' . $twitter_account . '"'; // adds @NewPlayMap
  $output .= '>Tweet</a>'; // Degraded text
  $output .= '<script type="text/javascript" src="http://platform.twitter.com/widgets.js"></script>'; // From twitter API
      
  $block->module = 'newplay_admin_links';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function newplay_admin_links_twitter_share_content_type_admin_title($subtype, $conf, $context) {
  return t("Twitter Like button");
}

function newplay_admin_links_twitter_share_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
