
1) After installed WampServer, by left clicking the icon - > Apache options - > Services options - > Test port 80,
   see if port 80 occupied by other processes.

2) If it is not being used, can use 127.0.0.1 direct access to the Wamp Server home page.

3) If it is being used, by left-click the icon - > Apache options - > Services options - > HTTPD. Conf option, open the HTTPD. Conf file,
   Search a listen to the statements of 80. Can listen instead of 8080, with 8080 127.0.0.1: visit the Wamp Server home page.

4) Before accessing the database phpmyadmin, needs to find the file config.inc.php which is under the folder
   wamp\apps\phpmyadmin3.4.10.1, and modified the attribute "auth_type" to "http".

5) The database configuration file is .opt file under the folder wamp\bin\mysql\mysql5.5.20\data\waijiao, and the form file is the .frm file.
