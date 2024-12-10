#include "SeqList.h"

int main() {
	SeqList sl;
	/*操作之前先初始化！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
	SeqListInit(&sl);
	/*操作之前先初始化！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/

	SeqListPushHead(&sl, 1);
	SeqListPushHead(&sl, 2);
	SeqListPushHead(&sl, 3);
	SeqListPushHead(&sl, 4);
	SeqListPushHead(&sl, 5);
	SeqListPushHead(&sl, 6);
	SeqListPushHead(&sl, 7);
	SeqListPushPos(&sl, 666, 2);
	SeqListPrint(&sl);

	int ret = SeqListFind(&sl, 7);
	printf("%d\n", ret);

	SeqListPopPos(&sl, 3);
	SeqListPrint(&sl);

	return 0;
}


