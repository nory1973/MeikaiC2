/* �ÎZ�\�̓`�F�b�N�i0�`99�̐������l���Z����̂ɗv���鎞�Ԃ��v���j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c, d;			/* �����鐔�l */
	int x;					/* �ǂݍ��񂾒l */
	time_t start, end;		/* �J�n�����E�I������ */

	srand(time(NULL));		/* �����̎�������� */

	a = rand() % 100;		/* 0�`99�̗����𐶐� */
	b = rand() % 100;		/* �@�@�@ �V�@�@�@�@ */
	c = rand() % 100;		/* �@�@�@ �V�@�@�@�@ */
	d = rand() % 100;		/* �@�@�@ �V�@�@�@�@ */

	printf("%d + %d + %d + %d�͉��ł����F", a, b, c, d);

	start = time(NULL);						/* �v���J�n */

	while (1) {
		scanf("%d", &x);
		if (x == a + b + c + d)
			break;
		printf("\a�Ⴂ�܂���!!\n�ē��͂��Ă��������F");
	}

	end = time(NULL);						/* �v���I�� */

	printf("%.0f�b������܂����B\n", difftime(end, start));

	return (0);
}
