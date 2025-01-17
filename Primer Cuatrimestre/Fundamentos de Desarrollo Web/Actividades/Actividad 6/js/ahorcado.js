// *** JUEGO AHORCADO ***

// *** VARIABLES ***
// Añadi dos nuevos arrays para las dificultades
var palabrasFacil = ["caballero", "espada", "escudo", "reina", "rey", "castillo", "dragon",
					"armadura", "arco", "flecha", "brujas", "magia", "hechizo", "reino", "encantado", 
					"justa", "torneo", "pocima", "mazmorra", "calabozo", "doncella", "corona", 
/*60palabras*/		"justicia", "batalla", "asedio", "catapulta", "tunica", "elixir",
					"magica", "cruzada", "forja", "oraculo", "alquimia", "pergamino",
					"grifo", "halcon", "ladron", "aristocrata", "festival", "caballeria",
					"hereje", "inquisidor", "linaje", "mito", "hacha", "armero", "barba",
					"brujo", "reliquia", "taberna", "ronda", "bosque", "mitologia",
					"sirviente", "trono", "joya", "heraldica", "torre", "legendaria", "tragedia"];

var palabrasMedio = [ "espada", "caballero", "hechicero", "arco", "mazmorra", "dragon", 
					"reina", "rey", "torneo", "escudo", "justiciero", "pocima", 
					"bruja", "castillo", "armadura", "caballeria", "flecha", "festival", 
					"reino", "princesa", "calabozo", "justicia", "batalla", "asedio", "catapulta", 
/*60palabras*/		"tunica", "elixir", "magico", "cruzada", "forja", "oraculo", 
					"alquimia", "principe", "pergamino", "grifo", "halcon", "ladron", "aristocrata", 
					"caballo", "hereje", "inquisidor", "linaje", "mito", "hacha", 
					"armero", "barbudo", "brujo", "reliquia", "taberna", "ronda", 
					"bosque", "mitologia", "sirviente", "trono", "joya", 
					"heraldica", "torre", "legendaria", "tragedia", "fantasma", 
					"piedra", "nobleza", "bestia", "pocion", "linaje"];

var palabrasDificil = ["espiritu", "sombra", "jardin", "tragedia", "luna", "mascara", "ruina",
					"leyenda", "arquero", "estandarte", "roble", "sagrado", "crepusculo", "princesa",
					"poder", "honor", "espada", "sagrada", "mito", "antiguo", "bestia", "mitica", "canto",
					"amuleto", "destino", "paladin", "perdido", "caldero", "batalla", "eterna", "furia",
/*60palabras*/		"halcon", "real", "sendero", "reliquia", "ancestral", "vigia", "guardian", "emblema",
					"morada", "antorcha", "sortilegio", "espada", "eter", "hechizo", "olvidado",
					"centinela", "diosa", "misterio", "demonio", "destino", "entrelazado",
					"primo", "hoja", "ebano", "promesa", "manantial", "susurro", "legado", "campana"];
				
var palabra = ""; // Palabra a averiguar
var rand;  // nº aleatorio
var oculta = [];  // Palabra oculta. Array vacío
var cont = 6;  //Contador
var hueco = document.getElementById("palabra");  
var buttons = document.getElementsByClassName('letra');  // Botones de letras
var btnInicio = document.getElementById("reset");  // Boton de reset
// Cambie todos los audios
var rightAudio = new Audio("sfx/right.mp3");
var wrongAudio = new Audio("sfx/wrong.mp3");
var completeAudio = new Audio("sfx/victory.mp3");
var gameOver = new Audio("sfx/gameOver.mp3");


// *** FUNCIONES ***
// Añadido desde la linea 57 hasta la 127
/* La funcion jugar consiste en:
- Esconde con la clase zoom-out los elementos mostrados al iniciar el HTML
- Remueve la clase zoom-out de los siguientes elementos a mostrar
- Se activa al darle al boton de la linea 19 del HTML
*/
function jugar(){
	document.getElementsByClassName("titulo")[0].className += " zoom-out";
	document.getElementById("jugar").className += "zoom-out";
	document.getElementById("espada").className += "zoom-out";
	document.getElementsByClassName("titulo")[1].className = "titulo";
	document.getElementsByClassName("dificultad")[0].className = "dificultad";
	document.getElementsByClassName("dificultad")[1].className = "dificultad";
	document.getElementsByClassName("dificultad")[2].className = "dificultad";
	document.getElementById("reset").className = "";
}
/* La funcion dificultad consiste en:
- Esconde con la clase zoom-out los elementos mostrados por la funcion jugar excepto el Id "reset"
- Remueve la clase zoom-out de los siguientes elementos a mostrar
- Se activa dependiendo de la funcion seleccionada (facil, medio, dificil)
*/
function dificultad(){
	pintarGuiones(palabra.length);
	generaABC("a","z");
	document.getElementById("intentos").innerHTML = cont;
	document.getElementsByClassName("titulo")[1].className += " zoom-out";
	document.getElementById("descripcion").className = "";
	document.getElementsByClassName("dificultad")[0].className += " zoom-out";
	document.getElementsByClassName("dificultad")[1].className += " zoom-out";
	document.getElementsByClassName("dificultad")[2].className += " zoom-out";
	document.getElementsByClassName("titulo")[2].className = "titulo";
	document.getElementById("picture").className = "";
	document.getElementById("turnos").className = "";
	document.getElementById("intentos").className = "";
	document.getElementById("reset").className = "";
	document.getElementById("main-container").className = "";
	document.getElementsByTagName('body')[0].style.backgroundImage = 'url("img/paisaje_medieval2.jpeg")'
}
/* La funcion facil consiste en:
- Activa las funciones generaPalabraFacil y dificultad
- Se activa al darle al boton de la linea 23 del HTML
*/
function facil(){
	generaPalabraFacil();
	dificultad();
}
/* La funcion facil consiste en:
- Activa las funciones generaPalabraMedio y dificultad
- Se activa al darle al boton de la linea 24 del HTML
*/
function medio(){
	generaPalabraMedio();
	dificultad();
}
/* La funcion facil consiste en:
- Activa las funciones generaPalabraDificil y dificultad
- Se activa al darle al boton de la linea 25 del HTML
*/
function dificil(){
	generaPalabraDificil();
	dificultad();
}
/* Las siguientes funciones que empiezan por "genera" son la misma que la original ("generaPalabra"), solo con el cambio del tipo de array utilizado */
function generaPalabraFacil(){
  rand = Math.round(Math.random() * palabrasFacil.length); //nº aleatorio entre 0 y 60 
  palabra = palabrasFacil[rand].toUpperCase();
}

