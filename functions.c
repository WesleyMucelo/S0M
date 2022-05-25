/**
 * @file functions.c
 *
 * Neste ficheiro estão contidos os programas que realizam a operações consoante os inputs e devolvem outputs adequados aos mesmos.
 */

#include "library.h"
#include "functions.h"


/**
 * \brief Esta função realiza a operação da soma dado um determinado input.
 * Se o input for uma string ou um array, esta concatena-os.
 *
 * @param s.
 */
void adicao(STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG))
        push_LONG(s, x.celula.LONG + y.celula.LONG);
    else if (verify(x, DOUBLE) && verify(y, LONG))
        push_DOUBLE(s, x.celula.DOUBLE + (double) y.celula.LONG);
    else if (verify(x, LONG) && verify(y, DOUBLE))
        push_DOUBLE(s, (double) x.celula.LONG + y.celula.DOUBLE);
    else if (verify(x, DOUBLE) && verify(y, DOUBLE))
        push_DOUBLE(s, x.celula.DOUBLE + y.celula.DOUBLE);
    else {
        push(s, y);
        push(s, x);
    }
}

/**
 * \brief Esta função realiza a operação da subtração dado um determinado input.
 *
 * @param s.
 */
void subtracao(STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG))
        push_LONG(s, y.celula.LONG - x.celula.LONG);
    else if (verify(x, LONG) && verify(y, DOUBLE))
        push_DOUBLE(s, y.celula.DOUBLE - (double) x.celula.LONG);
    else if (verify(x, DOUBLE) && verify(y, LONG))
        push_DOUBLE(s, (double) y.celula.LONG - x.celula.DOUBLE);
    else if (verify(x, DOUBLE) && verify(y, DOUBLE))
        push_DOUBLE(s, y.celula.DOUBLE - x.celula.DOUBLE);
}

/**
 * \brief Esta função realiza a operação da multplicação dado um determinado input.
 * Se o input for uma string ou um array, esta repete os n-vezes.
 *
 * @param s.
 */
void multiplicacao (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG))
        push_LONG(s, x.celula.LONG * y.celula.LONG);
    else if (verify(x, DOUBLE) && verify(y, LONG))
        push_DOUBLE(s, x.celula.DOUBLE * (double) y.celula.LONG);
    else if (verify(x, LONG) && verify(y, DOUBLE))
        push_DOUBLE(s, (double) x.celula.LONG * y.celula.DOUBLE);
    else if (verify(x, DOUBLE) && verify(y, DOUBLE))
        push_DOUBLE(s, x.celula.DOUBLE * y.celula.DOUBLE);
    else if (verify(x, LONG) && verify(y, STRING))
        for (; x.celula.LONG != 0; x.celula.LONG--)
            push_STRING(s, y.celula.STRING);
}

/**
 * \brief Esta função realiza a operação da divisão dado um determinado input.
 *
 * @param s.
 */
void divisao (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG))
        push_LONG(s, y.celula.LONG / x.celula.LONG);
    else if (verify(x, DOUBLE) && verify(y, LONG))
        push_DOUBLE(s, (double) y.celula.LONG / x.celula.DOUBLE);
    else if (verify(x, LONG) && verify(y, DOUBLE))
        push_DOUBLE(s, y.celula.DOUBLE / (double) x.celula.LONG);
    else if (verify(x, DOUBLE) && verify(y, DOUBLE))
        push_DOUBLE(s, x.celula.DOUBLE / y.celula.DOUBLE);
}

/**
 * \brief Esta função realiza a operação de decrementação por uma unidade(+1) dado um determinado input.
 * Se o input for uma string ou um array, esta retira o primeiro elemento e coloca-o no topo do anterior.
 *
 * @param s.
 */
void decrementa (STACK *s) {
    DADOS x = pop(s);
    if (verify(x, LONG))
        push_LONG(s, x.celula.LONG - 1);
    else if (verify(x, DOUBLE))
        push_DOUBLE(s, x.celula.DOUBLE - 1);
    else if (verify(x, CHAR))
        push_CHAR(s, (char)(x.celula.CHAR - 1));
    else if (verify(x,STRING)) {
        push_STRING(s,x.celula.STRING + 1);
        push_CHAR(s,x.celula.STRING[0]);
    }
}

