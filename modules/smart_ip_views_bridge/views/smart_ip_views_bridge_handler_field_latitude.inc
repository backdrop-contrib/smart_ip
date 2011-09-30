<?php
// $Id$

/**
 * @file
 * Contains the 'smart_ip_views_bridge_handler_field_latitude' field handler.
 */

/**
 * Field handler to display visitor's latitude.
 */
class smart_ip_views_bridge_handler_field_latitude extends smart_ip_views_bridge_handler_field_coordinates {

  function construct() {
    parent::construct();
  }

  function render($values) {
    if ($this->options['style'] == 'dd') {
      return $_SESSION['smart_ip']['location']['latitude'];
    }
    else {
      return theme('smart_ip_longitude_dms', $_SESSION['smart_ip']['location']['latitude']);
    }
  }
}
