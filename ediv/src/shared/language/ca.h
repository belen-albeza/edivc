/*
 * eDiv Compiler
 * Copyleft (C) 2000-2003 Sion Ltd.
 * Copyleft (C) 2005 eDIV Team
 * http://ediv.divsite.net
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

/*
 * ARCHIVO DE IDIOMA DE EDIV
 * 4 - CATAL�N (ca)
 * Autora: Bel�n Albeza (BenKo)
 */


/*
 * Errores de compilaci�n
 */

#if TRANSLATE == TRANSLATE_ERROR

/* 0	*/ "",
/* 1	*/ "Ha arribat el final dins d' un comentari",
/* 2	*/ "Excedida la capacitat del vector de noms",
/* 3	*/ "Literal sense tancar",
/* 4	*/ "S�mbol no reconegut",
/* 5	*/ "Car�cter no reconegut",
/* 6	*/ "Excedida la capacitat de la tabla d' objectes",
/* 7	*/ "Esperant '='",
/* 8	*/ "Esperant una opci� de compilaci�",
/* 9	*/ "Esperant ';'",
/* 10	*/ "S' esperava un operand",
/* 11	*/ "Expresi� incorrecta",
/* 12	*/ "Asignaci� a cadena incorrecta",
/* 13	*/ "Asignaci� incorrecta",
/* 14	*/ "No es pot calcular l' offset de la dada",
/* 15	*/ "No es pot calcular l' offset",
/* 16	*/ "No es pot realitzar l' increment",
/* 17	*/ "Local no es pot accedir",
/* 18	*/ "Esperant ')'",
/* 19	*/ "Esperant ']'",
/* 20	*/ "No �s un tipus de proc�s",
/* 21	*/ "Esperant el nom del proc�s",
/* 22	*/ "Esperant '('",
/* 23	*/ "Esperant un nom",
/* 24	*/ "No es pot calcular el tamany",
/* 25	*/ "Expresi� incorrecta",
/* 26	*/ "No es pot rebre una estructura com a par�metre",
/* 27	*/ "Esperant el nom de la estructura",
/* 28	*/ "Declaraci� incorrecta de punter a una estructura",
/* 29	*/ "Esperant el nom de la cadena",
/* 30	*/ "El nom no �s nou",
/* 31	*/ "Cadena de text de longitud negativa",
/* 32	*/ "Cadena de text massa llarga",
/* 33	*/ "No es pot especificar una tabla com a par�metre",
/* 34	*/ "Nombre desconegut: %s",
/* 35	*/ "S' esperava una coma",
/* 36	*/ "S' esperaba altre par�metre",
/* 37	*/ "No es pot accedir a dades PRIVATE externes",
/* 38	*/ "Nombre de par�metres incorrecte",
/* 39	*/ "Esperant un element de la estructura",
/* 40	*/ "Tabla de longitud negativa",
/* 41	*/ "La longitud no coincideix amb la declaraci� anterior",
/* 42	*/ "No es pot inicialitzar un par�metre",
/* 43	*/ "Estructura de longitud negativa",
/* 44	*/ "Esperant PROGRAM",
/* 45	*/ "Esperant el nom del programa",
/* 46	*/ "S' esperava un literal",
/* 47	*/ "Una estructura ha de contenir, almenys, un element",
/* 48	*/ "Massa valors per a la tabla",
/* 49	*/ "Literal massa llarg",
/* 50	*/ "Valor BYTE fora del rang (0...255)",
/* 51	*/ "Valor WORD fora del rang (0...65535)",
/* 52	*/ "No es pot duplicar 0 o menys vegades",
/* 53	*/ "Inicialitzaci� incorrecta",
/* 54	*/ "S' esperava una expresi� constant",
/* 55	*/ "Massa valors per a la estructura",
/* 56	*/ "Esperant BEGIN",
/* 57	*/ "Esperant END",
/* 58	*/ "Esperant UNTIL",
/* 59	*/ "Esperant una variable",
/* 60	*/ "Esperant TO",
/* 61	*/ "Sent�ncia FROM incorrecta",
/* 62	*/ "El valor STEP no es v�lid",
/* 63	*/ "Esperant CASE, DEFAULT o END",
/* 64	*/ "Esperant ':'",
/* 65	*/ "BREAK no apareix dins d' un bucle",
/* 66	*/ "CONTINUE no apareix dins d' un bucle",
/* 67	*/ "S' esperava una sent�ncia",
/* 68	*/ "Expresi� sense sentit",
/* 69	*/ "Asignaci� dins d' una condici�",
/* 70	*/ "Esperant el nomb del proc�s o funci�",
/* 71	*/ "Esperant PROCESS o FUNCTION",
/* 72	*/ "Par�metre no v�lid",
/* 73	*/ "ELSEIF no apareix dins d' un bloc IF" /* SIN COMA */


