/* �R���s���[�^���K��������񂯂�Q�[�� */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int human;				/* �l�Ԃ̎� */
	int comp;				/* �R���s���[�^�̎� */
	int judge;				/* ���s */
	int retry;				/* ������x�H */
	char *hd[] = {"�O�[", "�`���L", "�p�["};		/* �� */

	srand(time(NULL));		/* �����̎�������� */

	printf("����񂯂�Q�[���J�n!!\n");

	do {
		do {
			printf("\n\a����񂯂�|�� �c");
			for (i = 0; i < 3; i++)
				printf(" (%d)%s", i, hd[i]);
			printf("�F");
			scanf("%d", &human);	/* �l�Ԃ̎��ǂݍ��� */
		} while (human < 0 || human > 2);

		comp = (human + 2) % 3;		/* �R���s���[�^�͌�o���I */

		printf("����%s�ŁA���Ȃ���%s�ł��B\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;					/* ���s�𔻒� */

		switch (judge) {
		 case 0: puts("���������ł��B");		break;
		 case 1: puts("���Ȃ��̕����ł��B");	break;
		 case 2: puts("���Ȃ��̏����ł��B");	break;
		}

		printf("������x���܂����c(0)������ (1)�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	return (0);
}
