CFLAGS = -Wall -Werror -Wextra -pedantic

all: fork execve

fork: fork.c
	gcc $(CFLAGS) -o fork fork.c
	./fork

execve: execve.c
	gcc $(CFLAGS) -o execve execve.c
	./execve

pipe: pipe.c
	gcc $(CFLAGS) -o pipe pipe.c
	./pipe

dup2: dup2.c
	gcc $(CFLAGS) -o dup2 dup2.c
	./dup2

clean:
	rm -f fork execve

.PHONY: all fork execve pipe dup2 clean