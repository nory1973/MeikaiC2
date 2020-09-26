/*--- �v�f�ʂ̎�����asctime�֐��ɏ����ĕϊ��i���s�����͕t�����Ȃ��j---*/
char *asctime2(const struct tm *timeptr)
{
	const char wday_name[7][3] = {					/* �j�� */
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	};
	const char mon_name[12][3] = {					/* ���� */
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};
	static char result[25];				/* ������i�[��͐ÓI�ȗ̈� */

	sprintf(result, "%.3s %.3s %02d %02d:%02d:%02d %4d",
					wday_name[timeptr->tm_wday], mon_name[timeptr->tm_mon],
					timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min,
					timeptr->tm_sec,  timeptr->tm_year + 1900);
	return (result);
}
