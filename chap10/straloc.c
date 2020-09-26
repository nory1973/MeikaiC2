/* 文字列を動的に確保 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char st[16];
	char *pt;

	printf("文字列stを入力してください：");
	scanf("%s", st);

	pt = malloc(strlen(st) + 1);	/* 記憶域を動的に確保 */

	if (pt) {
		strcpy(pt, st);				/* 文字列をコピー */
		printf("その文字列の複製ptを作りました。\n");
		printf("st = %s\n", st);
		printf("pt = %s\n", pt);
		free(pt);					/* 記憶域を解放 */
	}

	return (0);
}
