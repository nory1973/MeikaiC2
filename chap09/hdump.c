/* hdump … ファイルのダンプ */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>

/*--- ストリームsrcの内容をdstへダンプ ---*/
void hdump(FILE *src, FILE *dst)
{
	int			  n;
	unsigned long count = 0;
	unsigned char buf[16];

	while ((n = fread(buf, 1, 16, src)) > 0) {
		int i;

		fprintf(dst, "%08lX ", count);						/* アドレス */

		for (i = 0; i < n; i++)								/* 16進数 */
			fprintf(dst, "%0*X ", (CHAR_BIT + 3) / 4, (unsigned)buf[i]);

		if (n < 16)
			for (i = n; i < 16; i++) fputs("   ", dst);

		for (i = 0; i < n; i++)								/* 文字 */
			fputc(isprint(buf[i]) ? buf[i] : '.', dst);

		fputc('\n', dst);

		count += 16;
	}
	fputc('\n', dst);
}

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
		hdump(stdin, stdout);		/* 標準入力 → 標準出力 */
	else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "rb")) == NULL) {
				fprintf(stderr, "ファイル%sが正しくオープンできません。\n", 
								*argv);
				return (1);
			} else {
				hdump(fp, stdout);	/* ストリームfp → 標準出力*/
				fclose(fp);
			}
		}
	}
	return (0);
}
