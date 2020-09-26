/* 総合タイピング練習 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define	NO			15			/* トレーニング回数 */
#define	KTYPE		16			/* ブロック数 */
#define	POS_LEN		10			/* ポジショントレーニングの文字数 */

/*--- 練習メニュー ---*/
typedef enum { Term, KeyPos, KeyPosComp, Clang, Conversation, InValid } Menu;

/*--- 各ブロックのキー ---*/
char *kstr[] = {
	"12345",  "67890-^\\",		/* 第１段         */
	"!\"#$%", "&'()=~|",		/* 第１段 [Shift] */
	"qwert",  "yuiop@[",		/* 第２段         */
	"QWERT",  "YUIOP`{",		/* 第２段 [Shift] */
	"asdfg",  "hjkl;:]",		/* 第３段         */
	"ASDFG",  "HJKL+*}",		/* 第３段 [Shift] */
	"zxcvb",  "nm,./\\",		/* 第４段         */
	"ZXCVB",  "NM<>?_",			/* 第４段 [Shift] */
};

/*--- Ｃ言語のキーワードとライブラリ関数 ---*/
char *cstr[] = {
	"auto",		"break",	"case",		"char",		"const",	"continue",
	"default",	"do",		"double",	"else",		"enum",		"extern",
	"float",	"for",		"goto",		"if",		"int",		"long",
	"register",	"return",	"short",	"signed",	"sizeof",	"static",
	"struct",	"switch",	"typedef",	"union",	"unsigned",	"void",
	"volatile",	"while",
	"abort",	"abs",		"acos",		"asctime",	"asin",		"assert",
	"atan",		"atan2",	"atexit",	"atof",		"atoi",		"atol",
	"bsearch",	"calloc",	"ceil",		"clearerr",	"clock",	"cos",
	"cosh",		"ctime",	"difftime",	"div",		"exit",		"exp",
	"fabs",		"fclose",	"feof",		"ferror",	"fflush",	"fgetc",
	"fgetpos",	"fgets",	"floor",	"fmod",		"fopen",	"fprintf",
	"fputc",	"fputs",	"fread",	"free",		"freopen",	"frexp",
	"fscanf",	"fseek",	"fsetpos",	"ftell",	"fwrite",	"getc",
	"getchar",	"getenv",	"gets",		"gmtime",	"isalnum",	"isalpha",
	"iscntrl",	"isdigit",	"isgraph",	"islower",	"isprint",	"ispunct",
	"isspace",	"isupper",	"isxdigit",	"labs",		"ldexp",	"ldiv",
	"localeconv",			"localtime","log",		"log10",	"longjmp",
	"malloc",	"memchr",	"memcmp",	"memcpy",	"memmove",	"memset",
	"mktime",	"modf",		"perror",	"pow",		"printf",	"putc",
	"putchar",	"puts",		"qsort",	"raise",	"rand",		"realloc",
	"remove",	"rename",	"rewind",	"scanf",	"setbuf",	"setjmp",
	"setlocale","setvbuf",	"signal",	"sin",		"sinh",		"sprintf",
	"sqrt",		"srand",	"sscanf",	"strcat",	"strchr",	"strcmp",
	"strcoll",	"strcpy",	"strcspn",	"strerror",	"strftime",	"strlen",
	"strncat",	"strncmp",	"strncpy",	"strpbrk",	"strrchr",	"strspn",
	"strstr",	"strtod",	"strtok",	"strtol",	"strtoul",	"strxfrm",
	"system",	"tan",		"tanh",		"time",		"tmpfile",	"tmpnam",
	"tolower",	"toupper",	"ungetc",	"va_arg",	"va_end",	"va_start",
	"vfprintf", "vprintf",	"vsprintf"
};

