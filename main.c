#include "library.h"
#include "functions.h"


int main() {

    char token [BUFSIZ]; // recebe a linha com os tokens

    assert(fgets(token, BUFSIZ, stdin) != NULL);
    assert(token[strlen(token) - 1] == '\n');
    STACK *s = cria_stack ();
    DADOS alfabeto[26];

    DADOS A;
    A.type = LONG;
    A.celula.LONG = 10;
    alfabeto[0] = A;

    DADOS B;
    B.type = LONG;
    B.celula.LONG = 11;
    alfabeto[1] = B;

    DADOS C;
    C.type = LONG;
    C.celula.LONG = 12;
    alfabeto[2] = C;

    DADOS D;
    D.type = LONG;
    D.celula.LONG = 13;
    alfabeto[3] = D;

    DADOS E;
    E.type = LONG;
    E.celula.LONG = 14;
    alfabeto[4] = E;

    DADOS F;
    F.type = LONG;
    F.celula.LONG = 15;
    alfabeto[5] = F;

    DADOS N;
    N.type = CHAR;
    N.celula.CHAR = '\n';
    alfabeto[13] = F;

    DADOS S;
    S.type = CHAR;
    S.celula.CHAR = ' ';
    alfabeto[18] = S;

    DADOS X;
    X.type = LONG;
    X.celula.LONG = 0;
    alfabeto[23] = X;

    DADOS Y;
    Y.type = LONG;
    Y.celula.LONG = 1;
    alfabeto[24] = Y;

    DADOS Z;
    Z.type = LONG;
    Z.celula.LONG = 2;
    alfabeto[25] = Z;

    doCase (s, token, alfabeto);
    imprime_stack(s);

    free(s);
    return 0;
}
