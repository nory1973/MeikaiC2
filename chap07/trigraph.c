/* �g���C�O���t�A�z�g���[�j���O�i�����E�p���̂R�����̕��т�����������j*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getputch.h"

#define	MAX_STAGE	20					/* ����� */
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	char *qstr[] = {"0123456789",					/* ���� */
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ",	/* �p�啶�� */
					"abcdefghijklmnopqrstuvwxyz",	/* �p������ */
				   };
	/* ���ꂼ��̕����� */
	int 	chmax[] = {10, 26, 26};
	int 	i, stage;
	int 	key;							/* �ǂݍ��񂾃L�[ */
	double	jikan;							/* ���� */
	clock_t	start, end;						/* �J�n�����E�I������ */

	init_getputch();

	srand(time(NULL));						/* �����̎�������� */

	printf("���A������O�̐������邢�͉p������\n");
	printf("���B����Ă��镶������͂��Ă��������B\n");
	printf("�����Ƃ��� A ? C : �ƕ\�����ꂽ��B��\n");
	printf("���@�@�@�@ 4 5 ? : �ƕ\�����ꂽ��6��\n");
	printf("�����͂��܂��B\n");
	printf("���X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int qtype = rand() % 3;		/* 0:�����^1:�p�啶���^2:�p������ */
		int nhead = rand() % (chmax[qtype] - 2);	/* �擪�����̓Y�� */
		int x     = rand() % 3;		/* �R�����̂ǂ��'?'�ɂ��邩 */

		putchar('\r');
		for (i = 0; i < 3; i++) {	/* ����\�� */
			if (i != x)
				printf(" %c", qstr[qtype][nhead + i]);
			else
				printf(" ?");
		}
		printf(" : ");

		do {
			key = getch();
			if (isprint(key)) {						/* �\���\�ł���� */
				putch(key);							/* �����ꂽ�L�[��\�� */
				if (key != qstr[qtype][nhead + x])	/* �����łȂ���� */
					putch('\b');					/* �J�[�\������߂� */
			}
		} while (key != qstr[qtype][nhead + x]);
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\n%.1f�b������܂����B\n", jikan);

	if (jikan > 50.0)
		printf("�݂����܂��B\n");
	else if (jikan > 40.0)
		printf("�����݂��ł��ˁB\n");
	else if (jikan > 34.0)
		printf("�܂��܂��ł��ˁB\n");
	else
		printf("�f�����ł��ˁB\n");

	term_getputch();

	return (0);
}
