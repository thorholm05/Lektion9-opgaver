#include "strrev.h"
#include <string.h>

// Byt det første og sidste tegn, derefter de næste to osv.
char *strrev(char *str) {
    size_t length = strlen(str);

    for (size_t i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    return str;
}
