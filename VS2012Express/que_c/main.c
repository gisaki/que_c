#include <stdio.h>
#include "que.h"

int main(void)
{
	TMyData data[MYDATA_NUM] = {
		{3, 1003}, 
		{4, 1004}, 
		{5, 1005}, 
		{6, 1005}, 
		/* à»ç~ÅA0x00 */
	};
	TMyData data1 = {1, 1001};
	TMyData data2 = {2, 1002};
	int i;

	my_app_addall(data);
	my_app_add(&data2);
	my_app_add(&data1);
	my_app_getall(data);

	for (i=0; i<MYDATA_NUM; i++)
	{
		printf("data[%d] = %d, %d\n", i, data[i].id, data[i].data); 
	}

	return 0;
}
