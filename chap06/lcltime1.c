/* ���݂̓��t�E������\���i���̂P�j*/

#include <time.h>
#include <stdio.h>

/*--- ���t�E������\�� ---*/
void put_date(struct tm *timer)
{
	char *wday_name[] = {"��", "��", "��", "��", "��", "��", "�y"};

	printf("%4d�N%02d��%02d��(%s)%02d��%02d��%02d�b",
			timer->tm_year + 1900,		/* �N */
			timer->tm_mon + 1,			/* �� */
			timer->tm_mday, 			/* �� */
			wday_name[timer->tm_wday],	/* �j�� */
			timer->tm_hour,				/* ��*/
			timer->tm_min,				/* ��*/
			timer->tm_sec				/* �b*/
		  );
}

int main(void)
{
	time_t current;					/* ����i�P��̎Z�p�^�j*/
	struct tm *timer;				/* �v�f�ʂ̎����i�\���́j*/

	time(&current);					/* ���݂̎������擾 */
	timer = localtime(&current);	/* �v�f�ʂ̎����i�n�����j�ɕϊ� */

	printf("���݂̓��t�E������");
	put_date(timer);
	printf("�ł��B\n");

	return (0);
}
