<?php
/**
 * Implementation of specially named hook_ctools_content_types()
 */
function newplay_admin_links_facebook_like_ctools_content_types() {
    return array(
      'single' => TRUE,
      'title' => t("Facebook like button"),
      'icon' => 'icon_node.png',
      'description' => t('Embed code from facebook for like button'),
      'required context' => new ctools_context_optional(t('Node'), 'node'),
      'category' => t('Custom'),
    );
}

function newplay_admin_links_facebook_like_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  $items = array();
  $output = '';
  $block = new stdClass();
  
  // Set up some variables
  $current_node = $context->argument;
  // @TODO: figure out how to not hard code the main domain
  $domain = (isset($_SERVER['HTTP_HOST'])) ? 'http://' . preg_replace('`^www.`', '', $_SERVER['HTTP_HOST']) : 'http://newplaymap.org';
  
  /* Template code:
   <iframe src="http://www.facebook.com/plugins/like.php?href=http%3A%2F%2Fnewplaymap%2Fartist%2Faditi-brennan-kapil&amp;send=false&amp;layout=button_count&amp;width=450&amp;show_faces=false&amp;action=like&amp;colorscheme=light&amp;font&amp;height=21" scrolling="no" frameborder="0" style="border:none; overflow:hidden; width:450px; height:21px;" allowTransparency="true"></iframe>
   */
  
  // Get the path alias for the current node
  $current_path = ($current_node) ? substr(base_path(), 1) . drupal_get_path_alias('node/' . $current_node) : '';
  // Add the domain and base path
  $share_link = $domain . base_path() . $current_path;
  
  $content_name = $context->title; // Get the content title from the context
  
  $facebook_account = 'NewPlayMap'; // @TODO: pull this from the twitter module when that's working
    
  $output .= '<iframe '; // From Facebook API
  $output .= 'src="http://www.facebook.com/plugins/like.php?'; // From FB API
  $output .= 'href=' . $share_link . '&amp;'; // What post should link to
  $output .= 'send=false' . '&amp;'; // From FB API
  $output .= 'layout=standard' . '&amp;';
  $output .= 'width=450' . '&amp;';
  $output .= 'show_faces=false' . '&amp;';
  $output .= 'colorscheme=light' . '&amp;';
  $output .= 'font' . '&amp;';
  $output .= 'height=21' . '" ';
  $output .= 'scrolling="no" ';
  $output .= 'frameboarder="0" ';
  $output .= 'style="border:none; overflow:hidden; width:450px; height:21px;" ';
  $output .= 'allowTransparency="true" ';
  $output .= '></iframe>';
  
      
  $block->module = 'newplay_admin_links';
  $block->delta  = 'unknown';
  $block->content = $output;

  return $block;
}

function newplay_admin_links_facebook_like_content_type_admin_title($subtype, $conf, $context) {
  return t("Facebook Like button");
}

function newplay_admin_links_facebook_like_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}