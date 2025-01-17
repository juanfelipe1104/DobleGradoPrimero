var fecha, hora, minuto, dia, mes, año;

function fechaActual(){
	fecha = new Date();
	hora = fecha.getHours();
	minuto = fecha.getMinutes();
	segundo = fecha.getSeconds();
	dia = fecha.getDate();
	mes = fecha.getMonth();
	año = fecha.getFullYear();
	document.getElementById('hora').innerHTML=(hora + ':' + minuto + ':' + segundo);
	document.getElementById('fecha').innerHTML=(dia + '/' + (mes + 1) + '/' + año);
}

function inicio(){
	fechaActual();
	setInterval(fechaActual, 1000);
}