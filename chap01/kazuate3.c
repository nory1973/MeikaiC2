/* �����ăQ�[���i���̂R�F������܂ŌJ��Ԃ��Fwhile���j*/

#include <stdio.h>

int main(void)
{
	int no;			/* �ǂݍ��񂾒l */
	int ans = 7;	/* ���Ă����鐔 */

	printf("0�`9�̐����𓖂ĂĂ��������B\n\n");

	while (1) {
		printf("�������ȁF");
		scanf("%d", &no);

		if (no > ans)
			printf("\a�����Ə�������B\n");
		else if (no < ans)
			printf("\a�����Ƒ傫����B\n");
		else
			break;
	}

	printf("�����ł��B\n");

	return (0);
}
