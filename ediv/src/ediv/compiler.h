/*
 * eDiv Compiler
 * Copyright (C) 2000-2002 Sion, Ltd.
 * http://www.sionhq.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __COMPILER_H
#define __COMPILER_H

#include "main.h"

/* "Truco" para que MSVC no de problemas 'raros' */
#ifdef _WINBASE_
#	undef lstrcpy
#	undef lstrcat
#	undef lstrlen
#endif

#define default_buffer    (16384*8)
#define security_distance (4096*8)
#define buffer_grow       (16384*8)

int * mem_ory, * frm;
int * mem, * loc;
int imem, imem_max;
int iloc, iloc_max;
int itxt, ifrm_max;

byte * imemptr;

int iloc_len; /* final de las variables locales incluyendo las privadas */

/*
 * mem[]        vector de memoria destino
 * imem         puntero para la generaci�n de datos y c�digo
 * imem_max     fin de la memoria destino (indice m�ximo de mem[])
 * iloc         inicio en mem[] de las variables locales (inicializadas)
 * iloc_len     longitud de las variables locales
 */

/* 
 * Inserci�n en la tabla de expresiones, acceso a variables:
 *
 * vglo           &vglo ptr
 * tglo[_exp]     &tglo <_exp> add rng ptr
 * vloc           &vloc aid ptr
 * tloc[_exp]      &tloc <_exp> add rng aid ptr
 * proc.vloc      &proc ptr &vloc add ptr
 * proc.tloc[_exp] &proc ptr &tloc <_exp> add rng add ptr
 */


FILE * fin, * fout;
byte * _source;
byte * source, * ierror, * ierror_end;

int longitud_textos;
int inicio_textos;
int max_process;
int ignore_errors;
int free_sintax;
int extended_conditions;
int simple_conditions;
int comprueba_rango;
int comprueba_id;
int comprueba_null;
int hacer_strfix;
int optimizar;
int case_sensitive;


/*
 *  MNEM�NICOS BYTECODE EML
 */
