/* �p�P��w�K�\�t�g����Łi���{��̒P��^�p�P��������_���ɕ\���j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define	QNO	   12		/* �P��̐� */

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

int main(void)
{
	int nq, pq;			/* ���ԍ��E�O��̖��ԍ� */
	int sw;				/* 0�F���{��^1�F�p�� */
	int retry;			/* �Ē��킷�邩�H */

	srand(time(NULL));	/* �����̎�������� */

	pq = QNO;			/* �O��̖��ԍ��i���݂��Ȃ��ԍ��j */

	do {
		do {					/* �����P���A�����ďo�肵�Ȃ� */
			nq = rand() % QNO;
		} while (nq == pq);

		sw = rand() % 2;		/* ���{�� or �p�� */

		printf("%s\n", sw ? eptr[nq] : jptr[nq]);

		pq = nq;

		printf("������x�H 0-�������^1-�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	return (0);
}
