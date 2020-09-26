/* 配列の要素数と各要素の値を表示 */

#include <stdio.h>

int main(void)
{
	int i;
	int a[] = {1, 2, 3, 4, 5};
	int na = sizeof(a) / sizeof(a[0]);	  /* 要素数 */

	printf("配列aの要素数は%dです。\n", na);

	for (i = 0; i < na; i++)
		printf("a[%d] = %d\n", i, a[i]);

	return (0);
}
