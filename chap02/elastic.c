/* ��������P�������\�����Č�납��P��������������̂��J��Ԃ� */

#include <time.h>
#include <stdio.h>
#include <string.h>

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
	int  i;
	char name[] = "BohYoh Shibata";			/* �\�����镶���� */
	int  name_len = strlen(name);			/* ������name�̕����� */

	while (1) {		/* �����ɌJ��Ԃ� */
		for (i = 0; i < name_len; i++) {	/* �擪����P�������\�� */
			putchar(name[i]);
			fflush(stdout);
			sleep(500);
		}
		for (i = 0; i < name_len; i++) {	/* ��������P���������� */
			printf("\b \b");
			fflush(stdout);
			sleep(500);
		}
	}
	return (0);
}
