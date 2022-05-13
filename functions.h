#ifndef LEIPL5G08_FUNCTIONS_H
#define LEIPL5G08_FUNCTIONS_H
#include "library.h"

void adicao(STACK *s);


void subtracao(STACK *s);


void multiplicacao (STACK *s);


void divisao (STACK *s);


void decrementa (STACK *s);


void incrementa (STACK *s);


void modulo (STACK *s);


void exponenciacao (STACK *s);

/**
 * \brief Função que implementa o e "&" comercial usando a comparação como shortcut
 *
 */
void elogico (STACK *s);


void oulogico (STACK *s);


void xorlogico (STACK *s);


void negacaologica (STACK *s);


void duplica (STACK *s);


void roda (STACK *s);


void troca (STACK *s);


void copia (STACK *s);


void if_then_else (STACK *s);


void E_shortcut (STACK *s);

/**
 * \brief Função que implementa o símbolo de maior elemento
 *
 */
void MaiorLogico (STACK *s);

/**
* \brief Função que implementa o símbolo de menor elemento
*
*/
void MenorLogico (STACK *s);


void OU_shortcut (STACK *s);


void Igual (STACK *s);

/**
 * \brief Função que implementa o símbolo de menor elemento
 *
 */
void Menor (STACK *s);


void Maior (STACK *s);


void Nao (STACK *s);

void coloca_topo (STACK *s);


void range (STACK *s);

/**
 * \brief Função que le uma linha.
 *
 */
void lelinha(STACK *s);

/**
 * \brief Função que converte outros tipos de variáveis para Long.
 *
 */
void convertLong(STACK *s);

/**
 * \brief Função que converte outros tipos de variáveis para Duble.
 *
 */
void convertDouble(STACK *s);

/**
 * \brief Função que converte outros tipos de variáveis para Long.
 *
 */
void convertChar(STACK *s);

/**
 * \brief Função para tratar dos tokens.
 *
 */
char *get_token(char *token, char **resto);

/**
 * \brief Função que identifica os tokens e realiza as operacoes correspondentes.
 *
 */
STACK *doCase(STACK *s, char *token, DADOS *alfabeto);



#endif //LEIPL5G08_FUNCTIONS_H
