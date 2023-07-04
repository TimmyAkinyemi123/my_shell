#include "shell.h"

int check_exec(char *args)
{
	if (access(args, X_OK) == 0 && access(args, F_OK) == 0)
		return (1);
	return (0);
}
void exec_command(char **args)
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
<<<<<<< HEAD
		if (check_exec(args[0]) == 1)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("execve error");
		}
		else
			 perror("Error: Executable file not found.\n");
=======
		char *argv[] = {line, NULL};
		execve(line, argv, NULL);
		perror("execve error");
>>>>>>> refs/remotes/origin/main
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
