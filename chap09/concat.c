/* concat �c �t�@�C���̃R�s�[ */

#include <stdio.h>

/*--- src����̓��͂�dst�֏o�� ---*/
void copy(FILE *src, FILE *dst)
{
	int	ch;

	while ((ch = fgetc(src)) != EOF)
		fputc(ch, dst);
}

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
		copy(stdin, stdout);		/* �W������ �� �W���o�� */
	else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "�t�@�C��%s���������I�[�v���ł��܂���B\n", 
								*argv);
				return (1);
			} else {
				copy(fp, stdout);	/* �X�g���[��fp �� �W���o�� */
				fclose(fp);
			}
		}
	}
	return (0);
}
