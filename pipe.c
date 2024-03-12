#include <unistd.h>
#include <stdio.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    printf("Read file descriptor: %d\n", fd[0]);
    printf("Write file descriptor: %d\n", fd[1]);

    // You can now use fd[0] to read from the pipe and fd[1] to write to the pipe.
	write(fd[1], "hello world\n", 12);
	char buffer[12];
	read(fd[0], buffer, 12);
	printf("Read from pipe: %s", buffer);

    close(fd[0]);
    close(fd[1]);

    return 0;
}
