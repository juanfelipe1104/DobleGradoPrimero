var nombre;
var cartas = ["img/magician.png", "img/hierophant.png", "img/chariot.png", "img/star.png", "img/world.png", "img/fool.png", "img/magician.png", "img/hierophant.png", "img/chariot.png", "img/star.png", "img/world.png", "img/fool.png"];
var permitirVoltearCartas = true;
var puntuacion = 0;
var segundos, minutos, tiempo;

function jugar(){
	nombre = document.getElementById("nombre").value;
	if (nombre === ''){
		alert("Ingresa un nombre");
	}
	else {
		document.getElementsByClassName("titulo")[0].className += " zoom-out";
		document.getElementById("nombre").className += " zoom-out";
		document.getElementById("jugar").className += " zoom-out";
		document.getElementsByClassName("titulo")[1].className = "titulo";
		document.getElementsByClassName("dificultad")[0].className = "dificultad";
		document.getElementsByClassName("dificultad")[1].className = "dificultad";
		document.getElementsByClassName("dificultad")[2].className = "dificultad";
		document.getElementById("reset").className = "";
		document.getElementsByClassName("descripcion")[1].innerHTML = "Nombre: " + nombre + "<br>Puntuacion: " + puntuacion;
	}
}

function dificultad(){
	var aleatorio;
	document.getElementsByClassName("titulo")[1].className += " zoom-out";
	document.getElementsByClassName("dificultad")[0].className += " zoom-out";
	document.getElementsByClassName("dificultad")[1].className += " zoom-out";
	document.getElementsByClassName("dificultad")[2].className += " zoom-out";
	document.getElementsByClassName("titulo")[2].className = "titulo";
	document.getElementsByClassName("descripcion")[0].className = "descripcion";
	document.getElementsByClassName("descripcion")[1].className = "descripcion";
	document.getElementById("tiempoRestante").className = "";
	document.getElementsByClassName("cartas")[0].className = "cartas";
	document.getElementsByClassName("cartas")[1].className = "cartas";
	document.getElementsByClassName("cartas")[2].className = "cartas";
	document.getElementsByClassName("cartas")[3].className = "cartas";
	document.getElementsByClassName("cartas")[4].className = "cartas";
	document.getElementsByClassName("cartas")[5].className = "cartas";
	document.getElementsByClassName("cartas")[6].className = "cartas";
	document.getElementsByClassName("cartas")[7].className = "cartas";
	document.getElementsByClassName("cartas")[8].className = "cartas";
	document.getElementsByClassName("cartas")[9].className = "cartas";
	document.getElementsByClassName("cartas")[10].className = "cartas";
	document.getElementsByClassName("cartas")[11].className = "cartas";
	aleatorio = cartas.sort(function(){return 0.5 - (Math.random())});
}

function facil(){
	minutos = 4;
	segundos = 59;
	tiempo = setInterval(duracion,1000);
	dificultad();
}

function medio(){
	minutos = 2;
	segundos = 30;
	tiempo = setInterval(duracion,1000);
	dificultad();
}

function dificil(){
	minutos = 0;
	segundos = 59;
	tiempo = setInterval(duracion,1000);
	dificultad();
}

function duracion(){
	if ((segundos === 0) && (minutos === 0)) {
		clearInterval(tiempo);
		document.getElementsByClassName("titulo")[3].innerHTML = "Perdiste";
		document.getElementsByClassName("descripcion")[2].innerHTML = "Se te acabo el tiempo!!!";
		terminar();
	}
	else if ((segundos === 0)){
		minutos--;
		segundos = 59;
		if (segundos > 9){
			document.getElementById("tiempoRestante").innerHTML = ("Tiempo restante: 0:0" + minutos + ":" + segundos);
		}
		else{
			document.getElementById("tiempoRestante").innerHTML = ("Tiempo restante: 0:0" + minutos + ":0" + segundos);
		}
	}
	else {
		segundos--;
		if (segundos > 9){
			document.getElementById("tiempoRestante").innerHTML = ("Tiempo restante: 0:0" + minutos + ":" + segundos);
		}
		else{
			document.getElementById("tiempoRestante").innerHTML = ("Tiempo restante: 0:0" + minutos + ":0" + segundos);
		}
	}
}

