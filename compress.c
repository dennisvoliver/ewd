#include <stdio.h>
#define SUBSLEN 5
#define SEQLEN 36
#define TRUE 1
#define FALSE 0

/* Generate all SEQLEN long sequences where
 * each SUBSLEN binary digit subsequence is unique.
 * The algorithm if very simple:
 *
 * while first subsequence is not affected by adjustment
 * 	extend
 * 	while not good
 * 		adjust
 *	if long enough
 *		print and adjust
 * adjust:
 * remove all terminal 1's
 * upgrade last digit
 *
 */
int main(void)
{
	typedef int bool;
	int d[SEQLEN + 1], length, j, k, last, dup;
	length = 1;
	/* initialize sequence */
	do {
		d[length] = 0;
		length = length + 1;
	} while (length != SUBSLEN);

	bool good;
	/* while the first subsequence is untouched */
	while (d[SUBSLEN] == 0) {
		/* produce next sequence */
		/* extend sequence */
		length = length + 1;
		d[length] = -1;
		good = FALSE;
		while (!good) {
			/* adjust */
			/* remove all terminal 1's */
			while (d[length] == 1) 
				length = length - 1;
			d[length] = d[length] + 1;

			/* set good */
			/* compare last subsequence with all */
			k = 1;
			last = length - SUBSLEN + 1;
			dup = 0;
			while (k != last) {
				/* compare the two subsequences */
				j = 0;
				while ((j < SUBSLEN) && (d[k + j] == d[last + j]))
					j = j + 1;
				/* a match is not good */
				if (j == SUBSLEN)
					dup = dup + 1;
				k = k + 1;
			}
			good = TRUE;
			if (dup > 0)
				good = FALSE;
		}

		if (length == SEQLEN) {
			/* print digits */
			k = 1;
			while (k <= length) {
				printf("%d", d[k]);
				k = k + 1;
			}
			printf("\n");


			/* adjust again */
			while (d[length] == 1) 
				length = length - 1;
			d[length] = d[length] + 1;
		}
	}
}