#define lnop  0 /* *            No operaci�n											*/
#define lcar  1 /* valor        Carga una constante en pila								*/
#define lasi  2 /*              Saca valor, offset y mete el valor en [offset]			*/
#define lori  3 /*              Or l�gico												*/
#define lxor  4 /*              Xor, or exclusivo										*/
#define land  5 /*              And l�gico, operador sobre condiciones					*/
#define ligu  6 /*              Igual, operador logico de comparaci�n					*/
#define ldis  7 /*              Distinto, true si los 2 valores son diferentes			*/
#define lmay  8 /*              Mayor, comparaci�n con signo							*/
#define lmen  9 /*              Menor, idem												*/
#define lmei 10 /*              Menor o igual											*/
#define lmai 11 /*              Mayor o igual											*/
#define ladd 12 /*              Suma dos constantes										*/
#define lsub 13 /*              Resta, operaci�n binaria								*/
#define lmul 14 /*              Multiplicaci�n											*/
#define ldiv 15 /*              Divisi�n de enteros										*/
#define lmod 16 /*              M�dulo, resto de la divisi�n							*/
#define lneg 17 /*              Negaci�n, cambia de signo una constante					*/
#define lptr 18 /*              Pointer, saca offset y mete [offset]					*/
#define lnot 19 /*              Negaci�n binaria, bit a bit								*/
#define laid 20 /*              Suma id a la constante de la pila						*/
#define lcid 21 /*              Carga id en la pila										*/
#define lrng 22 /* rango        Realiza una comparaci�n de rango						*/
#define ljmp 23 /* offset       Salta a una direcci�n de mem[]							*/
#define ljpf 24 /* offset       Salta si un valor es falso a una direcci�n				*/
#define lfun 25 /* c�digo       Llamada a un proceso interno, ej. signal()				*/
#define lcal 26 /* offset       Crea un nuevo proceso en el programa					*/
#define lret 27 /*              Auto-eliminaci�n del proceso							*/
#define lasp 28 /*              Desecha un valor apilado								*/
#define lfrm 29 /*              Detiene por este frame la ejecuci�n del proceso			*/
#define lcbp 30 /* num_par      Inicializa el puntero a los par�metros locales			*/
#define lcpa 31 /*              Saca offset, lee par�metro [offset] y bp++				*/
#define ltyp 32 /* bloque       Define el tipo de proceso actual (colisiones)			*/
#define lpri 33 /* offset       Salta a la direcci�n, y carga var. privadas				*/
#define lcse 34 /* offset       Si switch <> expresi�n, salta al offset					*/
#define lcsr 35 /* offset       Si switch no esta en el rango, salta al offset			*/
#define lshr 36 /*              Rotacion a la derecha (modo C, >>)						*/
#define lshl 37 /*              Rotacion a la izquierda (modo C, <<)					*/
#define lipt 38 /*              Incremento y pointer									*/
#define lpti 39 /*              Pointer e incremento									*/
#define ldpt 40 /*              Decremento y pointer									*/
#define lptd 41 /*              Pointer y decremento									*/
#define lada 42 /*              Add-asignaci�n											*/
#define lsua 43 /*              Sub-asignaci�n											*/
#define lmua 44 /*              Mul-asignaci�n											*/
#define ldia 45 /*              Div-asignaci�n											*/
#define lmoa 46 /*              Mod-asignaci�n											*/
#define lana 47 /*              And-asignaci�n											*/
#define lora 48 /*              Or-asignaci�n											*/
#define lxoa 49 /*              Xor-asignaci�n											*/
#define lsra 50 /*              Shr-asignaci�n											*/
#define lsla 51 /*              Shl-asignaci�n											*/
#define lpar 52 /* num_par_pri  Define el n�mero de par�metros privados					*/
#define lrtf 53 /*              Auto-eliminaci�n del proceso, devuelve un valor			*/
#define lclo 54 /* offset       Crea un clon del proceso actual							*/
#define lfrf 55 /*              Pseudo-Frame (frame a un porcentaje)					*/
#define limp 56 /* offset text  Importa una DLL externa									*/	
#define lext 57 /* c�digo       Llama a una funci�n externa								*/
#define lchk 58 /*              Comprueba la validez de un identificador				*/
#define ldbg 59 /*              Invoca al debugger										*/

/* Instrucciones a�adidas para la optimizaci�n (DIV 2.0) */
#define lcar2 60
#define lcar3 61
#define lcar4 62
#define lasiasp 63
#define lcaraid 64
#define lcarptr 65
#define laidptr 66
#define lcaraidptr 67
#define lcaraidcpa 68
#define laddptr 69
#define lfunasp 70
#define lcaradd 71
#define lcaraddptr 72
#define lcarmul 73
#define lcarmuladd 74
#define lcarasiasp 75
#define lcarsub 76
#define lcardiv 77

/* Instrucciones a�adidas para el manejo de caracteres */
#define lptrchr 78  /* Pointer, saca (index, offset) y mete [offset+byte index]				*/
#define lasichr 79  /* Saca (valor, index, offset) y mete el valor en [offset+byte index]	*/
#define liptchr 80  /* Incremento y pointer													*/
#define lptichr 81  /* Pointer e incremento													*/
#define ldptchr 82  /* Decremento y pointer													*/
#define lptdchr 83  /* Pointer y decremento													*/
#define ladachr 84  /* Add-asignaci�n														*/
#define lsuachr 85  /* Sub-asignaci�n														*/
#define lmuachr 86  /* Mul-asignaci�n														*/
#define ldiachr 87  /* Div-asignaci�n														*/
#define lmoachr 88  /* Mod-asignaci�n														*/
#define lanachr 89  /* And-asignaci�n														*/
#define lorachr 90  /* Or-asignaci�n														*/
#define lxoachr 91  /* Xor-asignaci�n														*/
#define lsrachr 92  /* Shr-asignaci�n														*/
#define lslachr 93  /* Shl-asignaci�n														*/
#define lcpachr 94  /* Saca offset, lee par�metro [offset] y bp++							*/

