#include "defination.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *getfield(char *line, int num) // Traversing or Tokenizing a ':' seperated String
{
    char *tok;
    for (tok = strtok(line, ":");
         tok && *tok;
         tok = strtok(NULL, ":\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int str2int(char *s) // String -> number converter
{
    int i, n;
    for (n = 0, i = 0; s[i] != '\0'; i++)
        n = n * 10 + (s[i] - '0');
    return n;
}
char *concat(const char *s1, const char *s2) // UDF to concat because whynot?
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}