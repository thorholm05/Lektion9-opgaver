#include <stdio.h>
#include "plural.h"

#define WORD_COUNT 9
#define MAX_LENGTH 30

int main(void) {
    // De ni engelske navneord fra opgaven.
    const char nouns[WORD_COUNT][MAX_LENGTH] = {
        "chair", "dairy", "boss", "circus", "fly",
        "dog", "church", "clue", "dish"
    };
    char plural[MAX_LENGTH];

    // Udskriv hvert ord i ental og flertal.
    for (int i = 0; i < WORD_COUNT; i++) {
        make_plural(nouns[i], plural);
        printf("%-10s -> %s\n", nouns[i], plural);
    }

    return 0;
}
