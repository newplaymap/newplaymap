<?php
// $Id: template.php,v 1.21 2009/08/12 04:25:15 johnalbin Exp $

/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can add new regions for block content, modify
 *   or override Drupal's theme functions, intercept or make additional
 *   variables available to your theme, and create custom PHP logic. For more
 *   information, please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to newplay_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: newplay_breadcrumb()
 *
 *   where newplay is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override any of the theme functions used in Zen core,
 *   you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_item_link()   in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and template suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440
 *   and http://drupal.org/node/190815#template-suggestions
 */


/**
 * Implementation of HOOK_theme().
 */
function newplay_theme(&$existing, $type, $theme, $path) {
  $hooks = zen_theme($existing, $type, $theme, $path);
  // Add your theme hooks like this:
  /*
  $hooks['hook_name_here'] = array( // Details go here );
  */
  // @TODO: Needs detailed comments. Patches welcome!
  return $hooks;
}

/**
 * Override or insert variables into all templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered (name of the .tpl.php file.)
 */
/* -- Delete this line if you want to use this function
function newplay_preprocess(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function newplay_preprocess_page(&$vars, $hook) {
  
  global $user;
  if($vars['logged_in']){
    $vars['top_right_links'] .=  '<span class="welcome">' . t('Welcome') . ', ' . $user->name . '!</span>';
    $vars['top_right_links'] .=  '<span class="my-account">' . l(t("My Account"), "user") . '</span>';
    $vars['top_right_links'] .=  '<span class="logout">' . l(t("Sign out"), "logout"). '</span>';
  }else{
    $vars['top_right_links'] .=  '<span class="welcome">' . t('Welcome') . '!</span>';
    $vars['top_right_links'] .=  '<span class="login">' . l(t("Sign in"), "user") . " or " . l(t("Create Account"), "user/register") . '</span>';
  }
  
  if ($vars['is_front'] == 1) {
    $vars['title'] = '';
    // $vars['head_title'] = $vars['title'] . t(' | ') . $vars['site_name'];
  }
  
  // on profile pages, this removes the title.
  // if (arg(0) == 'user' && is_numeric(arg(1)) && (arg(2) == '' || arg(2) == 'view')) {
  //   $vars['title'] = '';
  // }
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function newplay_preprocess_node(&$vars, $hook) {

  // Optionally, run node-type-specific preprocess functions, like
  // newplay_preprocess_node_page() or newplay_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars, $hook);
  }
  
  // Class hacking
  // $classes = explode(' ', $vars['classes']); // Explode with spaces
  // $classes[] = 'activity-type-' . $activity_type;
  // $vars['classes'] = implode(' ', $classes); // Concatenate with spaces  
  
  
  // This is LIFO (Last In First Out) so put them in reverse order, i.e. most important last.
  if ($vars['page']) {
    $vars['template_files'] = array('node-'. $vars['node']->type, 'node-default-page', 'node-'. $vars['node']->type .'-page', 'node-'. $vars['node']->nid, 'node-'. $vars['node']->nid .'-page',);
  } else {
    $vars['template_files'] = array('node-default', 'node-'. $vars['node']->type, 'node-'. $vars['node']->nid);
  }
  
  // Set up items in taxonomies
  if ($terms = taxonomy_node_get_terms($vars['node'], $key = 'tid')) {      
    foreach ($terms as $tid => $term) {
      $terms_by_vid[$term->vid][$tid] = $term;
    }
  }
  
  // set up $taxo1
  if (is_array($terms_by_vid[1])) {
    $terms = array();
    foreach ($terms_by_vid[1] as $term_single) {
      $terms[] = l($term_single->name, 'taxonomy/term/'. $term_single->tid, array('title' => $term_single->description));
    }
    $vars['taxo1'] = implode(', ', $terms);
  }
  
  // add access check here
  if (node_access('update', $vars['node'])) {
    $vars['edit_link'] = l(t('[Edit]'), 'node/' . $vars['node']->nid . '/edit');
  }
  
  // Set up read more link
    $read_more_link_options = array(
      'html' => TRUE,
      'attributes' => array(
        'class' => 'read-more'
      )
    );
    
    //$url = $vars['user_url']; // for user link
    $url = 'node/' . $vars['node']->nid; // regular node_link
    
    $vars['more_link'] = l(t("Read more&nbsp;&raquo;"), $url, $read_more_link_options);

    if ($vars['type'] == 'artist' || $vars['type'] == 'organization' || $vars['type'] == 'event' || $vars['type'] == 'play') {
      $vars['loading'] = TRUE;
    }
  // EXAMPLES OF COMMON FIELDS
    // To-do: These should all be modified so that they each allow for multiple values in the field.
  
  /* Set up taxonomy terms list */
    // if ($vars['node']->taxo_vocab_language) {
    //   $vars['languages'] = $vars['node']->taxo_vocab_language;
    // }

  /* Set up field type text field */
    // if ($vars['node']->field_event_title[0]['value']) {
    //   $vars['event_title'] = check_markup($vars['node']->field_event_title[0]['value'], $vars['node']->field_event_title[0]['format']);
    // }
    
  /* Set up field type textarea */
    // // Set up description
    //   if ($vars['node']->field_event_description[0]['value']) {
    //     $vars['event_description'] = check_markup($vars['node']->field_event_description[0]['value'], $vars['node']->field_event_description[0]['format']);
    //   }
    
  
  /* Set up field type node reference */
    // // Set up $event_organization
    //   if (is_numeric($vars['node']->field_event_organization[0]['nid'])) {
    //     $org_node = node_load($vars['node']->field_event_organization[0]['nid']);
    //     $vars['event_organization'] = l($org_node->title, 'node/' . $org_node->nid);
    //   }
  
  /* Set up field type user reference */
  
  /* Set up field type location */
    // // Set up $location
    //   if ($vars['node']->field_event_locations[0]) {
    //     $vars['event_location'] = theme('location', $vars['node']->field_event_locations[0]);
    //   }
    
  /* Set up field type image */
    // This is a relatively complicated example
    // if ($vars['page'] == 0) {
    //   // if we are looking at a teaser, define a default image if no images have been uploaded
    //   if ($vars['node']->field_housing_group_image[0]['filepath']) {
    //     $image_filepath = $vars['node']->field_housing_group_image[0]['filepath'];
    //   } else {
    //     $image_filepath = path_to_theme() . '/images/default-home-icon.png';
    //   }
    // 
    //   $link_options = array(
    //     'html' => TRUE,
    //   );
    // 
    //   if ($image_filepath) {
    //     $vars['housing_group_images'] = l(theme('imagecache', 'home_teaser', $image_filepath, $alt, $title, $attributes), 'node/' . $vars['node']->nid, $link_options); 
    //   }
    // 
    // } elseif ($vars['node']->field_housing_group_image[0]['filepath']) {
    //   // Add image pager here when ready
    //   $image_filepath = $vars['node']->field_housing_group_image[0]['filepath'];
    //   $vars['housing_group_images'] = theme('imagecache', 'home_page', $image_filepath, $alt, $title, $attributes);         
    // }
  
  /* Set up field type link */
    // // Set up $event_registration_link
    //   if ($vars['node']->field_event_registration_link[0]['url']) {
    //     if (check_plain($vars['node']->field_event_registration_link[0]['title'])) {
    //       $title = $vars['node']->field_event_registration_link[0]['title'];
    //     } else {
    //       $title = $vars['node']->field_event_registration_link[0]['url'];
    //     }
    //     $url = check_plain($vars['node']->field_event_registration_link[0]['url']);
    //     $link_options = array('html' => FALSE,);
    //     $vars['event_registration_link'] = l($title, $url, $link_options);
    //   }
    
  /* Set up field type datetime with no timezone conversion */
    // if ($vars['node']->field_housing_group_available[0]['value']) {
    //   $date = date_convert($vars['node']->field_housing_group_available[0]['value'], DATE_ISO, DATE_UNIX);
    //   $timezone = 0;
    //   $vars['housing_group_availability_date'] = format_date($date,'custom','F j, Y', $timezone);      
    // }    
  
  /* Set up field type datetime with site default timezone conversion */
    // if ($vars['node']->field_housing_group_available[0]['value']) {
    //   $date = date_convert($vars['node']->field_housing_group_available[0]['value'], DATE_ISO, DATE_UNIX);
    //   $timezone = variable_get('date_default_timezone', 0);    
    //   $vars['housing_group_availability_date'] = format_date($date,'custom','F j, Y', $timezone);      
    // }
  
  /* Set up field type datetime with user timezone conversion */
    // if ($vars['node']->field_housing_group_available[0]['value']) {
    //   $date = date_convert($vars['node']->field_housing_group_available[0]['value'], DATE_ISO, DATE_UNIX);
    //   if ($vars['user']->timezone) {
    //     $timezone = $vars['user']->timezone;  
    //   } else {
    //     $timezone = variable_get('date_default_timezone', 0); // fall back to site default
    //   }
    //   
    //   $vars['housing_group_availability_date'] = format_date($date,'custom','F j, Y', $timezone);      
    // }
    
    // // Set up $date for start and end dates
    // // Set up $date    
    //   if ($vars['node']->field_event_date[0]['value']) {
    // 
    //     // Set timezone conversion setting
    //     $timezone = 0;
    // 
    //     $date_begin = date_convert($vars['node']->field_event_date[0]['value'], DATE_ISO, DATE_UNIX);
    // 
    //     if ($vars['node']->field_event_date[0]['value2']) {
    //       $date_end = date_convert($vars['node']->field_event_date[0]['value2'], DATE_ISO, DATE_UNIX);
    //     }
    // 
    //     $event_begin_formatted_full = format_date($date_begin,'custom','M j, Y g:ia', $timezone);
    //     $event_begin_formatted_short_month = format_date($date_begin,'custom','M', $timezone);
    //     $event_begin_formatted_day = format_date($date_begin,'custom','j', $timezone);
    //     $event_end_just_time = format_date($date_end,'custom','g:ia', $timezone);
    //     $event_end_formatted_full = format_date($date_end,'custom','M j, Y g:ia', $timezone);
    // 
    //     if (format_date($date_begin,'custom','M j, Y') == format_date($date_end,'custom','M j, Y')) {
    //       $vars['event_date'] = theme_date_display_range($event_begin_formatted_full, $event_end_just_time);
    //     } else {
    //       $vars['event_date'] = theme_date_display_range($event_begin_formatted_full, $event_end_formatted_full);
    //     }
    // 
    //     $vars['event_date_icon'] = '<div class="month">' . $event_begin_formatted_short_month . '</div><div class="day">' . $event_begin_formatted_day . '</div>';
    //   }
        
  
  /* Set up field type phone / fax */
    // // Set up $event_phone
    //   if ($vars['node']->field_event_registration_phone[0]['value']) {
    //     $vars['event_phone'] = check_plain($vars['node']->field_event_registration_phone[0]['value']);
    //   } 
  
  /* Set up number field (formatted as 12,893) */
    // if (is_numeric($vars['node']->field_housing_group_estimated[0]['value'])) {
    //   $vars['housing_group_estimated'] =  number_format(check_plain($vars['node']->field_housing_group_estimated[0]['value']));
    // }
  
  /* Set up number field (formatted as dollars - $123,763) */
    // To-do: figure out a number field format that accomodates cents
    // if (is_numeric($vars['node']->field_housing_group_estimated[0]['value'])) {
    //   $vars['housing_group_estimated'] = "\$" . number_format(check_plain($vars['node']->field_housing_group_estimated[0]['value']));
    // }
  
}

