#define _CRT_SECURE_NO_WARNINGS 1
#include"sqslist.h"

void test()
{
	ListNode* plist = ListInit(plist);
	ListPushBack(plist, 0);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPrint(plist);

}

int main()
{
	test();
	return 0;
}