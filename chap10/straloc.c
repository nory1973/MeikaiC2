/* ������𓮓I�Ɋm�� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char st[16];
	char *pt;

	printf("������st����͂��Ă��������F");
	scanf("%s", st);

	pt = malloc(strlen(st) + 1);	/* �L����𓮓I�Ɋm�� */

	if (pt) {
		strcpy(pt, st);				/* ��������R�s�[ */
		printf("���̕�����̕���pt�����܂����B\n");
		printf("st = %s\n", st);
		printf("pt = %s\n", pt);
		free(pt);					/* �L�������� */
	}

	return (0);
}
