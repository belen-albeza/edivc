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
 * 1 - ITALIANO (it)
 * Autor: Francesto Amato (CicTec)
 */


/*
 * Errores de compilaci�n
 */

#if TRANSLATE == TRANSLATE_ERROR

/* 0	*/	"",
/* 1	*/	"Si aspettava '*/'",
/* 2	*/	"Capacit� vettore nomi oltrepassata",
/* 3	*/	"Si aspettava '\"'",
/* 4	*/	"Simbolo non riconosciuto",
/* 5	*/	"Carattere non riconosciuto",
/* 6	*/	"Capacit� tabella oggetti oltrepassata",
/* 7	*/	"Aspettando '='",
/* 8	*/	"Aspettando un'opzione di compilazione",
/* 9	*/	"Aspettando ';'",
/* 10	*/	"Si aspettava un operando",
/* 11	*/	"Espressione incorretta",
/* 12	*/	"Assegnazione a catena incorretta",
/* 13	*/	"Assegnazione incorretta",
/* 14	*/	"Impossibile calcolare l'offset del dato",
/* 15	*/	"Impossibile calcolare l'offset",
/* 16	*/	"Non � possibile realizzare l'incremento",
/* 17	*/	"Impossibile accedere a local",
/* 18	*/	"Aspettando ')'",
/* 19	*/	"Aspettando ']'",
/* 20	*/	"Non � un tipo di proceso",
/* 21	*/	"Aspettando il nome di un processo",
/* 22	*/	"Aspettando '('",
/* 23	*/	"Aspettando un nome",
/* 24	*/	"Impossibile calcolare la grandezza",
/* 25	*/	"Espressione incorretta",
/* 26	*/	"Non � possibile ricevere una struttura come parametro",
/* 27	*/	"Aspettando il nome della struttura",
/* 28	*/	"Dichiarazione incorretta di puntatore a struttura",
/* 29	*/	"Aspettando il nome della catena",
/* 30	*/	"Il nome non � nuovo",
/* 31	*/	"Catena di testo di lunghezza negativa",
/* 32	*/	"Catena di testo troppo lunga",
/* 33	*/	"Non si pu� specificare una tabella come parametro",
/* 34	*/	"Nome sconosciuto: %s",
/* 35	*/	"Si aspettava una virgola",
/* 36	*/	"Si aspettava un altro parametro",
/* 37	*/	"Non � possibile accedere a dati PRIVATE esterni",
/* 38	*/	"Numero di parametri incorretto",
/* 39	*/	"Aspettando un elemento della struttura",
/* 40	*/	"Tabella di lunghezza negativa",
/* 41	*/	"La lunghezza non coincide con la dichiarazione precedente",
/* 42	*/	"Impossibile inizializzare un parametro",
/* 43	*/	"Struttura di lunghezza negativa",
/* 44	*/	"Aspettando PROGRAM",
/* 45	*/	"Aspettando il nome del programma",
/* 46	*/	"Si aspettava un stringa",
/* 47	*/	"Una struttura deve contenere almeno un elemento",
/* 48	*/	"Troppi valori per la tabella",
/* 49	*/	"Stringa troppo lunga",
/* 50	*/	"Valore BYTE fuori rango (0...255)",
/* 51	*/	"Valore WORD fuori rango (0...65535)",
/* 52	*/	"Non si pu� duplicare 0 o meno volte",
/* 53	*/	"Inizializzazione incorretta",
/* 54	*/	"Si aspettava un'espressione costante",
/* 55	*/	"Troppi valori per la struttura",
/* 56	*/	"Aspettando BEGIN",
/* 57	*/	"Aspettando END",
/* 58	*/	"Aspettando UNTIL",
/* 59	*/	"Aspettando una variabile",
/* 60	*/	"Aspettando TO",
/* 61	*/	"Sentenza FROM incorretta",
/* 62	*/	"Il valore STEP non � valido",
/* 63	*/	"Aspettando CASE, DEFAULT o END",
/* 64	*/	"Aspettando ':'",
/* 65	*/	"BREAK non appare dentro un bugle",
/* 66	*/	"CONTINUE non appare dentro un bugle",
/* 67	*/	"Si aspettava una sentenza",
/* 68	*/	"Espressione insensata",
/* 69	*/	"Assegnazione dentro una condizione",
/* 70	*/	"Aspettando un nome di processo o funzione",
/* 71	*/	"Aspettando PROCESS o FUNCTION",
/* 72	*/	"Parametro non valido",
/* 73	*/	"ELSEIF non appare dentro un blocco IF" /* SIN COMA */


