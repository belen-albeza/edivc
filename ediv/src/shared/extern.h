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

#ifndef __EXTERN_H
#define __EXTERN_H

 /*#ifdef _WIN32
#	include "dll_load.h"
#endif*/

#include <SDL/SDL.h>
#include "main.h"

#define MAX_EXTERN_FUNCS	0xFFFF		// �Demasiado?
#define MAX_EXTFUNC_PARMS	0xFF
#define MAX_DLLS			0xFF
#define MAX_ENTRYPOINTS		0xFF

#define P_SIEMPRE			512			// yo creo ke esto vale
#define P_NUNCA				-512

char fichdll[256];	// Nombre de la DLL que se est� ejecutando ahora


///////////
// EXPORT

int EDIV_Export(char* cadena, int nparam, void* hfuncion);	// Funcion
int EDIV_Export_Const(char* cadena, int valor);				// Constante
int EDIV_Export_Global(char* cadena, int valor);			// Global
int EDIV_Export_Global_Tab(char* cadena, int numregs);		// Tabla global
int EDIV_Export_Global_Struct(char* cadena, int numregs);	// Struct global
int EDIV_Export_Member_Int(char* cadena, int valor);		// Miembro int
int EDIV_Export_Member_Str(char* cadena, int tamano);		// Miembro string
int EDIV_Export_Member_Tab(char* cadena, int numregs);		// Miembro tabla
int EDIV_Export_EndStruct();								// Cierra struct
int EDIV_Export_Local(char* cadena, int valor);				// Local
int EDIV_Export_Local_Tab(char* cadena, int numregs);		// Tabla local (NO USADO EN DIV2)
int EDIV_Export_Local_Struct(char* cadena, int numregs);	// Struct local
int EDIV_Export_Entrypoint(int ep, void* hfuncion);			// Entrypoint
int EDIV_Export_Priority(int priority);						// Prioridad de la DLL

// TYPEOF_EXPORT

typedef int (TYPEOF_EDIV_Export)(char* cadena, int nparam, void* hfuncion);
typedef int (TYPEOF_EDIV_Export_Const)(char* cadena, int valor);
typedef int (TYPEOF_EDIV_Export_Global)(char* cadena, int valor);
typedef int (TYPEOF_EDIV_Export_Global_Tab)(char* cadena, int numregs);
typedef int (TYPEOF_EDIV_Export_Global_Struct)(char* cadena, int numregs);
typedef int (TYPEOF_EDIV_Export_Member_Int)(char* cadena, int valor);
typedef int (TYPEOF_EDIV_Export_Member_Str)(char* cadena, int tamano);
typedef int (TYPEOF_EDIV_Export_Member_Tab)(char* cadena, int numregs);
typedef int (TYPEOF_EDIV_Export_EndStruct)();
typedef int (TYPEOF_EDIV_Export_Local)(char* cadena, int valor);
typedef int (TYPEOF_EDIV_Export_Local_Tab)(char* cadena, int numregs);
typedef int (TYPEOF_EDIV_Export_Local_Struct)(char* cadena, int numregs);
typedef int (TYPEOF_EDIV_Export_Entrypoint)(int ep, void* hfuncion);
typedef int (TYPEOF_EDIV_Export_Priority)(int priority);

// Call_Entrypoint
typedef int (TYPEOF_Call_Entrypoint)(int ep, ...);

// Dibuja
typedef int (TYPEOF_Dibuja)(SDL_Surface *, SDL_Rect , SDL_Rect , int , int ) ;

// Errores
typedef void (TYPEOF_Runtime_Error)(int, ...);
typedef void (TYPEOF_Critical_Error)(int, ...);

/////////////
// ENTRY-POINTS
///////////
// Estas funciones son llamadas por el STUB en determinados eventos
// (Cuando una DLL hace cierta acci�n, lo avisa al Stub y el stub se encarga de llamar
// a las correspondientes rutinas de las dll's, ordenadas por prioridad)
/////////

// Constantes para EDIV_Export_Entrypoint

