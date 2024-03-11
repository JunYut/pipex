#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	pid_t pid;
	pid = fork();
	if (pid == 0) printf("---------------------------------------------------------------\n");
	printf("pid = %d\n", pid);
	if (pid == 0)
	{
		char *args[] = {"/bin/echo", "hello world", NULL};
		execve(args[0], args, envp);
	}
	else
	{
		printf("I am the parent\n");
	}
	return (0);
}
