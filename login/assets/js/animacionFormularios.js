/* Ejecucion */
document.getElementById("btnRegistro").addEventListener("click", registros);
document.getElementById("btnIniciarSesion").addEventListener("click",iniciarSesion);
window.addEventListener("resize",ajusteAncho);

/* Variables de control */
var contenedorRegistros = document.querySelector(".registros");
var formularioIniciarS = document.querySelector(".inicioDs");
var formularioRegistro = document.querySelector(".registrarU");
var caja__trasera_inicio = document.querySelector(".caja__trasera-inicio");
var caja__trasera_registro = document.querySelector(".caja__trasera-registro");

/* Diseño Responsivo: [Reubica la posicion de los formularios, cuando se hace reduce la pantalla] */
function ajusteAncho() {
    if (window.innerWidth > 850) {
        caja__trasera_inicio.style.display = "block";
        caja__trasera_registro.style.display = "block";        
    } 
    else {
        caja__trasera_registro.style.display = "block";
        caja__trasera_registro.style.opacity = "1";
        caja__trasera_inicio.style.display = "none";
        formularioIniciarS.style.display = "block";
        formularioRegistro.style.display = "none";
        contenedorRegistros.style.left = "0px";
    }    
}
    
ajusteAncho();

/* Esta funcion se encarga de la animacion y acomodo el contenedor de registros */
function registros(){
    if (window.innerWidth > 850) {
        formularioRegistro.style.display = "block";
        contenedorRegistros.style.left = "410px";
        formularioIniciarS.style.display = "none";
        caja__trasera_registro.style.opacity = "0";
        caja__trasera_inicio.style.opacity = "1";
    } 
    else {
        formularioRegistro.style.display = "block";
        contenedorRegistros.style.left = "0px";
        formularioIniciarS.style.display = "none";
        caja__trasera_registro.style.display = "none";
        caja__trasera_inicio.style.display = "block";
        caja__trasera_inicio.style.opacity = "1";
    }

}

/* Esta funcion se encarga de la animacion y acomodo el contenedor de Inicio de sesion */
function iniciarSesion(){
    if (window.innerWidth > 850) {
        formularioRegistro.style.display = "none";
        contenedorRegistros.style.left = "10px";
        formularioIniciarS.style.display = "block";
        caja__trasera_registro.style.opacity = "1";
        caja__trasera_inicio.style.opacity = "0";
    }
    else{
        formularioRegistro.style.display = "none";
        contenedorRegistros.style.left = "0px";
        formularioIniciarS.style.display = "block";
        caja__trasera_registro.style.display = "block";
        caja__trasera_inicio.style.display = "none";        
    }
}