function generaPalabraMedio(){
  rand = Math.round(Math.random() * palabrasMedio.length); //nº aleatorio entre 0 y 60 
  palabra = palabrasMedio[rand].toUpperCase();
}

function generaPalabraDificil(){
  rand = Math.round(Math.random() * palabrasDificil.length); //nº aleatorio entre 0 y 60 
  palabra = palabrasDificil[rand].toUpperCase();
}

function pintarGuiones(num){
  for (var i = 0; i < num; i++){
    oculta[i] = "_";
  }
  hueco.innerHTML = oculta.join("");
}

//Generar abecedario (teclado)
function generaABC(a,z){
	document.getElementById("abcdario").innerHTML = "";
	var i = a.charCodeAt(0);
	var j = z.charCodeAt(0);
	var letra = "";
	for(i,j ; i<=j ; i++){
		letra = String.fromCharCode(i).toUpperCase();
		document.getElementById("abcdario").innerHTML += "<button value='" + letra + "' onclick='intento(\"" + letra + "\")' class='letra' id='"+letra+"'>" + letra + "</button>";
		if(i==110){
		document.getElementById("abcdario").innerHTML += "<button value='Ñ' onclick='intento(\"Ñ\")' class='letra' id='"+'Ñ'+"'>Ñ</button>";
		}
	}	
}

// Chequear intento (Cambie todos los mensajes de cada innerHTML)
function intento(letra){
  document.getElementById(letra).disabled = true;
  if(palabra.indexOf(letra) != -1){
    for(var i=0; i<palabra.length; i++){
      if(palabra[i]==letra){
		  oculta[i] = letra;
	  } 
    }
    hueco.innerHTML = oculta.join("");
    document.getElementById("acierto").innerHTML = "Has esquivado a la muerte";
    document.getElementById("acierto").className = "acierto verde";
	rightAudio.play();
  }else{
    cont--;
    document.getElementById("intentos").innerHTML = cont;
    document.getElementById("acierto").innerHTML = "Te apuñalaron";
    document.getElementById("acierto").className = "acierto rojo";
    document.getElementById("image"+cont).className += "fade-in";
	wrongAudio.play();
  }
  compruebaFin();
  setTimeout(function (){ 
    document.getElementById("acierto").className = ""; 
  }, 1000);
}

// Compruba si ha finalizado
/* Cambios:
- Añadi en las lineas 192 y 200 el cambio del boton en vez de al final (como originalmente estaba), para que solo cambiase cuando finalizaba el juego
- De la linea 201 a la 204 añadi el bucle con la linea 204 para mostrar la palabra al final (201-203) y eliminar los guiones (204)
- Cambie los mensajes de cada innerHTML
*/
function compruebaFin() {
	if(oculta.indexOf("_") == -1){
		document.getElementById("mensaje-final").innerHTML = "Has ganado la gratitud del pueblo";
		document.getElementById("mensaje-final").className += "zoom-in";
		for (var i = 0; i < buttons.length; i++){
			buttons[i].disabled = true;
		}
		completeAudio.play();
		btnInicio.innerHTML = "Volver a intentar";
    }else if(cont == 0) {
		document.getElementById("mensaje-final").innerHTML = "La palabra era: ";
		document.getElementById("mensaje-final").className += "zoom-in";
		for (var i = 0; i < buttons.length; i++){
			buttons[i].disabled = true;
		}
		gameOver.play();
		btnInicio.innerHTML = "Volver a intentar";
		for(var i=0; i<palabra.length; i++){
			oculta[i] = palabra[i]; 
		}
		hueco.innerHTML = oculta.join("");
	}	
}

btnInicio.onclick = function(){location.reload()}; /*carga de nuevo la URL actual, como el refresh del navegador*/

