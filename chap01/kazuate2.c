/* 数当てゲーム（その２：当たるまで繰り返す：do文）*/

#include <stdio.h>

int main(void)
{
	int no;			/* 読み込んだ値 */
	int ans = 7;	/* 当てさせる数 */

	printf("0～9の整数を当ててください。\n\n");

	do {
		printf("いくつかな：");
		scanf("%d", &no);

		if (no > ans)
			printf("\aもっと小さいよ。\n");
		else if (no < ans)
			printf("\aもっと大きいよ。\n");
	} while (no != ans);				/* 当たるまで繰り返す */

	printf("正解です。\n");

	return (0);
}
