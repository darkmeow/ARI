--
-- Datos de ejemplo!
--

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

SET search_path = public, pg_catalog;

--
-- Data for Name: Empleados; Type: TABLE DATA; Schema: public; Owner: meow
--

INSERT INTO "Empleados" VALUES (16207335, '4', 'Barbarita      ', 'Martínez       ', 'Lara           ', 'Ingeniería Civil Informática  ');
INSERT INTO "Empleados" VALUES (16431751, 'k', 'Roberto        ', 'Sandoval       ', 'Carvajal       ', 'Ingeniería Civil Química      ');


--
-- Data for Name: Horarios; Type: TABLE DATA; Schema: public; Owner: meow
--

INSERT INTO "Horarios" VALUES (1, 16207335, 'Lunes    ', '09:00:00', '13:00:00');
INSERT INTO "Horarios" VALUES (2, 16207335, 'Viernes  ', '09:00:00', '13:00:00');
INSERT INTO "Horarios" VALUES (3, 16431751, 'Viernes  ', '14:00:00', '18:00:00');
INSERT INTO "Horarios" VALUES (4, 16431751, 'Míercoles', '14:00:00', '18:00:00');
INSERT INTO "Horarios" VALUES (5, 16207335, 'Martes   ', '09:00:00', '13:00:00');
INSERT INTO "Horarios" VALUES (6, 16431751, 'Martes   ', '14:00:00', '18:00:00');


--
-- Name: Horarios_id_horario_seq; Type: SEQUENCE SET; Schema: public; Owner: meow
--

SELECT pg_catalog.setval('"Horarios_id_horario_seq"', 1, false);


--
-- Data for Name: Productos; Type: TABLE DATA; Schema: public; Owner: meow
--

INSERT INTO "Productos" VALUES (1, 'Queque                        ', 'Comestible                    ', 500, 100);
INSERT INTO "Productos" VALUES (3, 'Pinguinos                     ', 'Comestible                    ', 350, 800);
INSERT INTO "Productos" VALUES (4, 'Manqueque                     ', 'Comestible                    ', 300, 400);
INSERT INTO "Productos" VALUES (5, 'Super 8                       ', 'Comestible                    ', 100, 230);
INSERT INTO "Productos" VALUES (2, 'Pan con Chancho               ', 'Comestible                    ', 200, 1000);


--
-- Name: Productos_id_producto_seq; Type: SEQUENCE SET; Schema: public; Owner: meow
--

SELECT pg_catalog.setval('"Productos_id_producto_seq"', 1, false);


--
-- Data for Name: Ventas; Type: TABLE DATA; Schema: public; Owner: meow
--

INSERT INTO "Ventas" VALUES (1, 16207335, '2014-06-24', 2);
INSERT INTO "Ventas" VALUES (1, 16431751, '2014-07-01', 2);
INSERT INTO "Ventas" VALUES (1, 16431751, '2014-07-02', 3);
INSERT INTO "Ventas" VALUES (2, 16431751, '2014-07-04', 1);
INSERT INTO "Ventas" VALUES (2, 16207335, '2014-06-24', 3);


--
-- Name: Ventas_id_producto_seq; Type: SEQUENCE SET; Schema: public; Owner: meow
--

SELECT pg_catalog.setval('"Ventas_id_producto_seq"', 1, false);
