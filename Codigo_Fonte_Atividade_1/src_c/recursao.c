#include "recursao.h"
#include <string.h>

int recursao(const char *str, char alvo) {

    if (*str == '\0') {
        return 0;
    }

    
    int contador = 0;
    if (*str == alvo) {
        contador = 1;
    }

    return contador + recursao(str + 1, alvo);
}