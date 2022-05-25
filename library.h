/**
 * @file library.h
 *
 * A stack é uma estrutura estrutura de dados linear na ordem 'Last In First Out' (LIFO), sendo nessa ordem que são realizadas
 * e caracteriza um empilhamento de dados.
 *
 * Neste ficheiro tem-se como objectivo a implementação da stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#ifndef LAB22_LIBRARY_H
#define LAB22_LIBRARY_H


/**
 * @brief Definição do tipo enum que enumera os tipos de variáveis possíveis.
 */
typedef enum {
    LONG   = 1,             /**< Definição do tipo LONG */
    DOUBLE = 2,             /**< Definição do tipo DOUBLE */
    CHAR   = 4,             /**< Definição do tipo CHAR */
    STRING = 8              /**< Definição do tipo STRING */
} TYPE;


/**
 * @brief Definição da estrutura de dados que define o tipo DADOS.
 */
typedef struct {
    TYPE        type;       /**< Definição do tipo da estrutura de dados */
    union {
        long    LONG;       /**< Contém o valor do tipo long */
        double  DOUBLE;     /**< Contém o valor do tipo double */
        char    CHAR;       /**< Contém o valor do tipo char */
        char    *STRING;    /**< Contém o valor do tipo string */
    } celula;
} DADOS;


/**
 * @brief Definição da estrutura da stack.
 */
typedef struct stack {
    DADOS   *stack;         /**< Define do tipo de dados presente na stack */
    int     tamanho;        /**< Contém o valor do tamanho da stack */
    int     sp;             /**< Contém o valor do apontados da stack */
} STACK;


/**
 * @brief Definição dos protótipos do módulo library.c
 */
int verify (DADOS elem, int mascara);
STACK *cria_stack();
void push (STACK *s, DADOS elem);
DADOS pop (STACK *s);
DADOS top(STACK *s);
void imprime_stack (STACK *s);


/**
 * \brief Sequência de macros para auxiliar aos tipos de dados da stack
 *
 */
#define STACK_OPERATION_PROTO(_type, _name) \
    void push_##_name(STACK *s, _type val); \
    _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO (long, LONG)
STACK_OPERATION_PROTO (double , DOUBLE)
STACK_OPERATION_PROTO (char, CHAR)
STACK_OPERATION_PROTO (char *, STRING)



#endif //LAB22_LIBRARY_H
