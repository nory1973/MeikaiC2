/* ����񂯂�Q�[���i���̂S�F�֐��ɕ����^���т�\���j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int human;		/* �l�Ԃ̎� */
int comp;		/* �R���s���[�^�̎� */
int win_no;		/* �������� */
int lose_no;	/* �������� */
int draw_no;	/* ������������ */

char *hd[] = {"�O�[", "�`���L", "�p�["};		/* �� */

/*--- �������� ---*/
void initialize(void)
{
	win_no  = 0;		/* �������� */
	lose_no = 0;		/* �������� */
	draw_no = 0;		/* ������������ */

	srand(time(NULL));	/* �����̎�������� */

	printf("����񂯂�Q�[���J�n!!\n");
}

/*--- ����񂯂���s�i��̓Ǎ��݁^�����j ---*/
void jyanken(void)
{
	int i;

	comp = rand() % 3;		/* �R���s���[�^�̎�i0�`2�j�𗐐��Ő��� */

	do {
		printf("\n\a����񂯂�|�� �c");
		for (i = 0; i < 3; i++)
			printf(" (%d)%s", i, hd[i]);
		printf("�F");
		scanf("%d", &human);		/* �l�Ԃ̎��ǂݍ��� */
	} while (human < 0 || human > 2);
}

/*--- ���^���^���������񐔂��X�V ---*/
void count_no(int result)
{
	switch (result) {
	 case 0: draw_no++;	 break;						/* �������� */
	 case 1: lose_no++;	 break;						/* ���� */
	 case 2: win_no++;   break;						/* ���� */
	}
}

/*--- ���茋�ʂ�\�� ---*/
void disp_result(int result)
{
	switch (result) {
	 case 0: puts("���������ł��B");	   break;	/* �������� */
	 case 1: puts("���Ȃ��̕����ł��B");   break;	/* ���� */
	 case 2: puts("���Ȃ��̏����ł��B");   break;	/* ���� */
	}
}

/*--- �Ē��킷�邩���m�F ---*/
int confirm_retry(void)
{
	int x;

	printf("������x���܂����c(0)������ (1)�͂��F");
	scanf("%d", &x);

	return (x);
}

int main(void)
{
	int judge;				/* ���s */
	int retry;				/* ������x�H */

	initialize();							/* �������� */

	do {
		jyanken();							/* ����񂯂���s */

		/* �R���s���[�^�Ɛl�Ԃ̎��\�� */
		printf("����%s�ŁA���Ȃ���%s�ł��B\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;		/* ���s�𔻒� */

		count_no(judge);					/* ���^���^���������񐔂��X�V */

		disp_result(judge);					/* ���茋�ʂ�\�� */

		retry = confirm_retry();			/* �Ē��킷�邩���m�F */

	} while (retry == 1);

	printf("%d��%d�s%d�����ł����B\n", win_no, lose_no, draw_no);

	return (0);
}
