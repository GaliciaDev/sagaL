<?php
    session_start();
    /* Aqui comparamos si hay una sesion iniciada, guardada en las Cookies */
    if(!isset($_SESSION['usuario'])){
        echo '
            <script>
                alert("Por favor debes iniciar sesion");
                window.location = "index.php";
            </script>
        ';

        /* Esta linea, cierra la sesion */
        session_destroy();
        die();        
    }

    
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bienvenida</title>
</head>
<body>
    <h1>Bienvenido a  mi pagina</h1>

    <!-- Cerrar session -->
    <a href="assets/php/cerrar_sesion.php">Cerar session</a>
</body>
</html>