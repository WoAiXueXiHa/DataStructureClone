#include "SList.h"

int main() {
	SLTNode* plist = NULL;
	SLTPushHead(&plist,1);
	SLTPushHead(&plist,2);
	SLTPushHead(&plist,3);
	SLTPushHead(&plist,4);
	SLTPrint(plist);


	/*SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);*/
	/*SLTPopBack(&plist);
	SLTPopBack(&plist);*/
	/*SLTPoplist(&plist);*/

	SLTNode* find = SLTFind(plist, 2);
	SLTPushPosFront(&plist, find, 9);
	SLTPrint(plist);

	SLTNode* find0 = SLTFind(plist, 9);
	SLTPushPosAfter(find0, 100);
	SLTPrint(plist);

	SLTNode* find1 = SLTFind(plist, 100);
	SLTPopPosAfter(find1);
	SLTPrint(plist);

	SLTNode* find2 = SLTFind(plist, 100);
	SLTPopPos(&plist, find2);
	SLTPrint(plist);


	return 0;
}
