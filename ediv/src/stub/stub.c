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

#include <assert.h>

#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <zlib.h>

#include "extern.h"
#include "main.h"
#include "kernel.h"
#include "inte.h"
#include "varindex.h"

#define long_header 9    // Longitud de la cabecera al inicio de los programas



/* Main ( argc, argv )
 *
 * Rutina principal. Lee el bytecode del ejecutable, lo descomprime y lo carga en memoria
 * (La mayor�a de las variables y buffers se mantienen con el mismo nombre que en el compilador:
 * mem, imem_max, etc)
 */

int main(int argc, char* argv[])
{
	//FILE *f;
	int f , i;
	int stub_size;
	int mimem[10];
	Uint32 tiempo[100] , tiempo_i ;
	FILE *file_tiempo ;
	byte * ptr;
	unsigned long len,len_descomp;
#ifdef DBG
	int start_lin;
	int linsize;
	int comp_size;
	int descomp_size;
	char* progcomp;
#endif	
	numdlls=0;
	n_externs=0;

	for ( i = 0 ; i < 100 ; i++ )
		tiempo[ i ] = 0 ;
	tiempo_i = 0 ;

	file_tiempo = fopen( "time.txt" , "w+" ) ;



	#ifdef _WIN32
		f=strlen(argv[0]);
		if(argv[0][f-4]!='.' || (argv[0][f-3]!='e' && argv[0][f-3]!='E')
		|| (argv[0][f-2]!='x' && argv[0][f-2]!='X') || (argv[0][f-1]!='e' && argv[0][f-1]!='E')) {
			strcat(argv[0],".exe");
		}
	#endif
//	assert(0) ;
	if((f=open(argv[0],O_RDONLY | O_BINARY))==-1) {
		/*#ifdef WIN32
			strcat(argv[0],".exe");
			printf("%s\n",argv[0]);
			if((f=open(argv[0],O_RDONLY | O_BINARY))==-1)
		#endif*/
		critical_error(1); // error leyendo el c�digo del programa
	}

	lseek(f,-4,SEEK_END);
	read(f,&stub_size,4);
	printf("STUB_SIZE: %d\n",stub_size);
	lseek(f,stub_size,SEEK_SET);
	read(f,mimem,4*10);
	read(f,&len,4);

	iloc_len=(mimem[5]+mimem[6]);
	if (iloc_len&1) iloc_len++;
	
	if (mimem[3]>0) {
		imem_max=mimem[8]+mimem[3]*(iloc_len)+iloc_len+2;
	} else {
		imem_max=mimem[8]+128*(iloc_len)+iloc_len+2;
		if (imem_max<256*1024) imem_max=256*1024;
		if (imem_max>512*1024) imem_max=512*1024;
	}
	
	
	if ((mem=(int*)malloc(4*imem_max+1032*5+16*1025+3))!=NULL){
		
		mem=(int*)((((int)mem+3)/4)*4);
		
		//filenames=(char*)&mem[imem_max+258*5]; // Buffer de 16*1025 para dirinfo[].name
		
		memset(mem,0,4*imem_max+1032*5);
		// Para sumar cadenas "en el aire"
/*		nullstring[0]=imem_max+1+258*0; mem[nullstring[0]-1]=0xDAD00402;
		nullstring[1]=imem_max+1+258*1; mem[nullstring[1]-1]=0xDAD00402;
		nullstring[2]=imem_max+1+258*2; mem[nullstring[2]-1]=0xDAD00402;
		nullstring[3]=imem_max+1+258*3; mem[nullstring[3]-1]=0xDAD00402;*/
		memcpy(mem,mimem,40);
		
		if ((ptr=(byte*)malloc(len))!=NULL) {
			
			read(f,ptr,len);
			
			len_descomp=mem[9];
			
			if (!uncompress((unsigned char *)&mem[9],&len_descomp,ptr,len)) {
				
				free(ptr);
				
				#ifdef DBG
					if ((mem[0]&64)==64) { debug=1; mem[0]-=64; }
				#endif

				if ((mem[0]&512)==512) { ignore_errors=1; mem[0]-=512; }
				
				/*i=imem_max+258*4;
				if ((_argc=argc-1)>10) _argc=10;
				for (n=0;n<_argc && n<argc-1;n++) {
					memcpy(&mem[i],argv[n+1],strlen(argv[n+1])+1);
					_argv(n)=i; i+=(strlen(argv[n+1])+4)/4;
				} for (;n<10;n++) _argv(n)=0;*/
				
				memb=(byte*)mem;
				memw=(word*)mem;
				
				if (mem[0]!=0 && mem[0]!=1) {
					critical_error(2);	// error en el formato de codigo
				}
				
				// leemos el indice de variables

				//assert(0);
				read(f,&num_indexed_vars,4);
				read(f,&len,4);
				len_descomp=num_indexed_vars*4;
				ptr=(byte*)e_malloc(len);
				read(f,ptr,len);
				varindex=(int*)e_malloc(len_descomp);
				if(uncompress((byte*)varindex,&len_descomp,ptr,len)) {
					free(ptr);
					free(varindex);
					close(f);
					critical_error(1); // error leyendo el c�digo del programa
				}
//				assert(0) ;

				for(len=0;len<num_indexed_vars;len++)
					fprintf(stdout, "%d: %d\n",len,varindex[len]);



				dimem=long_header;
				diloc=0;
//assert(0);
				/// DEBUG ///
#ifdef DBG
				lseek(f,-12,SEEK_END);
				read(f,&start_lin,4);
				lseek(f,start_lin,SEEK_SET);
				read(f,&descomp_size,4);
				read(f,&comp_size,4);
				progcomp=(char*)e_malloc(comp_size);
				read(f,progcomp,comp_size);
				prog=(char*)e_malloc(descomp_size);
				if(uncompress(prog,&descomp_size,progcomp,comp_size)) {
					close(f);
					free(prog);
					free(progcomp);
					critical_error(1);	// error leyendo el c�digo del programa
				}
				free(progcomp);
				read(f,&linsize,4);
				lin=(int*)e_malloc(linsize*6*4+4);
				lin[0]=linsize;
				read(f,&lin[1],linsize);
#endif

				close(f);


				




				// AKI HAY KE LLAMAR A LAS RUTINAS K INICIALIZAN TODO Y LLAMAR AL INTERPRETE

				// - Inicializar SDL
				// - Inicializarlo todo (incluyendo trazador si DBG esta definido)
				// - Rular el kernel y ke interprete el programa
				// - Si hay un error, llamar a error() y que se encargue de todo. Si est�
				//   definido DBG, debe ser posible retomar la ejecuci�n despues del error
				// - Al terminar la ejecuci�n, descargarlo TODO (empezando por los recursos y
				//   acabando por el c�digo interno)
				// - Restaurar el estado del sistema si es necesario y finalizar SDL

				// Nota: las DLL's se cargan en el transcurso del programa (las instrucciones
				// que ordenan cargar las dll's necesarias se encuentran en el propio bytecode)

				if (ini_kernel())
					exit (0);
				

				// AHORA TODO ESTO EN LA GRAPHICS.DLL

				// SE INICIALIZA LA SDL
				if (SDL_Init(SDL_INIT_TIMER))
					k_error(K_ERR_SDL_INIT);

				

				atexit(SDL_Quit);

				// SE PONE EL MODO GRAFICO 320x200 MODO VENTANA
				// Ya se hara el modo full screen
				// En el futuro se permitira especificar la resolucion inicial en una compiler option
				//  para ganar tiempo de procesado
/*				screen = SDL_SetVideoMode(320, 200, 24, SDL_HWSURFACE );
				//screen = SDL_SetVideoMode(320, 200, 24, NULL );
				
				if ( screen == NULL )
					k_error(K_ERR_SDL_SET_VIDEO_MODE);
*/				
				if ( !ini_interprete() )
					k_error(K_ERR_INI_INTERPRETE) ;


				while (1) {
/*
					for ( i = 0 ; i < 256 ; i ++ )
					{
						if ( !SDL_PollEvent(&event[i]) )
							break ;
					}
						

					for ( i = 0 ; i < 256 ; i++ ) {
						switch (event[i].type) {
							case SDL_QUIT:
								printf("Quit requested, quitting.\n");
								exit (0);
								break;
						}
					}
					*/
					while ( SDL_PollEvent(&event[0] ) )
					{
						switch( event[0].type )
						{
						case SDL_QUIT:
							exit(0) ;
							break ;
						}
					}


					if (!interprete())
						k_error(K_ERR_INTERPRETE);
					
					// Control de Frames por segundo POR HACER !!!!!!
					
					if (!kernel())
						k_error(K_ERR_KERNEL);

					// tiempo
					/*
					tiempo_pre = tiempo ;
					tiempo = SDL_GetTicks() ;
					fprintf(file_tiempo , "fps: %d\n" , 1000/(tiempo - tiempo_pre) ) ;
                    */

					// PETA EN AMD????
					tiempo_i ++ ;
					if ( tiempo_i > 99 ) tiempo_i = 0 ;
					tiempo[ tiempo_i ] = SDL_GetTicks() ;
					
					if ( tiempo_i == 99 )
						fp.mem[ fp.varindex[_glo_fps] ] = 100000 / (tiempo[99] - tiempo[0]) ;
					else
						if ( tiempo[tiempo_i] - tiempo[tiempo_i+1] != 0 )
							fp.mem[ fp.varindex[_glo_fps] ] = 100000 / (tiempo[tiempo_i] - tiempo[tiempo_i+1] ) ;


					
					//SDL_BlitSurface( imagen1 , NULL , screen , NULL ) ;
					//SDL_Flip(screen);
				}
				
				exit(0); // fin del programa
				
			} else {
				close(f);
				free(ptr);
				critical_error(1); // error leyendo el c�digo del programa
			}
			
		} else {
			close(f);
			critical_error(1); // error leyendo el c�digo del programa
		}
		
  } else { close(f); error(1); } // error leyendo el c�digo del programa

  return 0;
}


void stub_quit()
{
	exit(0) ;
}


// id�ntico a malloc, pero con errormsg utom�tico
void* e_malloc(size_t size)
{
	void* ret;

	if(!(ret = malloc(size))) {
		printf("memoria insuficiente\n"); // memoria insuficiente
		exit(1);
	}

	return ret;
}

