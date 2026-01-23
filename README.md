Smart IP
========

Smart IP can identify a visitor's geographical country, location (longitude/latitude), 
region, city, and postal code based on the IP address of the visitor.  

Depending on the "data source" used (see below), the visitor's country code may be the only data provided.


Usage
-----

Visitor location information will be stored in the $_SESSION variable with array key 'smart_ip', 
and in $user->data object with array key 'geoip_location'. Optionally, it can  
be disabled (by role) on the Smart IP admin page. 

Developers can use the function `smart_ip_get_location($ip_address)` which returns an 
array containing the visitor's location information. 

Administrators can also perform an arbitrary IP lookup and spoofing for testing purposes.


**Important:** The Smart IP database is empty upon initial installation of this module. Either manually 
update the Smart IP database at admin page or wait for the cron to run and update Smart IP 
database automatically for you.


Features 
--------

- Multiple data source options available: 
    - free or paid [IP2Location](https://www.ip2location.com/) binary database (free only returns country code) **tested and recommended by [maintainer swampopus](https://github.com/swampopus)**
    - local database with data from parsed MaxMind CSV
    - [MaxMind GeoIP Services](http://dev.maxmind.com/geoip) - CSV, binary files, Apache module mod_geoip
        - special thanks to [jbulcher](https://www.drupal.org/user/1727252)
    - [IPInfoDB.com](https://www.ipinfodb.com/) web service
    - X-GeoIP-Country: XX header (thanks to [jp.stacey](https://www.drupal.org/user/130486)) 
    - [Cloudflare](https://www.cloudflare.com/) IP Geolocation.
    
- Maxmind's Apache module mod_geoip, Cloudflare IP Geolocation and X-GeoIP-Country as fallback for the current visitor's geolocation info if the data source of Smart IP returns empty.

- Both IPV4 and IPV6 support, depending on data source.

- Monthly or Weekly auto-updates, depending on data source.

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

- "zip" PHP extension is required if using IP2Location as data source.


Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

- Configure Smart IP settings at /admin/config/people/smart_ip.



Extra Notes
-----------
This module has been tested in Backdrop using IP2Location as a source, utilizing the free "lite" version, which
only provides the country of an IP address.  It also requires the "zip" extention in PHP be enabled, as
IP2Location delivers its bin files in a zip file which must be extracted.

MaxMind has two versions: a very accurate and up to date payable version and a 
not quite accurate free lite version. Smart IP downloads and process the 
CSV files (GeoLiteCity-Location.csv and GeoLiteCity-Blocks.csv) to store to 
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

Note that IPInfoDB.com service which also uses Maxmind's database, in 
this case IPInfoDB.com will handle database resource load instead of your server's database. 
By default the use of IPInfoDB.com service as source is enabled. If IPInfoDB.com is desired to  
handle database resource load, it can be configured at Smart IP admin page settings.


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.


Current Maintainers
-------------------

- [Juan Olalla](https://github.com/juanolalla)
- [Richard Peacock (swampopus)](https://github.com/swampopus)
- Seeking additional maintainers.


Credits
-------
- Drupal project maintained by [arpeggio](https://www.drupal.org/u/arpeggio).
- Drupal project also maintained by [mertres](https://www.drupal.org/u/mertres).
- Ported to Backdrop CMS by [Juan Olalla](https://github.com/juanolalla).
