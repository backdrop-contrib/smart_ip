Device Geolocation
==================

Provides visitor's geographical location using client device location source 
that implements W3C Geolocation API whereas the coordinates are geocoded using Google 
Geocoding service. Google Geocoding returns a more detailed location information such 
as: street number, postal code, route, neighborhood, locality, sublocality, establishment, 
administrative area level 1, administrative area level 2, etc. 

Smart IP is the last fallback if W3C Geolocation API failed. Even if the visitors refuses 
to share their location, the geographical information provided by Smart IP will be used 
to know your visitors' geolocation details. A themeable Block content is available to 
show your visitor's geolocation information. Device Geolocation merges its location data 
(collected at Google Geocoding service) with Smart IP visitor's location data storage 
which is in session variable ($_SESSION) with array key 'smart_ip' and Backdrop 
$user->data object with array key 'geoip_location'.


Installation
------------

- Install this module and Smart IP using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

- Configure Geolocation Device settings at /admin/config/people/smart_ip.
