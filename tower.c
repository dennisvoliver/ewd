#include <stdio.h>
#include <stdlib.h>


/* towers of Hanoi */
/* prints the moves necessary to transfer all N disks from pole A to B */
/* the output has been tested on five 'real' disks and it behaves accordingly */
/* God, I love this thing */
void movedisk(int from, int to);
int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <disks>\n", argv[0]);
		exit(-1);
	}

	const int N = atoi(argv[1]);

	/* stack */
	int s[4 * 2 * (N - 1)];

	/* stack index */
	int i = 1;

	enum poles {A, B, C};

	/* push initial action */
	i = i + 3;
	s[i] = N;
	s[i - 1] = A;
	s[i - 2] = B;
	s[i - 3] = C;


	do {
		/* if top is atomic */
		if (s[i] == 1) {
			/* execute */
			movedisk(s[i - 1], s[i - 2]);
			i = i - 4;
		} else {
			/* expand */

			/* movetower(k - 1, from, buffer, to) */
			s[i + 8] = s[i] - 1;
			s[i + 7] = s[i - 1];
			s[i + 6] = s[i - 3];
			s[i + 5] = s[i - 2];


			/* movetower(1, from, to, buffer) */
			s[i + 4] = 1;
			s[i + 3] = s[i - 1];
			s[i + 2] = s[i - 2];
			s[i + 1] = s[i - 3];
	
			/* movetower(k - 1, buffer, to, from */
			s[i] = s[i + 8];
			s[i - 1] = s[i + 6];
			s[i - 2] = s[i + 5];
			s[i - 3] = s[i + 7];

			i = i + 8;
		}
	/* while stack is not empty */
	} while (i != 0);
}

void movedisk(int from, int to)
{
	printf("%c %c\n", from + 'A', to + 'A');
}

