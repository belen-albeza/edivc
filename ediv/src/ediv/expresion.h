#ifndef __EXPRESION_H
#define __EXPRESION_H

#define max_exp 512     //M�ximo n�mero de elementos en una expresi�n
#define long_pila 2048  //Longitud de la pila en ejecuci�n

int pila[long_pila+max_exp+64]; // c�lculo de expresiones (compilaci�n y ejecuci�n)

// Tabla de elementos en la evaluaci�n de una expresi�n

struct exp_ele {
  byte tipo; // econs, eoper, erango, ewhoami, ecall
  union {
    int valor;
    int token;
    struct objeto * objeto;
  };
} tabexp[max_exp], *_exp;

#define econs   0       // Constante          // Tipos de elementos en tabexp[]
#define eoper   1       // Operador
#define erango  2       // Comprobaci�n de rango
#define ewhoami 3       // Identificador de proceso
#define ecall   4       // Creaci�n de un proceso
//#define efunc   5       // Llamada a una funci�n interna
#define efext   6       // Llamada a una funci�n externa
#define echeck  7       // Comprobaci�n de validez de un identificador
#define estring 8       // Cadena de texto (su offset constante)
#define enull   9       // Comprobaci�n de NULL pointer

//-----------------------------------------------------------------------------

void condicion(void);
void expresion(void);
void expresion_cpa(void);
void generar_expresion(void);
int constante(void);

#endif