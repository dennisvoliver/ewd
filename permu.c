#include <stdio.h>
#define N 8
int pos[N + 1];
int out[N + 1];
void plantnode(int x);
void print(void);
int main(void)
{
	int j = 0;
	int i = 0;
	while (j <= N) {
		out[j] = 0;
		pos[i] = i;
		j++;
		i++;
	}
	plantnode(1);
}

void plantnode(int x)
{
	if (x > N) {
		print();
		return;
	}
	pos[x] = 1;
	while (pos[x] <= N) {
		if (out[pos[x]] == 0) {
			out[pos[x]] = 1;
			plantnode(x + 1);
			out[pos[x]] = 0;
		}
		pos[x]++;
	}
}


void print(void)
{
	int i = 1;
	while (i <= N) {
		printf("%d ", pos[i]);
		i++;
	}
	printf("\n");
}
