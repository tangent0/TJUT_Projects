
1)安装好WampServer后，通过 左击图标 --> Apache选项 --> Services选项 --> Test port 80，查看80端口是否被其他进程占用。

2)如果未被占用，可以用127.0.0.1直接访问Wamp Server主页。

3)如果被占用，通过 左击图标--> Apache选项 --> Services选项 --> httpd.conf选项，打开httpd.conf文件，
  查找到语句listen 80。可以改为listen 8080，用127.0.0.1:8080访问Wamp Server主页。

4)访问数据库 phpmyadmin 前，需要将wamp\apps\phpmyadmin3.4.10.1下的config.inc.php文件中 auth_type 改为 http。

5)所建的数据库配置文件是wamp\bin\mysql\mysql5.5.20\data\bookstock_database\下的.opt文件，所建的表是.frm文件。

6)可以将此目录下的bookstock_database文件夹复制到wamp\bin\mysql\mysql5.5.20\data\下，通过网页访问Wamp主页下的phpmyadim进行数据的管理。