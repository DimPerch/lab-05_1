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
    char s_main[MAX_LEN], s_sep[MAX_LEN];
    int len_main, len_sep, maximum, last_word_index, i, f1, f2, result, count, max_count; 

    printf("Input string of text:\n");
    len_main = new_gets(s_main, MAX_LEN);

    printf("Input len of seps' string:\n");
    len_sep = new_gets(s_sep, MAX_LEN);

    maximum = 0;
    result = 0;
    last_word_index = 0;
    count = 0;

    // find the first word
    while (f1 == 1)
    {
        last_word_index += 1;
        f1 = is_sep(s_sep, len_sep, s_main[last_word_index]);
    }

    // main find
    for (i = last_word_index; i <= len_main + 1; i++)
    {
        f1 = is_sep(s_sep, len_sep, s_main[i]);
        f2 = is_sep(s_sep, len_sep, s_main[i + 1]);
        // if the end of word is find
        if (f1 == 0 && (f2 == 1 || i + 1 == len_main))
        {
            count += 1;
            // if new word is longer
            if (i - last_word_index >= maximum)
            {
                maximum = i - last_word_index;
                result = last_word_index;
                max_count = count;
            }
        }
        // if the start of word is find
        if (f1 == 1 && f2 == 0)
        {
            last_word_index = i + 1;
        }
    }

    printf("The result of program:\nLonest word is: ");
    for (i = result; i <= result + maximum; i++){
        printf("%c", s_main[i]);
    }
    printf(". It have number %i\n", max_count);

    return 0;
}