/* �}�X�^�[�}�C���h */

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- ���قȂ�l�̐����̕��т𐶐����Ĕz��x�Ɋi�[ ---*/
void make4digits(int x[])
{
	int i, j, val;

	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 10;			/* 0�`9�̗��� */
			for (j = 0; j < i; j++)		/* ���̐������ɓ����Ă��邩 */
				if (val == x[j])
					break;
		} while (j < i);		/* �d�����Ȃ��l��������܂ŌJ��Ԃ� */
		x[i] = val;
	}
}

/*--- ���͂��ꂽ������s�̑Ó������`�F�b�N ---*/
int check(const char s[])
{
	int i, j;

	if (strlen(s) != 4)			/* ������̒�����4�łȂ� */
		return (1);

	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return (2);			/* �����ȊO�̕������܂܂�Ă��� */
		for (j = 0; j < i; j++)
			if (s[i] == s[j])
				return (3);		/* ����̐������܂܂�Ă��� */
	}

	return (0);					/* ������͑Ó� */
}

/*--- �q�b�g���u���[�̔��� ---*/
void judge(const char s[], const int no[], int *hit, int *blow)
{
	int i, j;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j])	/* ��������v */
				if (i == j)
					(*hit)++;			/* �q�b�g�i�ʒu����v�j */
				else
					(*blow)++;			/* �u���[�i�ʒu���s��v�j */
		}
	}
}

/*--- ���茋�ʂ�\�� ---*/
void print_result(int snum, int spos)
{
	if (spos == 4)
		printf("�����ł�!!");
	else if (snum == 0)
		printf("�@�@�����̐����͂܂������܂܂�܂���B\n");
	else {
		printf("�@�@�����̐�����%d�̐������܂܂�܂��B\n", snum);

		if (spos == 0)
			printf("�@�@�������ʒu�������Ă��鐔���͂���܂���B\n");
		else
			printf("�@�@���̒���%d�͈ʒu�������Ă��܂��B\n", spos);
	}
	putchar('\n');
}

int main(void)
{
	int try_no = 0;		/* ���͉� */
	int chk;			/* ���͂��ꂽ������̃`�F�b�N���� */
	int hit;			/* �ʒu���������������Ă���� */
	int blow;			/* �������������Ĉʒu���������Ă��Ȃ������̌� */
	int no[4];			/* ���Ă鐔���̕��� */
	char buff[10];		/* �ǂݍ��ސ����̕��т��i�[���镶���� */
	clock_t	start, end;				/* �J�n�����E�I������ */

	srand(time(NULL));				/* �����̎�������� */

	puts("�� �}�X�^�[�}�C���h�����܂��傤�B");
	puts("�� �l�̐����̕��т𓖂ĂĂ��������B");
	puts("�� ���������������܂܂�邱�Ƃ͂���܂���B");
	puts("�� 4307�̂悤�ɘA�����ē��͂��Ă��������B");
	puts("�� �X�y�[�X�����Ȃǂ���͂��Ă͂����܂���B\n");

	make4digits(no);					/* ���قȂ�l�̐����̕��т𐶐� */

	start = clock();					/* �v���J�n */

	do {
		do {
			printf("���͂��Ă��������F");
			scanf("%s", buff);			/* ������Ƃ��ēǂݍ��� */

			chk = check(buff);			/* �ǂݍ��񂾕�������`�F�b�N */

			switch (chk) {
			 case 1: puts("\a������ƂS�����œ��͂��Ă��������B"); break;
			 case 2: puts("\a�����ȊO�̕�������͂��Ȃ��ł��������B"); break;
			 case 3: puts("\a����̐����𕡐����͂��Ȃ��ł��������B"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, no, &hit, &blow);	/* ���� */
		print_result(hit + blow, hit);	/* ���茋�ʂ�\�� */

	} while (hit < 4); 

	end = clock();						/* �v���I�� */

	printf("%d�񂩂���܂����B\n���v���Ԃ�%.1f�b�ł����B\n",
							try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return (0);
}
