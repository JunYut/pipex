# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int main(void)
{
	int file = open("test1.txt", O_WRONLY);
	int fd[2];

	pipe(fd);

	// Writing
	dup2(file, fd[1]);
	write(fd[1], "hello world", 11);

	// Reading
}
