# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int main(void)
{
	int file = open("test.txt", O_RDONLY);
	int file1 = open("test1.txt", O_WRONLY);
	int fd[2];

	pipe(fd);

	// Reading
	dup2(file, fd[1]);
	off_t file_size = lseek(file, 0, SEEK_END) - lseek(file, 0, SEEK_SET) + 1;
	char buffer[file_size];
	read(fd[0], buffer, file_size);
	buffer[file_size] = '\0';

	// Writing
	dup2(file1, fd[0]);
	write(fd[1], buffer, file_size);

	close(file);
	close(file1);
}
