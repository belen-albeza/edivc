/* IconChanger
 * Peque�a utilidad-complemento para eDIV que permite sustituir el icono del stub de
 * win32 por otro. El icono nuevo debe ser exactamente igual que el original del stub,
 * es decir, tiene que cumplir las siguientes condiciones:
 * - Contener 6 im�genes en total:
 *   + 16x16 a 4, 8 y 24 bits de color
 *   + 32x32 a 4, 8 y 24 bits de color
 * - "Pesar" exactamente 8.854 bytes.
 * Este programa es muy simple as� que no se molesta en comprobar el formato del fichero,
 * �nicamente comprueba su tama�o. Si metes un icono que no es adecuado.. all� t�..
 * Puede ser �til en el futuro currarnos un programa decente que soporte cualquier tipo
 * de iconos, que cambiara el tama�o del exe, etc etc, ya ser�a la reostia, pero por
 * ahora con esto nos sobra.
 * Peke�o inconveniente: s�lo se puede cambiar el icono 1 vez :p  Si se kiere cambiar el
 * icono por segunda vez, hay que recompilar el programa. En realidad no importa, ya que
 * en verdad es lo que pasa en todos los compiladores...
 * Si se kiere cambiar el icono y un virus te ha comido el ediv.exe o el .prg, pos tiras
 * de Resource Hacker y a kaxkarla...
 * 
 * Er_Makina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

#ifndef _WIN32
#error IconChanger es s�lamente para Win32
#endif

#define ICO_SIZE	8854		// Tama�o que debe tener el .ico
#define	ICO_START	0x66		// Offset donde se empieza a leer el .ico
#define ICO_LEN		0x2230		// Tama�o del bloque a copiar del .ico al .exe


void* e_malloc(size_t size)
{
	void* ret;

	if(!(ret = malloc(size))) {
		printf("ERROR: Memoria insuficiente.\n\n");
		exit(1);
	}

	return ret;
}

int main(int argc, char* argv[])
{
	FILE* f;
	unsigned char *exe,*ico;
	int tamanyo;
	int i,j;
	int ok=0;

	printf("eDIV IconChanger - (c) Copyright Sion Ltd. 2002\n\n");
	if(argc!=3) {
		printf("Modo de uso:\n\n    %s <programa.exe> <icono.ico>\n\n",argv[0]);
		exit(2);
	}

	if((f=fopen(argv[2],"rb"))==NULL) {
		printf("ERROR: No puedo abrir %s\n\n");
		exit(3);
	}

	fseek(f,0,SEEK_END);
	tamanyo=ftell(f);
	if(tamanyo!=ICO_SIZE) {
		fclose(f);
		printf("ERROR: El icono no es del formato v�lido\n\n");
		printf("Te refrescar� la memoria:\nEl icono (.ico) DEBE contener 6 im�genes en total, a saber:\n");
		printf(" - 3 im�genes de 16x16 (a 4, 8 y 24 bits de color).\n");
		printf(" - 3 im�genes de 32x32 (a 4, 8 y 24 bits de color).\n");
		printf("No puede faltar ninguna, ya que el archivo debe ocupar EXACTAMENTE %d bytes.\n\n",ICO_SIZE);
		exit(4);
	}

	ico=(unsigned char*)e_malloc(tamanyo);
	fseek(f,0,SEEK_SET);
	fread(ico,tamanyo,1,f);
	fclose(f);

	if((f=fopen(argv[1],"rb"))==NULL) {
		printf("ERROR: No puedo abrir %s\n\n");
		exit(5);
	}

	fseek(f,0,SEEK_END);
	tamanyo=ftell(f);
	fseek(f,0,SEEK_SET);
	exe=(unsigned char*)e_malloc(tamanyo);	/* no creo ke pase nada por unos 125 kb...
											   eso si, cuando se puedan meter el PAK y
											   las DLL's en el exe, va a haber ke cambiar
											   esto... */
	fread(exe,tamanyo,1,f);
	fclose(f);

	// BUSKEDA

	printf("Buscando sitio donde meter mano en el exe...\n");

	for(i=20;i<tamanyo-sizeof(image);i++) {
		if(exe[i]==image[0]) {
			ok=1;
			for(j=1;j<sizeof(image);j++) {
				if(exe[i+j]!=image[j]) {
					ok=0;
					break;
				}
			}
			if(ok) break;
		}
	}

	if(!ok) {
		free(ico);
		free(exe);
		printf("ERROR: El ejecutable no parece haber sido compilado con eDIV, o bien ya se le ha cambiado el icono.\n\n");
		exit(6);
	}

	// "parcheamos" el exe en memoria
	memcpy(&exe[i],&ico[ICO_START],ICO_LEN);
	free(ico);
	
	// y escribimos el exe enterito al disco duro.. lo mio si es optimizar eh? xDD
	if((f=fopen(argv[1],"wb"))==NULL) {
		free(exe);
		printf("ERROR: No tengo acceso de escritura a %s\n\n",argv[1]);
		exit(7);
	}

	fwrite(exe,tamanyo,1,f);
	fclose(f);
	free(exe);
	printf("Completado :)\n\n");

	return 0;
}

