/* ��������̕�����16�i����2�i���ŕ\�� */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>

/*--- ��������̕�����16�i����2�i���ŕ\�� ---*/
void strdump(const char *s)
{
	while (*s) {
		int i;
		unsigned char x = (unsigned char)*s;

		printf("%c  ", isprint(x) ? x : ' ');	 /* ���� */
		printf("%0*X  ", (CHAR_BIT + 3) / 4, x); /* 16�i�� */
		for (i = CHAR_BIT - 1; i >= 0; i--)		 /* �Q�i�� */
			putchar(((x >> i) & 1U) ? '1' : '0');
		putchar('\n');
		s++;
	}
}

int main(void)
{
	puts("����");		strdump("����");		putchar('\n');

	puts("12���{��AB");	strdump("12���{��AB");	putchar('\n');

	return (0);
}
