/* -------- */
/* ’è‹` */
/* -------- */

/* app layer */
typedef struct _MyData {
	int id;
	int data;
} TMyData;
#define MYDATA_NUM (5)
void my_app_addall(TMyData *buf);
void my_app_add(TMyData *item);
void my_app_getall(TMyData *buf);
