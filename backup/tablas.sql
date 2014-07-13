--

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: Empleados; Type: TABLE; Schema: public; Owner: meow; Tablespace: 
--

CREATE TABLE "Empleados" (
    rut integer NOT NULL,
    dv "char" NOT NULL,
    nombre character(15) NOT NULL,
    apellido_materno character(15) NOT NULL,
    apellido_paterno character(15) NOT NULL,
    carrera character(30) NOT NULL
);


ALTER TABLE public."Empleados" OWNER TO meow;

--
-- Name: Horarios; Type: TABLE; Schema: public; Owner: meow; Tablespace: 
--

CREATE TABLE "Horarios" (
    id_horario integer NOT NULL,
    rut integer NOT NULL,
    dia character(9),
    hora_inicio time without time zone NOT NULL,
    hora_termino time without time zone NOT NULL
);


ALTER TABLE public."Horarios" OWNER TO meow;

--
-- Name: Horarios_id_horario_seq; Type: SEQUENCE; Schema: public; Owner: meow
--

CREATE SEQUENCE "Horarios_id_horario_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Horarios_id_horario_seq" OWNER TO meow;

--
-- Name: Horarios_id_horario_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: meow
--

ALTER SEQUENCE "Horarios_id_horario_seq" OWNED BY "Horarios".id_horario;


--
-- Name: Productos; Type: TABLE; Schema: public; Owner: meow; Tablespace: 
--

CREATE TABLE "Productos" (
    id_producto integer NOT NULL,
    nombre character(30) NOT NULL,
    tipo character(30) NOT NULL,
    precio integer NOT NULL,
    stock integer NOT NULL
);


ALTER TABLE public."Productos" OWNER TO meow;

--
-- Name: Productos_id_producto_seq; Type: SEQUENCE; Schema: public; Owner: meow
--

CREATE SEQUENCE "Productos_id_producto_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Productos_id_producto_seq" OWNER TO meow;

--
-- Name: Productos_id_producto_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: meow
--

ALTER SEQUENCE "Productos_id_producto_seq" OWNED BY "Productos".id_producto;


--
-- Name: Ventas; Type: TABLE; Schema: public; Owner: meow; Tablespace: 
--

CREATE TABLE "Ventas" (
    id_producto integer NOT NULL,
    rut integer NOT NULL,
    fecha_y_hora date NOT NULL,
    cantidad integer NOT NULL
);


ALTER TABLE public."Ventas" OWNER TO meow;

--
-- Name: Ventas_id_producto_seq; Type: SEQUENCE; Schema: public; Owner: meow
--

CREATE SEQUENCE "Ventas_id_producto_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Ventas_id_producto_seq" OWNER TO meow;

--
-- Name: Ventas_id_producto_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: meow
--

ALTER SEQUENCE "Ventas_id_producto_seq" OWNED BY "Ventas".id_producto;


--
-- Name: test; Type: VIEW; Schema: public; Owner: meow
--

CREATE VIEW test AS
 SELECT "Empleados".apellido_materno,
    "Empleados".apellido_paterno,
    "Empleados".dv,
    "Empleados".rut,
    "Empleados".nombre,
    "Empleados".carrera
   FROM "Empleados";


ALTER TABLE public.test OWNER TO meow;

--
-- Name: id_horario; Type: DEFAULT; Schema: public; Owner: meow
--

ALTER TABLE ONLY "Horarios" ALTER COLUMN id_horario SET DEFAULT nextval('"Horarios_id_horario_seq"'::regclass);


--
-- Name: id_producto; Type: DEFAULT; Schema: public; Owner: meow
--

ALTER TABLE ONLY "Productos" ALTER COLUMN id_producto SET DEFAULT nextval('"Productos_id_producto_seq"'::regclass);


--
-- Name: id_producto; Type: DEFAULT; Schema: public; Owner: meow
--

ALTER TABLE ONLY "Ventas" ALTER COLUMN id_producto SET DEFAULT nextval('"Ventas_id_producto_seq"'::regclass);


--
-- Name: Empleados_pkey; Type: CONSTRAINT; Schema: public; Owner: meow; Tablespace: 
--

ALTER TABLE ONLY "Empleados"
    ADD CONSTRAINT "Empleados_pkey" PRIMARY KEY (rut);


--
-- Name: Horarios_pkey; Type: CONSTRAINT; Schema: public; Owner: meow; Tablespace: 
--

ALTER TABLE ONLY "Horarios"
    ADD CONSTRAINT "Horarios_pkey" PRIMARY KEY (id_horario);


--
-- Name: Productos_pkey; Type: CONSTRAINT; Schema: public; Owner: meow; Tablespace: 
--

ALTER TABLE ONLY "Productos"
    ADD CONSTRAINT "Productos_pkey" PRIMARY KEY (id_producto);


--
-- Name: Ventas_pkey; Type: CONSTRAINT; Schema: public; Owner: meow; Tablespace: 
--

ALTER TABLE ONLY "Ventas"
    ADD CONSTRAINT "Ventas_pkey" PRIMARY KEY (id_producto, rut, fecha_y_hora);



--
-- Name: Horarios_rut_fkey; Type: FK CONSTRAINT; Schema: public; Owner: meow
--

ALTER TABLE ONLY "Horarios"
    ADD CONSTRAINT "Horarios_rut_fkey" FOREIGN KEY (rut) REFERENCES "Empleados"(rut);


--
-- Name: Ventas_id_producto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: meow
--

ALTER TABLE ONLY "Ventas"
    ADD CONSTRAINT "Ventas_id_producto_fkey" FOREIGN KEY (id_producto) REFERENCES "Productos"(id_producto);


--
-- Name: Ventas_rut_fkey; Type: FK CONSTRAINT; Schema: public; Owner: meow
--

ALTER TABLE ONLY "Ventas"
    ADD CONSTRAINT "Ventas_rut_fkey" FOREIGN KEY (rut) REFERENCES "Empleados"(rut);



