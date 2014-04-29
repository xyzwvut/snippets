#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Find the first non-repeating character in a string ABCA -> B
 */

char
find_first_char1(const char *str)
{
    size_t len = strlen(str);
    int *ctrs;

    if (len < 1)
        return '\0';

    ctrs = malloc( sizeof(char) * len);
    if (ctrs == NULL)
        return '\0';

    /* Keep track how often a character is present */
    for (size_t i = 0; i < len; i++)
        ctrs[str[i]]++;

    /* Find the first char that occurs 1 time */
    for (size_t i = 0; i < len; i++) {
        if (ctrs[str[i]] == 1)
            return str[i];
    }

    return '\0';
}

char
find_first_char2(const char *str)
{
    for(size_t i = 0; i < strlen(str); i++) {
        if (strchr(str, str[i]) == strrchr(str, str[i]))
            return str[i];
    }

    return '\0';
}


int
main(void)
{
    char *str = "ABCAA";
    printf("String '%s'\n", str);
    printf("Method 1 '%c'\n", find_first_char1(str));
    printf("Method 2 '%c'\n", find_first_char2(str));
}
