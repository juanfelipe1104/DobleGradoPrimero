var imagen = ["albert.png", "confucio.png", "descartes.png"];
var texto = ["Educación es lo que queda después de olvidar lo que se ha aprendido en la escuela.<br><br>", "Donde hay educación no hay distinción de clases.<br><br>", "Daría todo lo que sé, por la mitad de lo que ignoro.<br><br>"];
var texto2 = ['<i id="text2">Albert Einstein</i>', '<i id="text2">Confucio</i>', '<i id="text2">René Descartes</i>']
var contador = 1;

function carousel() {
	document.getElementById('image').src=imagen[contador];
	document.getElementById('text').innerHTML=texto[contador] + texto2[contador];
	contador++;
	if (contador === 3) {
		contador = 0;
	}
} 

function inicio() {
	setInterval(carousel, 3000);
}