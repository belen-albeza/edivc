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

#include <stdio.h>
#include <SDL/SDL.h>

#include <export.h>
#include "input.h"

#define _KEY(a) CONST(#a,a)


#define _esc 1
#define _f1 59
#define _f2 60
#define _f3 61
#define _f4 62
#define _f5 63
#define _f6 64
#define _f7 65
#define _f8 66
#define _f9 67
#define _f10 68
#define _f11 87
#define _f12 88
#define _prn_scr 55     /* Impr Pant */
#define _scroll_lock 70 /* Bloq Despl */

#define _wave 41 /* "�" */
#define _1 2
#define _2 3
#define _3 4
#define _4 5
#define _5 6
#define _6 7
#define _7 8
#define _8 9
#define _9 10
#define _0 11
#define _minus 12 /* ? */
#define _plus 13  /* � */

#define _backspace 14
#define _tab 15
#define _q 16
#define _w 17
#define _e 18
#define _r 19
#define _t 20
#define _y 21
#define _u 22
#define _i 23
#define _o 24
#define _p 25
#define _l_brachet 26 /* "`" "^" */
#define _r_brachet 27 /* "+" "*" */
#define _enter 28

#define _caps_lock 58
#define _a 30
#define _s 31
#define _d 32
#define _f 33
#define _g 34
#define _h 35
#define _j 36
#define _k 37
#define _l 38
#define _semicolon 39  /* � */
#define _apostrophe 40 /* { */
#define _backslash 43  /* } */

#define _l_shift 42
#define _z 44
#define _x 45
#define _c 46
#define _v 47
#define _b 48
#define _n 49
#define _m 50
#define _comma 51
#define _point 52
#define _slash 53 /* "-" "_" */
#define _r_shift 54

#define _control 29
#define _alt 56
#define _space 57

#define _ins 82
#define _home 71
#define _pgup 73
#define _del 83
#define _end 79
#define _pgdn 81

#define _up 72
#define _down 80
#define _left 75
#define _right 77

#define _num_lock 69
#define _c_backslash 90
#define _c_asterisk 91
#define _c_minus 92
#define _c_home 93
#define _c_up 94
#define _c_pgup 95
#define _c_left 96
#define _c_center 97
#define _c_right 98
#define _c_end 99
#define _c_down 100
#define _c_pgdn 101
#define _c_ins 102
#define _c_del 103
#define _c_plus 104
#define _c_enter 105



Uint8 *keys ;
Uint8 mbuttons;

int SDLtoDIV[1024] ;


