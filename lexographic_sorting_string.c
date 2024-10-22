#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for qsort (for lexicographic order)
int compareStrings(const void *a, const void *b) {
    // Cast void pointers to const char* pointers
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    // Use strcmp to compare strings
    return strcmp(str1, str2);
}

main() {
    // Array of strings to be sorted
    const char *words[] = {
        "banana", "apple", "orange", "grape", "kiwi", "pear"
    };
    int n = sizeof(words) / sizeof(words[0]);

    // Sort the array using qsort
    qsort(words, n, sizeof(const char *), compareStrings);

    // Print the sorted array
    printf("Sorted strings (lexicographically):\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return ;
}