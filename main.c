#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	while (1)
	{
		printf("Macmillian$ ");
		nread = getline(&buffer, &bufsize, stdin);
		if (nread == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (nread > 0 && buffer[nread - 1] == '\n')
			buffer[nread - 1] = '\0';
		if (access(buffer, F_OK) == 0)
			system(buffer);
		else
			printf("Command not found: %s\n", buffer);
	}
	return (0);
}
