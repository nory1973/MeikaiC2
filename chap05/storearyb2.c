/* �D���Ȍ������l��ǂݍ���ŗv�f��10�̔z��ɍŌ��10���i�[�i���̂Q�j*/

#include <stdio.h>

#define MAX		10			/* �z��̗v�f�� */

int main(void)
{
	int i;
	int a[MAX];				/* �ǂݍ��񂾒l���i�[����z�� */
	int cnt = 0;			/* �ǂݍ��񂾌� */
	int retry;				/* ������x�H */

	printf("��������͂��Ă��������B\n");

	do {
		printf("%d�ڂ̐����F", cnt + 1);
		scanf("%d", &a[cnt++ % MAX]);

		printf("�����܂����H�iYes�c1�^No�c0�j�F");
		scanf("%d", &retry);
	} while (retry == 1);

	i = cnt - MAX;
	if (i < 0) i = 0;

	for ( ; i < cnt; i++)
		printf("%2d�� : %d\n", i + 1, a[i % MAX]);

	return (0);
}
