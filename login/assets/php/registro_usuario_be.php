<?php

    /* Instancia a la conexion HOST-DB */
    include 'conexion_be.php';

    /* Variables de inicio de sesion */
    $nombre_completo = $_POST['nombre_completo'];
    $correo= $_POST['correo'];
    $usuario= $_POST['usuario'];
    $contrasena= $_POST['contrasena'];

    /* Encriptacion */
    $contrasena = hash('sha512',$contrasena);

    /* Consultas [Nota: respeta el orden de las consultas]*/
    $query = "INSERT INTO usuarios(nombre_completo, correo, usuario, contrasena)
                VALUES('$nombre_completo', '$correo', '$usuario', '$contrasena')";

    /* Verificar que el usuario no se repita no exista en la BD*/
    $verificar_usuario = mysqli_query($conexion, "SELECT * FROM usuarios WHERE usuario='$usuario' ");
    
    if (mysqli_num_rows($verificar_usuario) > 0){
        echo '
            <script>
                alert("Este usuario ya esta registrado, intenta con otro diferente");
                window.location = "../../index.php";
            </script>
        ';
        exit();
    }

    /* Verificar que el correo no se repita no exista en la BD*/
    $verificar_correo = mysqli_query($conexion, "SELECT * FROM usuarios WHERE correo='$correo' ");
    
    if (mysqli_num_rows($verificar_correo) > 0){
        echo '
            <script>
                alert("Este correo ya esta registrado, intenta con otro diferente");
                window.location = "../../index.php";
            </script>
        ';
        exit();
    }

    /* Depuracion */
    $ejecutar = mysqli_query($conexion,$query);

    /* Condicion para redireccionar */
    if($ejecutar){
        echo '
            <script>
                alert("Usuario almacenado exitosamente");                                
                window.location = "../../index.php";
            </script>
            ';
    }
    else {
        echo '
            <script>
                alert("Intentalo de nuevo, usuario no almacenado");                                
                window.location = "../../index.php";
            </script>
            ';        
    }

    /* Cierre de conexion con la base de datos */
    mysqli_close($conexion);

?>