/*--- 英会話 ---*/
char *vstr[] = {
	"Hello!",							/* こんにちは。*/
	"How are you?",						/* お元気ですか。 */
	"Fine thanks.",						/* はい元気です。 */
	"I can't complain, thanks.",		/* まあ、何とか。 */
	"How do you do?",					/* 初めまして。 */
	"Good bye!",						/* さようなら。 */
	"Good morning!",					/* おはよう。 */
	"Good afternoon!",					/* こんにちは。 */
	"Good evening!",					/* こんばんは。 */
	"See you later!",					/* さようなら（またね）。 */
	"Go ahead, Please.",				/* お先にどうぞ。 */
	"Thank you.",						/* ありがとう。 */
	"No, thank you.",					/* いいえ結構です。 */
	"May I have your name?",			/* お名前は？ */
	"I'm glad to meet you.",			/* お目にかかれて光栄です。 */
	"What time is it now?",				/* 何時ですか。 */
	"It's about seven.",				/* 大体７時くらいです。 */
	"I must go now.",					/* もういかなくちゃ。 */
	"How much?",						/* おいくら？ */
	"Where is the restroom?",			/* お手洗いはどちらですか。 */
	"Excuse me.",						/* 失礼します（一人）。*/
	"Excuse us.",						/* 失礼します（二人以上）。*/
	"I'm sorry.",						/* ごめんなさい。 */
	"I don't know.",					/* さあ、知らないよ。 */
	"I have no change with me.",		/* 小銭がないのです。 */
	"I will be back.",					/* また戻って来ます。 */
	"Are you going out?",				/* 出かけるの？ */
	"I hope I'm not disturbing you.",	/* お邪魔じゃなければいいのですが。*/
	"I'll offer no excuse.",			/* 弁解するつもりはありません。 */
	"Shall we dance?",					/* 踊りませんか。 */
	"Will you do me a favor?",			/* ちょっとお願いしたいのですが。 */
	"It's very unseasonable.",			/* それは季節外れだね。 */
	"You are always welcome.",			/* いつでも歓迎しますよ。 */
	"Hold still!",						/* じっとして！ */
	"Follow me.",						/* 付いて来て。 */
	"Just follow my lead.",				/* 僕のするとおりにやるだけだよ。 */
	"To be honest with you,",			/* 正直に言うと… */
};

/*--- 文字列strをタイプ練習（ミス回数を返す） ---*/
int go(const char *str)
{
	int i;
	int len = strlen(str);			/* 文字数 */
	int mistake = 0;				/* ミス回数 */

	for (i = 0; i < len; i++) {
		/* str[i]以降を表示してカーソルを先頭へ戻す */
		printf("%s \r", &str[i]);
		fflush(stdout);
		while (getch() != str[i]) {
			mistake++;
		}
	}
	return (mistake);
}

