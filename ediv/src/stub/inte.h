/*
 * eDiv Compiler
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

#ifndef __INTE_H
#define __INTE_H

#include "main.h"

//-----------------------------------------------------------------------------
//  CANCELA LAS DEFINICIONES EXISTENTES EN WINBASE.H (Win32)
//-----------------------------------------------------------------------------
#ifdef _WIN32
 #undef lstrcpy
 #undef lstrcat
 #undef lstrlen
#endif /* _WIN32 */

//-----------------------------------------------------------------------------
//  MNEM�NICOS BYTECODE EML
//-----------------------------------------------------------------------------

//Mnem�nico-C�dg.-Operandos (Generaci�n de c�digo EML, "*" = "a�n no usado")

#define lnop  0 // *            No operaci�n
#define lcar  1 // valor        Carga una constante en pila
#define lasi  2 //              Saca valor, offset y mete el valor en [offset]
#define lori  3 //              Or l�gico
#define lxor  4 //              Xor, or exclusivo
#define land  5 //              And l�gico, operador sobre condiciones
#define ligu  6 //              Igual, operador logico de comparaci�n
#define ldis  7 //              Distinto, true si los 2 valores son diferentes
#define lmay  8 //              Mayor, comparaci�n con signo
#define lmen  9 //              Menor, idem
#define lmei 10 //              Menor o igual
#define lmai 11 //              Mayor o igual
#define ladd 12 //              Suma dos constantes
#define lsub 13 //              Resta, operaci�n binaria
#define lmul 14 //              Multiplicaci�n
#define ldiv 15 //              Divisi�n de enteros
#define lmod 16 //              M�dulo, resto de la divisi�n
#define lneg 17 //              Negaci�n, cambia de signo una constante
#define lptr 18 //              Pointer, saca offset y mete [offset]
#define lnot 19 //              Negaci�n binaria, bit a bit
#define laid 20 //              Suma id a la constante de la pila
#define lcid 21 //              Carga id en la pila
#define lrng 22 // rango        Realiza una comparaci�n de rango
#define ljmp 23 // offset       Salta a una direcci�n de mem[]
#define ljpf 24 // offset       Salta si un valor es falso a una direcci�n
#define lfun 25 // c�digo       Llamada a un proceso interno, ej. signal()
#define lcal 26 // offset       Crea un nuevo proceso en el programa
#define lret 27 //              Auto-eliminaci�n del proceso
#define lasp 28 //              Desecha un valor apilado
#define lfrm 29 //              Detiene por este frame la ejecuci�n del proceso
#define lcbp 30 // num_par      Inicializa el puntero a los par�metros locales
#define lcpa 31 //              Saca offset, lee par�metro [offset] y bp++
#define ltyp 32 // bloque       Define el tipo de proceso actual (colisiones)
#define lpri 33 // offset       Salta a la direcci�n, y carga var. privadas
#define lcse 34 // offset       Si switch <> expresi�n, salta al offset
#define lcsr 35 // offset       Si switch no esta en el rango, salta al offset
#define lshr 36 //              Rotacion a la derecha (modo C, >>)
#define lshl 37 //              Rotacion a la izquierda (modo C, <<)
#define lipt 38 //              Incremento y pointer
#define lpti 39 //              Pointer e incremento
#define ldpt 40 //              Decremento y pointer
#define lptd 41 //              Pointer y decremento
#define lada 42 //              Add-asignaci�n
#define lsua 43 //              Sub-asignaci�n
#define lmua 44 //              Mul-asignaci�n
#define ldia 45 //              Div-asignaci�n
#define lmoa 46 //              Mod-asignaci�n
#define lana 47 //              And-asignaci�n
#define lora 48 //              Or-asignaci�n
#define lxoa 49 //              Xor-asignaci�n
#define lsra 50 //              Shr-asignaci�n
#define lsla 51 //              Shl-asignaci�n
#define lpar 52 // num_par_pri  Define el n�mero de par�metros privados
#define lrtf 53 //              Auto-eliminaci�n del proceso, devuelve un valor
#define lclo 54 // offset       Crea un clon del proceso actual
#define lfrf 55 //              Pseudo-Frame (frame a un porcentaje, frame(100)==frame)
#define limp 56 // offset text  Importa una DLL externa
#define lext 57 // c�digo       Llama a una funci�n externa
#define lchk 58 //              Comprueba la validez de un identificador
#define ldbg 59 //              Invoca al debugger

