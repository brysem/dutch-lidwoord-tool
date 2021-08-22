#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "memory.h"
#include "http.h"

/*
 * Match string against the extended regular expression in
 * pattern, treating errors as no match.
 *
 * Return 1 for match, 0 for no match.
 */

int
match(const char *string, char *pattern)
{
    int    status;
    regex_t    re;

    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
        return(0);      /* Report error. */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        return(0);      /* Report error. */
    }
    return(1);
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        printf("ERROR: The argument \"word\" must be supplied.\n");

        return 1;
    }

    char* word = argv[1];
    char* url = concat("https://www.welklidwoord.nl/", word);
    char* data = httpGet(url);

    char* pattern = concat("De</span> ", word);
    pattern = concat(pattern, "</h1>");

    if (match(data, "Helaas, we zijn nog niet zo slim")) {
        printf("ERROR: The word \"%s\" could not found.\n", word);

        return 1;
    }

    if (match(data, pattern)) {
        printf("\033[0;32mde\033[0m %s\n", word);
    } else {
        printf("\033[0;32mhet\033[0m %s\n", word);
    }

    printf("\nSource: %s\n", url);

    free(url);
    free(data);
    free(pattern);

    return 0;
}
