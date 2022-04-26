#include "library.h"
#include "functions.h"

int main() {

    char token [BUFSIZ];

    assert(fgets(token, BUFSIZ, stdin) != NULL);
    assert(token[strlen(token) - 1] == '\n');
    STACK *s = cria_stack ();
    doCase (s, token);
    imprime_stack(s);


    free(s);
    return 0;
}
