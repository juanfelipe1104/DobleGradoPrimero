// Variables

var base = document.getElementById('base').value;
var altura = document.getElementById('altura').value;
var radioC = document.getElementById('radio').value;
var areaT;
var areaC;

function calculaAreaT(){
	areaT = parseFloat(base) * parseFloat(altura) / 2;
	document.getElementById('resultado_T').value = areaT;
}

function calculaAreaCirculo(){
	areaC = parseFloat(radioC) * parseFloat(radioC) * Math.PI;
	document.getElementById('resultado_C').value = areaC;
}