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


/**** ��� OJO CON LAS COMAS !!! ****/


#ifdef _WIN32
#	include <windows.h>
#else
#	include <stdlib.h>
#	include <string.h>
#endif

#include "shared.h"
#include "language.h"


int detecta_idioma_iso(char* lang)
{
	int i;
	static char getid[NUM_LANGUAGES][3] = {
		"es",	// espa�ol
		"it",	// italiano
		"pt",	// portugu�s
		"en",	// ingl�s
		"ca",	// catal�n
		"eu"	// euskera
	};
	if(lang==NULL) return DEFAULT_LANGUAGE;
	if(strlen(lang)>2) lang[2]=0;
	strlwr(lang);
	for(i=0;i<NUM_LANGUAGES;i++)
		if(lang[0]==getid[i][0])
			if(lang[1]==getid[i][1])
				break;
	if(i==NUM_LANGUAGES) i=DEFAULT_LANGUAGE;
	return i;
}


int detecta_idioma()
{
	#ifdef _WIN32
		int i;
		static int getid[NUM_LANGUAGES] = {
			0x0a,	// espa�ol
			0x10,	// italiano
			0x16,	// portugu�s
			0x09,	// ingl�s
			0x03,	// catal�n
			0x2d	// euskera
		};
		LANGID lang;

		lang=GetSystemDefaultLangID()&0xff;
		for(i=0;i<NUM_LANGUAGES;i++)
			if(lang==getid[i]) break;
		if(i==NUM_LANGUAGES) i=DEFAULT_LANGUAGE;
		return i;
	#else
		char* langcfg=getenv("LANG");
		if(langcfg==NULL) return DEFAULT_LANGUAGE;
		else return detecta_idioma_iso(langcfg);
	#endif
}


char* translate(int id_cadena)
{
	static char *msg[NUM_LANGUAGES][5]= {

		/* 0 - ESPA�OL */

		/* 0	*/	"ERROR %d: ",
		/* 1	*/	"eDIV: Error en ejecuci�n",
		/* 2	*/	"eDIV: Error cr�tico",
		/* 3	*/	"Error en %s: ",
		/* 4	*/	"eDIV: Error en librer�a din�mica",

		/* 1 - ITALIANO */

		/* 0	*/	"ERRORE %d: ",
		/* 1	*/	"eDIV: Errore in esecuzione",
		/* 2	*/	"eDIV: Errore critico",
		/* 3	*/	"Errore in %s: ",
		/* 4	*/	"eDIV: Errore in libreria dinamica",

		/* 2 - PORTUGU�S (FIXMI: traducir) */

		/* 0	*/	"ERROR %d: ",
		/* 1	*/	"eDIV: Error en ejecuci�n",
		/* 2	*/	"eDIV: Error cr�tico",
		/* 3	*/	"Error en %s: ",
		/* 4	*/	"eDIV: Error en librer�a din�mica",
		
		/* 3 - INGL�S */

		/* 0	*/	"ERROR %d: ",
		/* 1	*/	"eDIV: Run-time error",
		/* 2	*/	"eDIV: Critical error",
		/* 3	*/	"Error in %s: ",
		/* 4	*/	"eDIV: Error in dynamic library",

		/* 4 - CATAL�N (FIXMI: traducir) */

		/* 0	*/	"ERROR %d: ",
		/* 1	*/	"eDIV: Error en ejecuci�n",
		/* 2	*/	"eDIV: Error cr�tico",
		/* 3	*/	"Error en %s: ",
		/* 4	*/	"eDIV: Error en librer�a din�mica",

		/* 5 - EUSKERA (FIXMI: traducir) */

		/* 0	*/	"ERROR %d: ",
		/* 1	*/	"eDIV: Error en ejecuci�n",
		/* 2	*/	"eDIV: Error cr�tico",
		/* 3	*/	"Error en %s: ",
		/* 4	*/	"eDIV: Error en librer�a din�mica"

	};
	return msg[idioma][id_cadena];
}


/*
 * NOTA: los huecos vac�os (184..199) son de errores no usados en DIV2, por favor
 * aprovechadlos para a�adir nuevos errores.
 */

