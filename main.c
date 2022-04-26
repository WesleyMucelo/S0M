#include "library.h"
#include "functions.h"

int main() {

//    char line [BUFSIZ];  // A linha inserida pelo terminal
    char token [BUFSIZ]; // Tamanho da string para especificar o formado que dever ser recebida

//    if (fgets(line, BUFSIZ, stdin) != NULL) {    //Busca a linha inserida no terminal
//        while (sscanf(line, "%s %[^\n]", token, line) == 2) {
//            doCase (s, token);
//        }
    assert(fgets(token, BUFSIZ, stdin) != NULL);
    assert(token[strlen(token) - 1] == '\n');
    STACK *s = cria_stack ();
    doCase (s, token);
    imprime_stack(s);
//    printf("\n");

    free(s);
    return 0;
}
//
//    return 0;
//}
