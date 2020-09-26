/* 数当てゲーム（その４：当てさせる数は0～999の乱数）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int no;		/* 読み込んだ値 */
	int ans;	/* 当てさせる数 */

	srand(time(NULL));		/* 乱数の種を初期化 */
	ans = rand() % 1000;	/* 0～999の乱数を生成 */

	printf("0～999の整数を当ててください。\n\n");

	do {
		printf("いくつかな：");
		scanf("%d", &no);

		if (no > ans)
			printf("\aもっと小さいよ。\n");
		else if (no < ans)
			printf("\aもっと大きいよ。\n");
	} while (no != ans);					/* 当たるまで繰り返す */

	printf("正解です。\n");

	return (0);
}