char* translate_runtime_error(int num)
{
	static char *e[NUM_LANGUAGES][101]= {

		/* 0 - ESPA�OL */

		/* 100 */ "No hay memoria suficiente para ejecutar el programa.",
		/* 101 */ "Llamada a key() con un c�digo de tecla inexistente.",
		/* 102 */ "No se pudo cargar la paleta, archivo no encontrado.",
		/* 103 */ "Se intent� cargar un archivo de paleta inv�lido.",
		/* 104 */ "Demasiados ficheros FPG abiertos a la vez.",
		/* 105 */ "No se pudo cargar el fichero, archivo no encontrado.",
		/* 106 */ "Se intent� cargar un fichero FPG no v�lido.",
		/* 107 */ "N�mero de scroll inv�lido (debe estar entre 0 y 9).",
		/* 108 */ "N�mero de regi�n inv�lido (fuera de rango).",
		/* 109 */ "C�digo de fichero inv�lido.",
		/* 110 */ "C�digo de gr�fico inv�lido.",
		/* 111 */ "Se intent� usar un fichero FPG antes de cargarlo.",
		/* 112 */ "Se necesita un c�digo de gr�fico para el scroll.",
		/* 113 */ "Se han cargado demasiados fuentes de letras.",
		/* 114 */ "No se pudo cargar el fuente, archivo no encontrado.",
		/* 115 */ "Se intent� cargar un archivo de fuente no v�lido.",
		/* 116 */ "C�digo identificador de fuente de letras inv�lido.",
		/* 117 */ "C�digo de centrado de texto inv�lido.",
		/* 118 */ "Hay demasiados textos activos en el programa.",
		/* 119 */ "Indentificador de texto no v�lido.",
		/* 120 */ "Regi�n de pantalla definida incorrectamente.",
		/* 121 */ "Se intent� utilizar un gr�fico que no existe.",
		/* 122 */ "Se intent� escribir un bloque fuera de la memoria.",
		/* 123 */ "No se pudo abrir el archivo para escritura.",
		/* 124 */ "No se pudo escribir el archivo (ver espacio en disco).",
		/* 125 */ "Se intent� leer un bloque fuera de la memoria.",
		/* 126 */ "No se pudo abrir el archivo para lectura.",
		/* 127 */ "No se pudo leer el archivo.",
		/* 128 */ "No se pudo cargar el efecto de sonido.",
		/* 129 */ "No se pudo tocar el efecto de sonido solicitado.",
		/* 130 */ "No se pudo iniciar la animaci�n solicitada.",
		/* 131 */ "N�mero de modo 7 inv�lido (debe estar entre 0 y 9).",
		/* 132 */ "Se necesita un c�digo de gr�fico para el modo 7.",
		/* 133 */ "N�mero de punto de control inv�lido.",
		/* 134 */ "N�mero de bot�n incorrecto (debe estar entre 0 y 3).",
		/* 135 */ "N�mero de eje incorrecto (debe estar entre 0 y 3).",
		/* 136 */ "Direcci�n de la tabla de paleta fuera de la memoria.",
		/* 137 */ "No se pueden comprobar regiones en gr�ficos de m-7.",
		/* 138 */ "C�digo de informaci�n gr�fica incorrecto.",
		/* 139 */ "No se pueden comprobar colisiones en gr�ficos de m-7.",
		/* 140 */ "Acceso fuera de rango.",
		/* 141 */ "Se intent� acceder a un proceso inv�lido.",
		/* 142 */ "El proceso parece bloqueado, esperando FRAME.",
		/* 143 */ "No se pudo cargar el mapa, archivo no encontrado.",
		/* 144 */ "Se intent� cargar un archivo de mapa inv�lido.",
		/* 145 */ "Se ha intentado hacer una divisi�n entre cero.",
		/* 146 */ "El tama�o de la regi�n es incorrecto.",
		/* 147 */ "No se pudo cargar FLI/FLC, archivo no encontrado.",
		/* 148 */ "Valor de timeout incorrecto (debe ser entre 1 y 60).",
		/* 149 */ "N�mero de jugadores incorrecto (debe ser entre 2 y 8).",
		/* 150 */ "S�lo se pueden enviar datos globales.",
		/* 151 */ "Tama�o de casilla inv�lido (debe ser entre 1 y 256).",
		/* 152 */ "Mapa de b�squeda no v�lido (desde 1x1 hasta 128x128).",
		/* 153 */ "Tama�o de mapa incorrecto (de 1x1 a 32768x32768).",
		/* 154 */ "N�mero de color incorrecto (debe ser de 0 a 255).",
		/* 155 */ "El centro est� fuera de los l�mites del gr�fico.",
		/* 156 */ "El objeto se encuentra fuera del mapa y sera eliminado.",
		/* 157 */ "Textura del mapa no encontrada.",
		/* 158 */ "El tama�o de la textura es incorrecto.",
		/* 159 */ "No se pudo cargar el mundo, archivo no encontrado.",
		/* 160 */ "No se pudo cargar el mundo, archivo no v�lido.",
		/* 161 */ "El n�mero de bandera no es v�lido.",
		/* 162 */ "Dispositivo inv�lido (s�lo 1-IPX,2-SERIAL,3-MODEM).",
		/* 163 */ "Tama�o de paquete inv�lido (s�lo de 1 a 199).",
		/* 164 */ "La cadena de texto destino no es v�lida.",
		/* 165 */ "Se intent� acceder a un puntero nulo.",
		/* 166 */ "El modo de acceso al archivo no es v�lido.",
		/* 167 */ "No se pudo cargar el m�dulo.",
		/* 168 */ "Demasiados errores ignorados.",
		/* 169 */ "Demasiados archivos abiertos.",
		/* 170 */ "Identificador de archivo (handle) no v�lido.",
		/* 171 */ "Valor fuera de rango.",
		/* 172 */ "Demasiados objetos gr�ficos visualizados.",
		/* 173 */ "Tipo de objeto gr�fico no conocido.",
		/* 174 */ "Porcentaje de tinta fuera de rango (0..15).",
		/* 175 */ "N�mero de objeto gr�fico no v�lido.",
		/* 176 */ "Error variable de vpe: Textura de mapa [a] no encontrada en fichero [b].",
		/* 177 */ "Textura de mapa.",
		/* 178 */ "no encontrada en fichero.",
		/* 179 */ "Se realizaron demasiadas peticiones de memoria din�mica.",
		/* 180 */ "El puntero no se corresponde con ninguno de los bloques reservados.",
		/* 181 */ "No se pueden reservar bloques de menos de una posici�n.",
		/* 182 */ "Se intent� (des)encriptar un bloque fuera de la memoria.",
		/* 183 */ "No se puede cargar otra paleta cuando est� forzada la actual.",
		/* 184 */ "",
		/* 185 */ "",
		/* 186 */ "",
		/* 187 */ "",
		/* 188 */ "",
		/* 189 */ "",
		/* 190 */ "",
		/* 191 */ "",
		/* 192 */ "",
		/* 193 */ "",
		/* 194 */ "",
		/* 195 */ "",
		/* 196 */ "",
		/* 197 */ "",
		/* 198 */ "",
		/* 199 */ "",
		/* 200 */ "Archivo con datos corrompidos, no se pudo cargar.",

		/* 1 - ITALIANO */

		/* 100 */ "Non hai memoria sufficiente per eseguire il programma.",
		/* 101 */ "Chiamata a key() con un codice di tasto inesistente.",
		/* 102 */ "Non � tasto possibile caricare la paletta, archivio non trovato.",
		/* 103 */ "Si � tentato di caricare un archivio di paletta non valido.",
		/* 104 */ "Troppi file FPG aperti contemporaneamente.",
		/* 105 */ "Non � stato possibile caricare il file, archivio non trovato.",
		/* 106 */ "Si � tentato di caricare un file FPG non valido.",
		/* 107 */ "Numero di scroll non valido (deve essere tra 0 e 9).",
		/* 108 */ "Numero di regione non valido (fuori rango).",
		/* 109 */ "Codice di file non valido.",
		/* 110 */ "Codice di grafico non valido.",
		/* 111 */ "Si � tentato di usare un file FPG prima di caricarlo.",
		/* 112 */ "Si necessita un codice di grafico per lo scroll.",
		/* 113 */ "Sono state caricate troppe fonti di lettere.",
		/* 114 */ "Non � stato possibile caricare la fonte, archivio non trovato.",
		/* 115 */ "Si � tentato di caricare un archivio di fonte non valido.",
		/* 116 */ "Codice identificatore fonte di lettere non valido.",
		/* 117 */ "Codice di centrato di testo non valido.",
		/* 118 */ "Hai troppi testi attivi nel programma.",
		/* 119 */ "Identificatore di testo non valido.",
		/* 120 */ "Regione di schermo definita incorrettamente.",
		/* 121 */ "Si � tentato di utilizzare un grafico che non esiste.",
		/* 122 */ "Si � tentato di scrivere un blocco fuori della memoria.",
		/* 123 */ "Non � stato possibile aprire l'archivio per la scrittura.",
		/* 124 */ "Non � stato possibile scrivere l'archivio (vedere spazio nel disco).",
		/* 125 */ "Si � tentato di leggere un blocco fuori della memoria.",
		/* 126 */ "Non � stato possibile aprire l'archivio per la lettura.",
		/* 127 */ "Non � stato possibile leggere l'archivio.",
		/* 128 */ "Non � stato possibile caricare l'effetto di suono.",
		/* 129 */ "Non � stato possibile eseguire l'effetto di suono sollecitato.",
		/* 130 */ "Non � stato possibile iniziare l'animazione sollecitata.",
		/* 131 */ "Numero di mode 7 non valido (deve essere tra 0 e 9).",
		/* 132 */ "Si necessita un codice di grafico per il mode 7.",
		/* 133 */ "Numero punto di controllo non valido.",
		/* 134 */ "Numero di bottone incorretto (deve essere tra 0 e 3).",
		/* 135 */ "Numero di asse incorretto (deve essere tra 0 e 3).",
		/* 136 */ "Direzione della tabella di paletta fuori della memoria.",
		/* 137 */ "Non si possono comprovare regioni in grafici di m-7.",
		/* 138 */ "Codice d'informazione grafica incorretto.",
		/* 139 */ "Non si possono comprovare collisioni in grafici di m-7.",
		/* 140 */ "Accesso fuori rango.",
		/* 141 */ "Si � tentato di accedere ad un processo non valido.",
		/* 142 */ "Il processo sembra bloccato, aspettando FRAME.",
		/* 143 */ "Non � stato possibile caricare la mappa, archivio non trovato.",
		/* 144 */ "Si � tentato di caricare un archivio di mappa non valido.",
		/* 145 */ "Si � tentato di eseguire una divisione per zero.",
		/* 146 */ "La grandezza della regione � incorretta.",
		/* 147 */ "Non � stato possibile caricare FLI/FLC, archivio non trovato.",
		/* 148 */ "Valore del timeout incorretto (deve essere tra 1 e 60).",
		/* 149 */ "Numero di giocatori incorretto (deve essere tra 2 e 8).",
		/* 150 */ "Si possono inviare solo dati globali.",
		/* 151 */ "Grandezza di casella invalida (deve essere tra 1 e 256).",
		/* 152 */ "Mappa di ricerca non valida (da 1x1 a 128x128).",
		/* 153 */ "Grandezza di mappa incorretta (da 1x1 a 32768x32768).",
		/* 154 */ "Numero di colore incorretto (deve essere da 0 a 255).",
		/* 155 */ "Il centro � fuori dai limiti del grafico.",
		/* 156 */ "L'oggetto si trova fuori dalla mappa � sar� eliminato.",
		/* 157 */ "Textura della mappa non trovata.",
		/* 158 */ "La grandezza della textura � incorretta.",
		/* 159 */ "Non � stato possibile caricare il mondo, archivio non trovato.",
		/* 160 */ "Non � stato possibile caricare il mondo, archivio non valido.",
		/* 161 */ "Il numero di bandiera non � valido.",
		/* 162 */ "Dispositivo non valido (solo 1-IPX,2-SERIAL,3-MODEM).",
		/* 163 */ "Grandezza di pacchetto non valida (solo da 1 a 199).",
		/* 164 */ "La catena testo di destinazione non � valida.",
		/* 165 */ "Si � tentato di accedere ad un puntatore nullo.",
		/* 166 */ "Il modo di acceso all'archivio non � valido.",
		/* 167 */ "Non � stato possibile caricare il modulo.",
		/* 168 */ "Troppi errori ignorati.",
		/* 169 */ "Troppi archivi aperti.",
		/* 170 */ "Identificatore archivio (handle) non valido.",
		/* 171 */ "Valore fuori rango.",
		/* 172 */ "Troppi oggetti grafici visualizzati.",
		/* 173 */ "Tipo di oggetto grafico sconosciuto.",
		/* 174 */ "Percentuale d'inchiostro fuori rango (0..15).",
		/* 175 */ "Numero di oggetto grafico non valido.",
		/* 176 */ "Errore variabile mode 8: Textura di mappa [a] non trovata in file [b]."
		/* 177 */ "Textura di mappa.",
		/* 178 */ "non trovata in file.",
		/* 179 */ "Sono state realizzate troppe sollecitazioni di memoria dinamica.",
		/* 180 */ "Il puntatore non corrisponde con nessuno dei blocchi reservati.",
		/* 181 */ "Non � possibile riservare blocchi minori di una posizione.",
		/* 182 */ "Si � tentato di (dis)encriptare un blocco fuori della memoria.",
		/* 183 */ "Non � possibile caricare un'altra paletta quando � forzata l'attuale.",
		/* 184 */ "",
		/* 185 */ "",
		/* 186 */ "",
		/* 187 */ "",
		/* 188 */ "",
		/* 189 */ "",
		/* 190 */ "",
		/* 191 */ "",
		/* 192 */ "",
		/* 193 */ "",
		/* 194 */ "",
		/* 195 */ "",
		/* 196 */ "",
		/* 197 */ "",
		/* 198 */ "",
		/* 199 */ "",
		/* 200 */ "Archivio con dati corrotti, non si � potuto caricare.",

		/* 2 - PORTUGU�S (FIXMI: traducir) */

		/* 100 */ "No hay memoria suficiente para ejecutar el programa.",
		/* 101 */ "Llamada a key() con un c�digo de tecla inexistente.",
		/* 102 */ "No se pudo cargar la paleta, archivo no encontrado.",
		/* 103 */ "Se intent� cargar un archivo de paleta inv�lido.",
		/* 104 */ "Demasiados ficheros FPG abiertos a la vez.",
		/* 105 */ "No se pudo cargar el fichero, archivo no encontrado.",
		/* 106 */ "Se intent� cargar un fichero FPG no v�lido.",
		/* 107 */ "N�mero de scroll inv�lido (debe estar entre 0 y 9).",
		/* 108 */ "N�mero de regi�n inv�lido (fuera de rango).",
		/* 109 */ "C�digo de fichero inv�lido.",
		/* 110 */ "C�digo de gr�fico inv�lido.",
		/* 111 */ "Se intent� usar un fichero FPG antes de cargarlo.",
		/* 112 */ "Se necesita un c�digo de gr�fico para el scroll.",
		/* 113 */ "Se han cargado demasiados fuentes de letras.",
		/* 114 */ "No se pudo cargar el fuente, archivo no encontrado.",
		/* 115 */ "Se intent� cargar un archivo de fuente no v�lido.",
		/* 116 */ "C�digo identificador de fuente de letras inv�lido.",
		/* 117 */ "C�digo de centrado de texto inv�lido.",
		/* 118 */ "Hay demasiados textos activos en el programa.",
		/* 119 */ "Indentificador de texto no v�lido.",
		/* 120 */ "Regi�n de pantalla definida incorrectamente.",
		/* 121 */ "Se intent� utilizar un gr�fico que no existe.",
		/* 122 */ "Se intent� escribir un bloque fuera de la memoria.",
		/* 123 */ "No se pudo abrir el archivo para escritura.",
		/* 124 */ "No se pudo escribir el archivo (ver espacio en disco).",
		/* 125 */ "Se intent� leer un bloque fuera de la memoria.",
		/* 126 */ "No se pudo abrir el archivo para lectura.",
		/* 127 */ "No se pudo leer el archivo.",
		/* 128 */ "No se pudo cargar el efecto de sonido.",
		/* 129 */ "No se pudo tocar el efecto de sonido solicitado.",
		/* 130 */ "No se pudo iniciar la animaci�n solicitada.",
		/* 131 */ "N�mero de modo 7 inv�lido (debe estar entre 0 y 9).",
		/* 132 */ "Se necesita un c�digo de gr�fico para el modo 7.",
		/* 133 */ "N�mero de punto de control inv�lido.",
		/* 134 */ "N�mero de bot�n incorrecto (debe estar entre 0 y 3).",
		/* 135 */ "N�mero de eje incorrecto (debe estar entre 0 y 3).",
		/* 136 */ "Direcci�n de la tabla de paleta fuera de la memoria.",
		/* 137 */ "No se pueden comprobar regiones en gr�ficos de m-7.",
		/* 138 */ "C�digo de informaci�n gr�fica incorrecto.",
		/* 139 */ "No se pueden comprobar colisiones en gr�ficos de m-7.",
		/* 140 */ "Acceso fuera de rango.",
		/* 141 */ "Se intent� acceder a un proceso inv�lido.",
		/* 142 */ "El proceso parece bloqueado, esperando FRAME.",
		/* 143 */ "No se pudo cargar el mapa, archivo no encontrado.",
		/* 144 */ "Se intent� cargar un archivo de mapa inv�lido.",
		/* 145 */ "Se ha intentado hacer una divisi�n entre cero.",
		/* 146 */ "El tama�o de la regi�n es incorrecto.",
		/* 147 */ "No se pudo cargar FLI/FLC, archivo no encontrado.",
		/* 148 */ "Valor de timeout incorrecto (debe ser entre 1 y 60).",
		/* 149 */ "N�mero de jugadores incorrecto (debe ser entre 2 y 8).",
		/* 150 */ "S�lo se pueden enviar datos globales.",
		/* 151 */ "Tama�o de casilla inv�lido (debe ser entre 1 y 256).",
		/* 152 */ "Mapa de b�squeda no v�lido (desde 1x1 hasta 128x128).",
		/* 153 */ "Tama�o de mapa incorrecto (de 1x1 a 32768x32768).",
		/* 154 */ "N�mero de color incorrecto (debe ser de 0 a 255).",
		/* 155 */ "El centro est� fuera de los l�mites del gr�fico.",
		/* 156 */ "El objeto se encuentra fuera del mapa y sera eliminado.",
		/* 157 */ "Textura del mapa no encontrada.",
		/* 158 */ "El tama�o de la textura es incorrecto.",
		/* 159 */ "No se pudo cargar el mundo, archivo no encontrado.",
		/* 160 */ "No se pudo cargar el mundo, archivo no v�lido.",
		/* 161 */ "El n�mero de bandera no es v�lido.",
		/* 162 */ "Dispositivo inv�lido (s�lo 1-IPX,2-SERIAL,3-MODEM).",
		/* 163 */ "Tama�o de paquete inv�lido (s�lo de 1 a 199).",
		/* 164 */ "La cadena de texto destino no es v�lida.",
		/* 165 */ "Se intent� acceder a un puntero nulo.",
		/* 166 */ "El modo de acceso al archivo no es v�lido.",
		/* 167 */ "No se pudo cargar el m�dulo.",
		/* 168 */ "Demasiados errores ignorados.",
		/* 169 */ "Demasiados archivos abiertos.",
		/* 170 */ "Identificador de archivo (handle) no v�lido.",
		/* 171 */ "Valor fuera de rango.",
		/* 172 */ "Demasiados objetos gr�ficos visualizados.",
		/* 173 */ "Tipo de objeto gr�fico no conocido.",
		/* 174 */ "Porcentaje de tinta fuera de rango (0..15).",
		/* 175 */ "N�mero de objeto gr�fico no v�lido.",
		/* 176 */ "Error variable de vpe: Textura de mapa [a] no encontrada en fichero [b].",
		/* 177 */ "Textura de mapa.",
		/* 178 */ "no encontrada en fichero.",
		/* 179 */ "Se realizaron demasiadas peticiones de memoria din�mica.",
		/* 180 */ "El puntero no se corresponde con ninguno de los bloques reservados.",
		/* 181 */ "No se pueden reservar bloques de menos de una posici�n.",
		/* 182 */ "Se intent� (des)encriptar un bloque fuera de la memoria.",
		/* 183 */ "No se puede cargar otra paleta cuando est� forzada la actual.",
		/* 184 */ "",
		/* 185 */ "",
		/* 186 */ "",
		/* 187 */ "",
		/* 188 */ "",
		/* 189 */ "",
		/* 190 */ "",
		/* 191 */ "",
		/* 192 */ "",
		/* 193 */ "",
		/* 194 */ "",
		/* 195 */ "",
		/* 196 */ "",
		/* 197 */ "",
		/* 198 */ "",
		/* 199 */ "",
		/* 200 */ "Archivo con datos corrompidos, no se pudo cargar.",

		/* 3 - INGL�S - Gracias a los chicos de FastTrak ;) */

		/* 100 */ "There is not enough memory to execute the program.",
		/* 101 */ "Call to a key() with a nonexistent key code.",
		/* 102 */ "The palette was not loaded, archive not found.",
		/* 103 */ "A not valid archive of palette was loaded.",
		/* 104 */ "Too many files FPG opened at the same time.",
		/* 105 */ "The file was not loaded, archive not found.",
		/* 106 */ "A not valid FPG file was loaded.",
		/* 107 */ "Not valid number of scroll (must be between 0 and 9).",
		/* 108 */ "Not valid number of region (out of rank).",
		/* 109 */ "Not valid code of file.",
		/* 110 */ "Not valid code of graphic.",
		/* 111 */ "A file FPG was used before load it.",
		/* 112 */ "A code of graphic is needed for the scroll.",
		/* 113 */ "Too many letter font have been loaded.",
		/* 114 */ "The font can't be loaded, archive not found.",
		/* 115 */ "A not valid archive of font was loaded.",
		/* 116 */ "Not valid identifier code of letter fonts.",
		/* 117 */ "Not valid text's code of centrate.",
		/* 118 */ "Too many active texts in the program.",
		/* 119 */ "Not valid text identifier.",
		/* 120 */ "Region of screen defined incorrectly.",
		/* 121 */ "A nonexistent graphic was used.",
		/* 122 */ "A block out of memory was written.",
		/* 123 */ "An archive of writeness can't be opened.",
		/* 124 */ "The archive can't be written (see space in disk).",
		/* 125 */ "The block out of the memory was readen.",
		/* 126 */ "The readness archive can't be opened.",
		/* 127 */ "The archive can't be readen.",
		/* 128 */ "The sound effect can't be loaded.",
		/* 129 */ "The asked sound effect can't be played.",
		/* 130 */ "The asked animation can't be started.",
		/* 131 */ "Not valid number of mode 7 (must be between 0 and 9).",
		/* 132 */ "The code of graphic for mode 7 is needed.",
		/* 133 */ "Not valid checkpoint number.",
		/* 134 */ "Incorrect botton number (must be between 0 and 3).",
		/* 135 */ "Incorrect axis number (must be between 0 and 3).",
		/* 136 */ "Adress of palette board out of the memory.",
		/* 137 */ "Regions in graphics of m-7 can't be checked.",
		/* 138 */ "Incorrect code of graphic information.",
		/* 139 */ "Collisions in graphics of m-7 can't be checked.",
		/* 140 */ "Access out of rank.",
		/* 141 */ "A not valid process was accessed.",
		/* 142 */ "The process seems to be blocked, waiting FRAME.",
		/* 143 */ "The map can't be loaded, archive not found.",
		/* 144 */ "A not valid archive of map was loaded.",
		/* 145 */ "A division by zero was made.",
		/* 146 */ "The size of the region is incorrect.",
		/* 147 */ "Can't be loaded FLI/FLC, archive not found.",
		/* 148 */ "Incorrect value of timeout (must be between 1 and 60).",
		/* 149 */ "Incorrect number of players (must be between 2 and 8).",
		/* 150 */ "Only global data can be send.",
		/* 151 */ "Not valid size of square (must be between 1 and 256).",
		/* 152 */ "Not valid map of search (from 1x1 to 128x128).",
		/* 153 */ "Incorrect size of map (from 1x1 to 32768x32768).",
		/* 154 */ "Incorrect number of color (must be between 0 and 255).",
		/* 155 */ "The center is outside of the graphic's limits.",
		/* 156 */ "The object is outside of the map and will be eliminated.",
		/* 157 */ "Texture of the map not found.",
		/* 158 */ "The size of the texture is incorrect.",
		/* 159 */ "The world can't be loaded, archive not found.",
		/* 160 */ "The world can't be loaded, archive not valid.",
		/* 161 */ "Not valid flag number.",
		/* 162 */ "Not valid dispositive (only 1-IPX,2-SERIAL,3-MODEM).",
		/* 163 */ "Not valid size of box (only from 1 to 199).",
		/* 164 */ "The string of destination text is not valid.",
		/* 165 */ "A wrong cursor has been accessed.",
		/* 166 */ "The mode of access to the archive is not valid.",
		/* 167 */ "The module can't be loaded.",
		/* 168 */ "Too many ignored errors.",
		/* 169 */ "Too many open archives.",
		/* 170 */ "Identifier of archive (handle) not valid.",
		/* 171 */ "Value out of rank.",
		/* 172 */ "Too many graphic objects visualizated.",
		/* 173 */ "Type of graphic object unknown.",
		/* 174 */ "Percentage of ink out of rank (0..15).",
		/* 175 */ "Number of graphic object not valid.",
		/* 176 */ "Variable error of vpe: Texture of map [a] not found in the file [b]",
		/* 177 */ "Texture of map",
		/* 178 */ "Doesn't found in file",
		/* 179 */ "Too many petitions of dynamic memory has been made.",
		/* 180 */ "The cursor doesn't relate with any of the reserved blocks.",
		/* 181 */ "No blocks of less than one position can be reserved.",
		/* 182 */ "A block out of memory was (des)encript.",
		/* 183 */ "Can't be loaded another palette when the current one is forced.",
		/* 184 */ "",
		/* 185 */ "",
		/* 186 */ "",
		/* 187 */ "",
		/* 188 */ "",
		/* 189 */ "",
		/* 190 */ "",
		/* 191 */ "",
		/* 192 */ "",
		/* 193 */ "",
		/* 194 */ "",
		/* 195 */ "",
		/* 196 */ "",
		/* 197 */ "",
		/* 198 */ "",
		/* 199 */ "",
		/* 200 */ "Archive with corrupted data, can't be loaded.",

		/* 4 - CATAL�N */

		/* 100 */ "No hi ha mem�ria suficient per a executar el programa.",
		/* 101 */ "Crida a key() amb un codi de tecla inexistent.",
		/* 102 */ "No es va poder carregar la paleta, arxiu no trobat.",
		/* 103 */ "Es va intentar carregar un arxiu de paleta inv�lid.",
		/* 104 */ "Massa arxius FPG oberts al mateix temps.",
		/* 105 */ "No es va poder carregar l' arxiu, arxiu no trobat.",
		/* 106 */ "Es va intentar carregar un arxiu FPG no v�lid.",
		/* 107 */ "N�mero d' scroll inv�lid (ha d' estar entre 0 y 9).",
		/* 108 */ "N�mero de regi� inv�lid (fora de rang).",
		/* 109 */ "Codi d' arxiu inv�lido.",
		/* 110 */ "Codi de gr�fic inv�lid.",
		/* 111 */ "Es va intentar usar un arxiu FPG abans de carregar-lo.",
		/* 112 */ "Es necesita un codi de gr�fic per a l' scroll.",
		/* 113 */ "S' han carregat massa fonts de lletres.",
		/* 114 */ "No es va poder carregar la font, arxiu no trobat.",
		/* 115 */ "Es va intentar carregar un arxiu de font no v�lid.",
		/* 116 */ "Codi identificador de font de lletres inv�lid.",
		/* 117 */ "Codi de centrat de text inv�lid.",
		/* 118 */ "Hi ha massa textos actius al programa.",
		/* 119 */ "Indentificador de text no v�lid.",
		/* 120 */ "Regi� de pantalla definida incorrectament.",
		/* 121 */ "Es va intentar utilitzar un gr�fic que no existeix.",
		/* 122 */ "Es va intentar escriure un bloc fora de la mem�ria.",
		/* 123 */ "No es va poder obrir l' arxiu per a escritura.",
		/* 124 */ "No es va poder escriure l' arxiu (veure espai al disc).",
		/* 125 */ "Es va intentar llegir un bloc fora de la mem�ria.",
		/* 126 */ "No es va poder obrir l' arxiu per a lectura.",
		/* 127 */ "No es va poder llegir l' arxiu.",
		/* 128 */ "No es va poder carregar l' efecte de so.",
		/* 129 */ "No es va poder reproduir l' efecte de so sol�licitat.",
		/* 130 */ "No es va poder iniciar l' animaci� sol�licitada.",
		/* 131 */ "N�mero de mode 7 inv�lid (ha d' estar entre 0 y 9).",
		/* 132 */ "Es necessita un codi de gr�fic per al mode 7.",
		/* 133 */ "N�mero de punt de control inv�lid.",
		/* 134 */ "N�mero de bot� incorrecte (ha d' estar entre 0 y 3).",
		/* 135 */ "N�mero d' eix incorrecte (ha d' estar entre 0 y 3).",
		/* 136 */ "Direcci� de la tabla de paleta fora de la mem�ria.",
		/* 137 */ "No es poden comprovar regions en gr�fics de mode 7.",
		/* 138 */ "Codi d' informaci� gr�fica incorrecte.",
		/* 139 */ "No es poden comprovar col�lisions en gr�fics de mode 7.",
		/* 140 */ "Acc�s fora de rang.",
		/* 141 */ "Es va intentar accedir a un proc�s inv�lid.",
		/* 142 */ "El proc�s sembla bloquejat, esperant FRAME.",
		/* 143 */ "No es va poder carregar el mapa, arxiu no trobat.",
		/* 144 */ "Es va intentar carregar un arxiu de mapa inv�lid.",
		/* 145 */ "S' ha intentar fer una divisi� entre zero.",
		/* 146 */ "El tamany de la regi� es incorrecte.",
		/* 147 */ "No es va poder carregar FLI/FLC, arxiu no trobat.",
		/* 148 */ "Valor de timeout incorrecte (ha de ser entre 1 y 60).",
		/* 149 */ "Nombre de jugadors incorrecte (ha de ser entre 2 y 8).",
		/* 150 */ "Nom�s es poden enviar dades globals.",
		/* 151 */ "Tamany de casella inv�lid (ha de ser entre 1 y 256).",
		/* 152 */ "Map de b�squeda no v�lid (des d' 1x1 fins a 128x128).",
		/* 153 */ "Tamany de mapa incorrecte (des d' 1x1 fins a 32768x32768).",
		/* 154 */ "N�mero de color incorrecte (ha de ser ser des de 0 fins a 255).",
		/* 155 */ "El centre es troba fora dels l�mits del gr�fic.",
		/* 156 */ "L' objecte es troba fora del mapa i ser� eliminat.",
		/* 157 */ "Textura del mapa no trobada.",
		/* 158 */ "El tamany de la textura �s incorrecte.",
		/* 159 */ "No es va poder carregar el m�n, arxiu no trobat.",
		/* 160 */ "No es va poder carregar el m�n, arxiu no v�lid.",
		/* 161 */ "El n�mero de bandera no �s v�lid.",
		/* 162 */ "Dispositiu inv�lid (nom�s 1-IPX,2-SERIAL,3-MODEM).",
		/* 163 */ "Tamany de paquet inv�lid (nom�s des d' 1 fins a 199).",
		/* 164 */ "La cadena de text dest� no �s v�lida.",
		/* 165 */ "Es va intentar accedir a un punter nul.",
		/* 166 */ "El mode d' acc�s a l' arxiu no �s v�lid.",
		/* 167 */ "No es va poder carregar el m�dul.",
		/* 168 */ "Massa errors ignorats.",
		/* 169 */ "Massa arxius oberts.",
		/* 170 */ "Identificador d' arxiu (handle) no v�lid.",
		/* 171 */ "Valor fora de rang.",
		/* 172 */ "Massa objectes gr�fics visualitzats.",
		/* 173 */ "Tipus d' objecte gr�fic no conegut.",
		/* 174 */ "Percentatge de tinta fora de rang (0..15).",
		/* 175 */ "N�mero d' objecte gr�fic no v�lid.",
		/* 176 */ "Error variable de mode 8: Textura de mapa [a] no trobada en arxiu [b].",
		/* 177 */ "Textura de map.",
		/* 178 */ "no trobada en arxiu.",
		/* 179 */ "Es van realitzar massa peticions de mem�ria din�mica.",
		/* 180 */ "El punter no es corresp�n amb ning� dels blocs reservats.",
		/* 181 */ "No es poden reservar blocs de menys d' una posici�.",
		/* 182 */ "Es va intentar (des)encriptar un bloc fora de la mem�ria.",
		/* 183 */ "No es pot carregar altra paleta quan est� for�ada l' actual.",
		/* 184 */ "",
		/* 185 */ "",
		/* 186 */ "",
		/* 187 */ "",
		/* 188 */ "",
		/* 189 */ "",
		/* 190 */ "",
		/* 191 */ "",
		/* 192 */ "",
		/* 193 */ "",
		/* 194 */ "",
		/* 195 */ "",
		/* 196 */ "",
		/* 197 */ "",
		/* 198 */ "",
		/* 199 */ "",
		/* 200 */ "Arxiu amb dades corrompudes, no es va poder carregar.",

		/* 5 - EUSKERA */

		/* 100 */ "Ez dago behar beste memoria programa egikaritzeko.",
		/* 101 */ "Key() deitu duzu existitzen ez den tekla kode batekin.",
		/* 102 */ "Ezin da paleta kargatu, ez bait da fitxategia aurkitu.",
		/* 103 */ "Okerreko paleta fitxategi bat kargatzen saiatu zara.",
		/* 104 */ "FPG fitxategi gehiegi aldi berean kargaturik.",
		/* 105 */ "Ezin da fitxategia kargatu, ez bait da aurkitzen.",
		/* 106 */ "Okerreko FPG fitxategi bat kargatzen saiatu zara.",
		/* 107 */ "Okerreko scroll zenbakia (0 eta 9 artean egon behar du).",
		/* 108 */ "Okerreko erregio zenbakia (Barrutiaren kanpo dago).",
		/* 109 */ "Okerreko fitxategi zenbakia.",
		/* 110 */ "Okerreko irudi zenbakia.",
		/* 111 */ "FPG fitxategi bat erabiltzen saiatu zara kargatu baino lehen.",
		/* 112 */ "Irudi kode bat behar da scroll-arentzat.",
		/* 113 */ "Letra-tipo gehiegi kargatu dira.",
		/* 114 */ "Ezin da letra-tipoa kargatu, ez bait da aurkitzen.",
		/* 115 */ "Okerreko letra-tipoa kargatzen saiatu zara.",
		/* 116 */ "Okerreko letra-tipo kode identifidorea.",
		/* 117 */ "Okerreko testua zentratzeko kodea.",
		/* 118 */ "Testu gehiegi aktibaturik programan.",
		/* 119 */ "Okerreko testu identifikadorea.",
		/* 120 */ "Pantaila erregio txarto mugatua.",
		/* 121 */ "Existitzen ez den irudi bat erabiltzen saiatu zara.",
		/* 122 */ "Multzo bat memoriaz kanpo idazten saiatu zara.",
		/* 123 */ "Ezin izan da fitxategia idazteko ireki.",
		/* 124 */ "Ezin izan da fitxategia idatzi (begiratu diskoan dagoen lekuari).",
		/* 125 */ "Multzo bat memoriaz kanpotik irakurtzen saiatu zara.",
		/* 126 */ "Ezin izan da fitxategia irakurtzeko ireki.",
		/* 127 */ "Ezin izan da fitxategia irakurri.",
		/* 128 */ "Ezin izan da soinu efektua kargatu.",
		/* 129 */ "Ezin izan da aukeratutako soinu efektua jo.",
		/* 130 */ "Ezin izan da aukeratutako animazioa iniziatu.",
		/* 131 */ "Okerreko 7 modu zenbakia (0 eta 9 artean egon behar du).",
		/* 132 */ "Irudi kode bat behar da 7 moduarentzat.",
		/* 133 */ "Okerreko kotroleko puntua.",
		/* 134 */ "Okerreko botoi zenbakia (0 eta 3 artean egon behar du).",
		/* 135 */ "Okerreko ardatz zenbakia (0 eta 3 artean egon behar du).",
		/* 136 */ "Paletaren taularen helbidea memoriaz kanpo dago.",
		/* 137 */ "7 moduan ezin da irudi erregiorik egiaztatu.",
		/* 138 */ "Okerreko irudi informazio kodea.",
		/* 139 */ "7 moduan ezin da irudien arteko talkarik egiaztatu.",
		/* 140 */ "Barrutiaren kanpoko atzipena.",
		/* 141 */ "Okerreko prozesu bat atziten saiatu zara.",
		/* 142 */ "Prozesuak blokeaturik dirudi, FRAME-aren zai.",
		/* 143 */ "Ezin izan da mapa kargatu, ez bait da aurkitzen.",
		/* 144 */ "Okerreko mapa fitxategi bat kargatzen saiatu zara.",
		/* 145 */ "Zeroz zatitzen saiatu zara.",
		/* 146 */ "Okerreko erregio neurria.",
		/* 147 */ "Ezin da FLI/FLC fitxategia kargatu, ez bait da aurkitzen.",
		/* 148 */ "Okerreko timeout zenbakia (1 eta 60 artean egon behar du).",
		/* 149 */ "Okerreko jokalari zenbaia (2 eta 8 artean egon behar du).",
		/* 150 */ "Datu orrokorrak bakarrik bidali daitezke.",
		/* 151 */ "Okerreko lauki neurria (1 eta 256 artean egon behar du).",
		/* 152 */ "Okerreko bilaketa mapa zenbakia (1x1 eta 128x128 artean egon behar du).",
		/* 153 */ "Okerreko mapa neurria (1x1 eta 32768x32768 artean egon behar du).",
		/* 154 */ "Okerreko kolore zenbakia (0 eta 255 artean egon behar du).",
		/* 155 */ "Erdia iruditik kanpo dago.",
		/* 156 */ "Objektua mapatik kanpo dago eta ezabaturik izango da.",
		/* 157 */ "Ezin da aurkitu maparen egitura.",
		/* 158 */ "Egituraren neurria okerrekoa da.",
		/* 159 */ "Ezin izan da mundua kargatu, ez bait da aurkitzen.",
		/* 160 */ "Ezin izan da mundua kargatu, okerreko fitxategia da.",
		/* 161 */ "Okerreko bandera zenbakia.",
		/* 162 */ "Okerreko dispositiboa (1-IPX,2-SERIAL edo 3-MODEM soilik).",
		/* 163 */ "Okerreko pakete neurria (1 eta 199 artean egon behar du).",
		/* 164 */ "Okerreko helburuko testua.",
		/* 165 */ "Balio gabeko erakusle bat atziten saiatu zara.",
		/* 166 */ "Okerreko fitxategi atzipen modua.",
		/* 167 */ "Ezin izan da modulua kargatu.",
		/* 168 */ "Alde batera utzitako akatz gehiegi.",
		/* 169 */ "Irekitako fitxategi gehiegi.",
		/* 170 */ "Okerreko fitxategi identifikadorea (handle).",
		/* 171 */ "Barrutiaren kanpoko datua.",
		/* 172 */ "Erakutsitako irudi objektu gehiegi.",
		/* 173 */ "Irudi objektu mota ezesaguna.",
		/* 174 */ "Barrutiaren kanpoko tinta porzentaia (0..15).",
		/* 175 */ "Okerreko irudi objektu zenbakia.",
		/* 176 */ "Vpe akatz aldakorra: ezin da [a] maparen egitura [b] fitxategian aurkitu.",
		/* 177 */ "Maparen egitura.",
		/* 178 */ "ezin da fitxategian aurkitu.",
		/* 179 */ "Memoria dinamiko gehiegi eskatu da.",
		/* 180 */ "Erakuslea ez dator bat erreserbaturiko multzo bakar batekin.",
		/* 181 */ "Ezin da posizio bat baino gutxiko multzorik erreserbatu.",
		/* 182 */ "Memoriarik gabeko multzo bat (des)enkriptatzen saiatu zara.",
		/* 183 */ "Ezin da beste paleta bat kargatu oraingokoa derrigorturik dagoenean.",
		/* 184 */ "",
		/* 185 */ "",
		/* 186 */ "",
		/* 187 */ "",
		/* 188 */ "",
		/* 189 */ "",
		/* 190 */ "",
		/* 191 */ "",
		/* 192 */ "",
		/* 193 */ "",
		/* 194 */ "",
		/* 195 */ "",
		/* 196 */ "",
		/* 197 */ "",
		/* 198 */ "",
		/* 199 */ "",
		/* 200 */ "Hondaturiko fitxategia, ezin da kargatu."

	};

	return e[idioma][num];

}


