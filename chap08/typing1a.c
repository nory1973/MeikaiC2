/* ��̕�����ɂ��L�[�^�C�s���O���K�i���̂P�j*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

int main(void)
{
	int 	i;
	char	*str = "How do you do?";	/* �^�C�v���镶���� */
	int 	len = strlen(str);			/* ������str�̕����� */
	clock_t	start, end;					/* �J�n�����E�I������ */

	init_getputch();

	printf("���̂Ƃ���^�C�v���Ă��������B\n");
	printf("%s\n", str);				/* �^�C�v���镶�����\�� */
	fflush(stdout);

	start = clock();					/* �J�n���� */

	for (i = 0; i < len; i++) {
		int ch;

		do {
			ch = getch();				/* �L�[�Ǎ��� */
			if (isprint(ch)) {
				putch(ch);				/* �����ꂽ�L�[��\�� */
				if (ch != str[i])		/* �Ⴄ�L�[�������ꂽ�� */
					putch('\b');		/* �J�[�\������߂�   */
			}
		} while (ch != str[i]);
	}

	end = clock();						/* �I������ */

	printf("\n%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return (0);
}
