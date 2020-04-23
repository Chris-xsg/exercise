#define _CRT_SECURE_NO_WARNINGS 1

#include"sqlist.h"


void TestSqlist()
{
	SListNode* plist = NULL;
	SListPushBack(&plist,1);
	SListPushBack(&plist,2);
	SListPushBack(&plist,3);
	SListPushBack(&plist,4);
	SListPushBack(&plist,5);
	SListPrint(plist);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	printf("%d\n", SListFind(plist, 2));
	SListInsertAfter(2, 6);
	SListPrint(plist);

}
int main()
{

	TestSqlist();
	return 0;
}