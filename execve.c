#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
	char *args[] = {"/bin/ls", "-p", NULL, NULL};
	execve(args[0], args, envp);
	printf("execve failed to run /bin/ls\n");
	(void)argc;
	(void)argv;
	return (0);
}
