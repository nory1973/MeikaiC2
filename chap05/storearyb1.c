/* �D���Ȍ������l��ǂݍ���ŗv�f��10�̔z��ɍŌ��10���i�[�i���̂P�j*/

#include <stdio.h>

#define	MAX		10			/* �z��̗v�f�� */

int main(void)
{
	int i;
	int a[MAX];				/* �ǂݍ��񂾒l���i�[����z�� */
	int cnt = 0;			/* �ǂݍ��񂾌� */
	int retry;				/* ������x�H */

	printf("��������͂��Ă��������B\n");

	do {
		if (cnt >= MAX) {		/* MAX+1�ڈȍ~��ǂݍ��ޑO�� */
			for (i = 0; i < MAX - 1; i++)	/* �v�fa[1]�`a[MAX-1]�� */
				a[i] = a[i + 1];			/* ��擪���ɂ��炷 */
		}
		printf("%d�ڂ̐����F", cnt + 1);
		scanf("%d", &a[cnt < MAX ? cnt : MAX - 1]);
		cnt++;

		printf("�����܂����H�iYes�c1�^No�c0�j�F");
		scanf("%d", &retry);
	} while (retry == 1);

	if (cnt <= MAX)					/* �ǂݍ��񂾂̂�MAX�ȉ� */
		for (i = 0; i < cnt; i++)
			printf("%2d�� : %d\n", i + 1, a[i]);
	else							/* �ǂݍ��񂾂̂�MAX��葽�� */
		for (i = 0; i < MAX; i++)
			printf("%2d�� : %d\n", cnt - MAX + 1 + i, a[i]);

	return (0);
}
