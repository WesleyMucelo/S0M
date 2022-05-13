#include "library.h"

/*
 * Neste fucherio estao contidas as direfentes funcoes que modificam a stack.
 */


// Sequencia de macros
#define STACK_OPERATION(_type, _name)          \
    void push_##_name(STACK *s, _type val) {  \
    DADOS elem;                               \
    elem.type = _name;                        \
    elem.celula._name = val;                         \
    push(s, elem);                            \
    }                                         \
    _type pop_##_name(STACK *s) {             \
    DADOS elem = pop(s);                      \
    elem.type = _name;                        \
    return elem.celula._name;                        \
    }

STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)

// Funcao que verifica se o tipo do elem corresponde a respectiva mascara
int verify(DADOS elem, int mascara) {
    return (elem.type & mascara) != 0;
}

// Funcao que cria a STACK
STACK *cria_stack() {
    STACK *s = (STACK *) malloc(sizeof(STACK));
    s->tamanho = BUFSIZ;
    s->stack = (DADOS *) calloc(s->tamanho, sizeof(DADOS));
    return s;
}

// Fucnao que adiciona um elemento ao topo da stack
void push(STACK *s, DADOS elem) {
    if (s->tamanho == s->sp) {
        s->sp += BUFSIZ;
        s->stack = (DADOS *) realloc(s->stack, s->tamanho * sizeof(DADOS));
    }
    s->stack[s->sp] = elem;
    s->sp++;
}

// Funcao que retira o elemento que esta no topo da stack.
DADOS pop(STACK *s) {
    s->sp--;
    return s->stack[s->sp];
}

// Funcao que aponta para o topo da stack.
DADOS top(STACK *s) {
    return s->stack[s->sp - 1];
}

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

// Funcao que imprime a STACK
void imprime_stack (STACK *s) {
    for (int i = 0; i < s->sp; i++)
    {
        DADOS elem = s->stack[i];
        printa(elem);
    }
    printf("\n");
}

