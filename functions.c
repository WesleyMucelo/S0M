#include "library.h"
#include "functions.h"

/*
 * Neste ficheiro estao contidas as operacoes que sao feitas sobre a stack.
 */

void adicao(STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG))
        push_LONG(s, x.LONG + y.LONG);
    else if (verify(x, DOUBLE) && verify(y, LONG))
        push_DOUBLE(s, x.DOUBLE + (double) y.LONG);
    else if (verify(x, LONG) && verify(y, DOUBLE))
        push_DOUBLE(s, (double) x.LONG + y.DOUBLE);
    else if (verify(x, DOUBLE) && verify(y, DOUBLE))
        push_DOUBLE(s, x.DOUBLE + y.DOUBLE);
    else {
        push(s, y);
        push(s, x);
    }
}

void subtracao (STACK *s) {
DADOS x = pop(s);
DADOS y = pop(s);
if (verify(x, LONG) && verify(y, LONG))
push_LONG(s, y.LONG - x.LONG);
else if (verify(x, DOUBLE) && verify(y, LONG))
push_DOUBLE(s, (double) y.LONG - x.DOUBLE);
else if (verify(x, LONG) && verify(y, DOUBLE))
push_DOUBLE(s, y.DOUBLE - (double) x.LONG);
else {
push_DOUBLE(s, y.DOUBLE - x.DOUBLE);
}
}

void multiplicacao (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG))
        push_LONG(s, x.LONG * y.LONG);
    else if (verify(x, DOUBLE) && verify(y, LONG))
        push_DOUBLE(s, x.DOUBLE * (double) y.LONG);
    else if (verify(x, LONG) && verify(y, DOUBLE))
        push_DOUBLE(s, (double) x.LONG * y.DOUBLE);
    else if (verify(x, LONG) && verify(y, STRING))
        for (; x.LONG != 0; x.LONG--)
            push_STRING(s, y.STRING);
    else {
        push_DOUBLE(s, x.DOUBLE * y.DOUBLE);
    }
}

void divisao (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG))
        push_LONG(s, y.LONG / x.LONG);
    else if (verify(x, DOUBLE) && verify(y, LONG))
        push_DOUBLE(s, (double) y.LONG / x.DOUBLE);
    else if (verify(x, LONG) && verify(y, DOUBLE))
        push_DOUBLE(s, y.DOUBLE / (double) x.LONG);
    else {
        push_DOUBLE(s, y.DOUBLE / x.DOUBLE);
    }
}

void decrementa (STACK *s) {
    DADOS x = pop(s);
    if (verify(x, LONG))
        push_LONG(s, x.LONG + 1);
    else if (verify(x, DOUBLE)) {
        push_DOUBLE(s, x.DOUBLE + 1);
    }
}

void incrementa (STACK *s) {
    DADOS x = pop(s);
    if (verify(x, LONG))
        push_LONG(s, x.LONG - 1);
    else if (verify(x, DOUBLE)) {
        push_DOUBLE(s, x.DOUBLE - 1);
    }
}

void modulo (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    push_LONG(s, y.LONG % x.LONG);
}

void exponenciacao (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG))
        push_LONG(s, (long) pow((double) y.LONG, (double) x.LONG));
    else if (verify(x, DOUBLE) && verify(y, LONG))
        push_DOUBLE(s, pow((double) y.LONG, x.DOUBLE));
    else if (verify(x, LONG) && verify(y, DOUBLE))
        push_DOUBLE(s, pow(y.DOUBLE, (double) x.LONG));
    else {
        push_DOUBLE(s, pow(y.DOUBLE, x.DOUBLE));
    }
}

void elogico (STACK *s) {
    long y = pop_LONG(s);
    long x = pop_LONG(s);
    push_LONG(s, x & y);
}

void oulogico (STACK *s) {
    long y = pop_LONG(s);
    long x = pop_LONG(s);
    push_LONG(s, x | y);
}

void xorlogico (STACK *s){
    long y = pop_LONG(s);
    long x = pop_LONG(s);
    push_LONG(s, x ^ y);
}

void negacaologica (STACK *s) {
    DADOS x = pop(s);
    if (verify(x, LONG))
        push_LONG(s, ~x.LONG);
    else
        push_STRING(s, x.STRING);
}

void duplica (STACK *s) {
    DADOS x = pop(s);
    if (verify(x, LONG)) {
        push_LONG(s, x.LONG);
        push_LONG(s, x.LONG);
    } else if (verify(x, DOUBLE)) {
        push_DOUBLE(s, x.DOUBLE);
        push_DOUBLE(s, x.DOUBLE);
    }
}

void roda (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    DADOS z = pop(s);
    push(s, y);
    push(s, x);
    push(s, z);
}

void troca (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    push(s, x);
    push(s, y);
}

















/**
 * \brief Função que le uma linha.
 *
 */
void lelinha(STACK *s) {
    char linha[BUFSIZ];
    assert(fgets(linha, sizeof(linha), stdin));
    push_STRING(s, strdup(linha));
}

