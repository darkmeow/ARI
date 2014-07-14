 _______________
|TAREA 3 ARI    |
|               |
|Barbarita Lara |
|   201021048-0 |
 ---------------

La creación de índices se utiliza para acelerar el acceso a los datos mediante operaciones físicas más rápidas y eficientes. Básicamente, el Index permite acceder más rápido a los datos. 
Es necesario si se requiere hacer consultas optimizadas y eficientes.

**Nuevos Indices:

+ La consulta "Mostrar el nombre completo de todos los empleados que hayan vendido algún "Queque" un "Martes"", se demora 2,45ms en una BD con pocos productos. Pensando en una situación cotidiana con muchos productos, puede demorarse aún más, por lo mismo es necesario indexar: "nombre" (tabla Productos).
+ Otra consulta que requiere acelerar la búsqueda es, "Mostrar el nombre completo de todos los empleados que trabajan los "Viernes"", por lo mismo es necesario indexar: "dia" (tabla Horarios)

**Extras:
 + El archivo contenido.sql contiene los datos de ejemplo para poblar la Base de Datos.
 + Para probar las consultas en mi computador utilicé los comandos
 	
 	  	psql -U meow -h localhost -d ari -f consultas.sql && vim query_result.out
 	
 	Permite conectarse con mi usuario a la BD "ari" y ejecutar las consultas para luego guardar los resultados en
"query_result.out".

	IMPORTANTE: 

	Para lograr esto el archivo consultas.sql debe comenzar con:
 	
 	  	\o /home/meow/ownCloud/U/ILI135_ARI/ARI/tarea3/query_result.out
 	
 	y terminar con 
 		\o
 	Esto indica donde se guarda el archivo con los resultados.




