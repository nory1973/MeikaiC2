/* �����������P�������炵�Ȃ���\���i���̂Q�j*/

#include <stdio.h>

int main(void)
{
	int i;
	int x;		/* �\������i�� */

	printf("���i�\�����܂����F");
	scanf("%d", &x);

	for (i = 1; i <= x; i++)
		printf("%*d\n", i, i % 10);

	return (0);
}
