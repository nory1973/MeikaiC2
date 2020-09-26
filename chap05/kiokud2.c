/* �P���L���g���[�j���O�i���l���L���F���x���������̐ݒ肠��j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE	10					/* �X�e�[�W�� */
#define LEVEL_MIN	 3					/* �ŏ����x���i�����j*/
#define LEVEL_MAX	20					/* �ő僌�x���i�����j*/

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
	int 	level;			/* ���x���i���l�̌����j*/
	int 	success = 0;	/* ���� */
	clock_t	start, end;		/* �J�n�����E�I������ */

	srand(time(NULL));		/* �����̎�������� */

	printf("���l�L���g���[�j���O\n");

	do {
		printf("���킷�郌�x���i%d�`%d�j�F", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	printf("%d���̐��l���L�����܂��傤�B\n", level);

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char no[LEVEL_MAX + 1];				/* �L�����ׂ������̕��� */
		char x[LEVEL_MAX * 2];				/* �ǂݍ��񂾐����̕��� */

		no[0] = '1' + rand() % 9;			/* �擪������'1'�`'9' */
		for (i = 1; i < level; i++)
			no[i] = '0' + rand() % 10;		/* ����ȍ~��'0'�`'9' */
		no[level] = '\0';

		printf("%s", no);
		fflush(stdout);
		sleep(125 * level);					/* ���񎦂�125�~level�~���b */

		printf("\r%*s\r���͂���F", level, "");
		scanf("%s", x);

		if (strcmp(no, x) != 0)
			printf("\a�ԈႢ�ł��B\n");
		else {
			printf("�����ł��B\n");
			success++;
		}
	}
	end = clock();

	printf("%d��%d�񐬌����܂����B\n", MAX_STAGE, success);
	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	return (0);
}
