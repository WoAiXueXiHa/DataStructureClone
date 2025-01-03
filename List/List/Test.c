#include "List.h"

int main() {
	ListNode* list = ListInit();

	/*ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);*/

	ListPushFront(list, 1);
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 4);
	/*ListNode* find = ListFind(list, 2);
	ListInsert(find, 666);*/

	/*ListNode* find = ListFind(list, 4);
	ListErase(find);*/

	ListPrint(list);

	return 0;
}