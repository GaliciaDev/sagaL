//Instalacion de servicios basicos para el sistema

/*Actualizacion de paquetes*/
sudo apt-get update
sudo apt-get upgrade

/*Activar SSH*/
sudo systemctl start ssh

/*Instalar neofetch*/
sudo apt-get install neofetch -y

// Hacer que se habra neofetch al iniciar la terminal
    sudo nano ~/.bashrc
    //Agregar la siguiente linea al final del archivo
    neofetch


/*Instalar AnyDesk*/

    //Abrir chromium

    //Ingresar al siguiente link
    https://download.anydesk.com/rpi/anydesk_2.9.4-1_armhf.deb

    //Descargar el archivo

    //Abrir el archivo y dar click en instalar



    // Configurar la contraseña
    srvty505

    //Para conectarse a la raspberry pi 4 desde cualquier dispositivo
    Direccion: 16/06/2021 = 1431021554

/*Instalacion de CURL*/
sudo apt-get install curl

/*Instalacion de GIT*/
sudo apt-get install git

/*Ligar el DNS dinamico a la IP de SAGA*/
curl https://freemyip.com/update?token=a163b52abe2a7d2cbf9b9a6f&domain=saga.freemyip.com

/*Ligar el DNS dinamico a la IP de CETIPT*/
curl https://freemyip.com/update?token=5524f9218a66e7ff40f995cd&domain=cetipt.freemyip.com

/*Relacionar el dominio con la IP de manera automatica*/
crontab -e
#DOMINIO SAGA
*/5 * * * * curl https://freemyip.com/update?token=a163b52abe2a7d2cbf9b9a6f&domain=saga.freemyip.com

#DOMINIO CETIPT
*/5 * * * * curl https://freemyip.com/update?token=5524f9218a66e7ff40f995cd&domain=cetipt.freemyip.com

sudo systemctl restart cron

/*Apache 2*/
sudo apt-get install apache2 -y

/*Gestor de base de datos*/
sudo apt-get install mariadb-server -y

/*Instalacion de PHP*/
sudo apt-get install php -y

/*Instalacion de PHPMyAdmin*/
sudo apt-get install phpmyadmin

/*Configuraciones dentro del instalador

Indicar que se usara apache2

Indicar que se va configurar la base de datos
Configurar la contraseña del usuario root de la base de datos: 
CLAVE = srvtyDB#
Aceptar
*/

/*Configuracion de usuario y permisos de la base de datos mariaDB*/
sudo -i
mariadb -u root -p

//Crear usuario y contraseña para la base de datos de SAGA
create user 'DBA-Saga'@'%' identified by 'srvtySDL&';
grant all privileges on *.* to 'DBA-Saga'@'%' with grant option;
flush privileges;

//Crear usuario y contraseña para la base de datos de CETIPT
create user 'DBA-Cetipt'@'%' identified by 'hent41#';
grant all privileges on *.* to 'DBA-Cetipt'@'%' with grant option;
flush privileges;

exit


/*Habilitar componentes de APACHE2*/
sudo a2enmod proxy_fcgi
//Habilitar modulo SSL
sudo a2enmod ssl
//Habilitar modulo HTTP2
sudo a2enmod http2

/*Reiniciar el servicio de apache2*/
sudo systemctl restart apache2

/*Crear carpeta para los sitios de los dominios*/
//Direccion para SAGA
sudo mkdir /var/www/html/saga

//Direccion para CETIPT
sudo mkdir /var/www/html/cetipt


/*-------------------------------------------------------Configuracion de FTP-------------------------------------------------------*/
/*Instalacion de FTP para el servidor*/
sudo apt-get install vsftpd -y

sudo nano /etc/vsftpd.conf
//Descomentar las siguientes lineas
write_enable=YES
local_umask=022
chroot_local_user=YES
allow_writeable_chroot=YES


//Crear usuario para FTP de SAGA
sudo adduser sagaftp
sudo passwd srcpyCommits#
//Darle permisos de escritura y lectura al usuario
sudo chown -R sagaftp:sagaftp /var/www/html/saga/
sudo chmod -R 755 /var/www/html/saga/



//Crear usuario para FTP de CETIPT
sudo adduser cetiptftp
sudo passwd jiutepec#
//Darle permisos de escritura y lectura al usuario
sudo chown -R cetiptftp:cetiptftp /var/www/html/cetipt/
sudo chmod -R 755 /var/www/html/cetipt/

//Reiniciar el servicio de FTP
sudo systemctl restart vsftpd

/*Instalacion de Vscode para el servidor en la raspberry pi 4 */
//Abrir chromium
//Ingresar al siguiente link


//Darle permisos para editar las carpetas de los dominios [SAGA]
sudo chown -R lnxserver:lnxserver /var/www/html/saga
sudo chmod -R 755 /var/www/html/saga


/*-------------------------------------------------------Configuracion de Git Hub-------------------------------------------------------*/
//Configurar el usuario de git
git config --global user.name "bitersDevs"
git config --global user.email "sgceo.biters@gmail.com"

//Clonar el repositorio de SAGA en la ruta /var/www/html/saga
cd /var/www/html/saga
git clone https://github.com/GaliciaDev/saga.git

//Clonar el repositorio de CETIPT en la ruta /var/www/html/cetipt
cd /var/www/html/cetipt
git clone https://github.com/GaliciaDev/cetipt.git

//Darle permisos de escritura y lectura a git en las carpetas de los dominios
sudo chown -R git /var/www/html/saga
sudo chown -R git /var/www/html/cetipt










