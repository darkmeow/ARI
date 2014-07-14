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

-- CONSULTAS EXTRAS

--INSERT
INSERT INTO "Productos" VALUES(DEFAULT,'Negrita','Comestible',100,150); -- Ingresar producto nuevo
INSERT INTO "Productos" VALUES(DEFAULT, 'Chocolito', 'Comestible',1000,100); -- Ingresar producto nuevo
INSERT INTO "Empleados" VALUES(12245954,'k','Juan','Perez','Soto', 'Ingeniería Civil'); -- Ingresar empleado nuevo
INSERT INTO "Empleados" VALUES(18203034,1,'Alexis','Medel','Vidal', 'Ingeniería Electrónica'); -- Ingresar empleado nuevo
INSERT INTO "Horarios" VALUES(DEFAULT,12245954,'Jueves', '09:00:00', '13:00:00'); -- Ingresar horario nuevo

--SELECT
SELECT nombre, tipo, precio, stock FROM public."Productos" WHERE nombre = 'Negrita'; -- Seleccionar producto llamado Negrita
SELECT nombre, tipo, precio, stock FROM public."Productos" WHERE stock < 10; -- Seleccionar productos con stock menor a 10
SELECT * FROM public."Empleados"; -- Seleccionar todos los empleados
SELECT * FROM public."Ventas" WHERE cantidad > 3; -- Seleccionar ventas cuya cantidad sea superior a 3
SELECT * FROM public."Horarios" WHERE dia='Jueves'; -- Seleccionar el horario de los días Jueves

--UPDATE
UPDATE "Productos" SET stock = 100 WHERE nombre = 'Negrita'; -- Actualizar el stock del producto Negrita a 100
UPDATE "Horarios" SET hora_inicio = '08:00:00' WHERE rut = 12245954 AND dia = 'Jueves'; -- Actualizar el horario de inicio para el turno del día Jueves del empleado RUT 12245954
UPDATE "Productos" SET precio = 200 WHERE nombre = 'Negrita'; -- Actualizar el precio del producto Negrita a 200
UPDATE "Horarios" SET rut = 18203034 WHERE dia = 'Lunes'; -- Actualizar el horario del día Lunes y asignarlo al empleado 18203034
UPDATE "Empleados" SET carrera = 'Ingeniería Civil Electrónica' WHERE rut = 18203034; -- Actualizar la carrera del empleado 18203034

--DELETE Borramos el producto
DELETE FROM public."Productos" WHERE nombre = 'Negrita'; -- Eliminar producto de nombre Negrita
DELETE FROM public."Horarios" WHERE rut = 12245954 OR rut = 18203034; -- Eliminar horarios de empleado 12245954 o 18203034
DELETE FROM public."Productos" WHERE precio = 1000; -- Eliminar productos de precio 1000
DELETE FROM public."Empleados" WHERE rut = 12245954; -- Eliminar empleado de rut 12245954
DELETE FROM public."Horarios" WHERE dia = 'Domingo' -- Eliminar los horarios del día domingo :D

--Nuevo Select para ver si funciona
SELECT nombre, stock, precio FROM public."Productos" WHERE nombre = 'Negrita';


\o
