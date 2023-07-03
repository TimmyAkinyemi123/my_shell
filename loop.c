#include "shell.h"

void shell_loop(void)
{
	char *line;
	char **args;

	while (1)
	{
		write(1, "$ ", 2);
		line = read_line();

		if (line[0] == '\0')
		{
			free(line);
			continue;
		}

		args = tokenize_input(line);
		exec_command(args);
		
		free(args);
		free(line);
	}
}