int ExportaFuncs(EXPORTAFUNCS_PARAMS)
{
	_KEY(_esc) ;
	_KEY(_f1) ;
	_KEY(_f2) ;
	_KEY(_f3) ;
	_KEY(_f4) ;
	_KEY(_f5) ;
	_KEY(_f6) ;
	_KEY(_f7) ;
	_KEY(_f8) ;
	_KEY(_f9) ;
	_KEY(_f10) ;
	_KEY(_f11) ;
	_KEY(_f12) ;
	_KEY(_prn_scr ) ;
	_KEY(_scroll_lock ) ;
	_KEY(_wave) ;
	_KEY(_1) ;
	_KEY(_2) ;
	_KEY(_3) ;
	_KEY(_4) ;
	_KEY(_5) ;
	_KEY(_6) ;
	_KEY(_7) ;
	_KEY(_8) ;
	_KEY(_9) ;
	_KEY(_0) ;
	_KEY(_minus) ;
	_KEY(_plus) ;
	_KEY(_backspace) ;
	_KEY(_tab) ;
	_KEY(_q) ;
	_KEY(_w) ;
	_KEY(_e) ;
	_KEY(_r) ;
	_KEY(_t) ;
	_KEY(_y) ;
	_KEY(_u) ;
	_KEY(_i) ;
	_KEY(_o) ;
	_KEY(_p) ;
	_KEY(_l_brachet) ;
	_KEY(_r_brachet) ;
	_KEY(_enter) ;
	_KEY(_caps_lock ) ;
	_KEY(_a) ;
	_KEY(_s) ;
	_KEY(_d) ;
	_KEY(_f) ;
	_KEY(_g) ;
	_KEY(_h) ;
	_KEY(_j) ;
	_KEY(_k) ;
	_KEY(_l) ;
	_KEY(_semicolon) ;
	_KEY(_apostrophe) ;
	_KEY(_backslash) ;
	_KEY(_l_shift) ;
	_KEY(_z) ;
	_KEY(_x) ;
	_KEY(_c) ;
	_KEY(_v) ;
	_KEY(_b) ;
	_KEY(_n) ;
	_KEY(_m) ;
	_KEY(_comma) ;
	_KEY(_point) ;
	_KEY(_slash) ;
	_KEY(_r_shift) ;
	_KEY(_control) ;
	_KEY(_alt) ;
	_KEY(_space) ;
	_KEY(_ins) ;
	_KEY(_home) ;
	_KEY(_pgup) ;
	_KEY(_del) ;
	_KEY(_end) ;
	_KEY(_pgdn) ;
	_KEY(_up) ;
	_KEY(_down) ;
	_KEY(_left) ;
	_KEY(_right) ;
	_KEY(_num_lock) ;
	_KEY(_c_backslash) ;
	_KEY(_c_asterisk) ;
	_KEY(_c_minus) ;
	_KEY(_c_plus) ;
	_KEY(_c_enter) ;
	_KEY(_c_home) ;
	_KEY(_c_pgup) ;
	_KEY(_c_end) ;
	_KEY(_c_pgdn) ;
	_KEY(_c_up) ;
	_KEY(_c_down) ;
	_KEY(_c_left) ;
	_KEY(_c_right) ;
	_KEY(_c_center) ;
	_KEY(_c_ins) ;
	_KEY(_c_del) ;
	
	FUNCTION("key",1,eDiv_Key) ;

	GLOBAL_STRUCT("mouse",0);
		_INT("x",0);			/* Coordenada x */
		_INT("y",0);			/* Coordenada y */
		_INT("graph",0);		/* Gr�fico */
		_INT("file",0);			/* FPG */
		_INT("z",-512);			/* Profundidad (TODO) */
		_INT("angle",0);		/* �ngulo (TODO) */
		_INT("size",100);		/* Tama�o (TODO) */
		_INT("flags",0);		/* Banderas (TODO) */
		_INT("region",0);		/* Regi�n (TODO) */
		_INT("left",0);			/* Bot�n izquierdo */
		_INT("middle",0);		/* Bot�n central o de ruedecilla */
		_INT("right",0);		/* Bot�n derecho */
		_INT("wheelup",0);		/* Ruedecilla arriba (NUEVO) */
		_INT("wheeldown",0);	/* Ruedecilla abajo (NUEVO) */
		_INT("cursor",0);		/* Emulaci�n con teclas de cursor (TODO) */
		_INT("speed",0);		/* Velocidad del rat�n (TODO) */
		_INT("transparency",0); /* Transparencia (NUEVO) (TODO) */
	END_STRUCT;

	ENTRYPOINT(first_load) ;
	ENTRYPOINT(frame) ;

	return TRUE;
}

int eDiv_Key(FUNCTION_PARAMS)
{
	/* FILE *fichero ; */
	int a ;
	
	/* fichero = fopen("input.txt" , "a+" ) ; */
	a = getparm() ;
	/* fprintf( fichero , "key: %i , keys[30]: %i \n" , a , keys[30] ) ; */
	/* fclose( fichero ) ; */
	
	if ( a == _control )
		if ( keys[ SDLK_RCTRL ] )
			return 1 ;
	if ( a == _alt )
		if ( keys[ SDLK_RALT ] )
			return 1 ;

	return keys[ SDLtoDIV[a] ] ;
}

/*
 * Entrypoints
 */
