#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 500


int is_sep(char a, char* sep)
{
    int i,key;
    key = 0;
    for (i=0;i<strlen(sep);i++)
    {
        if (a == sep[i])
        {
            key = 1;
        }
    }
    return key;
}

int main()
{
    char string[MAXLEN],sep[MAXLEN],words[MAXLEN][MAXLEN],sepstr[MAXLEN][MAXLEN];
    int i,chr[MAXLEN],count,l,l2,flag,j;
    count = 0;
    l = 0;
    l2 = 0;
    flag = 0;
    puts("Enter your string:");
    fgets(string,MAXLEN,stdin);
    puts("Enter separator string:");
    fgets(sep,MAXLEN,stdin);
    string[strlen(string) - 1] = '\0';
    for (i=0;i<strlen(string);i++)
    {
        if (((is_sep(string[i-1],sep) == 1) || (i == 0)) && (is_sep(string[i],sep) != 1))
        {
            l = 0;
            flag = 1;
            l2 = 0;
        }
        if (flag == 1)
        {
            words[count][l] = string[i];
            l += 1;
        }
        else
        {
            sepstr[count-1][l2] = string[i];
            l2 += 1;
        }
        if (((is_sep(string[i+1],sep) == 1) || (i == strlen(string) - 1)) && (is_sep(string[i],sep) != 1))
        {
            chr[count] = (int)toupper(words[count][0]);
            count += 1;
            flag = 0;
        }
    }
    for (i=0;i<count-1;i++)
    {
        for (j=i+1;j<count;j++)
        {
            if (chr[i] == chr[j])
            {
                chr[i] = '\0';
            }
            if (chr[i] > chr[j])
            {
                chr[i] = chr[i] + chr[j];
                chr[j] = chr[i] - chr[j];
                chr[i] = chr[i] - chr[j];
            }
        }
    }
    l = 0;
    for (i=0;i<count;i++)
    {
        for (j=0;j<count;j++)
        {
            if (chr[i] == (int)words[j][0])
            {
                printf("%s",words[j]);
                printf("%s",sepstr[l]);
                l += 1;
            }
        }
        for (j=0;j<count;j++)
        {
            if ((chr[i] == (int)toupper(words[j][0])) && (chr[i] != (int)words[j][0]))
            {
                printf("%s",words[j]);
                printf("%s",sepstr[l]);
                l += 1;
            }
        }
    }
    return 0;
}
