/* �����ăQ�[���i���̂T�F���͉񐔂ɐ�����݂���j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int no;					/* �ǂݍ��񂾒l */
	int ans;				/* ���Ă����鐔 */
	int max_stage = 10;		/* �ő���͉� */
	int remain = max_stage;	/* �c�艽����͂ł��邩�H */

	srand(time(NULL));		/* �����̎�������� */
	ans = rand() % 1000;	/* 0�`999�̗����𐶐� */

	printf("0�`999�̐����𓖂ĂĂ��������B\n\n");

	do {
		printf("�c��%d��B�������ȁF", remain);
		scanf("%d", &no);
		remain--;			/* �c��񐔂��f�N�������g */

		if (no > ans)
			printf("\a�����Ə�������B\n");
		else if (no < ans)
			printf("\a�����Ƒ傫����B\n");
	} while (no != ans && remain > 0);

	if (no != ans)
		printf("\a�c�O�B������%d�ł����\n", ans);
	else {
		printf("�����ł��B\n");
		printf("%d��œ�����܂����ˡ\n", max_stage - remain);
	}

	return (0);
}
