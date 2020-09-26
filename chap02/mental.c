/* 暗算トレーニング（３桁の整数を三つ加える）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c;				/* 加算する数値 */
	int x;						/* 読み込んだ値 */
	clock_t start, end;			/* 開始時刻・終了時刻 */
	double req_time;			/* 所要時間 */

	srand(time(NULL));			/* 乱数の種を初期化 */

	a = 100 + rand() % 900;		/* 100～999の乱数を生成 */
	b = 100 + rand() % 900;		/* 　　　　 〃 　　　　 */
	c = 100 + rand() % 900;		/* 　　　　 〃 　　　　 */

	printf("%d + %d + %dは何ですか：", a, b, c);

	start = clock();			/* 計測開始 */

	while (1) {
		scanf("%d", &x);
		if (x == a + b + c)
			break;
		printf("\a違いますよ!!\n再入力してください：");
	}

	end = clock();				/* 計測終了 */

	req_time = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", req_time);

	if (req_time > 30.0)
		printf("時間がかかりすぎです。\n");
	else if (req_time > 17.0)
		printf("まあまあですね。\n");
	else
		printf("素早いですね。\n");

	return (0);
}
