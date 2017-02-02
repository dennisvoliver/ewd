#include <stdio.h>
#define N 8
int row[N];
int out[N];

/* There are only 15 up an down diagonals,
 * The beauty of this solution is its
 * ingenius characterization of each diagonal
 * using the sum and difference of the row and column
 * It provides a cheap way to determine
 * whether a diagonal is free or not.
 */
int up[N + N - 1];
int down[N + N - 1];
void plantnode(int x);
void print(void);
void check(void);

/* the eigth queens problem:
 * produce a configuration 
 * of eight queens on an 8x8 chess board
 * such that no two queens can take each other
 * x is the column number and row[x] is the row number 
 * of each square.
 * Each configuration is represented in the array row[]
 */
int main(void)
{
	int j = 0;

	/* initialize squares */
	while (j < N) {
		row[j] = out[j] = 0;
		j++;
	}
	j = 0;
	while (j < N + N - 1) {
		up[j] = down[j] = 0;
		j++;
	}
	plantnode(0);
}

void plantnode(int x)
{
	if (x == N) {
		print();
		return;
	}
	row[x] = 0;
	/* try out each free square on column x */
	while (row[x] < N) {
		/* if row and column are free */
		if (out[row[x]] == 0
			/* and up and down diagonals are free */
			&& up[row[x] - x + 7] == 0
			&& down[row[x] + x] == 0) {

			/* unfree them for protection*/
			out[row[x]] = 1;
			up[row[x] - x + 7] = 1;
			down[row[x] + x] = 1;

			/* and put our queen there */
			plantnode(x + 1);

			/* free them again so they can be used by the next columns */
			out[row[x]] = 0;
			up[row[x] - x + 7] = 0;
			down[row[x] + x] = 0;
		}
		row[x]++;
	}
}

	



void print(void)
{
	int i = 0;
	while (i < N) {
		printf("%d ", row[i]);
		i++;
	}
	printf("\n");
}
