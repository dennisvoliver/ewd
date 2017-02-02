#include <stdio.h>
#include <string.h>

typedef int boolean;
typedef char obj;
void invert(boolean *v);
void swap(obj *a, int left, int right);
int part(obj *a, int left, int right);
void qsort(obj *a, int left, int right);
#define TRUE 1
#define FALSE 0

int main(void)
{
	char s[] = "hello world";
	qsort(s, 0, strlen(s) - 1);
	printf("%s\n", s);
}

void qsort(obj *a, int left, int right)
{
	if (left >= right)
		return;
	int border;
	border = part(a, left, right);
	qsort(a, left, border - 1);
	qsort(a, border + 1, right);
}

int part(obj *a, int left, int right)
{
	int i, j, up;
	i = left;
	j = right;
	up = TRUE;
	while (i < j) {
		if (a[i] > a[j]) {
			swap(a, i, j);
			invert(&up);
		}
		if (up)
			i = i + 1;
		else
			j = j - 1;
	}
	return i;
}

void swap(obj *a, int left, int right)
{

	int tmp = a[left];
	a[left] = a[right];
	a[right] = tmp;
}

void invert(boolean *v)
{
	if (*v)
		*v = FALSE;
	else
		*v = TRUE;
}

