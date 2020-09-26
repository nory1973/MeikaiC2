/* �v���X�����g���[�j���O�i�L�����������̐��l�ɂP���������l����́j
		 �| �Ō��MAX_RECORD�X�e�[�W�̐��𐔂�\�� �|				*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define LEVEL_MIN	 2				/* �ŏ����x���i���l�̌��j*/
#define LEVEL_MAX	 5				/* �ő僌�x���i���l�̌��j*/
#define	MAX_RECORD	10				/* �|�C���g���L�^����X�e�[�W�� */

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
	int 	i, j, stage, stage2;
	int 	level;						/* ���x�� */
	int 	success;					/* ���� */
	int 	point[MAX_RECORD];			/* �|�C���g */
	int 	retry;						/* ������x�H */
	clock_t	start, end;					/* �J�n�����E�I������ */

	srand(time(NULL));					/* �����̎�������� */

	printf("���l���L�����ĂP���������l����͂��܂��傤�B\n");

	do {
		printf("���킷�郌�x���i%d�`%d�j�F", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	success = stage = 0;
	start = clock();
	do {
		int no[LEVEL_MAX];		/* �L�����鐔 */
		int x[LEVEL_MAX];		/* �ǂݍ��񂾒l */
		int seikai = 0;			/* ���̃X�e�[�W�ł̐����� */

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

		point[stage++ % MAX_RECORD] = seikai;	/* �X�e�[�W�̐��𐔂��L�^ */
		success += seikai;						/* �S�̂̐��𐔂��X�V */

		printf("�����܂����H�iYes�c1�^No�c0�j�F");
		scanf("%d", &retry);
	} while (retry == 1);
	end = clock();

	printf("\n���� ���� ����\n");

	stage2 = stage - MAX_RECORD;
	if (stage2 < 0) stage2 = 0;

	for (i = level; i >= 1; i--) {
		for (j = stage2; j < stage; j++)
			if (point[j % MAX_RECORD] >= i)
				printf(" �� ");
			else
				printf("    ");
		putchar('\n');
	}
	printf("-----------------------------------------\n");

	for (j = stage2; j < stage; j++)
		printf(" %02d ", j + 1);
	putchar('\n');

	printf("%d��%d�������܂����B\n", level * stage, success);
	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	return (0);
}
