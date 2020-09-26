/* キー配置連想タイピング練習（タイプする文字を考えさせる）
		A?DFG と表示されたらSをタイプ
		qwe?t と表示されたらrをタイプ						*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define	NO			30			/* 練習回数 */
#define	KTYPE		16			/* ブロック数 */

int main(void)
{
	char *kstr[] = {"12345",  "67890-^\\",		/* 第１段         */
					"!\"#$%", "&'() =~|",		/* 第１段 [Shift] */
					"qwert",  "yuiop@[",		/* 第２段         */
					"QWERT",  "YUIOP`{",		/* 第２段 [Shift] */
					"asdfg",  "hjkl;:]",		/* 第３段         */
					"ASDFG",  "HJKL+*}",		/* 第３段 [Shift] */
					"zxcvb",  "nm,./\\",		/* 第４段         */
					"ZXCVB",  "NM<> _",			/* 第４段 [Shift] */
					};
	int 	i, stage;
	clock_t	start, end;			/* 開始時刻・終了時刻 */

	init_getputch();
	srand(time(NULL));			/* 乱数の種を初期化 */

	printf("キー位置連想タイピング練習を始めます。\n");
	printf("？で隠された文字をタイプしてください。\n");
	printf("スペースキーで開始します。\n");
	fflush(stdout);
	while (getch() != ' ')
		;

	start = clock();				/* 開始時刻 */

	for (stage = 0; stage < NO; stage++) {
		int  k, p, key;
		char temp[10];

		do {
			k = rand() % KTYPE;
			p = rand() % strlen(kstr[k]);
			key = kstr[k][p];
		} while (key == ' ');

		strcpy(temp, kstr[k]);
		temp[p] = '?';

		printf("%s", temp);
		fflush(stdout);

		while (getch() != key)
			;
		putchar('\n');
	}

	end = clock();					/* 終了時刻 */

	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return (0);
}