/*
 * Advertencias
 */

#elif TRANSLATE == TRANSLATE_WARNING

/* 0	*/ "",
/* 1	*/ "SETUP_PROGRAM: Caracter�stica desfasada",
/* 2	*/ "IMPORT: Sintaxi antiga, s' ignora" /* SIN COMA */


/*
 * Errores de DLL
 */

#elif TRANSLATE == TRANSLATE_DLL_ERROR

/* 1	*/ "Sobrepassat buffer de noms d' objecte",
/* 2	*/ "Objecte '%s': El nom no �s nou",
/* 3	*/ "Massa objectes declarats",
/* 4	*/ "Funci� '%s': El nom no �s nou",
/* 5	*/ "Error declarant objecte '%s'",
/* 6	*/ "Objecte '%s': Declaraci� il�legal dins d' struct",
/* 7	*/ "Objecte '%s': Declaraci� d' un membre fora d' struct",
/* 8	*/ "Tamany il�legal de l' string '%s'",
/* 9	*/ "EndStruct sense Struct",
/* 10	*/ "Una estructura ha de contenir almenys un element" /* SIN COMA */


/*
 * Errores de ltlex.def
 */

#elif TRANSLATE == TRANSLATE_LTLEX_ERROR

/* 0	*/ "",
/* 1	*/ "Arxiu ltlex.def no trobat",
/* 2	*/ "S' esperava un valor hexadecimal (&00..&FF)",
/* 3	*/ "Massa s�mbols definits",
/* 4	*/ "S�mbol no v�lid" /* SIN COMA */


/*
 * Mensajes del compilador
 */

#elif TRANSLATE == TRANSLATE_COMPILER