void first_load(FUNCTION_PARAMS)
{
	int i ;
	SDL_Init( SDL_INIT_EVENTTHREAD ) ;

	for ( i = 0 ; i < 1024 ; i++ )
	{
		SDLtoDIV[ i ] = 0 ;
	}

	SDLtoDIV[ _esc ] = SDLK_ESCAPE ;
	SDLtoDIV[ _1 ] = SDLK_1 ;
	SDLtoDIV[ _2 ] = SDLK_2 ;
	SDLtoDIV[ _3 ] = SDLK_3 ;
	SDLtoDIV[ _4 ] = SDLK_4 ;
	SDLtoDIV[ _5 ] = SDLK_5 ;
	SDLtoDIV[ _6 ] = SDLK_6 ;
	SDLtoDIV[ _7 ] = SDLK_7 ;
	SDLtoDIV[ _8 ] = SDLK_8 ;
	SDLtoDIV[ _9 ] = SDLK_9 ;
	SDLtoDIV[ _0 ] = SDLK_0 ;
	SDLtoDIV[ _minus ] = SDLK_MINUS ;
	SDLtoDIV[ _plus ] =SDLK_EQUALS  ;
	SDLtoDIV[ _backspace ] =SDLK_BACKSPACE  ;
	SDLtoDIV[ _tab ] =SDLK_TAB  ;
	SDLtoDIV[ _q ] =SDLK_q  ;
	SDLtoDIV[ _w ] =SDLK_w  ;
	SDLtoDIV[ _e ] =SDLK_e  ;
	SDLtoDIV[ _r ] =SDLK_r  ;
	SDLtoDIV[ _t ] =SDLK_t  ;
	SDLtoDIV[ _y ] =SDLK_y  ;
	SDLtoDIV[ _u ] =SDLK_u  ;
	SDLtoDIV[ _i ] =SDLK_i  ;
	SDLtoDIV[ _o ] =SDLK_o  ;
	SDLtoDIV[ _p ] =SDLK_p  ;
	SDLtoDIV[ _l_brachet ] =SDLK_LEFTBRACKET  ;
	SDLtoDIV[ _r_brachet ] =SDLK_RIGHTBRACKET  ;
	SDLtoDIV[ _enter ] =SDLK_RETURN  ;
	SDLtoDIV[ _control ] =SDLK_LCTRL  ;
	SDLtoDIV[ _a ] =SDLK_a  ;
	SDLtoDIV[ _s ] =SDLK_s  ;
	SDLtoDIV[ _d ] =SDLK_d  ;
	SDLtoDIV[ _f ] =SDLK_f  ;
	SDLtoDIV[ _g ] =SDLK_g  ;
	SDLtoDIV[ _h ] =SDLK_h  ;
	SDLtoDIV[ _j ] =SDLK_j  ;
	SDLtoDIV[ _k ] =SDLK_k  ;
	SDLtoDIV[ _l ] =SDLK_l  ;
	SDLtoDIV[ _semicolon ] =SDLK_SEMICOLON  ;
	SDLtoDIV[ _apostrophe ] =SDLK_QUOTE  ;
	SDLtoDIV[ _wave ] =SDLK_BACKQUOTE  ;
	SDLtoDIV[ _l_shift ] =SDLK_LSHIFT  ;
	SDLtoDIV[ _backslash ] =SDLK_BACKSLASH  ;
	SDLtoDIV[ _z ] =SDLK_z  ;
	SDLtoDIV[ _x ] =SDLK_x  ;
	SDLtoDIV[ _c ] =SDLK_c  ;
	SDLtoDIV[ _v ] =SDLK_v  ;
	SDLtoDIV[ _b ] =SDLK_b  ;
	SDLtoDIV[ _n ] =SDLK_n  ;
	SDLtoDIV[ _m ] =SDLK_m  ;
	SDLtoDIV[ _comma ] =SDLK_COMMA  ;
	SDLtoDIV[ _point ] =SDLK_PERIOD  ;
	SDLtoDIV[ _slash ] =SDLK_SLASH  ;
	SDLtoDIV[ _r_shift ] =SDLK_RSHIFT  ;
	SDLtoDIV[ _prn_scr ] =SDLK_SYSREQ  ;
	SDLtoDIV[ _alt ] =SDLK_LALT  ;
	SDLtoDIV[ _space ] =SDLK_SPACE  ;
	SDLtoDIV[ _caps_lock ] =SDLK_CAPSLOCK  ;
	SDLtoDIV[ _f1 ] =SDLK_F1  ;
	SDLtoDIV[ _f2 ] =SDLK_F2  ;
	SDLtoDIV[ _f3 ] =SDLK_F3  ;
	SDLtoDIV[ _f4 ] =SDLK_F4  ;
	SDLtoDIV[ _f5 ] =SDLK_F5  ;
	SDLtoDIV[ _f6 ] =SDLK_F6  ;
	SDLtoDIV[ _f7 ] =SDLK_F7  ;
	SDLtoDIV[ _f8 ] =SDLK_F8  ;
	SDLtoDIV[ _f9 ] =SDLK_F9  ;
	SDLtoDIV[ _f10 ] =SDLK_F10  ;
	SDLtoDIV[ _f11 ] =SDLK_F11  ;
	SDLtoDIV[ _f12 ] =SDLK_F12  ;
	SDLtoDIV[ _num_lock ] =SDLK_NUMLOCK  ;
	SDLtoDIV[ _scroll_lock ] =SDLK_SCROLLOCK  ;
	SDLtoDIV[ _home ] =SDLK_HOME  ;
	SDLtoDIV[ _up ] =SDLK_UP  ;
	SDLtoDIV[ _pgup ] =SDLK_PAGEUP  ;
	SDLtoDIV[ _end ] =SDLK_END  ;
	SDLtoDIV[ _down ] =SDLK_DOWN  ;
	SDLtoDIV[ _left ] =SDLK_LEFT ;
	SDLtoDIV[ _right ] =SDLK_RIGHT ;
	SDLtoDIV[ _pgdn ] =SDLK_PAGEDOWN  ;
	SDLtoDIV[ _ins ] =SDLK_INSERT  ;
	SDLtoDIV[ _c_del ] =SDLK_KP_PERIOD  ;
	SDLtoDIV[ _c_backslash ] =SDLK_KP_DIVIDE  ;
	SDLtoDIV[ _c_asterisk ] =SDLK_KP_MULTIPLY  ;
	SDLtoDIV[ _c_minus ] =SDLK_KP_MINUS  ;
	SDLtoDIV[ _c_plus ] =SDLK_KP_PLUS  ;
	SDLtoDIV[ _c_enter ] =SDLK_KP_ENTER  ;
	SDLtoDIV[ _c_ins ] =SDLK_KP0  ;
	SDLtoDIV[ _c_end ] =SDLK_KP1  ;
	SDLtoDIV[ _c_down ] =SDLK_KP2  ;
	SDLtoDIV[ _c_pgdn ] =SDLK_KP3  ;
	SDLtoDIV[ _c_left ] =SDLK_KP4  ;
	SDLtoDIV[ _c_center ] =SDLK_KP5  ;
	SDLtoDIV[ _c_right ] =SDLK_KP6  ;
	SDLtoDIV[ _c_home ] =SDLK_KP7  ;
	SDLtoDIV[ _c_up ] =SDLK_KP8  ;
	SDLtoDIV[ _c_pgup ] =SDLK_KP9  ;
}

