/*
 * eDIV Compiler
 * Copyleft (C) 2000-2003 Sion Ltd.
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

/* Este fichero es la cabecera para las DLL's de eDIV.
 * Para saber c�mo se utiliza, consulte el eDIV SDK de la documentaci�n de eDIV
 * ESTE FICHERO -NO- HA DE SER MODIFICADO PARA CREAR DLLs, TAN S�LO POR
 * DESARROLLADORES DE eDIV. EN CASO DE SER MODIFICADO, SE PERDER� LA
 * COMPATIBILIDAD CON eDIV Y EL RESTO DE DLLs.
 * En caso de encontrar cualquier bug o anomal�a en este archivo, por favor
 * notif�quelo a Sion Entertainment en bugs@edivcentral.com
 */

/*! \file export.h
 * \brief Cabecera del SDK para DLL's de eDIV
 */
/*! \defgroup sdk SDK
 * @{
 */

#ifndef __EDIV_EXPORT_H_
#define __EDIV_EXPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

/* COMPATIBILIDAD WIN <-> LINUX */

#ifdef _WIN32
#	include <windows.h>
#else
	#ifndef bool
		typedef enum { FALSE, TRUE } bool;
	#endif
#endif

/* VARINDEX */
/*! \defgroup varindex Acceso a variables indexadas */
/*! @{ */

/*! Para usar con las funciones o macros de acceso a variables indexadas */
typedef enum { v_global, v_reserved, v_local } tipo_t;

/*! Estructura de variables indexadas */
typedef struct {
	unsigned char hash;	/*!< Hash del nombre de la variable, para acelerar su b�squeda */
	tipo_t tipo;		/*!< Tipo de variable (global, reservada o local) */
	char* nombre;		/*!< Nombre de la variable */
	int offset;			/*!< offset en mem[] (relativo al proceso si es local o reservada) */
} varindex_t;

#define global(nombre) fp->mem[fp->GetVarOffset(v_global,nombre)]
#define reserved(nombre,id) fp->mem[(id)+fp->GetVarOffset(v_reserved,nombre)]
#define local(nombre,id) fp->mem[(id)+fp->GetVarOffset(v_local,nombre)]
#define globalptr(nombre) fp->GetVarOffset(v_global,nombre)
#define reservedptr(nombre) fp->GetVarOffset(v_reserved,nombre)
#define localptr(nombre) fp->GetVarOffset(v_local,nombre)

/*! @} */
/* FIN DE VARINDEX */


#include <SDL/SDL.h>

/* Funciones de exportaci�n de datos */
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

/* Call_Entrypoint */
typedef int (TYPEOF_Call_Entrypoint)(int ep, ...);

/* Dibuja */
typedef int (TYPEOF_Dibuja)(SDL_Surface *, SDL_Rect, SDL_Rect, int, int, int, int);

/* Errores */
/*! Tipos de error para custom_error() */
typedef enum {
	_runtime_error=1,	/*!< Error normal (se puede depurar y/o ignorar) */
	_critical_error=2	/*!< Error cr�tico (interrumpe obligatoriamente el programa) */
} tipoerror;

typedef void (TYPEOF_Runtime_Error)(int, ...);
typedef void (TYPEOF_Critical_Error)(int, ...);
typedef void (TYPEOF_Custom_Error)(tipoerror,char*);

/*! Obtiene offset de variable indexada din�micamente */
typedef int (TYPEOF_GetVarOffset)(tipo_t tipo,char* nombre);

/*! Finaliza el stub (exit) */
typedef void (TYPEOF_Stub_Quit)(int n);

