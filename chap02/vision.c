/* ���E��������g��P�������˂��ÎZ�g���[�j���O */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int stage;
	int a, b, c;						/* ���Z���鐔�l */
	int x;								/* �ǂݍ��񂾒l */
	int n;								/* �]���̕� */
	clock_t	start, end;					/* �J�n�����E�I������ */

	srand(time(NULL));					/* �����̎�������� */

	printf("����g��ÎZ�g���[�j���O�J�n!!\n");
	start = clock();					/* �v���J�n */

	for (stage = 0; stage < 10; stage++) {
		a = 10 + rand() % 90;			/* 10�`99�̗����𐶐� */
		b = 10 + rand() % 90;			/* �@�@�@�@�V�@�@�@�@ */
		c = 10 + rand() % 90;			/* �@�@�@�@�V�@�@�@�@ */
		n = rand() % 17;				/*  0�`16�̗����𐶐� */

		printf("%d%*s+%*s%d%*s+%*s%d�F", a, n, "", n, "", b, n, "", n, "", c);

		do {
			scanf("%d", &x);
			if (x == a + b + c)
				break;
			printf("\a�Ⴂ�܂��B�ē��͂��Ă��������F");
		} while (1);
	}

	end = clock();						/* �v���I�� */

	printf("%.1f�b������܂����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	return (0);
}
