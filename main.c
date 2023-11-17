#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

extern char **environ; /* Declare the environment variable array */

void print_environment(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

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

		if (strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else if
			(strcmp(args[0], "env") == 0)
			{
				print_environment();
			}
		else
		{
			/* Handle other commands (search in PATH, execute, etc.) */
			/* ... */
			printf("Error: command not found\n");
		}
	}
	return (0);
}
