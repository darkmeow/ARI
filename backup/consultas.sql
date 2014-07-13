<<<<<<< HEAD
﻿\o /home/meow/ownCloud/U/ILI135_ARI/ARI/tarea3/query_result.out
=======
﻿\o /home/meow/Documentos/query_result.out
>>>>>>> 040e29303bab39c2cb857e2a3950e54b60a9d780

--Mostrar el nombre Completo de todos los empleados de la carrera "Ingeniería Civil Informática"

SELECT CONCAT (nombre, apellido_paterno, apellido_materno), carrera
FROM 
  public."Empleados"
WHERE 
  carrera = 'Ingeniería Civil Informática'
;

--Mostrar el nombre y el stock de todos los productos que hay en kiosko

SELECT nombre,stock
FROM 
  public."Productos"
;

--Mostrar el nombre completo de los empleados que trabajan los "Viernes"

SELECT CONCAT(A1.nombre,A1.apellido_paterno,A1.apellido_materno) NOMBRE, A2.rut RUT
FROM public."Empleados" A1, public."Horarios" A2
WHERE A1.rut = A2.rut AND A2.dia = 'Viernes'
;

--Mostrar el nombre de todos los productos que cuestan menos de $500

SELECT nombre, stock
FROM
  public."Productos"
WHERE stock < 500
;

--Mostrar el nombre completo de todos los empleados que hayan vendido algún "Queque" un "Martes"

<<<<<<< HEAD
SELECT CONCAT(A1.nombre, A1.apellido_paterno, A1.apellido_materno) NOMBRE,to_char(fecha_y_hora::timestamp, 'TMDay') AS dia, A2.nombre NOMBRE_PRODUCTO
FROM public."Ventas" Ventas, public."Empleados" A1, public."Productos" A2
GROUP BY Ventas.rut, fecha_y_hora, A1.nombre, apellido_paterno, apellido_materno, A1.rut, A2.nombre, Ventas.id_producto, A2.id_producto
HAVING to_char(fecha_y_hora::timestamp, 'TMDay') = 'Martes' AND  A1.rut = Ventas.rut AND Ventas.id_producto = A2.id_producto AND A2.nombre = 'Queque'
=======
SELECT *,to_char(fecha_y_hora::timestamp, 'TMDay') AS dia
FROM public."Ventas"
GROUP BY rut, fecha_y_hora, id_producto  
HAVING to_char(fecha_y_hora::timestamp, 'TMDay') = 'Martes' 
>>>>>>> 040e29303bab39c2cb857e2a3950e54b60a9d780
;

\o
