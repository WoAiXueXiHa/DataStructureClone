#include "Stack.h"
#include "Queue.h"
//int main() {
//
//	ST s;
//	STInit(&s);
//	STPush(&s, 1);
//	STPush(&s, 2);
//	STPush(&s, 3);
//	STPush(&s, 4);
//	STPush(&s, 5);
//
//	while (!STEmpty(&s))
//	{
//		int top = STTopVal(&s);
//		printf("%d ", top);
//		STPop(&s);
//	}
//
//	STDestory(&s);
//
//	return 0;
//}

int main() {
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q)) {
		printf("%d ", QueueFrontVal(&q));
		QueuePop(&q);
	}

	QueueDestory(&q);

	return 0;
}