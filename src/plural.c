#include "plural.h"
#include <string.h>

// Omdanner et engelsk navneord fra ental til flertal.
void make_plural(const char singular[], char plural[]) {
    size_t length = strlen(singular);

    // Kopier først ordet, så vi ikke ændrer på originalen.
    strcpy(plural, singular);

    if (length == 0) {
        return;
    }

    // Regel 1: Erstat 'y' med "ies".
    if (plural[length - 1] == 'y') {
        plural[length - 1] = '\0';
        strcat(plural, "ies");
    }
    // Regel 2: Tilføj "es" efter 's', "ch" eller "sh".
    else if (plural[length - 1] == 's' ||
             (length >= 2 && strcmp(plural + length - 2, "ch") == 0) ||
             (length >= 2 && strcmp(plural + length - 2, "sh") == 0)) {
        strcat(plural, "es");
    }
    // Regel 3: Tilføj ellers "s".
    else {
        strcat(plural, "s");
    }
}
