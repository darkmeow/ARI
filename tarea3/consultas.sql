\o /home/meow/ownCloud/U/ILI135_ARI/ARI/tarea3/query_result.out

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

SELECT nombre, precio
FROM
  public."Productos"
WHERE precio < 500
;

--Mostrar el nombre completo de todos los empleados que hayan vendido algún "Queque" un "Martes"

SELECT CONCAT(A1.nombre, A1.apellido_paterno, A1.apellido_materno) NOMBRE,to_char(fecha_y_hora::timestamp, 'TMDay') AS dia, A2.nombre NOMBRE_PRODUCTO
FROM public."Ventas" Ventas, public."Empleados" A1, public."Productos" A2
GROUP BY Ventas.rut, fecha_y_hora, A1.nombre, apellido_paterno, apellido_materno, A1.rut, A2.nombre, Ventas.id_producto, A2.id_producto
HAVING to_char(fecha_y_hora::timestamp, 'TMDay') = 'Martes' AND  A1.rut = Ventas.rut AND Ventas.id_producto = A2.id_producto AND A2.nombre = 'Queque'
;

--INSERT Ingresamos un nuevo producto
INSERT INTO "Productos" VALUES(DEFAULT,'Negrita','Comestible',100,150);

--SELECT Seleccionamos Negrita y vemos su información
SELECT nombre, tipo, precio, stock FROM public."Productos" WHERE nombre = 'Negrita';

--UPDATE Cambiamos el Stock de la Negrita de 150 a 100
UPDATE "Productos" SET stock = 100 WHERE nombre = 'Negrita';

--Nuevo Select para ver si funciona
SELECT nombre, stock, precio FROM public."Productos" WHERE nombre = 'Negrita';

--DELETE Borramos el producto
DELETE FROM public."Productos" WHERE nombre = 'Negrita';

--Nuevo Select para ver si funciona
SELECT nombre, stock, precio FROM public."Productos" WHERE nombre = 'Negrita';


\o
