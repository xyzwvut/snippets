#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Find the first non-repeating character in a string ABCA -> B
 *
 * - Function signature?
 * - Trade-offs in return value (char vs. error code vs. position)
 * - What type/level of parameter validation?
 * - Which testing input NULL, "\0", ...
 * - UCHAR_MAX vs. 256 vs. 1 << sizeof(char) * 8
 * - Space vs. Time trade-off?
 * - bigOh Notation O(n)
 * - Extensions
 *   - Input set
 *   - Generic?
 *
 * TODO:
 * - sort + walk through?
 * - no memory overhead O(n^2)
 * - assert()?
 */

char
find_first_char1(const char *str)
{
    size_t len;
    int *ctrs;

    if (str == NULL)
      return '\0';

    len = strlen(str);

    ctrs = malloc(sizeof(int) * UCHAR_MAX);
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
    if (str == NULL)
        return '\0';

    for(size_t i = 0; i < strlen(str); i++) {
        if (strchr(str, str[i]) == strrchr(str, str[i]))
            return str[i];
    }

    return '\0';
}


int
main(void)
{
    char *str = NULL;
    printf("String '%s'\n", str);
    printf("Method 1 '%c'\n", find_first_char1(str));
    printf("Method 2 '%c'\n", find_first_char2(str));

    str = "ABCAA";
    printf("String '%s'\n", str);
    printf("Method 1 '%c'\n", find_first_char1(str));
    printf("Method 2 '%c'\n", find_first_char2(str));
}