/* Instrucciones a�adidas para el manejo de cadenas */
#define lstrcpy 95  /* Saca si, di, y hace strcpy(mem[di],[si]) (deja di en pila)			*/
#define lstrfix 96  /* Amplia una cadena antes de meter un char en ella						*/
#define lstrcat 97  /* Concatena dos cadenas (opera como strcpy)							*/
#define lstradd 98  /* Suma dos strings "en el aire" y deja en pila el puntero al aire		*/
#define lstrdec 99  /* A�ade o quita caracteres a una cadena								*/
#define lstrsub 100 /* Quita caracteres a una cadena (-=)									*/
#define lstrlen 101 /* Sustituye una cadena por su longitud									*/
#define lstrigu 102 /* Comparacion de igualdad de dos cadenas								*/
#define lstrdis 103 /* Cadenas distintas													*/
#define lstrmay 104 /* Cadena mayor															*/
#define lstrmen 105 /* Cadena menor															*/
#define lstrmei 106 /* Cadena mayor o igual													*/
#define lstrmai 107 /* Cadena menor o igual													*/
#define lcpastr 108 /* Carga un par�metro en una cadena										*/

/* Instrucciones a�adidas para el manejo de Words */
#define lptrwor 109 /* Pointer, saca (index, offset) y mete [offset+byte index]				*/
#define lasiwor 110 /* Saca (valor, index, offset) y mete el valor en [offset+byte index]	*/
#define liptwor 111 /* Incremento y pointer													*/
#define lptiwor 112 /* Pointer e incremento													*/
#define ldptwor 113 /* Decremento y pointer													*/
#define lptdwor 114 /* Pointer y decremento													*/
#define ladawor 115 /* Add-asignaci�n														*/
#define lsuawor 116 /* Sub-asignaci�n														*/
#define lmuawor 117 /* Mul-asignaci�n														*/
#define ldiawor 118 /* Div-asignaci�n														*/
#define lmoawor 119 /* Mod-asignaci�n														*/
#define lanawor 120 /* And-asignaci�n														*/
#define lorawor 121 /* Or-asignaci�n														*/
#define lxoawor 122 /* Xor-asignaci�n														*/
#define lsrawor 123 /* Shr-asignaci�n														*/
#define lslawor 124 /* Shl-asignaci�n														*/
#define lcpawor 125 /* Saca offset, lee par�metro [offset] y bp++							*/

/* Miscel�nea */
#define lnul    126 /* Comprueba que un puntero no sea NULL									*/


struct {      // Peephole, "mirilla" para el optimizador
  int dir;    // Direcci�n
  int param;  // Indica si ese opcode tiene par�metro
  int op;     // Opcode
} code[16];   // En code[15] debe quedar siempre la �ltima instrucci�n generada

/* Informacion para temporal de debug (posicion en mem y fuente de cada sentencia) */
FILE * linf;	/* En este temporal guardamos la info y luego lo agregamos al exe */

int inicio,final;     /* Direcciones inicial y final de mem[] de la sentencia */
//int linea1,columna1;  /* Posicion en la que comienza la sentencia en el fuente */
//int linea2,columna2;  /* Posicion en la que acaba la sentencia en el fuente */
int inicio_prg,final_prg; /* Direcciones inicial y final en el PRG de la sentencia */
int linsize;

void inicio_sentencia(void);  /* Fija inicio, linea1, columna1 */
void final_sentencia(void);   /* Fija final, linea2, columna2 */
void grabar_sentencia(void);  /* Guarda las seis variables en el fichero */

void escribe_lin(FILE* f);
void escribe_dbg(FILE* f);


int salto_import;	/* offset donde guardaremos el offset del ljmp que salta
					 * a la rutina de carga de DLLs.
					 */
					

#define max_break 512
int tbreak[max_break];
int itbreak;

#define max_cont 256
int tcont[max_cont];
int itcont;

#define max_elseif 256
int telseif[max_elseif];
int itelseif;


/*
 *  PROTOTIPOS
 */

void gen(int param, int op, int pa);
void remove_code(int i);
void delete_code(void);
void add_code(int dir, int param, int op);
int optimizado;

void prepara_compilacion();
void compila();
void test_buffer(int * * ,int * ,int);
void sentencia();

void g1(int op);
void g2(int op, int pa);

#endif /* __COMPILER_H */