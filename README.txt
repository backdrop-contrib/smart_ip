$Id$

Description:
Smart IP identify visitor's geographical location (longitude/latitude), country, 
region, city and postal code based on the IP address of the user. These information 
will be stored at Drupal $user->data object with array key 'geoip_location' upon login 
of the user but optionally it can be disabled at Smart IP admin page. Other modules can 
use the function smart_ip_get_location($ip_address) that returns an array containing 
the visitor's ISO 3166 2-character country code, longitude, latitude, region code (FIPS), 
city and postal code. It provides a feature for you to perform your own IP lookup and admin 
spoofing of an arbitrary IP for testing purposes.

Maxmind's database is the source of Smart IP database that makes the association between IP 
address and geographical location (longitude/latitude), region, city and postal code. It can 
be found at http://www.maxmind.com/app/geolitecountry it has two versions: a very accurate 
and up to date payable version and a not quite accurate free lite version. Smart IP downloads 
and process the CSV files (GeoLiteCity-Location.csv and GeoLiteCity-Blocks.csv) to store to 
Smart IP database. An optional once a month (Maxmind updates its database every first day of 
a month) automatic update of the Smart IP database is provided or it can be manually updated 
at Smart IP admin page. The database of Maxmind is very huge, the two CSV files size is about 
150MB and the size when stored to SQL database is about 320MB with almost 5 million rows. The 
process of downloading the archived CSV files from Maxmind's server, extracting the downloaded 
zip file, parsing the CSV files and storing to the database will took more or less five hours. 
It uses the batch system process. If interrupted by an unexpected error, the administrator can 
manually continue and recover from where it stopped at Smart IP admin page.

Note: The Smart IP database is empty upon initial installation of this module. This module will 
do nothing if Smart IP database is empty. Either manually update the Smart IP database at admin 
page or wait for the cron to run and update Smart IP database automatically for you.

Requirements:
Drupal 7.x

Installation:
1. Copy the extracted smart_ip directory to your Drupal sites/all/modules directory.
2. Login as an administrator. Enable the module at http://www.example.com/admin/modules
3. Configure/update Smart IP database/lookup an IP at 
http://www.example.com/admin/config/people/smart_ip.

Support:
Please use the issue queue for filing bugs with this module at
http://drupal.org/project/issues/smart_ip