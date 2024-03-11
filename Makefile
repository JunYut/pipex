CFLAGS = -Wall -Werror -Wextra -pedantic

all: fork execve

fork: fork.c
	gcc $(CFLAGS) -o fork fork.c
	./fork

execve: execve.c
	gcc $(CFLAGS) -o execve execve.c
	./execve

clean:
	rm -f fork execve

.PHONY: all fork execve clean