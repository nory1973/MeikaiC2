/* �j�������߂�i���̂P�Fmktime�֐��𗘗p�j*/

#include <time.h>
#include <stdio.h>

/*--- year�Nmonth��day���̗j�������߂� ---*/
int dayofweek(int year, int month, int day)
{
	struct tm t;

	t.tm_year  = year - 1900;	/* �N�𒲐� */
	t.tm_mon   = month - 1;		/* ���𒲐� */
	t.tm_mday  = day;			/* �� */
	t.tm_hour  = 0;				/* �� */
	t.tm_min   = 0;				/* �� */
	t.tm_sec   = 0;				/* �b */
	t.tm_isdst = -1;			/* �Ď��� */

	if (mktime(&t) == (time_t)-1)	/* �ϊ��Ɏ��s������ */
		return (-1);				/* -1��ԋp */
	return (t.tm_wday);			/* mktime�֐��ɂ���Đݒ肳�ꂽ�j����ԋp */
}

int main(void)
{
	int  y, m, d, w;
	char *ws[] = {"��", "��", "��", "��", "��", "��", "�y"};

	printf("�j�������߂܂��B\n");
	printf("�N�F");	  scanf("%d", &y);
	printf("���F");	  scanf("%d", &m);
	printf("���F");	  scanf("%d", &d);

	w = dayofweek(y, m, d);			/* �j�������߂� */

	if (w != -1)
		printf("�����%s�j���ł��B\n", ws[w]);
	else
		printf("���߂��܂���ł����B\n");

	return (0);
}
