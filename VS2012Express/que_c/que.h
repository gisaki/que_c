/* -------- */
/* ’è‹` */
/* -------- */

/* app layer */
struct MyData {
	int timestamp;
	int data;
};
#define MYDATA_NUM (10)
void my_app_addall(struct MyData *data);
void my_app_add(struct MyData *data);
void my_app_getall(struct MyData *data);
