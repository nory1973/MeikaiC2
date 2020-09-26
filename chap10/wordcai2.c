/* �p�P��w�K�\�t�g�i���_�����ށj*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define QNO	   12		/* �P��̐� */
#define CNO	    4		/* �I�����̐� */

/*--- ���{�� ---*/
char *jptr[] = {
	"����", "��",	"��",	"��",	"��",	"�{",
	"�֎q", "��",	"��",	"��",	"���a",	"�G��",
};

/*--- �p�� ---*/
char *eptr[] = {
	"animal", "car",	"flower", "house", "desk",	"book",
	"chair",  "father",	"mother", "love",  "peace",	"magazine",
};

/*--- �I������\�� ---*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d) %s  ", i, sw ? jptr[c[i]] : eptr[c[i]]);
	printf("�F");
}

/*--- �l�̑I�������쐬���Đ����̓Y����Ԃ� ---*/
int make_cand(int c[], int n)
{
	int	i;

	c[0] = n;							/* �擪�v�f�ɐ��������� */
	for (i = 1; i < CNO; i++)			/* ����ȍ~�̗v�f�� */
		c[i] = rand() % QNO;			/* 0�ȏ�QNO�����̒l */

	return (0);
}

int main(void)
{
	int nq, pq;			/* ���̔ԍ��E�O��̖��ԍ� */
	int na;				/* �����̔ԍ� */
	int sw;				/* ���̌���i0�F���{��^1�F�p��j */
	int retry;			/* �Ē��킷�邩�H */
	int cand[CNO];		/* �I�����̔ԍ� */

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
				puts("\a�Ⴂ�܂��B");
		} while (no != na);
		puts("�����ł��B");

		pq = nq;

		printf("������x�H 0-�������^1-�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	return (0);
}