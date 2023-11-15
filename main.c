#include "main.h"

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t nread;

    while (1)
    {
        printf("$ ");
        nread = getline(&buffer, &bufsize, stdin);
        if (nread == -1)
        {
            free(buffer);
            exit(EXIT_SUCCESS);
        }
        printf("%s", buffer);
    }
    return (0);
}
