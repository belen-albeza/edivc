#ifndef __EDIV_GR_WIN32_H_
#define __EDIV_GR_WIN32_H_

/***                       ***
 ***  USAR DIRECTX SDK 6.1 ***
 ***                       ***/

#include <windows.h>
#include <ddraw.h>

#include "export.h"

#define	WINDOW_STYLE	(WS_OVERLAPPED|WS_BORDER|WS_CAPTION|WS_VISIBLE)
#define WINDOW_CLASS_NAME "qgraphics"

extern	HINSTANCE	global_hInstance;

extern HWND			cl_hwnd;
extern bool			ActiveApp, Minimized;

extern int		window_center_x, window_center_y;
extern RECT		window_rect;


typedef struct
{
	HINSTANCE		hInstance;
	void			*wndproc;
	HDC				hDC;				// DC global que usamos
	HWND			hWnd;				// HWND de la ventana principal

	HDC				hdcDIBSection;		// DC compatible con secci�n DIB
	HBITMAP			hDIBSection;		// secci�n DIB
	unsigned char	*pDIBBase;			// puntero base DIB, �NO usado directamente para dibujar!

	HPALETTE		hPal;				// paleta actual
	HPALETTE		hpalOld;			// paleta original del sistema
	COLORREF		oldsyscolors[20];	// colores del sistema originales

	HINSTANCE		hinstDDRAW;			// instancia de DDRAW.DLL
	LPDIRECTDRAW 	lpDirectDraw;		// puntero al objeto DirectDraw

	LPDIRECTDRAWSURFACE lpddsFrontBuffer;	// frontbuffer en memoria de v�deo
	LPDIRECTDRAWSURFACE lpddsBackBuffer;	// backbuffer en memoria del sistema
	LPDIRECTDRAWSURFACE lpddsOffScreenBuffer;	// backbuffer en memoria del sistema
	LPDIRECTDRAWPALETTE	lpddpPalette;		// paleta DirectDraw

	bool		palettized;			// cierto si el escritorio esta paletizado
	bool		modex;

	bool		initializing;
} swwstate_t;

extern swwstate_t sww_state;

/*
** DirectDraw
*/
bool DDRAW_Init( unsigned char **ppbuffer, int *ppitch );
void DDRAW_Shutdown( void );
void DDRAW_SetPalette( const unsigned char *palette );


#endif /* __EDIV_GR_WIN32_H_ */
