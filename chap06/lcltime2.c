/* ���݂̓��t�E������\���i���̂Q�Fasctime�֐��𗘗p�j*/

#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t current = time(NULL);	/* ���݂̎������擾 */

	printf("���݂̓��t�E�����F%s", asctime(localtime(&current)));

	return (0);
}
