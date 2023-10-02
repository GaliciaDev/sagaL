<?php
    /* Definir que trabajaremos con variables de sesion */
    session_start();
    include 'conexion_be.php';

    /* Variables de acceso */
    $correo = $_POST['correo'];
    $contrasena = $_POST['contrasena'];
    $contrasena = hash('sha512', $contrasena);

    // Limitar los intentos de inicio de sesion con variables de sesion en 3 intentos
    if (!isset($_SESSION['intentos'])) {
        $_SESSION['intentos'] = 0;
    }

    if (isset($_SESSION['ultimoIntento']) && time() - $_SESSION['ultimoIntento'] < 20) {
        $tiempoRestante = 20 - (time() - $_SESSION['ultimoIntento']);
        echo '
            <script>
                alert("Debe esperar '.$tiempoRestante.' segundos antes de intentar iniciar sesión nuevamente");
                var tiempoRestante = '.$tiempoRestante.';
                var intervalo = setInterval(function() {
                    tiempoRestante--;
                    if (tiempoRestante <= 0) {
                        clearInterval(intervalo);
                        window.location = "../../index.php";
                    }
                    else {
                        document.getElementById("tiempo-restante").innerHTML = tiempoRestante;
                    }
                }, 1000);
            </script>
        ';
        exit;
    }

    if ($_SESSION['intentos'] > 3) {
        echo '
            <script>
                alert("Ha excedido el numero de intentos permitidos");
                window.location = "../../index.php";
            </script>
        ';
        exit;
    }
    else {
        $_SESSION['intentos']++;
        $_SESSION['ultimoIntento'] = time();
    }

    /* Consulta y verificacion del usuario */
    $validar_login = mysqli_query($conexion, "SELECT * FROM usuarios WHERE correo='$correo'
    and contrasena='$contrasena'");

    if (mysqli_num_rows($validar_login) > 0) {
        /* Variables de sesion */
        $_SESSION['usuario'] = $correo;
        header("location: ../../bienvenida.php");
        exit;

    }
    else {
        echo '
            <script>
                alert("Usuario no existe, por favor verifique los datos introducidos");
                window.location = "../../index.php";
            </script>
        ';

        exit;
    }
?>