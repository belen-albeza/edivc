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
 * 2 - PORTUGU�S (pt)
 * Autor: tareko
 */


/*
 * Errores de compilaci�n
 */

#if TRANSLATE == TRANSLATE_ERROR

/* 0	*/	"",
/* 1    */  "Esperava-se '*/'",
/* 2	*/	"Capacidade do vector de nomes excedida",
/* 3    */  "Esperava-se '\"'",
/* 4    */  "S�mbolo desconhecido",
/* 5    */  "Caracter desconhecido",
/* 6	*/	"Capacidade da tabela de objectos excedida",
/* 7    */  "Esperando '='",
/* 8    */  "Esperando uma op��o de compila��o",
/* 9    */  "Esperando ';'",
/* 10   */  "Esperando um operando",
/* 11   */  "Express�o incorrecta",
/* 12   */  "Asigna��o a cadeia incorrecta",
/* 13   */  "Asigna��o incorrecta",
/* 14   */  "N�o se pode calcular o offset do dado",
/* 15   */  "N�o se pode calcular o offset",
/* 16   */  "N�o se pode realizar o incremento",
/* 17   */  "Local n�o se pode aceder",
/* 18   */  "Esperando ')'",
/* 19   */  "Esperando ']'",
/* 20   */  "N�o � um tipo de processo",
/* 21   */  "Esperando o nome de um processo",
/* 22   */  "Esperando '('",
/* 23   */  "Esperando um nome",
/* 24   */  "N�o se pode calcular o tamanho",
/* 25   */  "Express�o incorrecta",
/* 26   */  "N�o se pode receber uma estructura como parametro",
/* 27   */  "Esperando o nome da estructura",
/* 28   */  "Declara��o incorrecta de ponteiro a uma estructura",
/* 29   */  "Esperando o nome da cadeia",
/* 30   */  "O nome n�o � novo",
/* 31   */  "Cadeia de texto de longitude negativa",
/* 32   */  "Cadeia de texto demasiado larga",
/* 33   */  "N�o se pode especificar uma tabela como parametro",
/* 34   */  "Nome desconhecido: %s",
/* 35   */  "Esperava-se uma virgula",
/* 36   */  "Esperava-se outro parametro",
/* 37   */  "N�o se pode aceder a dados PRIVATE externos",
/* 38   */  "N�mero de parametros incorrecto",
/* 39   */  "Esperando um elemento da estructura",
/* 40   */  "Tabela de longitude negativa",
/* 41   */  "A longitude n�o coincide con a declara��o anterior",
/* 42   */  "N�o se pode inicializar un parametro",
/* 43   */  "Estructura de longitude negativa",
/* 44	*/	"Esperando PROGRAM",
/* 45   */  "Esperando o nome do programa",
/* 46   */  "Esperava-se um literal",
/* 47   */  "Uma estructura deve conter, pelo menos, um elemento",
/* 48   */  "Demasiados valores para a tabela",
/* 49	*/	"Literal demasiado largo",
/* 50   */  "Valor BYTE fora de alcance (0...255)",
/* 51   */  "Valor WORD fora de alcance (0...65535)",
/* 52   */  "N�o se pode duplicar 0 o menos veces",
/* 53   */  "Inicializa��o incorrecta",
/* 54   */  "Esperava-se uma express�o constante",
/* 55   */  "Demasiados valores para a estructura",
/* 56	*/	"Esperando BEGIN",
/* 57	*/	"Esperando END",
/* 58	*/	"Esperando UNTIL",
/* 59   */  "Esperando uma variable", 
/* 60	*/	"Esperando TO",
/* 61   */  "Senten�a FROM incorrecta", 
/* 62   */  "O valor STEP n�o � v�lido",
/* 63   */  "Esperando CASE, DEFAULT ou END",
/* 64	*/	"Esperando ':'",
/* 65   */  "BREAK n�o aparece dentro de um ciclo",
/* 66   */  "CONTINUE n�o aparece dentro de um ciclo",
/* 67   */  "Esperava-se uma senten�a",
/* 68   */  "Express�o sem sentido",
/* 69   */  "Asigna��o dentro de uma condi��o",
/* 70   */  "Esperando o nome do processo ou fun��o",
/* 71   */  "Esperando PROCESS ou FUNCTION",
/* 72   */  "Parametro n�o v�lido",
/* 73   */  "ELSEIF n�o aparece dentro de um bloco IF" /* SIN COMA */


