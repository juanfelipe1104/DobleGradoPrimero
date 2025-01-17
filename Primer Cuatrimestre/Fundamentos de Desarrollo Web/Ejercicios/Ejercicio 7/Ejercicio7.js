var t = 10;
var intervalo;
function restart () {
	if (t === 0) {
		document.getElementById('reloj').innerHTML = ('BOOM');
		clearInterval(intervalo);
	}
	else {
		t--;
		document.getElementById('reloj').innerHTML = ('00:00:0'+ t);
	}
}
function activar () {
	intervalo = setInterval(restart , 1000); 
}
function desactivar () {
	clearInterval(intervalo);
}