/* ����������ɂ��L�[�^�C�s���O���K�i���̂Q�F�o�菇�������_�� �c ��@�P�j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define QNO		12		/* ��萔 */

#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	char	*str[QNO] = {"book",   "computer", "default",  "comfort",
						 "monday", "power",    "light",    "music", 
						 "programming", "dog", "video",    "include"};
	int   	i, stage;
	int 	qno[QNO];				/* �o�菇�� */
	clock_t	start, end;				/* �J�n�����E�I������ */

	init_getputch();
	srand(time(NULL));				/* �����̎�������� */

	for (i = 0; i < QNO; i++)
		qno[i] = i;

	for (i = QNO - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		if (i != j)
			swap(int, qno[i], qno[j]);
	}

	printf("�^�C�s���O���K���n�߂܂��B\n");
	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')			/* �X�y�[�X�L�[������ */
		;							/* �����܂ő҂� */

	start = clock();				/* �J�n���� */

	for (stage = 0; stage < QNO; stage++) {
		int len = strlen(str[qno[stage]]); /* ������str[qno[stage]]�̕����� */
		for (i = 0; i < len; i++) {
			/* str[qno[stage]][i]�ȍ~��\�����ăJ�[�\����擪�֖߂� */
			printf("%s \r", &str[qno[stage]][i]);

			fflush(stdout);
			while (getch() != str[qno[stage]][i])
				;
		}
	}

	end = clock();					/* �I������ */
	printf("\r%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return (0);
}
