/* �����������P�������炵�Ȃ���\���i���̂P�j*/

#include <stdio.h>

int main(void)
{
	int i, j;
	int x;		/* �\������i�� */

	printf("���i�\�����܂����F");
	scanf("%d", &x);

	for (i = 1; i <= x; i++) {
		for (j = 1; j < i; j++)
			putchar(' ');	
		printf("%d\n", i % 10);
	}

	return (0);
}
