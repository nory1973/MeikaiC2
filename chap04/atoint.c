/* �����̓Ǎ��݁i���̂Q�F������Ƃ��ēǂݍ���ŕϊ��j*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char temp[20];		/* �Ǎ��ݗp������ */

	printf("��������͂��Ă��������F");
	scanf("%s", temp);

	printf("%d�Ɠ��͂��܂����ˁB\n", atoi(temp));

	return (0);
}
