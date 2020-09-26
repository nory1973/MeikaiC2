/* 左右方向視野拡大訓練を兼ねた暗算トレーニング */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int stage;
	int a, b, c;						/* 加算する数値 */
	int x;								/* 読み込んだ値 */
	int n;								/* 余白の幅 */
	clock_t	start, end;					/* 開始時刻・終了時刻 */

	srand(time(NULL));					/* 乱数の種を初期化 */

	printf("視野拡大暗算トレーニング開始!!\n");
	start = clock();					/* 計測開始 */

	for (stage = 0; stage < 10; stage++) {
		a = 10 + rand() % 90;			/* 10～99の乱数を生成 */
		b = 10 + rand() % 90;			/* 　　　　〃　　　　 */
		c = 10 + rand() % 90;			/* 　　　　〃　　　　 */
		n = rand() % 17;				/*  0～16の乱数を生成 */

		printf("%d%*s+%*s%d%*s+%*s%d：", a, n, "", n, "", b, n, "", n, "", c);

		do {
			scanf("%d", &x);
			if (x == a + b + c)
				break;
			printf("\a違います。再入力してください：");
		} while (1);
	}

	end = clock();						/* 計測終了 */

	printf("%.1f秒かかりました。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return (0);
}
