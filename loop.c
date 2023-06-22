#include "shell.h"

void shell_loop(void)
{
	int exit_shell = 0;
	char *line;

	while (!exit_shell)
	{
		write(1, "$ ", 2);
		line = read_line();

		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		if (check_exec(line) == 1) 
			exec_command(line);
		else
			printf("Error: Executable file not found.\n");
		free(line);
	}
}
