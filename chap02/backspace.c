/* ���\b�̗��p��F�P�b���ƂɂP���������� */

#include <time.h>
#include <stdio.h>

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
	int i;

	printf("ABCDEFG");

	for (i = 0; i < 7; i++) {
		sleep(1000);				/* ��납��P�������� */
		printf("\b \b");			/* �P�b���Ƃɏ����@�@ */
		fflush(stdout);				/* �o�b�t�@��|���o�� */
	}

	return (0);
}
