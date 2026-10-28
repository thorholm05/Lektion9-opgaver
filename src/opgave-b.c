#include <stdio.h>
#include <string.h>
#include "strrev.h"

#define MAX_LENGTH 100

int main(void) {
    char word[MAX_LENGTH] = "streng";
    char original[MAX_LENGTH];

    // Gem det oprindelige ord, så begge versioner kan udskrives.
    strcpy(original, word);

    // Vend tegnene i det samme array.
    strrev(word);

    printf("Original: %s\n", original);
    printf("Omvendt: %s\n", word);

    return 0;
}
