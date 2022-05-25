/**
 * @file functions.h
 *
 * Neste ficheiro estão contidos os protótipos do módulo functions.c
 */

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
void MaiorLogico (STACK *s);
void MenorLogico (STACK *s);
void OU_shortcut (STACK *s);
void Igual (STACK *s);
void Menor (STACK *s);
void Maior (STACK *s);
void Nao (STACK *s);
void coloca_topo (STACK *s);
void range (STACK *s);
void carrega (STACK *s, DADOS *alfabeto, char tkn);
void lelinha(STACK *s);
void convertLong(STACK *s);
void convertDouble(STACK *s);
void convertChar(STACK *s);
char *get_array(char *token, char **resto);
char *get_string(char *token, char **resto);
char *get_token(char *token, char **resto);
STACK *doCase(STACK *s, char *token, DADOS *alfabeto);


#endif //LEIPL5G08_FUNCTIONS_H
