#include "../includes/pipex.h"



#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char **parse_cmd_args(const char *str)
 {
    // This is a simple implementation. You may need to expand it to handle more complex scenarios.
    int argc = 0;
    const char *temp = str;
    bool in_quotes = false;

    // Count the number of arguments
    while (*temp) {
        if (*temp == '"') {
            in_quotes = !in_quotes;
        } else if (*temp == ' ' && !in_quotes) {
            argc++;
        }
        temp++;
    }
    argc++; // For the last argument

    // Allocate array of arguments
    char **argv = malloc((argc + 1) * sizeof(char *));
    if (!argv) {
        return NULL; // Handle memory allocation failure
    }

    int arg_index = 0;
    const char *start = str;
    in_quotes = false;

    // Parse arguments
    for (temp = str; *temp; temp++) {
        if (*temp == '"') {
            in_quotes = !in_quotes;
            start++; // Skip the quote
        } else if ((*temp == ' ' && !in_quotes) || *(temp + 1) == '\0') {
            int len = temp - start + (*(temp + 1) == '\0');
            argv[arg_index] = malloc(len + 1);
            if (!argv[arg_index]) {
                // Handle memory allocation failure
                // Don't forget to free previously allocated memory
            }
            strncpy(argv[arg_index], start, len);
            argv[arg_index][len] = '\0';
            arg_index++;
            start = temp + 1;
        }
    }

    argv[arg_index] = NULL; // Null-terminate the array
    return argv;
}
