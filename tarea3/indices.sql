--
-- Name: idx_Empleados; Type: INDEX; Schema: public; Owner: meow; Tablespace: 
--

CREATE INDEX "idx_Empleados" ON "Empleados" USING btree (rut);

ALTER TABLE "Empleados" CLUSTER ON "idx_Empleados";


--
-- Name: idx_Horario; Type: INDEX; Schema: public; Owner: meow; Tablespace: 
--

CREATE INDEX "idx_Horario" ON "Horarios" USING btree (id_horario);

ALTER TABLE "Horario" CLUSTER ON "idx_Horario";

--
-- Name: idx_Productos; Type: INDEX; Schema: public; Owner: meow; Tablespace: 
--

CREATE INDEX "idx_Productos" ON "Productos" USING btree (id_producto);


ALTER TABLE "Productos" CLUSTER ON "idx_Productos";

--
-- Name: idx_Ventas; Type: INDEX; Schema: public; Owner: meow; Tablespace: 
--

CREATE INDEX "idx_Ventas" ON "Ventas" USING btree (id_producto, rut, fecha_y_hora);


ALTER TABLE "Ventas" CLUSTER ON "idx_Ventas";

