/* ����񂯂�Q�[���i���̂Q�F���҂̎��\���j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int human;				/* �l�Ԃ̎� */
	int comp;				/* �R���s���[�^�̎� */
	int judge;				/* ���s */
	int retry;				/* ������x�H */

	srand(time(NULL));		/* �����̎�������� */

	printf("����񂯂�Q�[���J�n!!\n");

	do {
		comp = rand() % 3;		/* �R���s���[�^�̎�i0�`2�j�𗐐��Ő��� */

		do {
			printf("\n\a����񂯂�|���c(0)�O�[ (1)�`���L (2)�p�[�F");
			scanf("%d", &human);	/* �l�Ԃ̎��ǂݍ��� */
		} while (human < 0 || human > 2);

		printf("����");

		switch (comp) {				/* �R���s���[�^�̎��\�� */
		 case 0: printf("�O�[");	break;
		 case 1: printf("�`���L");	break;
		 case 2: printf("�p�[");	break;
		}

		printf("�ŁA���Ȃ���");

		switch (human) {			/* �l�Ԃ̎��\�� */
		 case 0: printf("�O�[");	break;
		 case 1: printf("�`���L");	break;
		 case 2: printf("�p�[");	break;
		}

		printf("�ł��B\n");

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