// Instrucciones a�adidas para la optimizaci�n (DIV 2.0)

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

// Instrucciones a�adidas para el manejo de caracteres

#define lptrchr 78  // Pointer, saca (index, offset) y mete [offset+byte index]
#define lasichr 79  // Saca (valor, index, offset) y mete el valor en [offset+byte index]
#define liptchr 80  // Incremento y pointer
#define lptichr 81  // Pointer e incremento
#define ldptchr 82  // Decremento y pointer
#define lptdchr 83  // Pointer y decremento
#define ladachr 84  // Add-asignaci�n
#define lsuachr 85  // Sub-asignaci�n
#define lmuachr 86  // Mul-asignaci�n
#define ldiachr 87  // Div-asignaci�n
#define lmoachr 88  // Mod-asignaci�n
#define lanachr 89  // And-asignaci�n
#define lorachr 90  // Or-asignaci�n
#define lxoachr 91  // Xor-asignaci�n
#define lsrachr 92  // Shr-asignaci�n
#define lslachr 93  // Shl-asignaci�n
#define lcpachr 94  // Saca offset, lee par�metro [offset] y bp++

// Instrucciones a�adidas para el manejo de cadenas

#define lstrcpy 95  // Saca si, di, y hace strcpy(mem[di],[si]) (deja di en pila)
#define lstrfix 96  // Amplia una cadena antes de meter un char en ella
#define lstrcat 97  // Concatena dos cadenas (opera como strcpy)
#define lstradd 98  // Suma dos strings "en el aire" y deja en pila el puntero al aire
#define lstrdec 99  // A�ade o quita caracteres a una cadena
#define lstrsub 100 // Quita caracteres a una cadena (-=)
#define lstrlen 101 // Sustituye una cadena por su longitud
#define lstrigu 102 // Comparacion de igualdad de dos cadenas
#define lstrdis 103 // Cadenas distintas
#define lstrmay 104 // Cadena mayor
#define lstrmen 105 // Cadena menor
#define lstrmei 106 // Cadena mayor o igual
#define lstrmai 107 // Cadena menor o igual
#define lcpastr 108 // Carga un par�metro en una cadena

// Instrucciones a�adidas para el manejo de Words

#define lptrwor 109 // Pointer, saca (index, offset) y mete [offset+byte index]
#define lasiwor 110 // Saca (valor, index, offset) y mete el valor en [offset+byte index]
#define liptwor 111 // Incremento y pointer
#define lptiwor 112 // Pointer e incremento
#define ldptwor 113 // Decremento y pointer
#define lptdwor 114 // Pointer y decremento
#define ladawor 115 // Add-asignaci�n
#define lsuawor 116 // Sub-asignaci�n
#define lmuawor 117 // Mul-asignaci�n
#define ldiawor 118 // Div-asignaci�n
#define lmoawor 119 // Mod-asignaci�n
#define lanawor 120 // And-asignaci�n
#define lorawor 121 // Or-asignaci�n
#define lxoawor 122 // Xor-asignaci�n
#define lsrawor 123 // Shr-asignaci�n
#define lslawor 124 // Shl-asignaci�n
#define lcpawor 125 // Saca offset, lee par�metro [offset] y bp++

// Miscel�nea

#define lnul    126 // Comprueba que un puntero no sea NULL



//�����������������������������������������������������������������������������
// Variables locales del sistema de sprites (las primeras no son p�blicas)
//�����������������������������������������������������������������������������

