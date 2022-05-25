/**
 * @file library.c
 *
 * Neste ficheiro estão contidas as direfentes funções  que modificam/alteram a composição e estrutura da stack.
 */

#include "library.h"


/**
 * \brief Sequência de macros para auxiliar aos tipos de dados da stack
 *
 */
#define STACK_OPERATION(_type, _name)         \
    void push_##_name(STACK *s, _type val) {  \
    DADOS elem;                               \
    elem.type = _name;                        \
    elem.celula._name = val;                  \
    push(s, elem);                            \
    }                                         \
    _type pop_##_name(STACK *s) {             \
    DADOS elem = pop(s);                      \
    elem.type = _name;                        \
    return elem.celula._name;                 \
    }

STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)

/**
 * \brief Função que verifica se o tipo do elemento recebido corresponde a respectiva mascára.
 *
 * @param elem, mascara.
 * @returns (elem.type & mascara).
 */
int verify(DADOS elem, int mascara) {
    return (elem.type & mascara) != 0;
}

/**
 * \brief Funçao que cria uma STACK vazia.
 *
 * @return s.
 */
STACK *cria_stack() {
    STACK *s = (STACK *) malloc(sizeof(STACK));
    s->tamanho = BUFSIZ;
    s->stack = (DADOS *) calloc(s->tamanho, sizeof(DADOS));
    return s;
}

/**
 * \brief Função que adiciona um elemento ao topo da stack.
 *
 * @param s, elem.
 */
void push(STACK *s, DADOS elem) {
    if (s->tamanho == s->sp) {
        s->sp += BUFSIZ;
        s->stack = (DADOS *) realloc(s->stack, s->tamanho * sizeof(DADOS));
    }
    s->stack[s->sp] = elem;
    s->sp++;
}

/**
 * \brief Função que retira o elemento que está no topo da stack.
 *
 * @param s
 * @return s->stack[s->sp].
 */
DADOS pop(STACK *s) {
    s->sp--;
    return s->stack[s->sp];
}

/**
 * \brief Função que aponta para o topo da stack.
 *
 * @param s.
 * @returns s->stack[s->sp - 1].
 */
DADOS top(STACK *s) {
    return s->stack[s->sp - 1];
}

/**
 * \brief Função auxiliar da funçao imprime_stack que imprime os elementos da stack.
 *
 * @param elem.
 */
void printa(DADOS elem)
{
    switch(elem.type)
    {
        case LONG:
        {
            printf("%ld", elem.celula.LONG);
            return;
        }
        case CHAR:
        {
            printf("%c", elem.celula.CHAR);
            return;
        }
        case DOUBLE:
        {
            printf("%g", elem.celula.DOUBLE);
            return;
        }
        case STRING:
        {
            printf("%s", elem.celula.STRING);
            return;
        }
    }
}

/**
 * \brief Função que aponta para o conteúdo da stack.
 *
 * @param s.
 */
void imprime_stack (STACK *s) {
    for (int i = 0; i < s->sp; i++)
    {
        DADOS elem = s->stack[i];
        printa(elem);
    }
    printf("\n");
}