char* translate_critical_error(int num)
{
	static char *e[NUM_LANGUAGES][10] = {

		/* 0 - ESPA�OL */

		/* 0	*/	"",
		/* 1	*/	"Error leyendo el c�digo del programa",
		/* 2	*/	"Error en el formato de c�digo",
		/* 3	*/	"Redefinicion del tipo de proceso",
		/* 4	*/	"No se pudo reservar memoria para la pila",
		/* 5	*/	"Librer�a no encontrada: %s",
		/* 6	*/	"%s no es una librer�a v�lida de eDIV",
		/* 7	*/	"No se pudo inicializar SDL",
		/* 8	*/	"Demasiados procesos en ejecuci�n",
		/* 9	*/	"Se requiere SDL versi�n %d.%d.%d\nVersi�n detectada en el sistema: %d.%d.%d",

		/* 1 - ITALIANO */

		/* 0	*/	"",
		/* 1	*/	"Errore leggendo il codice del programma",
		/* 2	*/	"Errore nel formato di codice",
		/* 3	*/	"Ridefinizione del tipo di processo",
		/* 4	*/	"Non si � potuto riservare memoria per la pila",
		/* 5	*/	"Libreria non trovata: %s",
		/* 6	*/	"%s non � una libreria valida di eDIV",
		/* 7	*/	"Non � stato possibile inizializzare SDL",
		/* 8	*/	"Troppi processi in esecuzione",
		/* 9	*/	"E' richiesta SDL %d.%d.%d\nVersione rilevata nel sistema: %d.%d.%d",

		/* 2 - PORTUGU�S (FIXMI: traducir) */

		/* 0	*/	"",
		/* 1	*/	"Error leyendo el c�digo del programa",
		/* 2	*/	"Error en el formato de c�digo",
		/* 3	*/	"Redefinicion del tipo de proceso",
		/* 4	*/	"No se pudo reservar memoria para la pila",
		/* 5	*/	"Librer�a no encontrada: %s",
		/* 6	*/	"%s no es una librer�a v�lida de eDIV",
		/* 7	*/	"No se pudo inicializar SDL",
		/* 8	*/	"Demasiados procesos en ejecuci�n",
		/* 9	*/	"Se requiere SDL versi�n %d.%d.%d\nVersi�n detectada en el sistema: %d.%d.%d", // TODO

		/* 3 - INGL�S */

		/* 0	*/	"",
		/* 1	*/	"Error reading program bytecode",
		/* 2	*/	"Erroneous bytecode format",
		/* 3	*/	"Process type redefinition",
		/* 4	*/	"Can't allocate stack memory",
		/* 5	*/	"Library not found: %s",
		/* 6	*/	"%s is not a valid eDIV library",
		/* 7	*/	"Cannot initialize SDL",
		/* 8	*/	"Too many processes in execution",
		/* 9	*/	"This program requires SDL version %d.%d.%d\nSDL version detected in this system: %d.%d.%d",

		/* 4 - CATAL�N */

		/* 0	*/	"",
		/* 1	*/	"Error llegint el codi del programa",
		/* 2	*/	"Error en el format de codi",
		/* 3	*/	"Redefinici� del tipus de proc�s",
		/* 4	*/	"No es va poder reservar mem�ria per a la pila",
		/* 5	*/	"Llibreria no trobada: %s",
		/* 6	*/	"%s no �s una llibreria v�lida d' eDIV",
		/* 7	*/	"No se pudo inicializar SDL",	// TODO
		/* 8	*/	"Demasiados procesos en ejecuci�n", // TODO
		/* 9	*/	"Se requiere SDL versi�n %d.%d.%d\nVersi�n detectada en el sistema: %d.%d.%d", // TODO

		/* 5 - EUSKERA */

		/* 0	*/	"",
		/* 1	*/	"Akatz bat sortu da programaren kodea irakurtzean",
		/* 2	*/	"Akatz bat dago kodearen formatuan",
		/* 3	*/	"Prozesu motaren berdefinizioa",
		/* 4	*/	"Ezin izan da memoriarik erreserbatu pilarentzat",
		/* 5	*/	"Ezin da liburutegia aurkitu: %s",
		/* 6	*/	"%s ez da eDIV-en liburutegi zuzen bat",
		/* 7	*/	"No se pudo inicializar SDL",	// TODO
		/* 8	*/	"Demasiados procesos en ejecuci�n",	// TODO
		/* 9	*/	"Se requiere SDL versi�n %d.%d.%d\nVersi�n detectada en el sistema: %d.%d.%d" // TODO
	};

	return e[idioma][num];
}


