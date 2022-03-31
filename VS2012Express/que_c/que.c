#include <string.h>
#include "que.h"

/* -------- */
/* 定義 */
/* -------- */

/* raw layer */
void my_que_addall(void *pdata, void *buf, int bufsize);
void my_que_add(void *pitem, int itemsize, void *buf, int bufsize);
void my_que_getall(void *pdata, void *buf, int bufsize);

/* -------- */
/* 実装 */
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
	/* 先頭：最新、末尾：最古 */

	/* 1つずつ後ろへずらす */
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

	/* 先頭へ登録する */
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