/*
 * Advertencias
 */

#elif TRANSLATE == TRANSLATE_WARNING

/* 0	*/	"",
/* 1	*/	"SETUP_PROGRAM: Caratteristica sfasata",
/* 2	*/	"IMPORT: Sintassi antica, si ignora" /* SIN COMA */


/*
 * Errores de DLL
 */

#elif TRANSLATE == TRANSLATE_DLL_ERROR

/* 1	*/ "Limite buffer nomi oggetto oltrepassato",
/* 2	*/ "Oggetto '%s': Il nome non � nuovo",
/* 3	*/ "Troppi oggetti dichiarati",
/* 4	*/ "Funzione '%s': Il nome non � nuovo",
/* 5	*/ "Errore dichiarando oggetto '%s'",
/* 6	*/ "Oggetto '%s': Dichiarazione illegale dentro struct",
/* 7	*/ "Oggetto '%s': Dichiarazione di un membro fuori struct",
/* 8	*/ "Grandezza illegale di string '%s'",
/* 9	*/ "EndStruct senza Struct",
/* 10	*/ "Una struttura deve contenere almeno un elemento" /* SIN COMA */


/*
 * Errores de ltlex.def
 */

#elif TRANSLATE == TRANSLATE_LTLEX_ERROR

/* 0	*/ "",
/* 1	*/ "Archivio ltlex.def non trovato",
/* 2	*/ "Si aspettava un valore esadecimale (&00..&FF)",
/* 3	*/ "Troppi simboli definiti",
/* 4	*/ "Simbolo non valido" /* SIN COMA */


/*
 * Mensajes del compilador
 */

#elif TRANSLATE == TRANSLATE_COMPILER

