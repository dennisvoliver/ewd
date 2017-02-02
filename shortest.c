/* implementation of Dijkstra's shortest path tree */
/* using string generation as computational model */

#include <stdio.h>
#define N 4	/* N  nodes including root */
#define INFINITE 9999999	/* no path weight must exceed this */
#define TRUE 1
#define FALSE 0
#define ROOT 1	/* root node or root */
#define GHOST 0		/* ghost node, used for initializations */

void print(int k);
void print_path(int k);
int edge[N + 1][N + 1];
int path[N + 1], prefix[N + 1], done[N + 1];
int pending, least, last, first, k;

int main(void)
{

	/* SET EDGE WEIGHTS edge[][] TO ARBITRARY VALUES */
	edge[1][3] = 4;
	edge[1][2] = 80;
	edge[1][4] = 1;
	edge[2][3] = 9;
	edge[2][4] = 2;
	edge[3][4] = 10;
	edge[3][2] = 27;
	edge[4][2] = 6;
	edge[4][3] = 5;

	/* SET PATH prefix[] TO ROOT NODE */
	/* SET PATH WEIGHTS path[] TO INFINITE */
	/* SET ALL NODES TO NOT DONE */
	k = N;
	while (k > 0)
	{	prefix[k] = ROOT;
		path[k] = INFINITE;
		done[k] = FALSE;
		k = k - 1;
	}


	path[GHOST] = INFINITE;	/* path weight of ghost is infinite */
	path[ROOT] = 0;		/* path weight of root is zero */
	done[ROOT] = TRUE;	/* root node is done */
	print_path(ROOT);		/* root node is also first path */
	last = ROOT;		/* last path printed */

	pending = N - 1;	/* nodes not done */
	while (pending > 0)
	{	/* GENERATE NEXT SHORTEST PATH */
		least = GHOST;
		k = N;
		while (k > 1)
		{	/* UPDATE PREFIX AND PATH WEIGHT */
			/* OF ALL NODES NOT PROCESSED YET */
			/* WHILE LOOKING FOR THE NODE WITH THE LEAST PATH WEIGHT */
			if (!done[k])
			{	if (path[k] > path[last] + edge[last][k])
				{	prefix[k] = last;
					path[k] = path[last] + edge[last][k];
				}
				if (path[k] < path[least])
					least = k;
			}

			k = k - 1;
		}
		last = least;
		done[last] = TRUE;
		print_path(last);

		pending = pending - 1;
	}
}

void print_path(int k)
{
	print(k);
	printf("\n");
}
void print(int k)
{
	if (k != ROOT)
		print(prefix[k]);
	printf("%d ", k);
}
