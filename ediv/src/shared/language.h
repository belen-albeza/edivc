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

/* IDs de idioma:
 * 0  - ES - Espa�ol
 * 1  - IT - Italiano (CicTec)
 * 2  - PT - Portugu�s (tareco)
 * 3  - EN - Ingl�s (de momento Er_Makina :P)
 * 4  - CA - Catal�n (BenKo)
 * 5  - EU - Euskera (Jorge Urreta)
 */

#ifndef __LANGUAGE_H
#define __LANGUAGE_H

#define NUM_LANGUAGES 6

#define DEFAULT_LANGUAGE 3

int idioma;

// comunes
int detecta_idioma();
char* translate(int id_cadena);
char* translate_dll_error(int num);

// compilador
char* translate_error(int num);
char* translate_warning(int num);
char* translate_ltlex_error(int num);

// stub
char* translate_runtime_error(int num);
char* translate_critical_error(int num);

#endif // __LANGUAGE_H