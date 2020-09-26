/* 後退\bの利用例：１秒ごとに１文字ずつ消去 */

#include <time.h>
#include <stdio.h>

/*--- xミリ秒経過するのを待つ ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* エラー */
			return (0);
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return (1);
}

int main(void)
{
	int i;

	printf("ABCDEFG");

	for (i = 0; i < 7; i++) {
		sleep(1000);				/* 後ろから１文字ずつ */
		printf("\b \b");			/* １秒ごとに消す　　 */
		fflush(stdout);				/* バッファを掃き出す */
	}

	return (0);
}
