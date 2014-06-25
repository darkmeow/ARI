\o /home/meow/Documentos/query_result.out

--Mostrar el nombre Completo de todos los empleados de la carrera "Ingeniería Civil Informática"

SELECT CONCAT (nombre, apellido_paterno, apellido_materno), carrera
FROM 
  public."Empleados"
WHERE 
  carrera = 'Ingeniería Civil Informática' ;

--Mostrar el nombre y el stock de todos los productos que hay en kiosko

SELECT nombre,stock
FROM 
  public."Productos" ;

--Mostrar el nombre completo de los empleados que trabajan los "Viernes"

SELECT CONCAT(A1.nombre,A1.apellido_paterno,A1.apellido_materno) NOMBRE, A2.rut RUT
FROM public."Empleados" A1, public."Horarios" A2
WHERE A1.rut = A2.rut AND A2.dia = 'Viernes';

--Mostrar el nombre de todos los productos que cuestan menos de $500

SELECT nombre, stock
FROM
  public."Productos"
WHERE stock < 500;

--Mostrar el nombre completo de todos los empleados que hayan vendido algún "Queque" un "Martes"

SELECT *,to_char(fecha_y_hora::timestamp, 'TMDay') AS dia
FROM public."Ventas"
GROUP BY id_producto, rut, fecha_y_hora
HAVING to_char(fecha_y_hora::timestamp, 'TMDay') = 'Martes' 
;

\o