/*
 * Advertencias
 */

#elif TRANSLATE == TRANSLATE_WARNING

/* 0	*/	"",
/* 1    */	"SETUP_PROGRAM: Caracteristica amb�gua",
/* 2    */  "IMPORT: Sintaxe antiga, ignorado" /* SIN COMA */


/*
 * Errores de DLL
 */

#elif TRANSLATE == TRANSLATE_DLL_ERROR

/* 1	*/ "Buffer de nomes de objecto ultrapassado",
/* 2	*/ "Objecto '%s': O nome n�o � novo",
/* 3	*/ "Demasiados objectos declarados",
/* 4	*/ "Fun��o '%s': O nome n�o � novo",
/* 5	*/ "Erro declarando objecto '%s'",
/* 6	*/ "Objecto '%s': Declara��o ilegal dentro de struct",
/* 7	*/ "Objecto '%s': Declara��o de um membro fora de struct",
/* 8	*/ "Tamanho ilegal da string '%s'",
/* 9	*/ "EndStruct sem Struct",
/* 10	*/ "Uma estructura deve conter ao menos um elemento" /* SIN COMA */


/*
 * Errores de ltlex.def
 */

#elif TRANSLATE == TRANSLATE_LTLEX_ERROR

/* 0	*/ "",
/* 1	*/ "Arquivo ltlex.def n�o encontrado",
/* 2	*/ "Esperava-se um valor hexadecimal (&00..&FF)",
/* 3	*/ "Demasiados s�mbolos definidos",
/* 4	*/ "S�mbolo inv�lido" /* SIN COMA */


/*
 * Mensajes del compilador
 */

#elif TRANSLATE == TRANSLATE_COMPILER

/* 0	*/ " **** Compilador eDIV " VERSION " ****\nCopyleft (c) 2000-2003 Sion, Ltd.\nhttp://ediv.divsite.net\n",
/* 1    */ "ATEN��O: Esta vers�o de eDIV est� inacabada.\nPor favor informe-nos de qualquer bug a: ediv@divsite.net\n",
/* 2    */ "Ajuda de op��es de comando:\n\n",
/* 3    */ "%s [op��es] arquivo.prg [executavel]\n\n",
/* 4    */ "Lista de op��es:\n",
/* 5    */ "    -h, --help      Mostra esta ajuda e sai\n",
/* 6    */ "    -d, --debug     Gera informa��o adicional de depura��o\n",
/* 7    */ "    -l, --list      Guarda o listado EML como <programa.eml>\n",
/* 8    */ "    -t, --table     Guarda a tabela de objectos como <programa.tab>\n",
/* 9    */ "    -c, --check     N�o gera um executavel (para comprovar sintaxe, etc.)\n",
/* 10   */ "    -s, --system    Sistema Operativo de destino (por defeito %s)\n",
/* 11   */ "    -v, --version   Mostra vers�o e sai\n\n",
/* 12   */ "Parametro --system: deve indicar um sistema de destino\nConsulte a documenta��o para obter ajuda\n",
/* 13   */ "Parametro err�neo: %s\nUse a op��o -h para ver a ajuda\n",
/* 14   */ "Parametro -s: deve indicar um sistema de destino\nConsulte a documenta��o para obter ajuda\n",
/* 15   */ "Parametro err�neo: -%c\nUse a op��o -h para ver a ajuda\n",
/* 16   */ "N�o foi especificado um arquivo\nUse a op��o -h para ver a ajuda\n",
/* 17   */ "edivc: Erro ao abrir arquivo %s.\n",
/* 18	*/ "edivc: Compilando: %s\n",
/* 19   */ "edivc: ERROR: N�o se enconntra %s\n",
/* 20	*/ "edivc: ERROR: Formato incorrecto de %s\n",
/* 21   */ "edivc: Interrompido (%d advertencias)\n",
/* 22   */ "edivc: Finalizado con exito (%d advertencias)\n",
/* 23   */ "edivc: Saida com erros\n",
/* 24   */ "edivc: ERROR: Mem�ria insuficiente\n",
/* 25	*/ "%s:%d:%d: ERROR %d: ",
/* 26   */ "%s:%d: Advertencia: ",
/* 27	*/ "Precompilando...\n",
/* 28	*/ "Compilando...\n",
/* 29	*/ "Erro ao criar arquivo de intercambio\n",
/* 30	*/ "Generando listados...\n",
/* 31	*/ "Guardando executavel...\n",
/* 32	*/ "Guardando informa��o de depura��o...\n",
/* 33	*/ "Erro ao escrever executavel\n",
/* 34	*/ "Compila��o finalizada.\n",
/* 35	*/ "%s: ERRO: ",
/* 36	*/ "Erro ao criar arquivo %s\n",
/* 37	*/ "Listado de objectos de %s - eDIV vers�o " VERSION "\n\n",
/* 38	*/ "\tbloco(%u), anterior(%u)\n",
/* 39	*/ "C�digo EML de %s - eDIV vers�o " VERSION "\n",
/* 40	*/ "edivc: ERRO: %s\n\n",
/* 41	*/ "edivc: %s (linha %d) ERRO: %s\n\n",
/* 42	*/ "edivc: Interrompido - encontraram-se erros\n",
#ifdef _WIN32
/* 43	*/ "N�o se encontra nenhuma DLL\n",
/* 44	*/ "",
#else
/* 43	*/ "N�o se encontra nenhuma biblioteca\n",
/* 44	*/ "Directorio %s/ n�o foi encontrado\n",
#endif
/* 45	*/ "Erro ao carregar biblioteca %s\n",
#ifdef _WIN32
/* 46	*/ "N�o podo carregar %s\n",
/* 47	*/ "N�o se encontra ExportaFuncs em %s - DLL invalida\n",
#else
/* 46	*/ "N�o se pode carregar %s (%s)\n",
/* 47	*/ "N�o se encontra ExportaFuncs em %s - Biblioteca invalida (%s)\n",
#endif

