/* 複数文字列によるキータイピング練習（その２：出題順序ランダム … 手法１）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define QNO		12		/* 問題数 */

#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	char	*str[QNO] = {"book",   "computer", "default",  "comfort",
						 "monday", "power",    "light",    "music", 
						 "programming", "dog", "video",    "include"};
	int   	i, stage;
	int 	qno[QNO];				/* 出題順序 */
	clock_t	start, end;				/* 開始時刻・終了時刻 */

	init_getputch();
	srand(time(NULL));				/* 乱数の種を初期化 */

	for (i = 0; i < QNO; i++)
		qno[i] = i;

	for (i = QNO - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		if (i != j)
			swap(int, qno[i], qno[j]);
	}

	printf("タイピング練習を始めます。\n");
	printf("スペースキーで開始します。\n");
	while (getch() != ' ')			/* スペースキーが押下 */
		;							/* されるまで待つ */

	start = clock();				/* 開始時刻 */

	for (stage = 0; stage < QNO; stage++) {
		int len = strlen(str[qno[stage]]); /* 文字列str[qno[stage]]の文字数 */
		for (i = 0; i < len; i++) {
			/* str[qno[stage]][i]以降を表示してカーソルを先頭へ戻す */
			printf("%s \r", &str[qno[stage]][i]);

			fflush(stdout);
			while (getch() != str[qno[stage]][i])
				;
		}
	}

	end = clock();					/* 終了時刻 */
	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return (0);
}
