#include <stdio.h>
#include <string.h>
#include "strrev.h"

int main(void) {
    char word1[] = "streng";
    char word2[] = "abcde";
    char word3[] = "abba";
    char word4[] = "a";
    char word5[] = "";
    char word6[] = "hej med dig";

    char *words[] = {word1, word2, word3, word4, word5, word6};
    const char *expected[] = {"gnerts", "edcba", "abba", "a", "", "gid dem jeh"};
    int failures = 0;

    for (int i = 0; i < 6; i++) {
        strrev(words[i]);
        if (strcmp(words[i], expected[i]) != 0) {
            printf("Fejl i test %d: fik '%s', forventede '%s'\n",
                   i + 1, words[i], expected[i]);
            failures++;
        }
    }

    if (failures == 0) {
        printf("Alle 6 tests af strrev bestod.\n");
        return 0;
    }

    return 1;
}
