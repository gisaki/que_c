#include <string.h>
#include "que.h"

/* -------- */
/* ��` */
/* -------- */

/* raw layer */
void my_que_addall(void *pdata, void *buf, int bufsize);
void my_que_add(void *pdata, int size, void *buf, int bufsize);
void my_que_getall(void *pdata, void *buf, int bufsize);

/* -------- */
/* ���� */
/* -------- */
#define MY_DI()
#define MY_EI()

static char my_app_buf[sizeof(struct MyData) * MYDATA_NUM];

void my_app_addall(struct MyData *data)
{
	MY_DI();
	{
		my_que_addall(data, my_app_buf, sizeof(my_app_buf));
	}
	MY_EI();
}

void my_app_add(struct MyData *data)
{
	MY_DI();
	{
		my_que_add(data, sizeof(struct MyData), my_app_buf, sizeof(my_app_buf));
	}
	MY_EI();
}

void my_app_getall(struct TMyData *data)
{
	MY_DI();
	{
		my_que_getall(data, my_app_buf, sizeof(my_app_buf));
	}
	MY_EI();
}


void my_que_addall(void *pdata, void *buf, int bufsize)
{
	memcpy(buf, pdata, bufsize);
}

void my_que_add(void *pdata, int size, void *buf, int bufsize)
{
	/* �擪�F�ŐV�A�����F�Ō� */

	/* 1�����ւ��炷 */
	int N = bufsize / size;
	int dst;
	for (dst=N-1; dst>=1; dst--)
	{
		char *p = (char *)buf;
		memcpy(p + dst * size, p + (dst-1) * size, size);
		/* 
		 * dst          src  
		 * +----+       +----+
		 * |    |       |    |
		 * +----+       +----+
		 * |    |   +-- |****|
		 * +----+   |   +----+
		 * |****| <-+   |    |
		 * +----+       +----+
		 */
	}

	/* �擪�֓o�^���� */
	memcpy(buf, pdata, size);
	/* 
	 * dst
	 * +----+ 
	 * |****|<--
	 * +----+ 
	 * |    | 
	 * +----+ 
	 * |    |
	 * +----+
	 */
}

void my_que_getall(void *pdata, void *buf, int bufsize)
{
	memcpy(pdata, buf, bufsize);
}
