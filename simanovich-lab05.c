#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 99


int new_gets(char s[], int lim)
{
    char c;
    int i;
    i = 0;
    while(((c = getchar()) != '\n') && (i < lim - 1))
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}


int is_sep(char s[], int len_s, char c)
{
    int check, i;
    check = 0;
    for (i = 0; i < len_s; i++){
        if (c == s[i]){
            check = 1;
        }
    }
    return check;
}


int main()
{
    char string[MAX_LEN], sep[MAX_LEN], matrix[MAX_LEN][MAX_LEN];
    int string_len, sep_len, i, f1, f2, last_state, current_state;

    printf("Input string:\n");
    string_len = new_gets(string, MAX_LEN);
    printf("Input seps:\n");
    sep_len = new_gets(sep, MAX_LEN);

    for (i = 0; i < string_len; i++)
    {
        f1 = is_sep(sep, sep_len, string[i]);
        f2 = is_sep(sep, sep_len, string[i + 1]);
        printf("%c", string[i]);
        last_state = 1;

        if (f1 < f2)
        // start word
        {
            current_state = 0;
            printf("\n");
        }

        if (f1 > f2)
        // finish word
        {
            current_state = 1;
            printf("\n");
        }

        last_state = current_state;
    }

}