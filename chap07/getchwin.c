/* getch�̗��p��
   ��Visual C++�Ȃǂ�MS-Windows�^MS-DOS�œ��� */

#include <conio.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int ch;
	int retry;

	do {
		printf("�L�[�������Ă��������B");
		ch = getch();

		printf("\n�����ꂽ�L�[��%c�Œl��%d�ł��B\n",
											 isprint(ch) ? ch : ' ', ch);

		printf("������x�H�iY�^N�j�F");
		retry = getch();
		if (isprint(retry))
			putch(retry);

		putchar('\n');

	} while (retry == 'Y' || retry == 'y');

	return (0);
}
