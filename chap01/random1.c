/* �����𐶐��i���̂P�j*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int retry;			/* ������x�H */

	printf("���̏����n�ł�0�`%d�̗����������ł��܂��B\n", RAND_MAX);

	do {
		printf("\n����%d�𐶐����܂����B\n", rand());

		printf("������x�H �c (0)������ (1)�͂��F");
		scanf("%d", &retry);

	} while (retry == 1);

	return (0);
}
