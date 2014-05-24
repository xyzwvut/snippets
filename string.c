#include <stdio.h>

void
reverse(char s[])
{
    int i=0, j;
    int end = strlen(s);

    /*Take care that we go only till end-1 as array is indexed from 0 */
    for(i=0, j=end-1; i<j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}


int
palindrome(char s[])
{
    int i=0, j;
    int end = strlen(s);

    for(i=0, j=end-1; i<j; i++, j--) {
	    if (s[i] != s[j])
            return 0;
    }
    return 1;
}
