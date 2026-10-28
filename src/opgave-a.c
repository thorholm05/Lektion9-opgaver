#include <stdio.h>
#include <stdlib.h>
#include "plural.h"

#define WORD_COUNT 9
#define MAX_LENGTH 30

int main(void) {
    // De ni engelske navneord fra opgaven.
    const char nouns[WORD_COUNT][MAX_LENGTH] = {
        "chair", "dairy", "boss", "circus", "fly",
        "dog", "church", "clue", "dish"
    };

    // Alloker hukommelse til navneordet i flertal.
    char *plural = malloc(MAX_LENGTH * sizeof(char));

    if (plural == NULL) {
        printf("Hukommelsesallokering fejlede.\n");
        return 1;
    }

    // Udskriv hvert ord i ental og flertal.
    for (int i = 0; i < WORD_COUNT; i++) {
        make_plural(nouns[i], plural);
        printf("%-10s -> %s\n", nouns[i], plural);
    }

    // Frigiv den allokerede hukommelse.
    free(plural);

    return 0;
}
