#include "main.h"

/**
 * read_input -  Function to read a line of input
 *
 * Return: line
 */

char *read_input()
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);

	return (line);
}

/**
 * execute_command - Function to execute a command
 *
 * @command: input char
 * Return: void
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		char *args[] = {command, NULL};

		execve(command, args, NULL);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
	else if
		(pid > 0)
		{
			/* Parent process */
			wait(&status);
		}
	else
	{
		perror("Error forking process");
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *input;
	char *command;

	while (1)
	{
		printf("Mac_Millian$ "); /* Display prompt */
		input = read_input();    /* Read user input */

		/* Remove newline character */
		input[strcspn(input, "\n")] = '\0';
		/* Execute the command */
		command = strtok(input, " ");

		if (command != NULL)
		{
			execute_command(command);
		}
		else
		{
			printf("Invalid command. Please try again.\n");
		}

		free(input);
	}
	return (0);
}
