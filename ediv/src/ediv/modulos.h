/***************************************************************************
                          modulos.h  -  description
                             -------------------
    begin                : Sat Jun 23 2001
    copyright            : (C) 2001 by Sion Entertainment
    email                : bugs@edivcentral.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef __MODULOS_H
#define __MODULOS_H

#include <time.h>

#define MODULOS2

#ifdef MODULOS2

#define dlHandler void*
#define dlCast_1 (void*)
#define dlCast_2

struct Modulo {
  dlHandler Manejador;   /* Manejador del m�dulo */
  char *NombreArchivo;   /* Nombre del Archivo */
  char *NombreModulo;    /* Nombre del M�dulo */
  char *Descripcion;     /* Descripcion del M�dulo */
  char *Version;         /* Versi�n del M�dulo */
  char *Autor;           /* Autor del M�dulo */
  time_t FechaCarga;     /* Fecha de Carga del M�dulo */
  time_t UltimoUso;      /* Fecha del �ltimo uso del M�dulo */
  int (*Iniciar) (void); /* Funci�n llamada al inicio del M�dulo */
  int (*Detener) (void); /* Funci�n llamada en la descarga del M�dulo */
};

typedef struct _listamodulos
{
  /* Puntero al siguiente elemento de la lista.
   * Si no hay siguiente elemento, este es NULL.
   */	
  struct _listamodulos *siguiente;
  
  /*! \brief Puntero al elemento anterior de la
   *  lista.
   *  \note Si no hay elemento anterior, este es NULL.
   */
  struct _listamodulos *anterior;
  
  /*! \brief Puntero a la informaci�n del M�dulo */
  struct Modulo *modulo;
  
  /*! \brief Lista de Dependencias del m�dulo 
   *  \note Si no hay ninguna dependencia, este es NULL
   */
  struct _listadependencias
  {
    /*! \brief Puntero al siguiente elemento de la
     *  lista.
     *  \note Si no hay siguiente elemento, este es NULL.
     */
    struct _listadependencias *siguiente;
    /*! \brief Puntero al elemento anterior de la
     *  lista.
     *  \note Si no hay elemento anterior, este es NULL.
     */
    struct _listadependencias *anterior;
    /*! \brief Puntero a la dependencia */
    struct _listamodulos *dependencia;
  } *listadependencias;

} _listamodulos;

char *UltimoErrorDL;
struct _listamodulos *ListaModulos;
int Cargar (char *);
int Descargar (char *, unsigned short, unsigned short);
int NuevaDependencia (char *, char *);
int BorrarDependencia (char *, char *);
struct _listamodulos *Buscar (char *);
char *ObtenerUltimoErrorDL (void);

#endif /* MODULOS2 */

int* nuevo_orden;

int leedll();
void dll_func();
void dll_func2();

#endif