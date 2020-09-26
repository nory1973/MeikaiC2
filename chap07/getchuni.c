/* getch�̗��p��
   ��Curses���C�u�������񋟂����UNIX�^Linux�^OS X�œ��� */

#include <curses.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int ch;
	int retry;

	initscr();
	cbreak();
	noecho();
	refresh();

	do {
		printf("�L�[�������Ă��������B");
		fflush(stdout);

		ch = getch();

		printf("\n\r�����ꂽ�L�[��%c�Œl��%d�ł��B\n\r",
											 isprint(ch) ? ch : ' ', ch);

		printf("������x�H�iY�^N�j�F");
		fflush(stdout);
		retry = getch();
		if (isprint(retry))
			putchar(retry);

		putchar('\n');
		fflush(stdout);
	} while (retry == 'Y' || retry == 'y');

	endwin();

	return (0);
}