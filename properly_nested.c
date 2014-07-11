#include <assert.h>
#include <stdio.h>
#include <string.h>

/*
 * Return true if the input string contains
 * a properly nested sequence of braces
 */
int
properly_nested(const char *str)
{
    /* Remove non brace characters */
    const char *s = str;
    int level = 0;
    size_t idx;

    for (idx = 0; idx < strlen(str); idx++) {
        switch (str[idx]) {
        case '(' :
            level++;
            break;
        case ')' :
            level--;
            if (level < 0)
                goto exit;
            break;
        default:
            break;
        }
    }
exit:
    if (level == 0) {
        printf("All good\n");
    } else {
        printf("Braces error at position %zd\n", idx);
    }

    return !!level;
}


int
main(void)
{
    char *p1 = "()";
    char *p2 = "(())";
    char *p3 = "(()())";
    char *p4 = "(n)";
    char *p5 = "n";

    char *p6 = "(";
    char *p7 = "())";
    char *p8 = ")()";
    char *p9 = "nn)()";

    /* Expected passed */
    assert(properly_nested(p1));
    assert(properly_nested(p2));
    assert(properly_nested(p3));
    assert(properly_nested(p4));
    assert(properly_nested(p5));

    /* Expected failed */
    assert(!properly_nested(p6));
    assert(!properly_nested(p7));
    assert(!properly_nested(p9));

    return 0;
}