char* translate_dll_error(int num)
{
	static char *e[NUM_LANGUAGES][10] = {

		/* 0 - ESPA�OL */

		/* 1	*/ "Sobrepasado buffer de nombres de objeto",
		/* 2	*/ "Objeto '%s': El nombre no es nuevo",
		/* 3	*/ "Demasiados objetos declarados",
		/* 4	*/ "Funcion '%s': El nombre no es nuevo",
		/* 5	*/ "Error declarando objeto '%s'",
		/* 6	*/ "Objeto '%s': Declaraci�n ilegal dentro de struct",
		/* 7	*/ "Objeto '%s': Declaraci�n de un miembro fuera de struct",
		/* 8	*/ "Tama�o ilegal del string '%s'",
		/* 9	*/ "EndStruct sin Struct",
		/* 10	*/ "Una estructura debe contener al menos un elemento",

		/* 1 - ITALIANO */

		/* 1	*/ "Sorpassato buffer dei nomi oggetto",
		/* 2	*/ "Oggetto '%s': Il nome non � nuovo",
		/* 3	*/ "Troppi oggetti dichiarati",
		/* 4	*/ "Funzione '%s': Il nome non � nuovo",
		/* 5	*/ "Errore dichiarando oggetto '%s'",
		/* 6	*/ "Oggetto '%s': Dichiarazione illegale dentro struct",
		/* 7	*/ "Oggetto '%s': Dichiarazione di un membro fuori struct",
		/* 8	*/ "Grandezza illegale di string '%s'",
		/* 9	*/ "EndStruct senza Struct",
		/* 10	*/ "Una struttura deve contenere almeno un elemento",

		/* 2 - PORTUGU�S */

		/* 1	*/ "Buffer de nomes de objecto ultrapassado",
		/* 2	*/ "Objecto '%s': O nome n�o � novo",
		/* 3	*/ "Demasiados objectos declarados",
		/* 4	*/ "Fun��o '%s': O nome n�o � novo",
		/* 5	*/ "Erro declarando objecto '%s'",
		/* 6	*/ "Objecto '%s': Declara��o ilegal dentro de struct",
		/* 7	*/ "Objecto '%s': Declara��o de um membro fora de struct",
		/* 8	*/ "Tamanho ilegal da string '%s'",
		/* 9	*/ "EndStruct sem Struct",
		/* 10	*/ "Uma estructura deve conter ao menos um elemento",

		/* 3 - INGL�S */

		/* 1	*/ "Object name buffer out of bounds",
		/* 2	*/ "Object '%s': Name already exists",
		/* 3	*/ "Too many objects declared",
		/* 4	*/ "Function '%s': Name already exists",
		/* 5	*/ "Error declaring object '%s'",
		/* 6	*/ "Object '%s': Illegal declaration inside a struct",
		/* 7	*/ "Object '%s': Member declaration outside a struct",
		/* 8	*/ "Illegal size for string '%s'",
		/* 9	*/ "EndStruct without Struct",
		/* 10	*/ "A struct must contain at least one item",

		/* 4 - CATAL�N */

		/* 1	*/ "Sobrepassat buffer de noms d' objecte",
		/* 2	*/ "Objecte '%s': El nom no �s nou",
		/* 3	*/ "Massa objectes declarats",
		/* 4	*/ "Funci� '%s': El nom no �s nou",
		/* 5	*/ "Error declarant objecte '%s'",
		/* 6	*/ "Objecte '%s': Declaraci� il�legal dins d' struct",
		/* 7	*/ "Objecte '%s': Declaraci� d' un membre fora d' struct",
		/* 8	*/ "Tamany il�legal de l' string '%s'",
		/* 9	*/ "EndStruct sense Struct",
		/* 10	*/ "Una estructura ha de contenir almenys un element",

		/* 5 - EUSKERA */

		/* 1	*/ "Objektu izenen buffer-aren kapazitatea gainditurik",
		/* 2	*/ "'%s'objektua: Izena ez da berria",
		/* 3	*/ "Gehiegizko deklaraturiko objektuak",
		/* 4	*/ "'%s' funtzioa: izena ez da berria",
		/* 5	*/ "Akatz bat sortu da '%s' objektua deklaratzean",
		/* 6	*/ "'%s'objektua: Debekaturiko deklarazioa struct barruan",
		/* 7	*/ "'%s'objektua: Atal baten deklarazioan struct kanpo",
		/* 8	*/ "'%s' String-eko okerreko neurria",
		/* 9	*/ "Struct gabeko EndStruct",
		/* 10	*/ "Estruktura batek atal bat gutxienez eduki behar du"

	};
	return e[idioma][num];
}

