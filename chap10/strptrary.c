/* ������̔z��𓮓I�Ɋm�ہi�|�C���^�̔z��j*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int	num;			/* ������̌� */
	char **pt;

	printf("������͉��F");
	scanf("%d", &num);

	pt = (char **)calloc(num, sizeof(char *));

	if (pt == NULL) 
		puts("�L����̊m�ۂɎ��s���܂����B");
	else {
		int	i;

		for (i = 0; i < num; i++)
			pt[i] = NULL;

		for (i = 0; i < num; i++) {
			char temp[128];

			printf("pt[%d] : ", i);
			scanf("%s", temp);

			pt[i] = (char *)malloc(strlen(temp) + 1);

			if (pt[i] != NULL)
				strcpy(pt[i], temp);
			else {
				puts("�L����̊m�ۂɎ��s���܂����B");
 				goto Free;
			}
		}
		for (i = 0; i < num; i++)
			printf("pt[%d] = %s\n", i, pt[i]);
Free:
		for (i = 0; i < num; i++)
			free(pt[i]);
		free(pt);
	}

	return (0);
}
