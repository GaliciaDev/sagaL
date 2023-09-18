/*Instalacion y configuracion de certificados SSL para 2 Dominios*/

/*Entrar a la carpeta de los dominios*/
cd /etc/apache2/sites-available


//Crear los archivos para los dominios
sudo nano /etc/apache2/sites-available/saga.conf
sudo nano /etc/apache2/sites-available/cetipt.conf

//Host virtual para SAGA [Antes de instalar los certificados]
<IfModule mod_ssl.c>
        <VirtualHost _default_:443>
                ServerAdmin lnxserver@localhost
                ServerName saga.freemyip.com
                ServerAlias www.saga.freemyip.com
                DocumentRoot /var/www/html/saga
                ErrorLog ${APACHE_LOG_DIR}/error.log
                CustomLog ${APACHE_LOG_DIR}/access.log combined

                Protocols h2 http/1.1
        </VirtualHost>
</IfModule>

//Host virtual para CETIPT [Antes de instalar los certificados]
<IfModule mod_ssl.c>
        <VirtualHost _default_:443>
                ServerAdmin lnxserver@localhost
                ServerName cetipt.freemyip.com
                ServerAlias www.cetipt.freemyip.com
                DocumentRoot /var/www/html/cetipt
                ErrorLog ${APACHE_LOG_DIR}/error.log
                CustomLog ${APACHE_LOG_DIR}/access.log combined
                Protocols h2 http/1.1
        </VirtualHost>
</IfModule>

//Detener apache2
sudo systemctl stop apache2

/*Instalacion de Certbot*/
sudo apt-get install certbot -y

/*Instalacion de certificado SSL*/
//SAGA
sudo certbot certonly --standalone -d saga.freemyip.com
 - Congratulations! Your certificate and chain have been saved at:
   /etc/letsencrypt/live/saga.freemyip.com/fullchain.pem

   Your key file has been saved at:
   /etc/letsencrypt/live/saga.freemyip.com/privkey.pem


//CETIPT
sudo certbot certonly --standalone -d cetipt.freemyip.com
    - Congratulations! Your certificate and chain have been saved at:
    /etc/letsencrypt/live/cetipt.freemyip.com/fullchain.pem
    
    Your key file has been saved at:
    /etc/letsencrypt/live/cetipt.freemyip.com/privkey.pem


/* --Configuracion del sitio SAGA [CON SSL YA DESCARGADOS]-- */
sudo nano /etc/apache2/sites-available/saga.conf

<IfModule mod_ssl.c>
        <VirtualHost _default_:443>
                ServerAdmin lnxserver@localhost
                ServerName saga.freemyip.com
                ServerAlias www.saga.freemyip.com
                DocumentRoot /var/www/html/saga
                ErrorLog ${APACHE_LOG_DIR}/error.log
                CustomLog ${APACHE_LOG_DIR}/access.log combined

                SSLEngine on
                SSLCertificateKeyFile /etc/letsencrypt/live/saga.freemyip.com/privkey.pem
                SSLCertificateFile /etc/letsencrypt/live/saga.freemyip.com/fullchain.pem
                SSLProtocol all -SSLv3 -TLSv1 -TLSv1.1
                Protocols h2 http/1.1
        </VirtualHost>
</IfModule>

/* --Configuracion del sitio CETIPT [CON SSL YA DESCARGADOS]-- */
sudo nano /etc/apache2/sites-available/cetipt.conf

<IfModule mod_ssl.c>
        <VirtualHost _default_:443>
                ServerAdmin lnxserver@localhost
                ServerName cetipt.freemyip.com
                ServerAlias www.cetipt.freemyip.com
                DocumentRoot /var/www/html/cetipt
                ErrorLog ${APACHE_LOG_DIR}/error.log
                CustomLog ${APACHE_LOG_DIR}/access.log combined
                SSLEngine on
                SSLCertificateKeyFile /etc/letsencrypt/live/cetipt.freemyip.com/privkey.pem
                SSLCertificateFile /etc/letsencrypt/live/cetipt.freemyip.com/fullchain.pem
                SSLProtocol all -SSLv3 -TLSv1 -TLSv1.1
                Protocols h2 http/1.1
        </VirtualHost>
</IfModule>

//Iniciar el servidor apache
sudo systemctl start apache2

//Renovacion de certificado SSL automaticamente

//Crear el archivo
sudo mkdir /home/lnxserver/scripts
sudo nano /home/lnxserver/scripts/ssl-auto.sh

//Contenido del archivo
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

ServerTokens Prod
ServerSignature Off

//Reiniciar el servidor apache2
sudo systemctl restart apache2