/*! EXPORTAFUNCS_PARAMS deben usarse como par�metros para ExportaFuncs */
#define EXPORTAFUNCS_PARAMS \
TYPEOF_EDIV_Export                  *EDIV_Export              ,\
TYPEOF_EDIV_Export_Const            *EDIV_Export_Const        ,\
TYPEOF_EDIV_Export_Global           *EDIV_Export_Global       ,\
TYPEOF_EDIV_Export_Global_Tab       *EDIV_Export_Global_Tab   ,\
TYPEOF_EDIV_Export_Global_Struct    *EDIV_Export_Global_Struct,\
TYPEOF_EDIV_Export_Member_Int       *EDIV_Export_Member_Int   ,\
TYPEOF_EDIV_Export_Member_Str       *EDIV_Export_Member_Str   ,\
TYPEOF_EDIV_Export_Member_Tab       *EDIV_Export_Member_Tab   ,\
TYPEOF_EDIV_Export_EndStruct        *EDIV_Export_EndStruct    ,\
TYPEOF_EDIV_Export_Local            *EDIV_Export_Local        ,\
TYPEOF_EDIV_Export_Local_Tab        *EDIV_Export_Local_Tab    ,\
TYPEOF_EDIV_Export_Local_Struct     *EDIV_Export_Local_Struct ,\
TYPEOF_EDIV_Export_Entrypoint		*EDIV_Export_Entrypoint	  ,\
TYPEOF_EDIV_Export_Priority			*EDIV_Export_Priority


/*
 * ENTRY-POINTS
 *
 * Estas funciones son llamadas por el STUB en determinados eventos
 * (Cuando una DLL hace cierta acci�n, lo avisa al Stub y el stub se encarga de llamar
 * a las correspondientes rutinas de las dll's, ordenadas por prioridad)
 */

/* Constantes para EDIV_Export_Entrypoint */

/*! \defgroup entrypoints Entrypoints */
/*! @{ */
#define EDIV_set_video_mode			1	/* Al activar un nuevo modo de v�deo */
#define EDIV_process_palette		2	/* Al cargar una paleta */
#define EDIV_process_active_palette	3	/* Al modificar la paleta activa (usada en los fades) */
#define EDIV_process_sound			4	/* Al cargar un efecto sonoro */
#define EDIV_process_map			5	/* Al cargar un mapa */
#define EDIV_process_fpg			6	/* Al cargar un FPG */
#define EDIV_process_fnt			7	/* Al cargar una fuente */
#define EDIV_background_to_buffer	8	/* Volcar el fondo al buffer */
#define EDIV_buffer_to_video		9	/* Volcar el buffer a la memoria de video */
#define EDIV_post_process_scroll	10	/* Tras dibujar una ventana de scroll (sin los sprites) */
#define EDIV_post_process_m7		11	/* Tras dibujar una ventana de modo7 (sin los sprites) */
#define EDIV_post_process_m8		12	/* Tras dibujar una ventana de modo8 (sin los sprites) */
#define EDIV_post_process_buffer	13	/* Tras haber terminado de dibujarlo todo */
#define EDIV_post_process			14	/* Tras ejecutar el frame de un proceso (cualquier %) */
#define EDIV_put_sprite				15	/* Dibujar un sprite */
#define EDIV_ss_init				16	/* Inicio de salvapantallas */
#define EDIV_ss_frame				17	/* Frame de salvapantallas */
#define EDIV_ss_end					18	/* Fin de salvapantallas */
#define EDIV_frame					19	/* En cada frame */
#define EDIV_trace					20	/* Despu�s de ejecutar cada instrucci�n de bytecode (solo en debug) */
#define EDIV_debug					21	/* Invocar al trazador - sentencia debug (solo en debug) */
#define EDIV_first_load				22	/* Se ejecuta al cargar la DLL en ejecucion */
#define EDIV_quit					23  /* Llamado por stub_quit() */
/*! @} */

/* #defines para que la declaraci�n de datos sea un poco m�s BASIC... :p */
#ifdef CONST
#	undef CONST
#endif
#define FUNCTION		EDIV_Export
#define CONST			EDIV_Export_Const
#define GLOBAL			EDIV_Export_Global
#define GLOBAL_ARRAY	EDIV_Export_Global_Tab
#define GLOBAL_STRUCT	EDIV_Export_Global_Struct
#define _INT			EDIV_Export_Member_Int
#define _STRING			EDIV_Export_Member_Str
#define _ARRAY			EDIV_Export_Member_Tab
#define END_STRUCT		EDIV_Export_EndStruct()
#define LOCAL			EDIV_Export_Local
#define LOCAL_ARRAY		EDIV_Export_Local_Tab
#define LOCAL_STRUCT	EDIV_Export_Local_Struct
#define ENTRYPOINT(e)	EDIV_Export_Entrypoint(EDIV_##e,e)
#define PRIORITY		EDIV_Export_Priority