/**
 * \brief Função auxiliar usada para o operador ')' no caso de strings.
 *
 * @param s.
 * @returns s.
 */
char *aux (char *s) {
    unsigned int x = strlen(s) - 1;
    s[x] = '\0';

    return s;
}

/**
 * \brief Esta função realiza a operação de decrementação por uma unidade(+1) dado um determinado input.
 * Se o input for uma string ou um array, esta retira o último elemento e coloca-o no topo do anterior.
 *
 * @param s.
 */
void incrementa (STACK *s) {
    DADOS x = pop(s);
    if (verify(x, LONG))
        push_LONG(s, x.celula.LONG + 1);
    else if (verify(x, DOUBLE))
        push_DOUBLE(s, x.celula.DOUBLE + 1);
    else if (verify(x, CHAR))
        push_CHAR(s, (char) (x.celula.CHAR + 1));
    else if (verify(x, STRING)) {
        char c = x.celula.STRING[strlen(x.celula.STRING) - 1];
        push_STRING(s, aux(x.celula.STRING));
        push_CHAR(s, c);
    }
}

/**
 * \brief Esta função realiza a operação de módulo dado um determinado input.
 *
 * @param s.
 */
void modulo (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    push_LONG(s, y.celula.LONG % x.celula.LONG);
}

/**
 * \brief Esta função realiza a operação da divisão dado um determinado input.
 *
 * @param s.
 */
void exponenciacao (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG))
        push_LONG(s, (long) pow((double) y.celula.LONG, (double) x.celula.LONG));
    else if (verify(x, DOUBLE) && verify(y, LONG))
        push_DOUBLE(s, pow((double) y.celula.LONG, x.celula.DOUBLE));
    else if (verify(x, LONG) && verify(y, DOUBLE))
        push_DOUBLE(s, pow(y.celula.DOUBLE, (double) x.celula.LONG));
    else {
        push_DOUBLE(s, pow(y.celula.DOUBLE, x.celula.DOUBLE));
    }
}

/**
 * \brief Esta função realiza a operação de E lógico dado um determinado input.
 *
 * @param s.
 */
void elogico (STACK *s) {
    long y = pop_LONG(s);
    long x = pop_LONG(s);
    push_LONG(s, x & y);
}

/**
 * \brief Esta função realiza a operação de OU lógico dado um determinado input.
 *
 * @param s.
 */
void oulogico (STACK *s) {
    long y = pop_LONG(s);
    long x = pop_LONG(s);
    push_LONG(s, x | y);
}

/**
 * \brief Esta função realiza a operação de XOR lógico dado um determinado input.
 *
 * @param s.
 */
void xorlogico (STACK *s) {
    long y = pop_LONG(s);
    long x = pop_LONG(s);
    push_LONG(s, x ^ y);
}

/**
 * \brief Esta função realiza a operação de NEGAÇÃO lógico dado um determinado input.
 * Se o input for um array, coloca no topo da sack todos os elementos do array.
 *
 * @param s.
 */
void negacaologica (STACK *s) {
    DADOS x = pop(s);
    if (verify(x, LONG))
        push_LONG(s, ~ x.celula.LONG);
    else if (verify(x, STRING))
        push_STRING(s, x.celula.STRING);
}

/**
 * \brief Esta função realiza a operação que duplica um elemento de um determinado input.
 *
 * @param s.
 */
void duplica (STACK *s) {
    DADOS x = pop(s);
    if (verify(x, LONG)) {
        push_LONG(s, x.celula.LONG);
        push_LONG(s, x.celula.LONG);
    } else if (verify(x, DOUBLE)) {
        push_DOUBLE(s, x.celula.DOUBLE);
        push_DOUBLE(s, x.celula.DOUBLE);
    } else if (verify(x, CHAR)) {
        push_CHAR(s, x.celula.CHAR);
        push_CHAR(s, x.celula.CHAR);
    }
}

/**
 * \brief Esta função realiza a operação que roda a stack para um determinado input.
 *
 * @param s.
 */
