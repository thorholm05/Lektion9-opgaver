#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strrev.h"

int main(void) {
    const char original[] = "streng";

    // Alloker hukommelse til ordet og det afsluttende '\0'.
    char *word = malloc((strlen(original) + 1) * sizeof(char));

    if (word == NULL) {
        printf("Hukommelsesallokering fejlede.\n");
        return 1;
    }

    // Kopier ordet til den allokerede hukommelse.
    strcpy(word, original);

    // Vend tegnene i det samme array.
    strrev(word);

    printf("Original: %s\n", original);
    printf("Omvendt: %s\n", word);

    // Frigiv den allokerede hukommelse.
    free(word);

    return 0;
}