/*!
 * FUNCTION_PARAMS deben usarse como parametros para TODAS las funciones
 * �OJO! debe ser igual en extern.h
 */
#define FUNCTION_PARAMS	struct _fun_params * fp

/*! Estructura de una entrada de la tabla de procesos */
struct _procs_s{
	int id ;         /* offset de los datos locales del proceso */
	int tipo ;       /* tipo de proceso */
	int orden ;      /* indice en proc_orden[] */
	int num_params ; /* numero de parametros k coje ( NO SE PARA K SIRVE PERO PARA ALGO ESTARA CBP NO ? ) */
	int imem ;       /* Posicion en la k se quedo suspendido el proceso */
	int priority ;   /* Priority */
	int frame;       /* Frame completado */
	int graph ;
};

/*! Estructura de una regi�n de pantalla */
struct _regions {
	int x , y , w , h ;
};

/*! Permite asegurarnos de que ciertos recursos est�n cargados */
struct _existe {
	int regions ;
	int dibuja ;
};

/*! Mapa dentro de un FPG */
struct _file
{
	SDL_Surface *Surface;
	int w,h;
	int bpp;
	int existe ;
	struct
	{
		int x , y ;
	} cpoint[ 20 ] ;
};

/*! Vector de FPG's */
struct _files
{
	int num ;
	int existe ;
	struct _file *mapa ;
};

/*! Datos de la paleta en la estructura _graphics */
struct _palette {
	byte r,g,b;
	byte unused;
};

/*! Estructura graphics, permite acceder a la pantalla */
typedef struct {
	int ancho;
	int alto;
	int bpp;
	int flags;
	int resflags;
	byte* buffer;
	byte* background;
	struct _palette* palette;
	struct _palette* activepal;
} _graphics;

/*! Par�metros para las funciones exportadas */
struct _fun_params{
	int *pila ;
	int *sp ;
	int *mem ;
	int num_params;
	varindex_t *varindex ;
	struct _procs_s *procs_s ;
	int *num_procs ;
	int *proc_orden ;
	int *proceso_actual ;
	unsigned char* nombre_program;
	struct _regions *regions ;
	struct _existe existe ;
	struct _files *files ;
	TYPEOF_Dibuja *Dibuja ; 
	TYPEOF_Call_Entrypoint *Call_Entrypoint ;
	TYPEOF_Runtime_Error *Runtime_Error ;
	TYPEOF_Critical_Error *Critical_Error ;
	TYPEOF_Custom_Error *Custom_Error;
	TYPEOF_GetVarOffset *GetVarOffset ;
	TYPEOF_Stub_Quit *Stub_Quit ;
	int imem_max;
	int* nullstring;
	int* nstring;
	_graphics* graphics;
};

/* Flags para graphics */
#define GR_FULLSCREEN	0x01
/* Flags reservados */
#define GR_ACTIVE		0x01
#define GR_CHANGED		0x02

/* Valores para PRIORITY() */
#define P_SIEMPRE			512
#define P_NUNCA				-512

/* Se usa igual que el getparm() de DIV */
#define getparm()		fp->pila[(*fp->sp)--]
#define getstrparm()	(char*)&fp->mem[fp->pila[(*fp->sp)--]]

/* Y esto por si los despistes xD */
#define retval(a)	return (a)


/*
 * Prototipos de los entrypoints
 */

/*! \addtogroup entrypoints */
/*! @{ */
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
void frame(FUNCTION_PARAMS);
void trace(int imem, char* nombreprg, int* lin, void* dbg);
void debug(int imem, char* nombreprg, int* lin, void* dbg);
void first_load(FUNCTION_PARAMS) ;
void quit(void);
/*! @} */

#ifdef __cplusplus
}
#endif

#endif /* __EDIV_EXPORT_H_ */

/*! @} */
