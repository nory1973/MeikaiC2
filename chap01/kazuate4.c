/* �����ăQ�[���i���̂S�F���Ă����鐔��0�`999�̗����j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int no;		/* �ǂݍ��񂾒l */
	int ans;	/* ���Ă����鐔 */

	srand(time(NULL));		/* �����̎�������� */
	ans = rand() % 1000;	/* 0�`999�̗����𐶐� */

	printf("0�`999�̐����𓖂ĂĂ��������B\n\n");

	do {
		printf("�������ȁF");
		scanf("%d", &no);

		if (no > ans)
			printf("\a�����Ə�������B\n");
		else if (no < ans)
			printf("\a�����Ƒ傫����B\n");
	} while (no != ans);					/* ������܂ŌJ��Ԃ� */

	printf("�����ł��B\n");

	return (0);
}