/* FIXME: revisar/traducir esto */
/* 48	*/ "    -n, --news      Mostra a �ltima not�cia de eDivCentral.com e sai\n",
/* 49	*/ "Error: no se ha configurado un servidor de noticias en ediv.cfg\n",
/* 50	*/ "Error: el fichero recibido no es del tipo esperado\n" /* SIN COMA */


/*
 * Mensajes del stub
 */

#elif TRANSLATE == TRANSLATE_STUB

/* FIXME: traducir esto */
/* 0	*/	"ERROR %d: ",
/* 1	*/	"eDIV: Error en ejecuci�n",
/* 2	*/	"eDIV: Error cr�tico",
/* 3	*/	"Error en %s: ",
/* 4	*/	"eDIV: Error en librer�a din�mica" /* SIN COMA */


/*
 * Errores de tiempo de ejecuci�n del stub
 */

#elif TRANSLATE == TRANSLATE_RUNTIME_ERROR

/* FIXME: traducir esto */
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
/* 200 */ "Archivo con datos corruptos, no se pudo cargar." /* SIN COMA */


/*
 * Errores cr�ticos del stub
 */

#elif TRANSLATE == TRANSLATE_CRITICAL_ERROR

/* FIXME: traducir esto */
/* 0	*/	"",
/* 1	*/	"Error leyendo el c�digo del programa",
/* 2	*/	"Error en el formato de c�digo",
/* 3	*/	"Redefinicion del tipo de proceso",
/* 4	*/	"No se pudo reservar memoria para la pila",
/* 5	*/	"Librer�a no encontrada: %s",
/* 6	*/	"%s no es una librer�a v�lida de eDIV",
/* 7	*/	"No se pudo inicializar SDL",
/* 8	*/	"Demasiados procesos en ejecuci�n",
/* 9	*/	"Se requiere SDL versi�n %d.%d.%d\nVersi�n detectada en el sistema: %d.%d.%d" /* SIN COMA */


#endif

/* Fin de fichero */