/*--- 単純ポジショントレーニング ---*/
void pos_training(void)
{
	int i;
	int stage;
	int temp, line;
	int len;						/* 問題のブロックのキー数 */
	int qno, pno;					/* 問題番号・前回の問題番号 */
	int tno, mno;					/* 文字数・ミス回数 */
	clock_t	start, end;				/* 開始時刻・終了時刻 */

	printf("\n単純ポジショントレーニングを行います。\n");
	printf("練習するブロックを選択してください。\n");
	printf("第1段 (1) 左 %-8s    (2) 右 %-8s\n", kstr[ 0], kstr[ 1]);
	printf("第2段 (3) 左 %-8s    (4) 右 %-8s\n", kstr[ 4], kstr[ 5]);
	printf("第3段 (5) 左 %-8s    (6) 右 %-8s\n", kstr[ 8], kstr[ 9]);
	printf("第4段 (7) 左 %-8s    (8) 右 %-8s\n", kstr[12], kstr[13]);

	/* ブロックを選択させる */
	do {
		printf("番号（練習中止は99）：");
		scanf("%d", &temp);
		if (temp == 99) return;				/* 練習中止 */
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("%sの問題を%d回練習します。\n", kstr[line], NO);

	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;						/* 文字数・ミス回数をクリア */
	len = strlen(kstr[line]);			/* 練習するブロックのキー数 */

	start = clock();						/* 開始時刻 */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++)	/* 問題文字列を作成 */
			str[i] = kstr[line][rand() % len];
		str[i] = '\0';

		mno += go(str);						/* 練習実行 */
		tno += strlen(str);
	}

	end = clock();							/* 終了時刻 */

	printf("問題：%d文字／ミス：%d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- 複合ポジショントレーニング ---*/
void pos_training2(void)
{
	int i;
	int stage;
	int temp, line;
	int sno;						/* 選ばれたブロック数 */
	int select[KTYPE];				/* 選ばれたブロック */
	int len[KTYPE];					/* 問題のブロックのキー数 */
	int tno, mno;					/* 文字数・ミス回数 */
	clock_t	start, end;				/* 開始時刻・終了時刻 */
	char	*format = "第%d段 (%2d) 左 %-8s (%2d) 右 %-8s "
							 "(%2d)[左] %-8s (%2d)[右] %-8s\n";

	printf("\n複合ポジショントレーニングを行います。\n");
	printf("練習するブロックを選択してください（複数選べます）。\n");

	for (i = 0; i < 4; i++) {
		int k = i * 4;
		printf(format, i+1, k + 1, kstr[k],		k + 2, kstr[k + 1],
							k + 3, kstr[k + 2], k + 4, kstr[k + 3]);
	}

	/* ブロックを重複させずに選択させる（最大16個） */
	sno = 0;
	while (1) {
		printf("番号（選択終了は50／練習中止は99）：");

		do {
			scanf("%d", &temp);
			if (temp == 99) return;			/* 練習中止 */
		} while ((temp < 1 || temp > KTYPE) && temp != 50);

		if (temp == 50)
			break;
		for (i = 0; i < sno; i++)
			if (temp == select[i]) {
				printf("\aその段は既に選ばれています。\n");
				break;
			}
		if (i == sno)
			select[sno++] = temp;			/* 選ばれたブロックを登録 */
	}

	if (sno == 0)							/* 一つも選ばれなかった */
		return;

	printf("以下のブロックの問題を%d回練習します。\n", NO);

	for (i = 0; i < sno; i++)
		printf("%s ", kstr[select[i] - 1]);

	printf("\nスペースキーで開始します。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;							/* 文字数・ミス回数をクリア */
	for (i = 0; i < sno; i++)
		len[i] = strlen(kstr[select[i] - 1]);	/* ブロックのキー数 */

	start = clock();						/* 開始時刻 */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++) {		/* 問題文字列を作成 */
			int q = rand() % sno;
			str[i] = kstr[select[q] - 1][rand() % len[q]];
		}
		str[i] = '\0';

		mno += go(str);						/* 練習実行 */
		tno += strlen(str);
	}

	end = clock();							/* 終了時刻 */

	printf("問題：%d文字／ミス：%d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- Ｃ言語／英会話トレーニング ---*/
void word_training(const char *mes, const char *str[], int n)
{
	int stage;
	int qno, pno;					/* 問題番号・前回の問題番号 */
	int tno, mno;					/* 文字数・ミス回数 */
	clock_t	start, end;				/* 開始時刻・終了時刻 */

	printf("\n%sを%d個練習します。\n", mes, NO);

	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;					/* 文字数・ミス回数をクリア */
	pno = n;						/* 前回の問題番号（存在しない番号） */

	start = clock();				/* 開始時刻 */

	for (stage = 0; stage < NO; stage++) {
		do {						/* 同じ問題を連続して出題しない */
			qno = rand() % n;
		} while (qno == pno);

		mno += go(str[qno]);		/* 問題はstr[qno] */
		tno += strlen(str[qno]);
		pno = qno;
	}

	end = clock();					/* 終了時刻 */

	printf("問題：%d文字／ミス：%d回\n", tno, mno);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- メニュー選択 ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n練習を選択してください。\n");
		printf("(1) 単純ポジション  (2) 複合ポジション\n");
		printf("(3) Ｃ言語の単語    (4) 英会話      (0) 終了 ：");
		scanf("%d", &ch);
	} while (ch < Term || ch >= InValid);

	return ((Menu)ch);
}

int main(void)
{
	Menu menu;										/* メニュー */
	int cn = sizeof(cstr) / sizeof(cstr[0]);		/* Ｃ言語の単語数 */
	int vn = sizeof(vstr) / sizeof(vstr[0]);		/* 英会話の文書数 */

	init_getputch();

	srand(time(NULL));								/* 乱数の種を初期化 */

	do {
		switch (menu = SelectMenu()) {

		 case KeyPos :						/* 単純ポジショントレーニング */
		 			pos_training();
		 			break;

		 case KeyPosComp :					/* 複合ポジショントレーニング */
		 			pos_training2();
		 			break;

		 case Clang :						/* Ｃ言語の単語 */
		 			word_training("Ｃ言語の単語", cstr, cn);
		 			break;

		 case Conversation :				/* 英会話 */
		 			word_training("英会話の文書", vstr, vn);
		 			break;
		}
	} while (menu != Term);

	term_getputch();

	return (0);
}
