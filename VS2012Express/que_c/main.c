#include <stdio.h>
#include "que.h"

int main(void)
{
	struct MyData data[MYDATA_NUM] = {
		{3, 1003}, 
		{4, 1004}, 
		{5, 1005}, 
		/* à»ç~ÅA0x00 */
	};
	struct MyData data1 = {1, 1001};
	struct MyData data2 = {2, 1002};
	int i;

	my_app_addall(data);
	my_app_add(&data2);
	my_app_add(&data1);
	my_app_getall(data);

	for (i=0; i<MYDATA_NUM; i++)
	{
		printf("data[%d] = %d, %d\n", i, data[i].timestamp, data[i].data); 
	}

	return 0;
}
