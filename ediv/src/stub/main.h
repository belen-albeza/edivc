/*
 * eDiv Executable Stub
 * Copyleft (C) 2000-2002 Sion Entertainment
 * http://www.sion-e.com
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

#ifndef __MAIN_H
#define __MAIN_H

#include <SDL/SDL.h>
#include "shared.h"

//#define DEBUG_DLL		// para mostrar informaci�n al cargar las DLLs

#define swap(a,b) {(a)^=(b);(b)^=(a);(a)^=(b);}


//
// GLOBALES DEL INTERPRETE
//

byte nombre_program[256];	// nombre del programa, titulo por defecto de la ventana

int ignore_errors;		// 1 = se ignoran los errores 'evitables'

#ifdef DBG
int debug;				// 1 = el programa esta compilado en modo debug
#endif

int num_proc;			// Numero de proceso activo ( indice procs_s[] )

int imem;				// indice de mem
int imem_max;			// m�ximo indice de mem

int * mem;				// Memoria principal de la m�quina destino

// iguales que mem pero de tipo word y byte
word * memw;
byte * memb;

// igual pero para variables locales
int iloc, iloc_pub_len, iloc_len, inicio_privadas;

//pila
int * pila ;
int pila_max ; //maximo indice de pila
int sp ; // indice de la pila ;
int proceso_actual ; // indice para proc_orden
//struct _fun_params fp ;
//
// SDL
//
SDL_Surface * screen;
SDL_Surface * screen1;
//SDL_Surface * imgs[255];
SDL_Event event[0xFF];

Uint8 * keys;


//
// DEBUG
//

#ifdef DBG

unsigned char* prog;
int* lin;
int last_lin;
typedef struct _lin_item {
	int inicio;
	int fin;
	int inicio_prg;
	int fin_prg;
} lin_item;
int linsize;

#endif /* DBG */

///
// PROTOTIPOS
///

void error(int num, ...);		// Mensaje de error no cr�tico (trazable)
void critical_error(int num, ...);		// Mensaje de error cr�tico
void stub_quit(int n);				// Salir del stub
void* e_malloc(size_t size);	// identico a malloc pero con errormsg utom�tico

#endif /* __MAIN_H */