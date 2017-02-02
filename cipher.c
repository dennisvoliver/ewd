#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int c;
	if (argc != 2) {
		fprintf(stderr, "usage: %s <seed>\n", argv[0]);
		exit(-1);
	}
	int seed = atoi(argv[1]);
	while ((c=getchar()) != EOF)
		putchar(c + seed);
}
