<?php
// $Id$

/**
 * @file
 * Contains the 'smart_ip_views_bridge_handler_filter_location_country' filter handler.
 */

class smart_ip_views_bridge_handler_filter_location_country extends location_handler_filter_location_country {
  /**
   * {@inheritdoc}
   */
  public function get_value_options() {
    parent::get_value_options();
    $smart_ip_options = smart_ip_views_bridge_form_select_field_tokens();
    $this->value_options = array_merge($this->value_options, $smart_ip_options);
  }
}
