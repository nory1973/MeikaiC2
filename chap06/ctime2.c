/*--- time_t�^�ɂ�鎞����ctime�֐��ɏ����ĕϊ��i���s�����͕t�����Ȃ��j---*/
char *ctime2(const time_t *timer)
{
	return (asctime2(localtime(timer)));
}