function newplay_preprocess_node_profile(&$vars) {
  
  if (arg(0) == 'user' && is_numeric(arg(1))) {
    $vars['template_files'] = array('node-profile', 'node-profile-page');
    $vars['page'] = 1;
  }
  
  $vars['user_url'] = drupal_get_path_alias('user/' . $vars['node']->uid);
  
  if (!$vars['page']) {
    $vars['template_files'] = array('node-profile-teaser');
  }
  
  // set up $profile_photo
  if ($vars['user']->content_profile['profile']->field_profile_photo[0]['filepath']) {
    $image_filepath = $vars['user']->content_profile['profile']->field_profile_photo[0]['filepath'];
  } else {
    $image_filepath = path_to_theme() . '/images/default-user-icon.png';
  }

  if ($vars['node']->field_profile_image[0]['filepath']) {
    $image_filepath = $vars['node']->field_profile_image[0]['filepath'];
  } else {
    $image_filepath = path_to_theme() . '/images/default-user-icon.png';
  }
  
  $link_options = array(
    'html' => TRUE,
  );
  
  $vars['image'] =  l(theme('imagecache', 'profile_small', $image_filepath, $alt, $title, $attributes), $vars['user_url'], $link_options); 
  
  if ($vars['page']) {
    $vars['image_large'] = theme('imagecache', 'profile_regular', $image_filepath, $alt, $title, $attributes);
  } else {
    // put the link on the hover image
    $vars['image_large'] = l(theme('imagecache', 'profile_regular', $image_filepath, $alt, $title, $attributes), $vars['user_url'], $link_options);
  }

  $vars['name'] = l($vars['node']->title, $vars['user_url']); 
  $org_node = node_load($vars['node']->field_profile_organization[0]['nid']);
  // dpr($org_node); 
  if ($vars['node']->field_profile_organization[0]['nid']) {
    $vars['org_node_link'] = l($org_node->title, 'node/' . $vars['node']->field_profile_organization[0]['nid']); 
  }
  if ($org_node->field_organization_url[0]['url']) {
    $vars['org_link'] = l($org_node->title, $org_node->field_organization_url[0]['url']); 
  }
  $vars['position'] = $vars['node']->field_profile_position[0]['view']; 
  $vars['bio'] = $vars['node']->content['body']['#value']; 
  
  $read_more_link_options = array(
    'html' => TRUE,
    'attributes' => array(
      'class' => 'read-more'
    )
  );
  
  $vars['more_link'] = l(t("Read more&nbsp;&raquo;"), $vars['user_url'], $read_more_link_options);
}



/**
 * Override or insert variables into the comment templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function newplay_preprocess_comment(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function newplay_preprocess_block(&$vars, $hook) {
  if ($vars['block']->module == 'invite') {
    $vars['block']->subject = '<span>' . $vars['block']->subject . '</span>';
  }
}


/**
 * Override theme_content_view_multiple_field from content.views.inc
 *
 * For Org Type fields, make it a comma seperated list of spans
 */
function newplay_content_view_multiple_field($items, $field, $values) {
  $output = '';
  $i = 0;
  $length = count($items);
  
  if ($field['field_name'] == 'field_org_type') {
    // For Org Type fields, make it a comma seperated list of spans
    foreach ($items as $item) {
      if (!empty($item) || $item == '0') {
        $output .= '<span class="field-item field-item-'. $i .'">'. $item .'</span>';
        // Put commas after each one excpet the last one
        if ($i !== $length - 1) {
          $output .= '<span class="delimiter">,</span> ';
        }
        $i++;
      }
    }
  } else {
    // Original
    foreach ($items as $item) {
      if (!empty($item) || $item == '0') {
        $output .= '<div class="field-item field-item-'. $i .'">'. $item .'</div>';
        $i++;
      }
    }
  }
  
  return $output;
}
