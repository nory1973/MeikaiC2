/* �����z��𓮓I�Ɋm�� */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x;
	int n;						/* �v�f�� */

	printf("�m�ۂ���z��̗v�f���F");
	scanf("%d", &n);

	x = calloc(n, sizeof(int));						/* �m�� */

	if (x == NULL)
		puts("�L����̊m�ۂɎ��s���܂����B");
	else {
		int i;

		for (i = 0; i < n; i++)						/* �l���� */
			x[i] = i;

		for (i = 0; i < n; i++)						/* �l��\�� */
			printf("x[%d] = %d\n", i, x[i]);

		free(x);									/* ��� */
	}

	return (0);
}