#define EDIV_set_video_mode			1	// Al activar un nuevo modo de v�deo
#define EDIV_process_palette		2	// Al cargar una paleta
#define EDIV_process_active_palette	3	// Al modificar la paleta activa (usada en los fades)
#define EDIV_process_sound			4	// Al cargar un efecto sonoro
#define EDIV_process_map			5	// Al cargar un mapa
#define EDIV_process_fpg			6	// Al cargar un FPG
#define EDIV_process_fnt			7	// Al cargar una fuente
#define EDIV_background_to_buffer	8	// Volcar el fondo al buffer
#define EDIV_buffer_to_video		9	// Volcar el buffer a la memoria de video
#define EDIV_post_process_scroll	10	// Tras dibujar una ventana de scroll (sin los sprites)
#define EDIV_post_process_m7		11	// Tras dibujar una ventana de modo7 (sin los sprites)
#define EDIV_post_process_m8		12	// Tras dibujar una ventana de modo8 (sin los sprites)
#define EDIV_post_process_buffer	13	// Tras haber terminado de dibujarlo todo
#define EDIV_post_process			14	// Tras ejecutar el frame de un proceso (cualquier %)
#define EDIV_put_sprite				15	// Dibujar un sprite
#define EDIV_ss_init				16	// Inicio de salvapantallas
#define EDIV_ss_frame				17	// Frame de salvapantallas
#define EDIV_ss_end					18	// Fin de salvapantallas
#define EDIV_frame					19	// En cada frame
#define EDIV_trace					20	// Despu�s de ejecutar cada instrucci�n de bytecode (solo en debug)
#define EDIV_debug					21	// Invocar al trazador - sentencia debug (solo en debug)
#define EDIV_first_load				22	// Se ejecuta al cargar la DLL en ejecucion


// Call_Entrypoint
// Devuelve el n�mero de entrypoints a los que corresponde ese identificador.
// (0 si no hay ninguno)
int Call_Entrypoint(int ep, ...);

// Prototipos de los entrypoints (no hacen falta aki)
/*
void set_video_mode(void);
void process_palette(void);
void process_active_palette(void);
void process_sound(char *sound,int lenght);
void process_fpg(char *fpg,int fpg_lenght);
void process_map(char *map,int map_lenght);
void process_fnt(char *fnt,int fnt_lenght);
void background_to_buffer(void);
void buffer_to_video(void);
void post_process_scroll(void);
void post_process_m7(void);
void post_process_m8(void);
void post_process_buffer(void);
void post_process(void);
void put_sprite(unsigned char * si, int x,int y, int an, int al, int xg, int yg,
	            int ang, int size, int flags);
void ss_init(void);
void ss_frame(void);
void ss_end(void);
void frame(void);
*/
//////////////////////////////


#define EXPORTAFUNCS_PARAMS   \
	EDIV_Export              ,\
	EDIV_Export_Const        ,\
	EDIV_Export_Global       ,\
	EDIV_Export_Global_Tab   ,\
	EDIV_Export_Global_Struct,\
	EDIV_Export_Member_Int   ,\
	EDIV_Export_Member_Str   ,\
	EDIV_Export_Member_Tab   ,\
	EDIV_Export_EndStruct    ,\
	EDIV_Export_Local        ,\
	EDIV_Export_Local_Tab    ,\
	EDIV_Export_Local_Struct ,\
	EDIV_Export_Entrypoint   ,\
	EDIV_Export_Priority

#define EXPORTAFUNCS_PARAMS_DECLARE \
TYPEOF_EDIV_Export               *,\
TYPEOF_EDIV_Export_Const         *,\
TYPEOF_EDIV_Export_Global        *,\
TYPEOF_EDIV_Export_Global_Tab    *,\
TYPEOF_EDIV_Export_Global_Struct *,\
TYPEOF_EDIV_Export_Member_Int    *,\
TYPEOF_EDIV_Export_Member_Str    *,\
TYPEOF_EDIV_Export_Member_Tab    *,\
TYPEOF_EDIV_Export_EndStruct     *,\
TYPEOF_EDIV_Export_Local         *,\
TYPEOF_EDIV_Export_Local_Tab     *,\
TYPEOF_EDIV_Export_Local_Struct  *,\
TYPEOF_EDIV_Export_Entrypoint	 *,\
TYPEOF_EDIV_Export_Priority      *