void roda (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    DADOS z = pop(s);
    push(s, y);
    push(s, x);
    push(s, z);
}

/**
 * \brief Esta função realiza a operação de troca de dois elemento de um determinado input.
 *
 * @param s.
 */
void troca (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    push(s, x);
    push(s, y);
}

/**
 * \brief Esta função realiza a operação que copia o n-ésimo elemento para o topo da stack, de um determinado input.
 *
 * @param s.
 */
void copia (STACK *s) {
    long x = pop_LONG(s);
    for (int i = 0; i <= s->tamanho; i++) {
        if (x == i)
            push (s, s->stack[s->sp - x - 1]);
    }
}

/**
 * \brief Esta função realiza a operação de IF (topo da stack) Then Else, de um determinado input.
 *
 * @param s.
 */
void if_then_else (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    DADOS z = pop(s);
    if (z.celula.LONG >= 1)
        push(s,y);
    else
        push(s,x);
}

/**
 * \brief Esta função realiza a operação E lógico com shortcut, de um determinado input.
 *
 * @param s.
 */
void E_shortcut (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (x.celula.LONG == 0 || y.celula.LONG == 0)
        push_LONG(s,0);
    else if (x.celula.LONG > y.celula.LONG){
        push(s,x);
    } else
        push(s,y);
}

/**
 * \brief Esta função realiza a operação maior de um determinado input.
 *
 * @param s.
 */
void MaiorLogico (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG)) {
        if (x.celula.LONG > y.celula.LONG)
            push_LONG(s, x.celula.LONG);
        else
            push_LONG(s, y.celula.LONG);
    } else if (verify(x, DOUBLE) && verify(y, DOUBLE)) {
        if ((x.celula.DOUBLE > y.celula.DOUBLE))
            push_DOUBLE(s, x.celula.DOUBLE);
        else
            push_DOUBLE(s, y.celula.DOUBLE);
    } else if (verify(x, LONG) && verify(y, DOUBLE)){
        if ((double)x.celula.LONG > y.celula.DOUBLE)
            push_LONG(s,x.celula.LONG);
        else
            push_DOUBLE(s,y.celula.DOUBLE);
    } else if (verify(x, DOUBLE) && verify(y, LONG)){
        if (x.celula.DOUBLE > (double)y.celula.LONG)
            push_DOUBLE(s,x.celula.DOUBLE);
        else
            push_LONG(s,y.celula.LONG);
    }
}

/**
 * \brief Esta função realiza a operação menor de um determinado input.
 *
 * @param s.
 */
void MenorLogico (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG)) {
        if (x.celula.LONG < y.celula.LONG)
            push_LONG(s, x.celula.LONG);
        else
            push_LONG(s, y.celula.LONG);

    } else if (verify(x, DOUBLE) && verify(y, DOUBLE)) {
        if ((x.celula.DOUBLE < y.celula.DOUBLE))
            push_DOUBLE(s, x.celula.DOUBLE);
        else
            push_DOUBLE(s, y.celula.DOUBLE);
    } else if (verify(x, LONG) && verify(y, DOUBLE)){
        if ((double)x.celula.LONG < y.celula.DOUBLE)
            push_LONG(s,x.celula.LONG);
        else
            push_DOUBLE(s,y.celula.DOUBLE);
    } else if (verify(x, DOUBLE) && verify(y, LONG)){
        if (x.celula.DOUBLE < (double)y.celula.LONG)
            push_DOUBLE(s,x.celula.DOUBLE);
        else
            push_LONG(s,y.celula.LONG);
    }
}

/**
 * \brief Esta função realiza a operação OU lógico com shortcut, de um determinado input.
 *
 * @param s.
 */
void OU_shortcut (STACK *s) {
    DADOS x=pop(s);
    DADOS y=pop(s);
    if (y.celula.LONG != 0)
        push(s,y);
    else
        push (s,x);
}

/**
 * \brief Esta função verifica a veracidade da igualdadede de um determinado input.
 *
 * @param s.
 */
