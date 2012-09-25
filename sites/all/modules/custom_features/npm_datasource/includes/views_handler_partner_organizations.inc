<?php
/**
 * Field handler to provide a list of partner organizations formatted for the json export
 *
 * @ingroup views_field_handlers
 */
class views_handler_partner_organizations extends views_handler_field {

  function query() {
    // $this->field_alias = 'partner_organizations'. $this->position;
    
    // $value = db_escape_string($this->options['value']);
    // $this->query->add_field('', "'$value'", $this->field_alias);
  }

  function render($values) {
    $node = node_load($values->nid);
    $output = '';

    if (!empty($node->field_partner_org[0]['nid'])) {
      // @TODO: Maybe the whole thing should be json_encoded instead of manually wrapped in brackets?
      $output .= "[";
      $i = 0;
      foreach ($node->field_partner_org as $partner) {
        if($i > 0) {
         $output .= ',';
        }

        $partner_node = node_load($partner['nid']);
        $partner_has_location = ($partner_node->field_location[0]['lid'] != 0) ? TRUE : FALSE;

        $output .= json_encode(array(
          "name" => $partner_node->title,
          "path" => '/' . drupal_lookup_path('alias', 'node/' . $partner_node->nid),
          "has_location" => $partner_has_location,
        ));
    
        $i++;
      }
    
      $output .= "]";
    }

    return $output;
  }
}