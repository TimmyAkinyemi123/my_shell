#include "shell.h"

int check_exec(char *line)
{
	if (access(line, X_OK) == 0)
		return (1);
	return (0);
}
void exec_command(char *line)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *argv[] = {line, NULL};
		execve(line, argv, NULL);
		perror("execve error");
		exit(EXIT_FAILURE);
	}
	else
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
			if (wpid == -1)
			{
				perror("waitpid error");
				exit(EXIT_FAILURE);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
