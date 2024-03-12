# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

#include <stdio.h>

int main(void)
{
	FILE *file = fopen("test.txt", "r");
	FILE *file1 = fopen("test1.txt", "w");
	char c;

	while ((c = fgetc(file)) != EOF)
		printf("%c", c);

	printf("\n----------------\n");

	rewind(file);
	dup2(fileno(file1), fileno(stdout)); // Redirect stdout to file1
	while ((c = fgetc(file)) != EOF)
		printf("%c", c);

	fclose(file);
	fclose(file1);
	return 0;
}
