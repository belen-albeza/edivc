/*! \file regiones.c
 * \brief Funciones para manejo de regiones de pantalla
 */

#include <SDL/SDL.h>

#include "export.h"
#include "graphics.h"


/*! \brief Define una regi�n de pantalla
 * \todo A�adir un poco de comprobaci�n de errores
 * @param n N�mero de la regi�n a definir (1..31)
 * @param x Coordenada X de la esquina superior izquierda de la regi�n
 * @param y Coordenada Y de la esquina superior izquierda de la regi�n
 * @param w Anchura de la regi�n
 * @param h Altura de la regi�n
 * @return 1 si todo fue bien o 0 si hubo un error
 * @see eDIV_OUT_REGION(), eDIV_SCREEN_COPY()
 */
int eDIV_DEFINE_REGION(FUNCTION_PARAMS)
{
	int n , x , y , w , h ;
	h = getparm() ;
	w = getparm() ;
	y = getparm() ;
	x = getparm() ;
	n = getparm() ;

	if ( n > 31 || n < 1 ) {
		fp->Runtime_Error(108); /* n� de regi�n inv�lido */
		return 0;
	}

	fp->regions[n].x = x ;
	fp->regions[n].y = y ;
	fp->regions[n].w = w ;
	fp->regions[n].h = h ;


	return 1 ;
}

/*! \brief Indica si un proceso est� fuera de la regi�n indicada
 * @param id Identificador del proceso
 * @param r Regi�n
 * @return 1 si el proceso est� fuera de la regi�n o 0 en caso contrario
 * @see eDIV_DEFINE_REGION()
 */
int eDIV_OUT_REGION(FUNCTION_PARAMS)
{
	int id , r ;
	int f, g , x , y ;
	r = getparm() ;
	id = getparm() ;

	f = local("file",id) ;
	g = local("graph",id) ;
	
	if ( !files[f].existe || !files[f].mapa[g].existe )
		return -1 ;

	x = local("x",id) ;
	y = local("y",id) ;

	if ( x < fp->regions[r].x + fp->regions[r].w && x + files[f].mapa[g].Surface->w > fp->regions[r].x &&
		y < fp->regions[r].y + fp->regions[r].h && y + files[f].mapa[g].Surface->h > fp->regions[r].y )
		return 0 ;
	else
		return 1 ;
}
