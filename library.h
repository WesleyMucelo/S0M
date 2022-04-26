#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>


#ifndef LAB22_LIBRARY_H
#define LAB22_LIBRARY_H


/*
 * Neste ficheiro estao defenidas as estruturas que vao definir a stack.
 */


// Declaração de novos tipos de dados para utilizar máscaras
// facilitar a criaçao de mascaras que vao ajudar na definiçao de operaçoes que so vao ser possiveis sobre um determinado tipo.
typedef enum {
    LONG = 1,
    DOUBLE = 2,
    CHAR = 4,
    STRING = 8
} TYPE;

// Definicao das mascaras que vao facilitar em saber se por exemplo a operacao é sobre um numero ou letra...
//#define INTEGER (LONG | CHAR)
//#define NUMBER  (LONG | DOUBLE)

// Declaraco dos tipos de dados que estao na stack cada tipo tem um campo(ex: tipo: long -> campo: LONG)
typedef struct {
    TYPE    type;
    long    LONG;
    double  DOUBLE;
    char    CHAR;
    char    *STRING;
} DADOS;

// Estrutura da Stack
typedef struct stack {
    DADOS *stack;    // a stack vai ser um array do tipo DADOS * para puder ser alocado dinamicamente
    int tamanho;
    int sp; // Funciona como o stack pointer;
} STACK;

int verify (DADOS elem, int mascara);
STACK *cria_stack();
void push (STACK *s, DADOS elem);
DADOS pop (STACK *s);
//int verify_Empty (STACK *s);
void imprime_stack (STACK *s);


// Macros que fazem substituiçao de texto
#define STACK_OPERATION_PROTO(_type, _name) \
    void push_##_name(STACK *s, _type val); \
    _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO (long, LONG)
STACK_OPERATION_PROTO (double , DOUBLE)
STACK_OPERATION_PROTO (char, CHAR)
STACK_OPERATION_PROTO (char *, STRING)

#endif //LAB22_LIBRARY_H
