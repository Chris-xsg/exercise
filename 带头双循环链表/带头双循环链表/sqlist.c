#define _CRT_SECURE_NO_WARNINGS 1
#include"sqslist.h"

ListNode* ListInit(List* plist)
{
	plist->_head = NULL;
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
	return plist->_head;

}
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}
void ListPushBack(List* plist, LTDataType x)//Î²²å
{
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = plist->_head->_prev;
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = plist->_head;
	plist->_head->_prev = newnode;


}
void ListPrint(List* plist)
{
	ListNode* cur = plist;
	while (cur!= (plist->_head))
	{
		printf("head->%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