#define _Id         0  //Para comprobar validez de accesos externos
#define _IdScan     1  //Recorrido del resto de los procesos (p.ej.colisiones)
#define _Bloque     2  //Identificador del tipo de proceso (para colisiones)
#define _BlScan     3  //Ultimo tipo de proceso scaneado en el �ltimo recorrido
#define _Status     4  //Estado (0 dead, 1 killed, 2 alive, 3 sleept, 4 freezed)
#define _NumPar     5  //N�mero de par�metros del proceso
#define _Param      6  //Puntero a los par�metros pasados al proceso (en pila)
#define _IP         7  //Puntero de ejecuci�n (la siguiente al frame anterior)
#define _SP         8  //Puntero de pila (stack pointer del proceso)
#define _Executed   9  //Indica para cada frame si el proceso ya se ejecut�
#define _Painted    10 //Indica si el proceso ya ha sido pintado

// Las siguientes 2 variables son duales, segun el proceso sea de m7 o m8

#define _Dist1      11 //Distancia 1, para el modo 7
#define _Dist2      12 //Distancia 2, para el modo 7

#define _M8_Object  11 //Objeto dentro del mundo m8
#define _Old_Ctype  12 //Antiguo _Ctype

#define _Frame      13 //Cuanto frame lleva el proceso (frame(n))
#define _x0         14 //Caja ocupada por el sprite cada
#define _y0         15 // vez que se pinta para realizar
#define _x1         16 // volcado y restauraci�n de fondo
#define _y1         17 // parcial (dump_type==0 y restore_background==0)
#define _FCount     18 //Cuenta de llamadas a funcion (para saltarse retornos en frame)
#define _Caller     19   //ID del proceso o funcion llamador (0 si ha sido el kernel)

#define _Father     20 //Id del padre del proceso (0 si no existe)
#define _Son        21 //Id del �ltimo hijo que ha creado (0 sne)
#define _SmallBro   22 //Id del hermano menor del proceso (0 sne)
#define _BigBro     23 //Id del hermanos mayor (m�s viejo) del proceso (0 sne)
#define _Priority   24 //Prioridad de proceso (positivo o negativo)
#define _Ctype      25 //Indica si es relativo a pantalla, parallax o mode 7
#define _X          26 //Coordenada x (del centro gravitatorio del gr�fico)
#define _Y          27 //Coordenada y (idem)
#define _Z          28 //Coordenada z (Prioridad para la impresi�n)
#define _Graph      29 //C�digo del gr�fico (se corresponde con los ficheros)
#define _Flags      30 //Define espejados horizontales y verticales
#define _Size       31 //Tama�o (%) del gr�fico
#define _Angle      32 //Angulo de rotaci�n del gr�fico (0 gr�fico normal)
#define _Region     33 //Regi�n con la que hacer el clipping del gr�fico
#define _File       34 //FPG que contiene los gr�ficos del proceso
#define _XGraph     35 //Puntero a tabla: n�graficos,graf_angulo_0,...
#define _Height     36 //Altura de los procesos en el modo 7 (pix/4)
#define _Cnumber    37 //Indica en que scroll o m7 se ver� el gr�fico
#define _Resolution 38 //Resoluci�n de las coordenadas x,y para este proceso
#define _Radius     39 //Radio del objeto en m8
#define _M8_Wall    40 //Pared con la que colisiona
#define _M8_Sector  41 //Sector en el que esta
#define _M8_NextSector 42 //Sector que esta detras de la pared con la que colisiona
#define _M8_Step    43 //Lo que puede subir el sprite en m8 (altura escalon)



//----------------------------------------------------------------------



int proc_orden[ 4096 ] ;
int num_proc_orden ;

int devolver; // Si se espera devolucion > 0

//----------------------------------------------------------------------

int ini_interprete() ;
int busca_proc_libre() ;
int lista_mete(int) ;
int interprete() ;
int proceso(int) ;

#endif