/// FUNCIONES PREDEFINIDAS ///

typedef int (TYPEOF_ExportaFuncs)(EXPORTAFUNCS_PARAMS_DECLARE);


// FUNCI�N EXTERNA

// �ojo! debe ser igual en export.h
#define FUNCTION_PARAMS	\
	int *params, int *sp, \
	int mem[], \
	int *varindex, \
	struct _procs_s *procs_s, \
	TYPEOF_Call_Entrypoint *Call_Entrypoint

struct _procs_s{
	int id ; // offset de los datos locales del proceso
	int tipo ; // tipo de proceso
	int orden ; // indice en proc_orden[]
	int num_params ; // numero de parametros k coje ( NO SE PARA K SIRVE PERO PARA ALGO ESTARA CBP NO ? )
	int imem ; // Posicion en la k se quedo suspendido el proceso
	int priority ; // Priority
	int frame; // Frame completado
	int graph ;
} procs_s[ 4096 ] ;

struct _regions
{
	int x , y , w , h ;
} ;

struct _existe {
	int regions ;
	int dibuja ;
} ;

struct _file
{
	SDL_Surface *Surface ;
	int existe ;
	struct
	{
		int x , y ;
	} cpoint[ 20 ] ;
} ;

struct _files
{
	int num ;
	int existe ;
	struct _file *mapa ;
}  ;


struct _fun_params{
	int *pila ;
	int *sp ;
	int *mem ;
	int *varindex ;
	struct _procs_s *procs_s ;
	int *num_procs ;
	int *proc_orden ;
	int *proceso_actual ;
	struct _regions *regions ;
	struct _existe existe ;
	struct _files *files ;
	TYPEOF_Dibuja *Dibuja ; // <- Tienes una funcion identica a esta variable (Daijo) <<- Y que? , la funcion no esta dentro de esta estructura :P (Riseven)
	TYPEOF_Call_Entrypoint *Call_Entrypoint ;
	TYPEOF_Runtime_Error *Runtime_Error ;
	TYPEOF_Critical_Error *Critical_Error ;
} fp ;

		

// La pila de parametros y su se�alador o como se llame
//int params[MAX_EXTFUNC_PARMS];
//int sp;

void* extfuncs[MAX_EXTERN_FUNCS]; // tabla de punteros a las funciones de las DLLs (stub)

struct _entrypoints {
	int tipo;			// Ver #defines de entrypoints m�s arriba
	int dll;			// DLL que contiene este entrypoint
	void* hfuncion;		// Puntero a la funci�n entrypoint de la DLL
} entrypoints[MAX_ENTRYPOINTS];

struct _dlls {
    char* nombre;           // nombre de la DLL (ej: "sample.so")
    byte usado;				// si la dll es requerida por el programa
    int mem_nombre;			// posici�n del nombre en mem[]
	int prioridad;			// prioridad por defecto de la DLL
	void* hDLL;
//    int mem_size;			// tama�o ocupado en mem[]
//    int loc_size;			// tama�o ocupado en loc[]
//    int nfuncs;             // numero de funciones que contiene
//    struct _extfunc ext_funcs[MAX_EXTERN_FUNCS];
} dlls[MAX_DLLS];

int dimem;	// indices para poder devolver offsets de variables segun se van declarando
int diloc;

int numdlls;			// N�mero de DLLs encontradas en el directorio
int n_dlls;				// N�mero de DLLs requeridas por el programa
int n_externs;			// N�mero de funciones importadas
int n_entrypoints;		// N�mero de entrypoints declarados

// usar putparm() para poner los parametros en la pila de parametros en el orden normal
// (del primero al ultimo)
//#define putparm(a)	params[sp++]=(int)a

#endif // __EXTERN_H