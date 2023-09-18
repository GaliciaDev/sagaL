<?php
    session_start();

    if(isset($_SESSION['usuario'])) {
        header("location: bienvenida.php");
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registro</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Roboto:ital,wght@0,100;0,300;0,400;0,500;0,700;0,900;1,100;1,300;1,400;1,500;1,700;1,900&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="assets/css/inicioDsesion.css">
</head>

<body>
    <main>
        <div class="contenedor__todo">
            <div class="caja__trasera">
                <div class="caja__trasera-inicio">
                    <h3>¿Eres parte de la institucion?</h3>
                    <p>Inicia sesion para entrar</p>
                    <button id="btnIniciarSesion">Iniciar sesion</button>

                </div>
            
                <div class="caja__trasera-registro">
                    <h3>¿Aun no tienes cuenta?</h3>
                    <p>Registrate para ver el desempeño academico de su hijo</p>
                    <button id="btnRegistro">Registrate</button>

                </div>    
            </div>

            <!-- Formularios de inicio de R-I -->
            <div class="registros">
                 <form action="assets/php/login_usuario_be.php" method="POST" class="inicioDs">
                    <h2>Iniciar sesion</h2>
                    <input type="text" placeholder="Correo Electronico" name="correo">
                    <input type="password" placeholder="Contraseña" name="contrasena">
                    <button>Entrar</button>
                    
                 </form>

                 <form action="assets/php/registro_usuario_be.php" method="POST" class="registrarU">
                    <h2>Registrarte</h2>
                    <input type="text" placeholder="Nombre Completo" name="nombre_completo">
                    <input type="text" placeholder="Correo Electronico" name="correo">
                    <input type="text" placeholder="Usuario" name="usuario">
                    <input type="password" placeholder="Contraseña" name="contrasena">
                    <button>Registrarte</button>

                 </form>
            </div>
        </div>
    </main>  
    
    <script src="assets/js/animacionFormularios.js"></script>
</body>
</html>