<?php
	// Ejemplo de conexión a base de datos MySQL con PHP.
	//
	
	
	// Datos de la base de datos. Sustituir los valores entre "" por los correspondientes de la BBDD sobre la que
	// se quiere yrabajar
	$usuario = "usuario";
	$password = "password";
	$servidor = "endpoint";
	$basededatos = "nombre_BD";
    $tabla = "nombre_tabla";
	
	// creación de la conexión a la base de datos con mysql_connect()
	$conexion = mysqli_connect( $servidor, $usuario, $password ) or die ("No se ha podido conectar al servidor de Base de datos");
	
	// Selección del a base de datos a utilizar
	$db = mysqli_select_db( $conexion, $basededatos ) or die ( "Upps! Pues va a ser que no se ha podido conectar a la base de datos" );

	// establecer y realizar consulta. guardamos en variable.
	$consulta = "SELECT * FROM $tabla";
	$resultado = mysqli_query( $conexion, $consulta ) or die ( "Algo ha ido mal en la consulta a la base de datos");
	
	// Motrar el resultado de los registro de la base de datos. Aqui podemos poner los valores que queramos a Campo1, Campo2, etc.
	// pero es una práctica ponerle nombres similares a los de la base de datos
	// Encabezado de la tabla
	echo "<table borde='2'>";
	echo "<tr>";
	echo "<th>campo1</th>";
	echo "<th>campo2</th>";
	echo "<th>Campor3</th>";
	echo "<th>Campo4</th>";
	echo "</tr>";
	
	// Bucle while que recorre cada registro y muestra cada campo en la tabla. Los valores de Campo1, Campo2, etc. deben coincidir de forma exacta
	// con los campos de la BBDD
	while ($columna = mysqli_fetch_array( $resultado ))
	{
	    echo "<tr>";
            echo "<td>" . $columna['Campo1'] . "</td><td>" . $columna['Campo2'] . "</td><td>" . $columna['Campo3'] . "</td><td>". $columna['Campo4'] . "</td>";
	    echo "</tr>";
	}
	
	echo "</table>"; // Fin de la tabla

	// cerrar conexión de base de datos
	mysqli_close( $conexion );
?>
