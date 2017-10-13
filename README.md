Smart IP
========

Backdrop CMS port of the Drupal 7 module [Smart IP](https://www.drupal.org/project/smart_ip)

Smart IP identify visitor's geographical location (longitude/latitude), country, 
region, city and postal code based on the IP address of the user. These information 
will be stored at session variable ($_SESSION) with array key 'smart_ip' and  Backdrop 
$user->data object with array key 'geoip_location' of the user but optionally it can  
be disabled (by role) at Smart IP admin page. Other modules can use the function 
smart_ip_get_location($ip_address) that returns an array containing the visitor's 
ISO 3166 2-character country code, longitude, latitude, region, city and postal code. It 
provides a feature for you to perform your own IP lookup and admin spoofing of an arbitrary 
IP for testing purposes.

Maxmind's database is the source of Smart IP database that makes the association between IP 
address and geographical location (longitude/latitude), region, city and postal code. It can 
be found at http://www.maxmind.com/app/geolitecountry it has two versions: a very accurate 
and up to date payable version and a not quite accurate free lite version. Smart IP downloads 
and process the CSV files (GeoLiteCity-Location.csv and GeoLiteCity-Blocks.csv) to store to 
Smart IP database. An optional once a month (Maxmind updates its database every first day of 
a month) automatic update of the Smart IP database is provided or it can be manually updated 
at Smart IP admin page. The database of Maxmind is very huge, the two CSV files size is about 
150MB and the size when stored to SQL database is about 450MB with almost 5 million rows and 
about 600MB additional database space for temporary working table for Smart IP database 
update. The process of downloading the archived CSV files from Maxmind's server, extracting 
the downloaded zip file, parsing the CSV files and storing to the database will took more or 
less eight hours (depends on server's speed). It uses the batch system process. If interrupted 
by an unexpected error, it can recover from where it stopped or the administrator can manually 
continue the broken process at Smart IP admin page.

Another source of Smart IP is the IPInfoDB.com service which also uses Maxmind's database, in 
this case IPInfoDB.com will handle database resource load instead of your server's database. 
By default the use of IPInfoDB.com service as source is enabled. If IPInfoDB.com is desired to  
handle database resource load, it can be configured at Smart IP admin page settings.

Note: The Smart IP database is empty upon initial installation of this module. Either manually 
update the Smart IP database at admin page or wait for the cron to run and update Smart IP 
database automatically for you.


Features
--------

- Ten data source options available: local database with data from parsed MaxMind CSV, paid [MaxMind GeoIP Legacy Web Services](http://dev.maxmind.com/geoip/legacy/web-services/), paid [MaxMind GeoIP2 Precision Web Services](http://dev.maxmind.com/geoip/geoip2/web-services/), [MaxMind GeoIP Legacy](http://dev.maxmind.com/geoip/legacy/geolite/) binary file database (thanks to [jbulcher](https://www.drupal.org/user/1727252)), [MaxMind GeoIP2](http://dev.maxmind.com/geoip/legacy/geolite/) binary database, MaxMind's Apache module [mod_geoip](http://dev.maxmind.com/geoip/legacy/mod_geoip2/), [IP2Location](https://www.ip2location.com/) binary database, [IPInfoDB.com](https://www.ipinfodb.com/) web service, X-GeoIP-Country: XX header (thanks to [jp.stacey](https://www.drupal.org/user/130486)) and [Cloudflare](https://www.cloudflare.com/) IP Geolocation.

- Maxmind's Apache module mod_geoip, Cloudflare IP Geolocation and X-GeoIP-Country as fallback for the current visitor's geolocation info if the data source of Smart IP returns empty.

- IPV4 and IPV6 support by the following Smart IP data sources: MaxMind GeoIP Legacy Web Services, GeoIP2 Precision Web Services, MaxMind GeoIP2 binary database, IP2Location binary database and IPInfoDB.com web service.

- Monthly auto-update of MaxMind CSV database format file for local database source.

- Weekly auto-update of MaxMind GeoIP Legacy and MaxMind GeoIP2 binary database format file for licensed version.

- Monthly auto-update of MaxMind GeoIP Legacy and MaxMind GeoIP2 binary database format file for lite version.

- Visitor’s geolocation block available (Device Geolocation module).

- Geolocate users by role.

- Update users' geolocation info based on defined time interval (at "Frequency of user's geolocation checking" field). Useful to get the updated users' geolocation even they moved from one place to another.

- Geolocate users to specific pages and with timeout that will prompt users for geolocation.

- User's geolocation update using AJAX, useful for webpages or sites that are cached.

- Token support (Thanks to [bgilhome](https://www.drupal.org/user/313439)).

- Exposes Smart IP visitor's location details to Views field (coordinates, country, ISO 3166 2-character country code, region, region code (FIPS), city and zip), Views filter (country, ISO 3166 2-character country code, region, region code (FIPS), city and zip) and Views region/country (ISO 3166 2-character country code) filter/contextual filter sponsored by [Sohal Khatwani](https://www.drupal.org/user/2896733).

- Integration with [Rules module](https://backdropcms.org/project/rules). (Thanks to [klausi](https://www.drupal.org/user/262198)).

- Maxmind GeoIP Web Services, available for Country Web Service (Thanks to [echataig](https://www.drupal.org/user/1386376)), City/ISP/Organization Web Service (Thanks to [namli](https://www.drupal.org/user/112665) and [duntuk](https://www.drupal.org/user/6031)) and Insights (formerly Omni) Web Service.

- Smart IP with a Maxmind GeoIP City Database from a paid account [read steps](https://www.drupal.org/node/1901530).


Device Geolocation
------------------

Device Geolocation is integrated into this module which gives more detailed visitor's geolocation using client device location source that implements HTML5 or W3C Geolocation API whereas the coordinates are geocoded using Google Geocoding service.


Requirements
------------

- PHP 5.4 and up

- geoip2/geoip2 library (if using MaxMind as data source. [Setup instructions](https://www.webfoobar.com/node/71))
 
- ip2location/ip2location-php library (if using IP2Location as data source. [Setup instructions](https://www.webfoobar.com/node/68))


Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

- Configure Smart IP settings at /admin/config/people/smart_ip.


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.


Current Maintainers
-------------------

- Juan Olalla (https://github.com/juanolalla)
- Seeking additional maintainers.


Credits
-------
- Drupal project maintained by [arpeggio](https://www.drupal.org/u/arpeggio).
- Drupal project also maintained by [mertres](https://www.drupal.org/u/mertres).
- Ported to Backdrop CMS by [Juan Olalla](https://github.com/jenlampton).
