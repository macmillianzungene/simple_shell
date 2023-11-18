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
	char *args[2];

	while (1)
	{
		printf("Macmillian$ ");
		nread = getline(&buffer, &bufsize, stdin);

		if (nread == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[strcspn(buffer, "\n")] = 0;
		args[0] = buffer;
		args[1] = NULL;

		if (execve(args[0], args, NULL) == -1)
		{
			printf("Error: command not found\n");
		}
	}
	return (0);
}