void Igual (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG)) {
        if (x.celula.LONG == y.celula.LONG)
            push_LONG(s,1);
        else
            push_LONG(s,0);
    } else if (verify(x, DOUBLE) && verify(y, DOUBLE)) {
        if (x.celula.DOUBLE == y.celula.DOUBLE)
            push_LONG(s,1);
        else
            push_LONG(s,0);
    } else if (verify(x, LONG) && verify(y, DOUBLE)){
        if ((double)x.celula.LONG == y.celula.DOUBLE)
            push_LONG(s,1);
        else
            push_DOUBLE(s,0);
    } else if (verify(x, DOUBLE) && verify(y, LONG)){
        if (x.celula.DOUBLE == (double)y.celula.LONG)
            push_LONG(s,1);
        else
            push_LONG(s,0);
    }
    else if (verify(x,LONG) && verify(y,STRING))
        push_CHAR(s,y.celula.STRING[x.celula.LONG]);
    else if (verify(x,STRING) && verify(y,STRING))
        push_LONG(s, strcmp(x.celula.STRING, y.celula.STRING));
}

/**
 * \brief Esta função verifica a veracidade da relação menor de um determinado input.
 *
 * @param s.
 */
void Menor (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG)) {
        if (x.celula.LONG < y.celula.LONG)
            push_LONG(s,0);
        else
            push_LONG(s,1);
    } else if (verify(x, DOUBLE) && verify(y, DOUBLE)) {
        if (x.celula.DOUBLE < y.celula.DOUBLE)
            push_LONG(s,0);
        else
            push_LONG(s,1);
    } else if (verify(x, LONG) && verify(y, DOUBLE)){
        if ((double)x.celula.LONG < y.celula.DOUBLE)
            push_LONG(s,0);
        else
            push_DOUBLE(s,1);
    } else if (verify(x, DOUBLE) && verify(y, LONG)){
        if (x.celula.DOUBLE < (double)y.celula.LONG)
            push_LONG(s,0);
        else
            push_LONG(s,1);
    }
}

/**
 * \brief Esta função verifica a veracidade da relação maior de um determinado input.
 *
 * @param s.
 */
void Maior (STACK *s) {
    DADOS x = pop(s);
    DADOS y = pop(s);
    if (verify(x, LONG) && verify(y, LONG)) {
        if (x.celula.LONG > y.celula.LONG)
            push_LONG(s,0);
        else
            push_LONG(s,1);
    } else if (verify(x, DOUBLE) && verify(y, DOUBLE)) {
        if (x.celula.DOUBLE > y.celula.DOUBLE)
            push_LONG(s,0);
        else
            push_LONG(s,1);
    } else if (verify(x, LONG) && verify(y, DOUBLE)){
        if ((double)x.celula.LONG > y.celula.DOUBLE)
            push_LONG(s,0);
        else
            push_DOUBLE(s,1);
    } else if (verify(x, DOUBLE) && verify(y, LONG)){
        if (x.celula.DOUBLE > (double)y.celula.LONG)
            push_LONG(s,0);
        else
            push_LONG(s,1);
    }
}

/**
 * \brief Esta função realiza a operação de negação de um determinado input.
 * Se o input for um array, coloca-o no topo da stack.
 *
 * @param s.
 */
void Nao (STACK *s) {
    DADOS x = pop(s);
    if (verify(x, LONG)) {
        if (x.celula.LONG == 0)
            push_LONG (s, 1);
        else
            push_LONG (s,0);
    } else if (verify(x, DOUBLE)) {
        if (x.celula.DOUBLE == 0)
            push_LONG (s, 1);
        else
            push_LONG (s, 0);
    }
    else if (verify(x, CHAR)) {
        if (x.celula.CHAR == 0)
            push_CHAR(s, 1);
        else
            push_CHAR(s, 0);
    }
}

/**
 * \brief Esta função realiza a operação que coloca no topo da stack o conteúdo de uma determinada variável de um determinado input.
 *
 * @param s.
 */
void coloca_topo (STACK *s) {
    DADOS x = top(s);
    if (verify(x,LONG))
        push_LONG(s,x.celula.LONG);
    else if (verify(x,CHAR))
        push_CHAR(s,x.celula.CHAR);
    else if (verify(x,DOUBLE))
        push_DOUBLE(s,x.celula.DOUBLE);
}

