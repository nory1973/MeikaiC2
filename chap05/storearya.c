/* �ő�10�̒l��ǂݍ���ŗv�f��10�̔z��Ɋi�[ */

#include <stdio.h>

#define	MAX		10		/* �z��̗v�f�� */

int main(void)
{
	int i;
	int a[MAX];			/* �ǂݍ��񂾒l���i�[����z�� */
	int cnt = 0;		/* �ǂݍ��񂾌� */
	int retry;			/* ������x�H */

	printf("��������͂��Ă��������B\n");
	printf("���͂ł���͍̂ő��%d�ł��B\n", MAX);

	do {
		printf("%d�ڂ̐����F", cnt + 1);
		scanf("%d", &a[cnt++]);

		if (cnt == MAX)				/* cnt���ׂĂ̓��͂����������� */
			break;					/* �I�� */

		printf("�����܂����H (Yes�c1�^No�c0)�F");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < cnt; i++)
		printf("%2d�� : %d\n", i + 1, a[i]);

	return (0);
}
