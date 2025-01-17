var numero = 1;

function prev(){
	numero--;
	if (numero === 0) {
		document.getElementById('image').src=("foto1.png");
	}
	else {
		document.getElementById('image').src=("foto" + numero + ".png");
	}
}
function next(){
	numero++;
	if (numero === 6) {
		document.getElementById('image').src=("foto5.png");
	}
	else {
		document.getElementById('image').src=("foto" + numero + ".png")
	}
}