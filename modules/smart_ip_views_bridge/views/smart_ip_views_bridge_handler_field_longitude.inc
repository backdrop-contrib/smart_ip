<?php
// $Id$

/**
 * @file
 * Contains the 'smart_ip_views_bridge_handler_field_longitude' markup field handler.
 */

/**
 * Field handler to display visitor's longitude.
 */
class smart_ip_views_bridge_handler_field_longitude extends smart_ip_views_bridge_handler_field_coordinates {

  function construct() {
    parent::construct();
  }

  function render($values) {
    if ($this->options['style'] == 'dd') {
      return $_SESSION['smart_ip']['location']['longitude'];
    }
    else {
      return theme('smart_ip_longitude_dms', $_SESSION['smart_ip']['location']['longitude']);
    }
  }
}
