
1)��װ��WampServer��ͨ�� ���ͼ�� --> Apacheѡ�� --> Servicesѡ�� --> Test port 80���鿴80�˿��Ƿ���������ռ�á�

2)���δ��ռ�ã�������127.0.0.1ֱ�ӷ���Wamp Server��ҳ��

3)�����ռ�ã�ͨ�� ���ͼ��--> Apacheѡ�� --> Servicesѡ�� --> httpd.confѡ���httpd.conf�ļ���
  ���ҵ����listen 80�����Ը�Ϊlisten 8080����127.0.0.1:8080����Wamp Server��ҳ��

4)�������ݿ� phpmyadmin ǰ����Ҫ��wamp\apps\phpmyadmin3.4.10.1�µ�config.inc.php�ļ��� auth_type ��Ϊ http��

5)���������ݿ������ļ���wamp\bin\mysql\mysql5.5.20\data\bookstock_database\�µ�.opt�ļ��������ı���.frm�ļ���

6)���Խ���Ŀ¼�µ�bookstock_database�ļ��и��Ƶ�wamp\bin\mysql\mysql5.5.20\data\�£�ͨ����ҳ����Wamp��ҳ�µ�phpmyadim�������ݵĹ���