/* 数当てゲーム（その１）*/

#include <stdio.h>

int main(void)
{
	int no;			/* 読み込んだ値 */
	int ans = 7;	/* 当てさせる数 */

	printf("0～9の整数を当ててください。\n\n");

	printf("いくつかな：");
	scanf("%d", &no);

	if (no > ans)
		printf("\aもっと小さいよ。\n");
	else if (no < ans)
		printf("\aもっと大きいよ。\n");
	else
		printf("正解です。\n");

	return (0);
}
