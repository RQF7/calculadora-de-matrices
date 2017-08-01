#
#  Copyright (C) 2017 Ricardo Quezada Figueroa
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

#
#  Archivo:  makefile
#  Autor:    Ricardo Quezada Figueroa
#  Fecha:    27/03/17
#

#  Programas y compiladores
compilador_c := gcc
compilador_y := bison
compilador_l := flex
compilador_t := pdflatex

#  Opciones de compilación
banderas_ligado      := -lm -lncursesw -lgmp
banderas_c_propias   := -Wall
banderar_c_generales := -ggdb

#  Carpetas
carpeta_obj := obj
carpeta_fnt := fnt
carpeta_bin := bin

#  Productos
ejecutable := $(carpeta_bin)/calcMatrices

#  Código fuente
fuentes := vector.c \
	   vector_vectores.c \
	   vector_str.c \
	   matriz.c \
	   simbolo.c \
	   inicializar.c \
	   programa.c \
	   parser.tab.c \
	   lex.yy.c
objetos := $(addprefix $(carpeta_obj)/, $(fuentes:.c=.o))

#  Carpeta fuente a VPATH
VPATH := $(carpeta_fnt)

#  Objetivo principal
$(ejecutable): $(objetos)
	$(compilador_c) $(banderas_c_propias) $(banderar_c_generales) $(banderas_ligado) $(objetos) -o $@

#  Objetivos secundarios
$(carpeta_obj)/vector.o: vector.c vector.h parser.tab.c
	$(compilador_c) $(banderas_c_propias) $(banderar_c_generales) -c $< -o $@

$(carpeta_obj)/vector_vectores.o: vector_vectores.c vector_vectores.h parser.tab.c
	$(compilador_c) $(banderas_c_propias) $(banderar_c_generales) -c $< -o $@

$(carpeta_obj)/vector_str.o: vector_str.c vector_str.h
	$(compilador_c) $(banderas_c_propias) $(banderar_c_generales) -c $< -o $@

$(carpeta_obj)/matriz.o: matriz.c matriz.h parser.tab.c
	$(compilador_c) $(banderas_c_propias) $(banderar_c_generales) -c $< -o $@

$(carpeta_obj)/simbolo.o: simbolo.c simbolo.h parser.tab.c
	$(compilador_c) $(banderas_c_propias) $(banderar_c_generales) -c $< -o $@

$(carpeta_obj)/inicializar.o: inicializar.c inicializar.h parser.tab.c
	$(compilador_c) $(banderas_c_propias) $(banderar_c_generales) -c $< -o $@

$(carpeta_obj)/programa.o: programa.c programa.h parser.tab.c
	$(compilador_c) $(banderas_c_propias) $(banderar_c_generales) -c $< -o $@

$(carpeta_obj)/parser.tab.o: parser.tab.c
	$(compilador_c) $(banderar_c_generales) -c $< -o $@

$(carpeta_obj)/lex.yy.o: lex.yy.c
	$(compilador_c) $(banderar_c_generales) -c $< -o $@

#  Objetivos de yacc y lex
$(carpeta_fnt)/parser.tab.c: parser.y
	$(compilador_y) -d -o $@ $<

$(carpeta_fnt)/lex.yy.c: escaner.l
	$(compilador_l) $<
	mv lex.yy.c fnt/

# Reporte
reporte.pdf: reporte.tex
	$(compilador_t) -output-directory $(carpeta_obj) -shell-escape $<
	mv $(carpeta_obj)/$@ ./$@

fuentes: fuentes.bib
	/usr/bin/vendor_perl/biber $(carpeta_obj)/reporte.bcf -input-directory $(carpeta_fnt)

#  Objetivos phony
run: $(ejecutable)
	./$<

clean:
	rm -Rfv $(objetos) $(carpeta_fnt)/parser.tab.* $(carpeta_fnt)/lex.yy.c