function verificarCarta(){
	var cartasIguales = [];
	var carta, carta2;
	var encontroCartasIguales;
	puntuacion = 0;
	for (var i = 0; i < 12; i++) {
		carta = document.getElementsByClassName("cartas")[i].src;
		if (carta.indexOf("reverso.jpg") === -1) {
			for (var j = 0; j < 12; j++) {
				carta2 = document.getElementsByClassName("cartas")[j].src;
				if ((i != j) && (carta === carta2)) {
					cartasIguales.push(i);
					cartasIguales.push(j);
				}
			}
		}
	}
	for (var i = 0; i < 12; i++) {
		encontroCartasIguales = false;
		for (var j = 0; j < cartasIguales.length; j++) {
			if (i === cartasIguales[j]){
				encontroCartasIguales = true;
			}
		}
		if (encontroCartasIguales === false){
			document.getElementsByClassName("cartas")[i].src = "img/reverso.jpg";
			document.getElementsByClassName("cartas")[i].className = "cartas";
		}
		else{
			puntuacion += 12.5;
			document.getElementsByClassName("descripcion")[1].innerHTML = "Nombre: " + nombre + "<br>Puntuacion: " + puntuacion;
			comprobarFin(puntuacion);
		}
	}
	permitirVoltearCartas = true;
}

function voltearCarta(imagen, numeroCarta){
	var carta;
	var totalVolteadas;
	if (permitirVoltearCartas === true){
		totalVolteadas = 0;
		imagen.className += " giro";
		imagen.src = cartas[numeroCarta];
		for (var i = 0; i < 12; i++) {
			carta = document.getElementsByClassName("cartas")[i].src;
			if (carta.indexOf("reverso.jpg") === -1) {
				totalVolteadas++;
			}
		}
		if (totalVolteadas % 2 === 0) {
			permitirVoltearCartas = false;
			setTimeout(verificarCarta, 1000);
		}
	}
}

function comprobarFin(puntuacion){
	if (puntuacion === 150){
		document.getElementsByClassName("titulo")[3].innerHTML = "Ganaste";
		document.getElementsByClassName("descripcion")[2].innerHTML = "Lograste encontrar las parejas antes de que acabase el tiempo. Enhorabuena!!!";
		terminar();
	}
}

function terminar(){
	document.getElementsByClassName("titulo")[2].className += " zoom-out";
	document.getElementsByClassName("descripcion")[0].className += " zoom-out";
	document.getElementsByClassName("descripcion")[1].className += " zoom-out";
	document.getElementById("tiempoRestante").className += " zoom-out";
	document.getElementsByClassName("cartas")[0].className += " zoom-out";
	document.getElementsByClassName("cartas")[1].className += " zoom-out";
	document.getElementsByClassName("cartas")[2].className += " zoom-out";
	document.getElementsByClassName("cartas")[3].className += " zoom-out";
	document.getElementsByClassName("cartas")[4].className += " zoom-out";
	document.getElementsByClassName("cartas")[5].className += " zoom-out";
	document.getElementsByClassName("cartas")[6].className += " zoom-out";
	document.getElementsByClassName("cartas")[7].className += " zoom-out";
	document.getElementsByClassName("cartas")[8].className += " zoom-out";
	document.getElementsByClassName("cartas")[9].className += " zoom-out";
	document.getElementsByClassName("cartas")[10].className += " zoom-out";
	document.getElementsByClassName("cartas")[11].className += " zoom-out";
	document.getElementsByClassName("titulo")[3].className = "titulo final";
	document.getElementsByClassName("descripcion")[2].className = "descripcion final";
	document.getElementById("reset").className = "final";
}

document.getElementById("reset").onclick = function(){location.reload()};