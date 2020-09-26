/* ラックナンバーサーチ・トレーニング（その３：前回の日時・最高得点を表示）*/

#include <time.h>
#include <float.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "getputch.h"

#define MAX_STAGE	10
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

char dtfile[] = "LACKNUM.DAT";				/* ファイル名 */

/*--- 前回のトレーニング情報を取得・表示して最高得点を返す ---*/
double get_data(void)
{
	FILE *fp;
	double best;		/* 最高得点 */

	if ((fp = fopen(dtfile, "r")) == NULL) {
		printf("本プログラムを実行するのは初めてですね。\n\n");
		best = DBL_MAX;
	} else {
		int	year, month, day, h, m, s;

		fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
		fscanf(fp, "%lf", &best);
		printf("前回の終了は%d年%d月%d日%d時%d分%d秒でした。\n",
											year, month, day, h, m, s);

		printf("これまでの最高得点（最短所要時間）は%.1f秒です。\n\n", best);
		fclose(fp);
	}

	return (best);
}

/*--- 今回のトレーニング情報を書き込む ---*/
void put_data(double best)
{
	FILE *fp;
	time_t	  t = time(NULL);
	struct tm *local = localtime(&t);

	if ((fp = fopen(dtfile, "w")) == NULL)
		printf("エラー発生!!");
	else {
		fprintf(fp, "%d %d %d %d %d %d\n",
					local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
					local->tm_hour,		   local->tm_min,	  local->tm_sec);

		fprintf(fp, "%f\n", best);
		fclose(fp);
	}
}

/*--- トレーニングを実行して得点（所要時間）を返す ---*/
double go(void)
{
	int		i, j, stage;
	int		dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int		a[8];
	double	jikan;				/* 時間 */
	clock_t	start, end;			/* 開始時刻・終了時刻 */

	printf("欠けている数字を入力してください。\n");
	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* 0～8の乱数を発生 */
		int	no;					/* 読み込んだ値 */

		i = j = 0;
		while (i < 9) {			/* dgt[x]を飛ばしてコピー */
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {		/* 配列aをシャッフル */
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++)		/* 全要素を表示 */
			printf("%d ", a[i]);
		printf("：");
		fflush(stdout);

		do {
			no = getch();
			if (isprint(no)) {				/* 表示可能であれば */
				putch(no);					/* 押されたキーを表示 */
				if (no != dgt[x] + '0')		/* 正解でなければ */
					putch('\b');			/* カーソルを一つ戻す */
				else
					printf("\n");			/* 改行 */
			}
		} while (no != dgt[x] + '0');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0)
		printf("鈍すぎます。\n");
	else if (jikan > 20.0)
		printf("少し鈍いですね。\n");
	else if (jikan > 17.0)
		printf("まあまあですね。\n");
	else
		printf("素早いですね。\n");

	return (jikan);
}

int main(void)
{
	int	   retry;		/* もう一度？ */
	double score;		/* 得点（所要時間） */
	double best;		/* 最高得点（最短所要時間） */

	best = get_data();				/* 前回までの最高得点を得る */

	init_getputch();
	srand(time(NULL));				/* 乱数の種を初期化 */

	do {
		score = go();				/* トレーニング実行 */

		if (score < best) {
			printf("最高得点（所要時間）を更新しました!!\n");
			best = score;			/* 最高得点更新 */
		}

		printf("もう一度しますか … (0)いいえ (1)はい：");
		scanf("%d", &retry);
	} while (retry == 1);

	put_data(best);				/* 今回の日付・時刻・得点を書き込む */

	term_getputch();

	return (0);
}
