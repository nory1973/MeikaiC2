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
