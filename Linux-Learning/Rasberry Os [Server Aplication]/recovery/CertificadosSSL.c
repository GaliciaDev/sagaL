//Configuracion de Host virtuales
<IfModule mod_ssl.c>
        <VirtualHost _default_:443>
                ServerAdmin lnxserver@localhost
                ServerName www.saga.freemyip.com
                ServerAlias saga.freemyip.com
                DocumentRoot /var/www/html/saga
                ErrorLog /error.log
                CustomLog /access.log combined
                SSLEngine on
                SSLCertificateKeyFile /etc/letsencrypt/live/saga.freemyip.com/privkey.pem
                SSLCertificateFile /etc/letsencrypt/live/saga.freemyip.com/fullchain.pem
                SSLProtocol all -SSLv3 -TLSv1 -TLSv1.1
                Protocols h2 http/1.1
        </VirtualHost>
</IfModule>



//Instalacion de certificado SSL
sudo certbot certonly --standalone -d saga.freemyip.com

 - Congratulations! Your certificate and chain have been saved at:
   /etc/letsencrypt/live/saga.freemyip.com/fullchain.pem

   Your key file has been saved at:
   /etc/letsencrypt/live/saga.freemyip.com/privkey.pem

//Renovacion de certificado SSL automaticamente
#!/bin/bash
sudo systemctl stop apache2
sudo certbot renew
sudo systemctl start apache2

//Automatizar el archivo
sudo crontab -e
#Renovacion de certificado SSL
0 1 1 * * /home/lnxserver/scripts/ssl-auto.sh
chmod 777 ssl-auto.sh

//Borrar la version del servidor apache2
sudo nano /etc/apache2/conf-available/security.conf