void frame(FUNCTION_PARAMS)
{
	int numkeys ;
	int _mouse=globalptr("mouse");
	SDL_Rect srcrect,dstrect;
	SDL_Surface* mapamouse;
	
	SDL_PumpEvents();

	keys = SDL_GetKeyState(&numkeys ) ;

	/* MOUSE */

	mbuttons = SDL_GetMouseState(&fp->mem[_mouse],&fp->mem[_mouse+1]);
	
	/* Ponemos los 5 botones a 0 */
	memset(&fp->mem[_mouse+9],0,5*4);

	if(mbuttons&SDL_BUTTON(1))
		fp->mem[_mouse+9]=1;
	
	if(mbuttons&SDL_BUTTON(2))
		fp->mem[_mouse+10]=1;
	
	if(mbuttons&SDL_BUTTON(3))
		fp->mem[_mouse+11]=1;
	
	if(mbuttons&SDL_BUTTON(4))	/* podria no funcionar �necesario sdl_event? */
		fp->mem[_mouse+12]=1;
	
	if(mbuttons&SDL_BUTTON(5))	/* podria no funcionar �necesario sdl_event? */
		fp->mem[_mouse+13]=1;
	
	/* si mouse.graph!=0 */
	if(fp->mem[_mouse+2]!=0) {
		mapamouse=fp->files[fp->mem[_mouse+3]].mapa[fp->mem[_mouse+2]].Surface;
		srcrect.x=0;
		srcrect.y=0;
		srcrect.w=mapamouse->w;
		srcrect.h=mapamouse->h;
		
		dstrect.x=fp->mem[_mouse]-fp->files[fp->mem[_mouse+3]].mapa[fp->mem[_mouse+2]].cpoint[0].x;
		dstrect.y=fp->mem[_mouse+1]-fp->files[fp->mem[_mouse+3]].mapa[fp->mem[_mouse+2]].cpoint[0].y;
		dstrect.w=mapamouse->w;
		dstrect.h=mapamouse->h;

		/*
		 * TODO: a�adir chequeo de error si no existe file o mapa
		 */
		fp->Dibuja(mapamouse,srcrect,dstrect,fp->mem[_mouse+4],255,0,0);
	}

	/* FIN DE MOUSE */

	/* FILE* fichero ; */
	/* fichero = fopen( "input.txt" , "w+" ) ; */
	/* for ( i = 0 ; i < 256 ; i++ ) */
	/*	keys[i] = 0 ; */
/*
	for ( i = 0 ; i < 256 ; i++ )
	{
		if ( event[i].type == SDL_KEYDOWN )
		{
			keys[ SDLtoDIV[ event[i].key.keysym.sym ] ] = 1 ;
		}
		if ( event[i].type == SDL_KEYUP )
		{
			keys[ SDLtoDIV[ event[i].key.keysym.sym ] ] = 0 ;
		}
	}*/
	/*
	while(SDL_PollEvent(&tecla))
	{
		if(tecla.type == SDL_KEYDOWN)
		{
			if ( 
			keys[tecla.key.keysym.sym] = 1 ;
			//i=(int)tecla.key.keysym.sym;
		}
	}
	*/
/*	for ( i = 0 ; i < 256 ; i++ )
	{
		fprintf( fichero , "%i " , keys[i] ) ;
	}
	fprintf( fichero , "\n" ) ;
*/	
	//fclose( fichero ) ;
}