/* 0	*/ " **** Compilador eDIV " VERSION " ****\n" COPYRIGHT "\n" WEBSITE "\n",
/* 1	*/ "ATENCI�: Aquesta versi� d' eDIV est� sense acabar.\nSi us plau, informi de qualsevol bug a: ediv@divsite.net\n",
/* 2	*/ "Ajuda d' opcions de comand:\n\n",
/* 3	*/ "%s [opcions] arxiu.prg [executable]\n\n",
/* 4	*/ "Llista d' opcions:\n",
/* 5	*/ "    -h, --help      Mostra aquesta ajuda i en sort\n",
/* 6	*/ "    -d, --debug     Genera informaci� adicional de depurat\n",
/* 7	*/ "    -l, --list      Guarda el llistat EML com a <programa.eml>\n",
/* 8	*/ "    -t, --table     Guarda la tabla d' objectes com a <programa.tab>\n",
/* 9	*/ "    -c, --check     No genera un executable (per comprovar sintaxi, etc.)\n",
/* 10	*/ "    -s, --system    Sistema Operatiu dest� (per defecte %s)\n",
/* 11	*/ "    -v, --version   Mostra versi� i en sort\n\n",
/* 12	*/ "Par�metre --system: ha d' indicar un sistema dest�\nConsulti la documentaci� per a obtenir ajuda\n",
/* 13	*/ "Par�metre erroni: %s\nUtilitze la opci� -h per a veure l' ajuda\n",
/* 14	*/ "Par�metre -s: ha d' indicar un sistema dest�\nConsulti la documentaci� per a obtenir ajuda\n",
/* 15	*/ "Par�metre erroni: -%c\nUtilitze la opci� -h per a veure l' ajuda\n",
/* 16	*/ "No s'ha especificat un arxiu\nUtilitze la opci� -h per a veure l' ajuda\n",
/* 17	*/ "edivc: Error obrint l' arxiu %s.\n",
/* 18	*/ "edivc: Compilant: %s\n",
/* 19	*/ "edivc: ERROR: No es troba %s\n",
/* 20	*/ "edivc: ERROR: Format incorrecte de %s\n",
/* 21	*/ "edivc: Interromput (%d advert�ncies)\n",
/* 22	*/ "edivc: Finalitzat amb �xit (%d advert�ncies)\n",
/* 23	*/ "edivc: Sortida amb errors\n",
/* 24	*/ "edivc: ERROR: Mem�ria insuficient\n",
/* 25	*/ "%s:%d:%d: ERROR %d: ",
/* 26	*/ "%s:%d: Advert�ncia: ",
/* 27	*/ "Precompilant...\n",
/* 28	*/ "Compilant...\n",
/* 29	*/ "Error creant arxiu d' intercanvi\n",
/* 30	*/ "Generant llistats...\n",
/* 31	*/ "Guardant executable...\n",
/* 32	*/ "Guardant informaci� de depurat...\n",
/* 33	*/ "Error escriguent executable\n",
/* 34	*/ "Compilaci� finalitzada.\n",
/* 35	*/ "%s: ERROR: ",
/* 36	*/ "Error creant arxiu %s\n",
/* 37	*/ "Llistado d' objectes de %s - eDIV versi� " VERSION "\n\n",
/* 38	*/ "\tbloque(%u), anterior(%u)\n",
/* 39	*/ "Codi EML de %s - eDIV versi� " VERSION "\n",
/* 40	*/ "edivc: ERROR: %s\n\n",
/* 41	*/ "edivc: %s (l�nia %d) ERROR: %s\n\n",
/* 42	*/ "edivc: Interromput - s' han trobat errors\n",
#ifdef _WIN32
/* 43	*/ "No es troba cap DLL\n",
/* 44	*/ "",
#else
/* 43	*/ "No es troba cap llibreria\n",
/* 44	*/ "Directori %s/ no trobat\n",
#endif
/* 45	*/ "Error cargant llibrer�a %s\n",
#ifdef _WIN32
/* 46	*/ "No es pot cargar %s\n",
/* 47	*/ "No es troba ExportaFuncs en %s - DLL no v�lida\n",
#else
/* 46	*/ "No es pot cargar %s (%s)\n",
/* 47	*/ "No es troba ExportaFuncs en %s - Llibreria no v�lida (%s)\n",
#endif
/* 48	*/ "    -n, --news Mostra les �ltimes not�cies d' eDIVCentral i en surt\n",
/* 49	*/ "Error: No s' ha configurat un servidor de not�cies en ediv.cfg\n",
/* 50	*/ "Error: l' arxiu rebut no �s del tipus esperat\n" /* SIN COMA */


/*
 * Mensajes del stub
 */

#elif TRANSLATE == TRANSLATE_STUB

/* FIXMI: traducir esto */
/* 0	*/	"ERROR %d: ",
/* 1	*/	"eDIV: Error en ejecuci�n",
/* 2	*/	"eDIV: Error cr�tico",
/* 3	*/	"Error en %s: ",
/* 4	*/	"eDIV: Error en librer�a din�mica" /* SIN COMA */


/*
 * Errores de tiempo de ejecuci�n del stub
 */

#elif TRANSLATE == TRANSLATE_RUNTIME_ERROR

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
/* 200 */ "Arxiu amb dades corrompudes, no es va poder carregar." /* SIN COMA */


/*
 * Errores cr�ticos del stub
 */

#elif TRANSLATE == TRANSLATE_CRITICAL_ERROR

/* 0	*/	"",
/* 1	*/	"Error llegint el codi del programa",
/* 2	*/	"Error en el format de codi",
/* 3	*/	"Redefinici� del tipus de proc�s",
/* 4	*/	"No es va poder reservar mem�ria per a la pila",
/* 5	*/	"Llibreria no trobada: %s",
/* 6	*/	"%s no �s una llibreria v�lida d' eDIV",
/* 7	*/	"No se pudo inicializar SDL",	// FIXME: traducir esto
/* 8	*/	"Demasiados procesos en ejecuci�n", // FIXME: traducir esto
/* 9	*/	"Se requiere SDL versi�n %d.%d.%d\nVersi�n detectada en el sistema: %d.%d.%d" /* SIN COMA */ // FIXME: traducir esto


#endif

/* Fin de fichero */
