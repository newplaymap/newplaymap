<?php
// $Id: terms_of_use.pages.inc,v 1.1.2.4 2010/04/12 15:03:53 karst Exp $

/**
 * @file
 * Page callbacks for the Terms of Use module.
 */

/**
 * Helper function for autocompletion
 */
function terms_of_use_autocomplete($string = '') {
  $matches = array();
  if ($string != '') {
    $result = db_query_range(db_rewrite_sql("SELECT n.title FROM {node} AS n WHERE n.title LIKE '%%%s%%'"), $string, 0, 10);

    while ($node = db_fetch_object($result)) {
      $matches[$node->title] = $node->title;
    }
  }

  drupal_json($matches);
}

/**
 * Menu callback for AHAH addition.
 */
function terms_of_use_js() {

  // Build the new form.
  $form_state = array('submitted' => FALSE);
  $form_build_id = $_POST['form_build_id'];

  // We retreive the cached form, add the element value, and resave.
  $form = form_get_cache($form_build_id, $form_state);

  if (isset($form['terms_of_use_text']['terms_of_use_node_title'])) {
    // Create the extra field
    $form['terms_of_use_text']['terms_of_use_node_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Node id where your Terms of Use are published'),
      '#default_value' => variable_get('terms_of_use_node_id', ''),
      '#description' => t('Node <em>id</em> of the page or story (or blog entry or book page) where your Terms of Use are published.'),
    );
    unset($form['terms_of_use_text']['terms_of_use_node_title']);
    $form['terms_of_use_text']['terms_of_use_pick_node_id']['#value'] = t('I prefer to provide the title of the post');
  }
  else {
    // Create the extra field
    $form['terms_of_use_text']['terms_of_use_node_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title of the post where your Terms of Use are published'),
      '#default_value' => variable_get('terms_of_use_node_title', ''),
      '#description' => t('Node <em>title</em> of the page or story (or blog entry or book page) where your Terms of Use are published.'),
      '#autocomplete_path' => 'node/autocomplete',
    );
    unset($form['terms_of_use_text']['terms_of_use_node_id']);
    $form['terms_of_use_text']['terms_of_use_pick_node_id']['#value'] = t('I prefer to specify the node id');
  }

  form_set_cache($form_build_id, $form, $form_state);
  $form += array(
    '#post' => $_POST,
    '#programmed' => FALSE,
  );

  // Rebuild the form.
  $form = form_builder('terms_of_use_admin_settings', $form, $form_state);

  // Render the new output.
  $output = drupal_render($form['terms_of_use_text']);

  drupal_json(array('status' => TRUE, 'data' => $output));
}