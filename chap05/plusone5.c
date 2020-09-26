/* �v���X�����g���[�j���O�i�����̐��l���L�����ĂP���������l����́j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define LEVEL_MIN	2				/* �ŏ����x���i���l�̌��j*/
#define LEVEL_MAX	6				/* �ő僌�x���i���l�̌��j*/

/*--- x�~���b�o�߂���̂�҂� ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* �G���[ */
			return (0);
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x); 
	return (1);
}

int main(void)
{
	int 	i, stage;
	int 	max_stage;					/* �X�e�[�W�� */
	int 	level;						/* ���x�� */
	int 	success;					/* ���� */
	int 	*score;						/* �S�X�e�[�W�̐��� */
	clock_t	start, end;					/* �J�n�����E�I������ */

	srand(time(NULL));					/* �����̎�������� */

	printf("�v���X�����g���[�j���O�J�n!!\n");
	printf("�Q���̐��l���L�����܂��B\n");
	printf("�P���������l����͂��Ă��������B\n");

	do {
		printf("���킷�郌�x���i%d�`%d�j�F", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	do {
		printf("�g���[�j���O�񐔁F");
		scanf("%d", &max_stage);
	} while (max_stage <= 0);

	score = calloc(max_stage, sizeof(int));

	success = 0;
	start = clock();
	for (stage = 0; stage < max_stage; stage++) {
		int no[LEVEL_MAX];					/* �L�����鐔 */
		int x[LEVEL_MAX];					/* �ǂݍ��񂾒l */
		int seikai = 0;						/* ���̃X�e�[�W�ł̐��� */

		printf("\n��%d�X�e�[�W�J�n!!\n", stage + 1);

		for (i = 0; i < level; i++) {		/* level���� */
			no[i] = rand() % 90 + 10;		/* 10�`99�̗����𐶐����� */
			printf("%d ", no[i]);			/* �\������ */
		}
		fflush(stdout);
		sleep(300 * level);					/* 0.30�~level�b�҂��� */
		printf("\r%*s\r", 3 * level, "");	/* �������� */

		for (i = 0; i < level; i++) {		/* �𓚂�ǂݍ��� */
			printf("%d�Ԗڂ̐��F", i + 1);
			scanf("%d", &x[i]);
		}

		for (i = 0; i < level; i++) {		/* ����𔻒�E�\�� */
			if (x[i] != no[i] + 1)
				printf("�~ ");
			else {
				printf("�� ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++)			/* ������\�� */
			printf("%2d ", no[i]);

		printf(" �c %d�����ł��B\n", seikai);
		score[stage] = seikai;				/* �X�e�[�W�̐��𐔂��L�^ */
		success += seikai;					/* �S�̂̐��𐔂��X�V */
	}
	end = clock();

	printf("%d��%d�������܂����B\n", level * max_stage, success);

	for (stage = 0; stage < max_stage; stage++)
		printf("��%2d�X�e�[�W�F%d\n", stage + 1, score[stage]);

	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	free(score);

	return (0);
}
