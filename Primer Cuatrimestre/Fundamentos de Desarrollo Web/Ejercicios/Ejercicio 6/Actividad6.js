var resultado = +prompt("Introduce un tipo de operación: \n1. Multiplicación \n2. Mayor\n3. Encabezado");

switch (resultado){
	case 1:
		multiplicacion();
		break;
	case 2:
		comparacion();
		break;
	case 3:
		encabezado();
		break;
	default:
		alert("No has ingresado 1, 2 o 3");
}

function multiplicacion () {
	var a1 = +prompt("Introduzca el primer numero: ");
	var a2 = +prompt("Introduzca el segundo numero: ");
	if (isNaN (a1) || isNaN (a2)) {
		alert("Error");
	}
	else {
		document.write(`${a1} x ${a2} igual a ${a1*a2}`);
	}
}

function comparacion () {
	var b1 = +prompt("Introduzca el primer numero: ");
	var b2 = +prompt("Introduzca el segundo numero");
	if (isNaN (b1) || isNaN (b2)) {
		alert("Error");
	}
	else {
		if (b1 > b2){
			alert(`${b1} es mayor que ${b2}`);
		}
		else if (b2 > b1){
			alert(`${b2} es mayor que ${b1}`);
		}
		else {
			alert(`${b1} es igual que ${b2}`);
		}
	}
}

function encabezado () {
	var c1 = prompt("Introduzca una linea de texto");
	var c2 = +prompt("Introduzca el tipo de encabezado (1-6)");
	if (isNaN (c2)) {
		alert("Error");
	}
	else {
		if ((c2 < 1) || (c2 > 6)){
			alert("Error");
		}
		else {
			document.write(`<h${c2}> ${c1} </h${c2}>`);
		}
	}
}