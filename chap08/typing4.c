/* �����^�C�s���O���K */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define	NO			15			/* �g���[�j���O�� */
#define	KTYPE		16			/* �u���b�N�� */
#define	POS_LEN		10			/* �|�W�V�����g���[�j���O�̕����� */

/*--- ���K���j���[ ---*/
typedef enum { Term, KeyPos, KeyPosComp, Clang, Conversation, InValid } Menu;

/*--- �e�u���b�N�̃L�[ ---*/
char *kstr[] = {
	"12345",  "67890-^\\",		/* ��P�i         */
	"!\"#$%", "&'()=~|",		/* ��P�i [Shift] */
	"qwert",  "yuiop@[",		/* ��Q�i         */
	"QWERT",  "YUIOP`{",		/* ��Q�i [Shift] */
	"asdfg",  "hjkl;:]",		/* ��R�i         */
	"ASDFG",  "HJKL+*}",		/* ��R�i [Shift] */
	"zxcvb",  "nm,./\\",		/* ��S�i         */
	"ZXCVB",  "NM<>?_",			/* ��S�i [Shift] */
};

/*--- �b����̃L�[���[�h�ƃ��C�u�����֐� ---*/
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

/*--- �p��b ---*/
char *vstr[] = {
	"Hello!",							/* ����ɂ��́B*/
	"How are you?",						/* �����C�ł����B */
	"Fine thanks.",						/* �͂����C�ł��B */
	"I can't complain, thanks.",		/* �܂��A���Ƃ��B */
	"How do you do?",					/* ���߂܂��āB */
	"Good bye!",						/* ���悤�Ȃ�B */
	"Good morning!",					/* ���͂悤�B */
	"Good afternoon!",					/* ����ɂ��́B */
	"Good evening!",					/* ����΂�́B */
	"See you later!",					/* ���悤�Ȃ�i�܂��ˁj�B */
	"Go ahead, Please.",				/* ����ɂǂ����B */
	"Thank you.",						/* ���肪�Ƃ��B */
	"No, thank you.",					/* ���������\�ł��B */
	"May I have your name?",			/* �����O�́H */
	"I'm glad to meet you.",			/* ���ڂɂ�����Č��h�ł��B */
	"What time is it now?",				/* �����ł����B */
	"It's about seven.",				/* ��̂V�����炢�ł��B */
	"I must go now.",					/* ���������Ȃ�����B */
	"How much?",						/* ��������H */
	"Where is the restroom?",			/* ����􂢂͂ǂ���ł����B */
	"Excuse me.",						/* ���炵�܂��i��l�j�B*/
	"Excuse us.",						/* ���炵�܂��i��l�ȏ�j�B*/
	"I'm sorry.",						/* ���߂�Ȃ����B */
	"I don't know.",					/* �����A�m��Ȃ���B */
	"I have no change with me.",		/* ���K���Ȃ��̂ł��B */
	"I will be back.",					/* �܂��߂��ė��܂��B */
	"Are you going out?",				/* �o������́H */
	"I hope I'm not disturbing you.",	/* ���ז�����Ȃ���΂����̂ł����B*/
	"I'll offer no excuse.",			/* �ى��������͂���܂���B */
	"Shall we dance?",					/* �x��܂��񂩁B */
	"Will you do me a favor?",			/* ������Ƃ��肢�������̂ł����B */
	"It's very unseasonable.",			/* ����͋G�ߊO�ꂾ�ˁB */
	"You are always welcome.",			/* ���ł����}���܂���B */
	"Hold still!",						/* �����Ƃ��āI */
	"Follow me.",						/* �t���ė��āB */
	"Just follow my lead.",				/* �l�̂���Ƃ���ɂ�邾������B */
	"To be honest with you,",			/* �����Ɍ����Ɓc */
};

/*--- ������str���^�C�v���K�i�~�X�񐔂�Ԃ��j ---*/
int go(const char *str)
{
	int i;
	int len = strlen(str);			/* ������ */
	int mistake = 0;				/* �~�X�� */

	for (i = 0; i < len; i++) {
		/* str[i]�ȍ~��\�����ăJ�[�\����擪�֖߂� */
		printf("%s \r", &str[i]);
		fflush(stdout);
		while (getch() != str[i]) {
			mistake++;
		}
	}
	return (mistake);
}

