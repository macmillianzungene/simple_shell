#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char cmd[MAX_CMD_LEN];
	char *argv[MAX_ARGS];
	char *path = "/bin/";
	char progpath[20];
	int argc;

	while (1)
	{
		printf("Macmillian$ ");
		fgets(cmd, sizeof(cmd), stdin);

		/* Remove trailing newline character */
		if (cmd[strlen(cmd) - 1] == '\n')
		{
			cmd[strlen(cmd) - 1] = '\0';
		}

		/* Handle EOF */
		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}

		/* Prepare arguments for execve */
		argv[0] = cmd;
		argv[1] = NULL;

		/* Create program path */
		strcpy(progpath, path);
		strcat(progpath, cmd);

		/* Execute the command */
		if (execve(progpath, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
	return (0);
}
