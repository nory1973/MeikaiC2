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
