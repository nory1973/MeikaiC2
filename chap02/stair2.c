/* 数字文字を１桁ずつずらしながら表示（その２）*/

#include <stdio.h>

int main(void)
{
	int i;
	int x;		/* 表示する段数 */

	printf("何段表示しますか：");
	scanf("%d", &x);

	for (i = 1; i <= x; i++)
		printf("%*d\n", i, i % 10);

	return (0);
}