/*--- �P���|�W�V�����g���[�j���O ---*/
void pos_training(void)
{
	int i;
	int stage;
	int temp, line;
	int len;						/* ���̃u���b�N�̃L�[�� */
	int qno, pno;					/* ���ԍ��E�O��̖��ԍ� */
	int tno, mno;					/* �������E�~�X�� */
	clock_t	start, end;				/* �J�n�����E�I������ */

	printf("\n�P���|�W�V�����g���[�j���O���s���܂��B\n");
	printf("���K����u���b�N��I�����Ă��������B\n");
	printf("��1�i (1) �� %-8s    (2) �E %-8s\n", kstr[ 0], kstr[ 1]);
	printf("��2�i (3) �� %-8s    (4) �E %-8s\n", kstr[ 4], kstr[ 5]);
	printf("��3�i (5) �� %-8s    (6) �E %-8s\n", kstr[ 8], kstr[ 9]);
	printf("��4�i (7) �� %-8s    (8) �E %-8s\n", kstr[12], kstr[13]);

	/* �u���b�N��I�������� */
	do {
		printf("�ԍ��i���K���~��99�j�F");
		scanf("%d", &temp);
		if (temp == 99) return;				/* ���K���~ */
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("%s�̖���%d����K���܂��B\n", kstr[line], NO);

	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;

	tno = mno = 0;						/* �������E�~�X�񐔂��N���A */
	len = strlen(kstr[line]);			/* ���K����u���b�N�̃L�[�� */

	start = clock();						/* �J�n���� */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++)	/* ��蕶������쐬 */
			str[i] = kstr[line][rand() % len];
		str[i] = '\0';

		mno += go(str);						/* ���K���s */
		tno += strlen(str);
	}

	end = clock();							/* �I������ */

	printf("���F%d�����^�~�X�F%d��\n", tno, mno);
	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- �����|�W�V�����g���[�j���O ---*/
void pos_training2(void)
{
	int i;
	int stage;
	int temp, line;
	int sno;						/* �I�΂ꂽ�u���b�N�� */
	int select[KTYPE];				/* �I�΂ꂽ�u���b�N */
	int len[KTYPE];					/* ���̃u���b�N�̃L�[�� */
	int tno, mno;					/* �������E�~�X�� */
	clock_t	start, end;				/* �J�n�����E�I������ */
	char	*format = "��%d�i (%2d) �� %-8s (%2d) �E %-8s "
							 "(%2d)[��] %-8s (%2d)[�E] %-8s\n";

	printf("\n�����|�W�V�����g���[�j���O���s���܂��B\n");
	printf("���K����u���b�N��I�����Ă��������i�����I�ׂ܂��j�B\n");

	for (i = 0; i < 4; i++) {
		int k = i * 4;
		printf(format, i+1, k + 1, kstr[k],		k + 2, kstr[k + 1],
							k + 3, kstr[k + 2], k + 4, kstr[k + 3]);
	}

	/* �u���b�N���d���������ɑI��������i�ő�16�j */
	sno = 0;
	while (1) {
		printf("�ԍ��i�I���I����50�^���K���~��99�j�F");

		do {
			scanf("%d", &temp);
			if (temp == 99) return;			/* ���K���~ */
		} while ((temp < 1 || temp > KTYPE) && temp != 50);

		if (temp == 50)
			break;
		for (i = 0; i < sno; i++)
			if (temp == select[i]) {
				printf("\a���̒i�͊��ɑI�΂�Ă��܂��B\n");
				break;
			}
		if (i == sno)
			select[sno++] = temp;			/* �I�΂ꂽ�u���b�N��o�^ */
	}

	if (sno == 0)							/* ����I�΂�Ȃ����� */
		return;

	printf("�ȉ��̃u���b�N�̖���%d����K���܂��B\n", NO);

	for (i = 0; i < sno; i++)
		printf("%s ", kstr[select[i] - 1]);

	printf("\n�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;

	tno = mno = 0;							/* �������E�~�X�񐔂��N���A */
	for (i = 0; i < sno; i++)
		len[i] = strlen(kstr[select[i] - 1]);	/* �u���b�N�̃L�[�� */

	start = clock();						/* �J�n���� */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++) {		/* ��蕶������쐬 */
			int q = rand() % sno;
			str[i] = kstr[select[q] - 1][rand() % len[q]];
		}
		str[i] = '\0';

		mno += go(str);						/* ���K���s */
		tno += strlen(str);
	}

	end = clock();							/* �I������ */

	printf("���F%d�����^�~�X�F%d��\n", tno, mno);
	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- �b����^�p��b�g���[�j���O ---*/
void word_training(const char *mes, const char *str[], int n)
{
	int stage;
	int qno, pno;					/* ���ԍ��E�O��̖��ԍ� */
	int tno, mno;					/* �������E�~�X�� */
	clock_t	start, end;				/* �J�n�����E�I������ */

	printf("\n%s��%d���K���܂��B\n", mes, NO);

	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;

	tno = mno = 0;					/* �������E�~�X�񐔂��N���A */
	pno = n;						/* �O��̖��ԍ��i���݂��Ȃ��ԍ��j */

	start = clock();				/* �J�n���� */

	for (stage = 0; stage < NO; stage++) {
		do {						/* ��������A�����ďo�肵�Ȃ� */
			qno = rand() % n;
		} while (qno == pno);

		mno += go(str[qno]);		/* ����str[qno] */
		tno += strlen(str[qno]);
		pno = qno;
	}

	end = clock();					/* �I������ */

	printf("���F%d�����^�~�X�F%d��\n", tno, mno);
	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- ���j���[�I�� ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n���K��I�����Ă��������B\n");
		printf("(1) �P���|�W�V����  (2) �����|�W�V����\n");
		printf("(3) �b����̒P��    (4) �p��b      (0) �I�� �F");
		scanf("%d", &ch);
	} while (ch < Term || ch >= InValid);

	return ((Menu)ch);
}

int main(void)
{
	Menu menu;										/* ���j���[ */
	int cn = sizeof(cstr) / sizeof(cstr[0]);		/* �b����̒P�ꐔ */
	int vn = sizeof(vstr) / sizeof(vstr[0]);		/* �p��b�̕����� */

	init_getputch();

	srand(time(NULL));								/* �����̎�������� */

	do {
		switch (menu = SelectMenu()) {

		 case KeyPos :						/* �P���|�W�V�����g���[�j���O */
		 			pos_training();
		 			break;

		 case KeyPosComp :					/* �����|�W�V�����g���[�j���O */
		 			pos_training2();
		 			break;

		 case Clang :						/* �b����̒P�� */
		 			word_training("�b����̒P��", cstr, cn);
		 			break;

		 case Conversation :				/* �p��b */
		 			word_training("�p��b�̕���", vstr, vn);
		 			break;
		}
	} while (menu != Term);

	term_getputch();

	return (0);
}
