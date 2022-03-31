#include <string.h>
#include "que.h"

/* -------- */
/* ��` */
/* -------- */

/* raw layer */
void my_que_addall(void *pdata, void *buf, int bufsize);
void my_que_add(void *pitem, int itemsize, void *buf, int bufsize);
void my_que_getall(void *pdata, void *buf, int bufsize);

/* -------- */
/* ���� */
/* -------- */
#define LOCAL_DI()
#define LOCAL_EI()

static char my_app_buf[sizeof(TMyData) * MYDATA_NUM];

void my_app_addall(TMyData *buf)
{
	LOCAL_DI();
	{
		my_que_addall(buf, my_app_buf, sizeof(my_app_buf));
	}
	LOCAL_EI();
}

void my_app_add(TMyData *item)
{
	LOCAL_DI();
	{
		my_que_add(item, sizeof(TMyData), my_app_buf, sizeof(my_app_buf));
	}
	LOCAL_EI();
}

void my_app_getall(TMyData *buf)
{
	LOCAL_DI();
	{
		my_que_getall(buf, my_app_buf, sizeof(my_app_buf));
	}
	LOCAL_EI();
}


void my_que_addall(void *pdata, void *buf, int bufsize)
{
	memcpy(buf, pdata, bufsize);
}

void my_que_add(void *pitem, int itemsize, void *buf, int bufsize)
{
	/* �擪�F�ŐV�A�����F�Ō� */

	/* 1�����ւ��炷 */
	int N = bufsize / itemsize;
	int dst;
	for (dst=N-1; dst>=1; dst--)
	{
		char *p = (char *)buf;
		memcpy(p + dst * itemsize, p + (dst-1) * itemsize, itemsize);
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
	memcpy(buf, pitem, itemsize);
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