/* 0	*/ " **** Compilatore eDIV " VERSION " ****\nCopyleft (c) 2000-2003 Sion, Ltd.\nhttp://ediv.divsite.net\n",
/* 1	*/ "ATTENZIONE: Questa versione di eDIV � incompleta.\nPer favore informa su qualunque bug a: ediv@divsite.net\n",
/* 2	*/ "Guida opzioni di comando:\n\n",
/* 3	*/ "%s [opzioni] archivio.prg [eseguibile]\n\n",
/* 4	*/ "Lista opzioni:\n",
/* 5	*/ "    -h, --help      Mostra questa guida ed esce\n",
/* 6	*/ "    -d, --debug     Genera informazioni addizionali di depurazione\n",
/* 7	*/ "    -l, --list      Salva il listato EML come <programma.eml>\n",
/* 8	*/ "    -t, --table     Salva la tabella oggetti come <programma.tab>\n",
/* 9	*/ "    -c, --check     Non genera l'eseguibile (per comprovare sintassi, etc.)\n",
/* 10	*/ "    -s, --system    Sistema Operativo di destinazione (per difetto %s)\n",
/* 11	*/ "    -v, --version   Mostra la versione ed esce\n\n",
/* 12	*/ "Parametro --system: deve indicare il sistema di destinazione\nConsulta la documentazione per ottenere aiuto\n",
/* 13	*/ "Parametro errato: %s\nUsa l'opzione -h per visualizzare la guida\n",
/* 14	*/ "Parametro -s: deve indicare il sistema di destinazione\nConsulta la documentazione per ottenere aiuto\n",
/* 15	*/ "Parametro errato: -%c\nUsa l'opzione -h per visualizzare la guida\n",
/* 16	*/ "Non � stato specificato l'archivio\nUsa l'opzione -h per visualizzare la guida\n",
/* 17	*/ "edivc: Errore aprendo l'archivio %s.\n",
/* 18	*/ "edivc: Compilando: %s\n",
/* 19	*/ "edivc: ERRORE: Non si incontra %s\n",
/* 20	*/ "edivc: ERRORE: Formato incorretto di %s\n",
/* 21	*/ "edivc: Interrotto (%d avvertenze)\n",
/* 22	*/ "edivc: Completato con successo (%d avvertenze)\n",
/* 23	*/ "edivc: Uscita con errori\n",
/* 24	*/ "edivc: ERRORE: Memoria insufficiente\n",
/* 25	*/ "%s:%d:%d: ERRORE %d: ",
/* 26	*/ "%s:%d: Avvertenza: ",
/* 27	*/ "Precompilando...\n",
/* 28	*/ "Compilando...\n",
/* 29	*/ "Errore creando l'archivio d'intercambio\n",
/* 30	*/ "Generando listati...\n",
/* 31	*/ "Salvando eseguibile...\n",
/* 32	*/ "Salvando informazioni di depurazione...\n",
/* 33	*/ "Errore scrivendo l'eseguibile\n",
/* 34	*/ "Compilazione completata.\n",
/* 35	*/ "%s: ERRORE: ",
/* 36	*/ "Errore creando l'archivio %s\n",
/* 37	*/ "Listato oggetti di %s - eDIV versione " VERSION "\n\n",
/* 38	*/ "\tblocco(%u), precedente(%u)\n",
/* 39	*/ "Codice EML di %s - eDIV versione " VERSION "\n",
/* 40	*/ "edivc: ERRORE: %s\n\n",
/* 41	*/ "edivc: %s (linea %d) ERRORE: %s\n\n",
/* 42	*/ "edivc: Interrotto - Sono stati trovati errori\n",
#ifdef _WIN32
/* 43	*/ "Non si trova nessuna DLL\n",
/* 44	*/ "",
#else
/* 43	*/ "Non si trova nenssuna libreria\n",
/* 44	*/ "Percorso %s/ non trovato\n",
#endif
/* 45	*/ "Errore nel caricare la libreria %s\n",
#ifdef _WIN32
/* 46	*/ "Non posso caricare %s\n",
/* 47	*/ "Non si trova ExportaFuncs in %s - DLL non valida\n",
#else
/* 46	*/ "Non posso caricare %s (%s)\n",
/* 47	*/ "Non si trova ExportaFuncs in %s - Libreria non valida (%s)\n",
#endif
/* 48	*/ "    -n, --news      Mostra le ultime notizie di eDivCentral.com ed esce\n",
/* 49	*/ "Errore: non � stato configurato un server di notizie in ediv.cfg\n",
/* 50	*/ "Errore: il file ricevuto non � del tipo atteso\n" /* SIN COMA */


/*
 * Mensajes del stub
 */

#elif TRANSLATE == TRANSLATE_STUB

/* 0	*/	"ERRORE %d: ",
/* 1	*/	"eDIV: Errore in esecuzione",
/* 2	*/	"eDIV: Errore critico",
/* 3	*/	"Errore in %s: ",
/* 4	*/	"eDIV: Errore in libreria dinamica" /* SIN COMA */


/*
 * Errores de tiempo de ejecuci�n del stub
 */

#elif TRANSLATE == TRANSLATE_RUNTIME_ERROR

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
/* 117 */ "Codice di allineamento testo non valido.",
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
/* 200 */ "Archivio con dati corrotti, non si � potuto caricare." /* SIN COMA */


/*
 * Errores cr�ticos del stub
 */

#elif TRANSLATE == TRANSLATE_CRITICAL_ERROR

/* 0	*/	"",
/* 1	*/	"Errore leggendo il codice del programma",
/* 2	*/	"Errore nel formato di codice",
/* 3	*/	"Ridefinizione del tipo di processo",
/* 4	*/	"Non si � potuto riservare memoria per la pila",
/* 5	*/	"Libreria non trovata: %s",
/* 6	*/	"%s non � una libreria valida di eDIV",
/* 7	*/	"Non � stato possibile inizializzare SDL",
/* 8	*/	"Troppi processi in esecuzione",
/* 9	*/	"E' richiesta SDL %d.%d.%d\nVersione rilevata nel sistema: %d.%d.%d" /* SIN COMA */


#endif

/* Fin de fichero */
