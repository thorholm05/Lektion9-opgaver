#include <stdio.h>
#include <string.h>
#include "plural.h"

#define TEST_COUNT 11

int main(void) {
    // Forventede flertalsformer ud fra opgavens tre regler.
    const char *singular[TEST_COUNT] = {
        "chair", "dairy", "boss", "circus", "fly",
        "dog", "church", "clue", "dish", "", "brush"
    };
    const char *expected[TEST_COUNT] = {
        "chairs", "dairies", "bosses", "circuses", "flies",
        "dogs", "churches", "clues", "dishes", "", "brushes"
    };
    char actual[40];
    int failures = 0;

    for (int i = 0; i < TEST_COUNT; i++) {
        make_plural(singular[i], actual);

        if (strcmp(actual, expected[i]) != 0) {
            printf("Fejl: '%s' gav '%s', forventede '%s'\n",
                   singular[i], actual, expected[i]);
            failures++;
        }
    }

    if (failures == 0) {
        printf("Alle %d tests af make_plural bestod.\n", TEST_COUNT);
        return 0;
    }

    return 1;
}
