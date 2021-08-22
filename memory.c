#include <stdlib.h>
#include <string.h>

char* concat(const char *str1, const char *str2)
{
    char *result = malloc(strlen(str1) + strlen(str2) + 1); // +1 for the null-terminator

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}
