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
	char *path = getenv("PATH");

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

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(buffer, "env") == 0)
		{
			printf("%s\n", path);
			continue;
		}
		args[0] = buffer;
		args[1] = NULL;

		if (access(args[0], F_OK) != -1)
		{
			if (fork() == 0)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					printf("Error: command not found\n");
				}
			} else
			{
				wait(NULL);
			}
		} else
		{
			printf("Error: command not found\n");
		}
	}
	return (0);
}
