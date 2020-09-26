/* 数字文字を１桁ずつずらしながら表示（その１）*/

#include <stdio.h>

int main(void)
{
	int i, j;
	int x;		/* 表示する段数 */

	printf("何段表示しますか：");
	scanf("%d", &x);

	for (i = 1; i <= x; i++) {
		for (j = 1; j < i; j++)
			putchar(' ');	
		printf("%d\n", i % 10);
	}

	return (0);
}