/**
 * \brief Esta função  que identifica o tamanho ou comprimento de uma string ou array de um determinado input.
 *
 * @param s.
 */
void range (STACK *s) {
    DADOS x = pop(s);
    int i, conta = 0;
    if (verify(x, LONG)) {
        for (i = 0; i < x.celula.LONG; i++)
            push_LONG(s, i);
    }
    else if (verify(x, STRING)) {
        for (i = 0; x.celula.STRING[i] != '\0'; i++)
            conta++;
        push_LONG(s, conta);
    }
}

/**
 * \brief Esta função realiza a operação que carrega o topo da stack para uma determinada variavel de um determinado input.
 *
 * @param s, alfabeto, tkn
 */
void carrega (STACK *s, DADOS *alfabeto, char tkn) {
    int i;
    char alfa[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    DADOS x = top(s);

    for (i = 0; i < 26; i++) {
        alfabeto[i] = *(DADOS *) malloc(sizeof(DADOS));
        if (tkn == alfa[i]) {
            if (verify(x, LONG) == 0) {
                alfabeto[i].celula.LONG = x.celula.LONG;
                return;
            }
            else if (verify(x, DOUBLE) == 0) {
                alfabeto[i].celula.DOUBLE = x.celula.DOUBLE;
                return;
            }
            else if (verify(x, CHAR) == 0) {
                alfabeto[i].celula.CHAR = x.celula.CHAR;
                return;
            }
            else if (verify(x, STRING) == 0) {
                alfabeto[i].celula.STRING = strdup(x.celula.STRING);
                return;
            }
        }
    }
}

/**
 * \brief Esta função realiza a operação que lê input de uma nova linha.
 *
 * @param s.
 */
void lelinha(STACK *s) {
    char linha[BUFSIZ];
    assert(fgets(linha, sizeof(linha), stdin));
    push_STRING(s, strdup(linha));
}

/**
 * \brief Esta função realiza a operação que converte vários tipos de input para long.
 *
 * @param s.
 */
void convertLong(STACK *s) {
    DADOS x = pop(s);
    char *str;
    if (verify(x, LONG)) {
        push_LONG(s, x.celula.LONG);
    } else if (verify(x, CHAR)) {
        push_LONG(s, (long) x.celula.CHAR);
    } else if (verify(x, DOUBLE)) {
        push_LONG(s, (long) x.celula.DOUBLE);
    } else {
        push_LONG(s, strtol(x.celula.STRING, &str, 10));
    }
}

/**
 * \brief Esta função realiza a operação que converte vários tipos de input para double.
 *
 * @param s.
 */
void convertDouble(STACK *s) {
    DADOS x = pop(s);
    char *str;
    if (verify(x, DOUBLE)) {
        push_DOUBLE(s, x.celula.DOUBLE);
    } else if (verify(x, CHAR)) {
        push_DOUBLE(s, (double)((long) x.celula.CHAR));
    } else if (verify(x, LONG)) {
        push_DOUBLE(s, (double)x.celula.LONG);
    } else {
        push_DOUBLE(s, strtod(x.celula.STRING, &str));
    }
}

/**
 * \brief Esta função realiza a operação que converte vários tipos de input para char.
 *
 * @param s.
 */
void convertChar(STACK *s) {
    DADOS x = pop(s);
    if (verify(x , CHAR)) {
        push_CHAR(s, x.celula.CHAR);
    } else if (verify(x, DOUBLE)) {
        push_CHAR(s, (char)x.celula.DOUBLE);
    } else if (verify(x, LONG)) {
        push_CHAR(s, (char)x.celula.LONG);
    }
}

/**
 * \brief Esta função realiza a operação que devolve os elementos dentro de um array.
 *
 * @param token, resto.
 * @returns array.
 */
char *get_array(char *token, char **resto) {
    char *array = calloc(100,sizeof(char));
    *resto = NULL;
    int i = 0, j = 2, k = 0 , l = 0;

    while (token[j] != ']') {
        array[i] = token[j];
        i++, j++;
    }
    array[i-1] = '\0';

    if (token[j] != '\0')
        *resto = &token[j + 2];

    while (array[k] != '\0') {
        if	(!isspace(array[k]))	{
            array[l] = array[k];
            l++;
        }
        k++;
    }
    array[l] = '\0';

    return array;
}

/**
 * \brief Esta função realiza a operação que devolve os elementos dentro de uma string.
 *
 * @param token, resto.
 * @returns string.
 */
char *get_string(char *token, char **resto) {
    char *string = calloc(100,sizeof(char));
    *resto = NULL;
    int i = 0, j = 1, k = 0, l = 0;

    while (token[j] != '\"') {
        string[i] = token[j];
        i++, j++;
    }
    string[i] = '\0';

    if (token[j] != '\0')
        *resto = &token[j + 1];

    while (string[k] != '\0') {
        if	(!isspace(string[k])) {
            string[l] = string[k];
            l++;
        }
        k++;
    }
    string[l] = '\0';

    return string;
}

/**
 * \brief Esta função identifica os tokens.
 *
 * @param token, resto.
 * @returns tok.
 */
char *get_token(char *token, char **resto) {
    char *tok = malloc(sizeof(char));
    *resto = NULL;
    int i = 0;

    while (token[i] != ' ' && token[i] != '\0' && token[i] != '\n') {
            tok[i] = token[i];
            i++;
    }
    tok[i] = '\0';

    if (token[i] != '\0') {
        *resto = &token[i + 1];
    }
    return tok;
}

/**
 * \brief Esta função orquestra o funcionamento do nosso programa.
 *
 * @param s, token, alfabeto.
 * @returns s.
 */
STACK *doCase(STACK *s, char *token, DADOS *alfabeto) {
    char **resto = malloc(sizeof(char));
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
            if ((strcmp(tkn, "+") == 0)) {          // Adição
                adicao(s);
            } else if ((strcmp(tkn, "-") == 0)) {   // Subtração
                subtracao(s);
            } else if ((strcmp(tkn, "*") == 0)) {   // Multiplicação
                multiplicacao(s);
            } else if ((strcmp(tkn, "/") == 0)) {   // Divisão Inteira
                divisao(s);
            } else if ((strcmp(tkn, "(") == 0)) {   // Decrementar
                decrementa(s);
            } else if ((strcmp(tkn, ")") == 0)) {   // Incrementar
                incrementa(s);
            } else if ((strcmp(tkn, "%") == 0)) {   // Módulo
                modulo(s);
            } else if ((strcmp(tkn, "#") == 0)) {   // Exponenciação
                exponenciacao(s);
            } else if ((strcmp(tkn, "&") == 0)) {   // e_logico
                elogico(s);
            } else if ((strcmp(tkn, "|") == 0)) {   // ou_logico
                oulogico(s);
            } else if ((strcmp(tkn, "^") == 0)) {   // xor_logico
                xorlogico(s);
            } else if ((strcmp(tkn, "~") == 0)) {   // negacao_logica
                negacaologica(s);
            } else if ((strcmp(tkn, "_") == 0)) {   // Duplica elemento
                duplica(s);
            } else if ((strcmp(tkn, "@") == 0)) {   // Rodar os 3 elementos no topo da stack
                roda(s);
            } else if((strcmp(tkn, "\\") == 0)) {   // Trocar os dois elementos do topo da stack
                troca(s);
            } else if ((strcmp(tkn, ";") == 0)) {   // Pop
                pop(s);
            } else if ((strcmp(tkn, "$") == 0)) {   // Copia o n-ésimo elemento para o topo da stack, 0 é o topo da stack
                copia(s);
            } else if ((strcmp(tkn, "?") == 0)) {   //  If-Then-Else
                if_then_else(s);
            } else if ((strcmp(tkn, "e&") == 0)) {  // E com shortcut
                E_shortcut(s);
            } else if((strcmp(tkn, "e>") == 0)) {   //  Coloca o maior dos 2 valores na stack
                MaiorLogico(s);
            } else if ((strcmp(tkn, "e<") == 0)) {  //  Coloca o menor dos 2 valores na stack
                MenorLogico(s);
            } else if ((strcmp(tkn, "e|") == 0)) {  //   OU com shortcut
                OU_shortcut(s);
            } else if ((strcmp(tkn, "=") == 0)) {   // Igual
                Igual(s);
            } else if ((strcmp(tkn, "<") == 0)) {   // Menor
                Menor(s);
            } else if ((strcmp(tkn, ">") == 0)) {   // Maior
                Maior(s);
            } else if ((strcmp(tkn, "!") == 0)) {   // Não
                Nao(s);
            } else if ((strcmp(tkn, "A") == 0)) {    // Valor por omissão: 10
                push_LONG(s,alfabeto[0].celula.LONG);
            } else if ((strcmp(tkn, "B") == 0)) {    // Valor por omissão: 11
                push_LONG(s,alfabeto[1].celula.LONG);
            } else if ((strcmp(tkn, "C") == 0)) {    // Valor por omissão: 12
                push_LONG(s,alfabeto[2].celula.LONG);
            } else if ((strcmp(tkn, "D") == 0)) {    // Valor por omissão: 13
                push_LONG(s,alfabeto[3].celula.LONG);
            } else if ((strcmp(tkn, "E") == 0)) {    // Valor por omissão: 14
                push_LONG(s,alfabeto[4].celula.LONG);
            } else if ((strcmp(tkn, "F") == 0)) {    // Valor por omissão: 15
                push_LONG(s,alfabeto[5].celula.LONG);
            } else if ((strcmp(tkn, "N") == 0)) {    // Valor por omissão: '\n'
                push_CHAR(s,alfabeto[13].celula.CHAR);
            } else if ((strcmp(tkn, "S") == 0)) {    // Valor por omissão: ' '
                push_CHAR(s,alfabeto[18].celula.CHAR);
            } else if ((strcmp(tkn, "X") == 0)) {    // Valor por omissão: 0
                push_LONG(s,alfabeto[23].celula.LONG);
            } else if ((strcmp(tkn, "Y") == 0)) {    // Valor por omissão: 1
                push_LONG(s,alfabeto[24].celula.LONG);
            } else if ((strcmp(tkn, "Z") == 0)) {    // Valor por omissão: 2
                push_LONG(s,alfabeto[25].celula.LONG);
            } else if ((strcmp(tkn, "G") == 0) ||
                       (strcmp(tkn, "H") == 0) ||
                       (strcmp(tkn, "I") == 0) ||
                       (strcmp(tkn, "J") == 0) ||
                       (strcmp(tkn, "K") == 0) ||
                       (strcmp(tkn, "L") == 0) ||
                       (strcmp(tkn, "M") == 0) ||
                       (strcmp(tkn, "N") == 0) ||
                       (strcmp(tkn, "O") == 0) ||
                       (strcmp(tkn, "P") == 0) ||
                       (strcmp(tkn, "Q") == 0) ||
                       (strcmp(tkn, "R") == 0) ||
                       (strcmp(tkn, "T") == 0) ||
                       (strcmp(tkn, "U") == 0) ||
                       (strcmp(tkn, "V") == 0) ||
                       (strcmp(tkn, "W") == 0)) {   //  Coloca no topo da stack o conteúdo da
                coloca_topo(s);
            } else if ((strcmp(tkn, ",") == 0)) {   // Tamanho ou range
                range(s);
            } else if (tkn[0] == ':') {
                carrega(s, alfabeto, tkn[1]);
            } else if ((strcmp(tkn, "[") == 0)) {   // Criar um array
                char *array = get_array(token, resto);
                    push_STRING(s, array);
            } else if ((strcmp(tkn, "\"") == 0)) {
                char *string = get_string(token, resto);    // Criar uma string
                    push_STRING(s, string);
            } else if ((strcmp(tkn, "l") == 0)) {   // Leitura de linha
                lelinha(s);
            } else if ((strcmp(tkn, "i") == 0)) {   // Converte para Long
                convertLong(s);
            } else if ((strcmp(tkn, "f") == 0)) {   // Converte para Double
                convertDouble(s);
            } else if ((strcmp(tkn, "c") == 0)) {   // Converte para Char
                convertChar(s);
            }
        }
        if (*resto != NULL)
            token = *resto ;
    }
    return s;
}
