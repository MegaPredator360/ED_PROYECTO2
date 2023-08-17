// Para redirigir basado en un click
function redirigirBoton1() {
    var top = document.getElementById("titulo1").offsetTop - document.getElementById("navbar").offsetHeight - 10;
    window.scrollTo({
        top: top,
        behavior: "smooth"
    });
}

function redirigirBoton2() {
    var top = document.getElementById("titulo2").offsetTop - document.getElementById("navbar").offsetHeight - 10;
    window.scrollTo({
        top: top,
        behavior: "smooth"
    });
}

// Modo Oscuro
function toggleDarkMode() {
    var element = document.body;
    element.classList.toggle("darkMode");
 }