/**
 * \brief Função que converte outros tipos de variáveis para Long.
 *
 */
void convertLong(STACK *s) {
    DADOS x = pop(s);
    char *str;
    if (x.type == LONG) {
        push_LONG(s, x.LONG);
    } else if (x.type == CHAR) {
        push_LONG(s, (long) x.CHAR);
    } else if (x.type == DOUBLE) {
        push_LONG(s, (long) x.DOUBLE);
    } else {
        push_LONG(s, strtol(x.STRING, &str, 10));
    }

    x.type = LONG;
}

/**
 * \brief Função que converte outros tipos de variáveis para Duble.
 *
 */
void convertDouble(STACK *s) {
    DADOS x = pop(s);
    char *str;
    if (x.type == DOUBLE) {
        push_DOUBLE(s, x.DOUBLE);
    } else if (x.type == CHAR) {
        push_DOUBLE(s, (double)((long) x.CHAR));
    } else if (x.type == LONG) {
        push_DOUBLE(s, (double)x.LONG);
    } else {
        push_DOUBLE(s, strtod(x.STRING, &str));
    }

    x.type = DOUBLE;

}

/**
 * \brief Função que converte outros tipos de variáveis para Long.
 *
 */
void convertChar(STACK *s) {
    DADOS x = pop(s);
    if (x.type == CHAR) {
        push_CHAR(s, x.CHAR);
    } else if (x.type == DOUBLE) {
        push_CHAR(s, (char)x.DOUBLE);
    } else if (x.type == LONG) {
        push_CHAR(s, (char)x.LONG);
    }

    x.type = DOUBLE;
}


/**
 * \brief Função para tratar dos tokens.
 *
 */
char *get_token(char *token, char **resto) {
    char *tok = malloc(BUFSIZ);
    int i = 0;
    while (token[i] != ' ' && token[i] != '\0' && token[i] != '\n') {
        tok[i] = token[i];
        i++;
    }
    tok[i] = '\0';

    *resto = NULL;

    if (token[i] != '\0') {
        *resto = token + i + 1;
    }
    return tok;
}

/**
 * \brief Função que identifica os tokens e realiza as operacoes correspondentes.
 *
 */
STACK *doCase(STACK *s, char *token) {
    char **resto = malloc(sizeof(char *));
    for (char *tkn = get_token(token, resto); *resto != NULL; tkn = get_token(token, resto)) {
        char *elem_long;
        char *elem_double;
        long valor_long = strtol(tkn, &elem_long, 10);
        double valor_double = strtod(tkn, &elem_double);
        if (strlen(elem_long) == 0)
            push_LONG(s, valor_long);
        else if (strlen(elem_double) == 0)
            push_DOUBLE(s, valor_double);
        else if (tkn[0]) {
            if ((strcmp(tkn, "+") == 0)) { // Adição
                adicao(s);
            } else if ((strcmp(tkn, "-") == 0)) { // Subtração
                subtracao(s);
            } else if ((strcmp(tkn, "*") == 0)) { // Multiplicação
                multiplicacao(s);
            } else if ((strcmp(tkn, "/") == 0)) { // Divisão Inteira
                divisao(s);
            } else if ((strcmp(tkn, "(") == 0)) { // Decrementar
                decrementa(s);
            } else if ((strcmp(tkn, ")") == 0)) { // Incrementar
                incrementa(s);
            } else if ((strcmp(tkn, "%") == 0)) { // Módulo
                modulo(s);
            } else if ((strcmp(tkn, "#") == 0)) { // Exponenciação
                exponenciacao(s);
            } else if ((strcmp(tkn, "&") == 0)) {   // e_logico
                elogico(s);
            } else if ((strcmp(tkn, "|") == 0)) {   // ou_logico
                oulogico(s);
            } else if ((strcmp(tkn, "^") == 0)) {   // xor_logico
                xorlogico(s);
            } else if ((strcmp(tkn, "~") == 0)) {   // negacao_logica
                negacaologica(s);
            } else if ((strcmp(tkn, "_") == 0)) { // Duplica elemento
                duplica(s);
            } else if ((strcmp(tkn, "@") == 0)) { // Rodar os 3 elementos no topo da stack
                roda(s);
            } else if((strcmp(tkn, "\\") == 0)) { //Trocar os dois elementos do topo da stack
                troca(s);
            } else if ((strcmp(tkn, ";") == 0)) { // Pop
                pop(s);
            } else if ((strcmp(tkn, "l") == 0)) { // Leitura de linha
                lelinha(s);
            } else if ((strcmp(tkn, "i") == 0)) { // converte para Long
                convertLong(s);
            } else if ((strcmp(tkn, "f") == 0)) { // converte para Double
                convertDouble(s);
            } else if ((strcmp(tkn, "c") == 0)) { // converte para Char
                convertChar(s);
            }
        }
        token = *resto;
    }
    return s;
}
