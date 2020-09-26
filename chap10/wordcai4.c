/* �P��w�K�v���O�����i���̂S�F�P����t�@�C������ǂݍ��ށj*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	CNO		4		/* �I�����̐� */

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int	QNO;				/* �P��̐� */
char **jptr;			/* ���{��P��ւ̃|�C���^�̔z�� */
char **eptr;			/* �p�@��P��ւ̃|�C���^�̔z�� */

/*--- �I������\�� ---*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d) %s  ", i, sw ? jptr[c[i]] : eptr[c[i]]);
	printf("�F");
}

/*--- �I�������쐬���Đ����̓Y����Ԃ� ---*/
int make_cand(int c[], int n)
{
	int i, j, x;

	c[0] = n;						/* �擪�v�f�ɐ��������� */

	for (i = 1; i < CNO; i++) {
		do {						/* �d�����Ȃ��悤�ɗ����𐶐� */
			x = rand() % QNO;
			for (j = 0; j < i; j++)
				if (c[j] == x)		/* ���ɓ��������������ς� */
					break;
		} while (i != j);
		c[i] = x;
	}

	j = rand() % CNO;
	if (j != 0)
		swap(int, c[0], c[j]);	/* �������ړ� */

	return (j);
}

/*--- �P���ǂݍ��� ---*/
int read_tango(void)
{
	int	i;
	FILE *fp;

	if ((fp = fopen("TANGO", "r")) == NULL) return (1);

	fscanf(fp, "%d", &QNO);			/* �P�ꐔ��ǂݍ��� */

	if ((jptr = calloc(QNO, sizeof(char *))) == NULL) return (1);
	if ((eptr = calloc(QNO, sizeof(char *))) == NULL) return (1);

	for (i = 0; i < QNO; i++) {
		char etemp[1024];
		char jtemp[1024];

		fscanf(fp, "%s%s", etemp, jtemp);
		if ((eptr[i] = malloc(strlen(etemp) + 1)) == NULL) return (1);
		if ((jptr[i] = malloc(strlen(jtemp) + 1)) == NULL) return (1);
		strcpy(eptr[i], etemp);
		strcpy(jptr[i], jtemp);
	}
	fclose(fp);

	return (0);
}

int main(void)
{
	int i;
	int	nq, pq;			/* ���ԍ��E�O��̖��ԍ� */
	int	na;				/* �����̔ԍ� */
	int	sw;				/* ���̌���i0�F���{��^1�F�p��j */
	int	retry;			/* �Ē��킷�邩�H */
	int	cand[CNO];		/* �I�����̔ԍ� */

	if (read_tango() == 1) {
		printf("\a�P��t�@�C���̓Ǎ��݂Ɏ��s���܂����B\n");
		return (1);
	}
	srand(time(NULL));	/* �����̎�������� */

	pq = QNO;			/* �O��̖��ԍ��i���݂��Ȃ��ԍ��j */

	do {
		int	no;

		do {						/* �����P���A�����ďo�肵�Ȃ� */
			nq = rand() % QNO;
		} while (nq == pq);

		na = make_cand(cand, nq);	/* �I�������쐬 */
		sw = rand() % 2;

		printf("%s�͂ǂ�ł����H\n", sw ? eptr[nq] : jptr[nq]);

		do {
			print_cand(cand, sw);	/* �I������\�� */
			scanf("%d", &no);
			if (no != na)
				puts("�Ⴂ�܂��B");
		} while (no != na);
		puts("�����ł��B");

		pq = nq;

		printf("������x�H 0-�������^1-�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < QNO; i++) {
		free(eptr[i]);
		free(jptr[i]);
	}
	free(jptr);
	free(eptr);

	return (0);
}
