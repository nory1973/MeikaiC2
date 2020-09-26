/* �L�[�z�u�A�z�^�C�s���O���K�i�^�C�v���镶�����l��������j
		A?DFG �ƕ\�����ꂽ��S���^�C�v
		qwe?t �ƕ\�����ꂽ��r���^�C�v						*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define	NO			30			/* ���K�� */
#define	KTYPE		16			/* �u���b�N�� */

int main(void)
{
	char *kstr[] = {"12345",  "67890-^\\",		/* ��P�i         */
					"!\"#$%", "&'() =~|",		/* ��P�i [Shift] */
					"qwert",  "yuiop@[",		/* ��Q�i         */
					"QWERT",  "YUIOP`{",		/* ��Q�i [Shift] */
					"asdfg",  "hjkl;:]",		/* ��R�i         */
					"ASDFG",  "HJKL+*}",		/* ��R�i [Shift] */
					"zxcvb",  "nm,./\\",		/* ��S�i         */
					"ZXCVB",  "NM<> _",			/* ��S�i [Shift] */
					};
	int 	i, stage;
	clock_t	start, end;			/* �J�n�����E�I������ */

	init_getputch();
	srand(time(NULL));			/* �����̎�������� */

	printf("�L�[�ʒu�A�z�^�C�s���O���K���n�߂܂��B\n");
	printf("�H�ŉB���ꂽ�������^�C�v���Ă��������B\n");
	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	fflush(stdout);
	while (getch() != ' ')
		;

	start = clock();				/* �J�n���� */

	for (stage = 0; stage < NO; stage++) {
		int  k, p, key;
		char temp[10];

		do {
			k = rand() % KTYPE;
			p = rand() % strlen(kstr[k]);
			key = kstr[k][p];
		} while (key == ' ');

		strcpy(temp, kstr[k]);
		temp[p] = '?';

		printf("%s", temp);
		fflush(stdout);

		while (getch() != key)
			;
		putchar('\n');
	}

	end = clock();					/* �I������ */

	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return (0);
}
