#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Basic implementation of readline
    @param file: The file to read from
    @return A pointer to the line, or NULL if the end of the file is reached
*/
char *readline(FILE *file)
{
    char *line = NULL;
    char c;
    size_t len = 0;
    while ((c = (char)fgetc(file)) != '\n' && c != EOF)
    {
        line = (char *)realloc(line, len + 1);
        line[len] = c;
        len++;
    }
    if (line == NULL)
    {
        return line;
    }
    line[len] = '\0';
    return line;
}
