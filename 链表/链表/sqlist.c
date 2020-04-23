#define _CRT_SECURE_NO_WARNINGS 1
#include"sqlist.h"

//void SListInit(SListNode* plist)
//{
//	SListNode *plist = NULL;
//}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}
void SListPushBack(SListNode** pplist, SLTDataType x) //尾插
{
	SListNode* newnode = BuySListNode(x);
	
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->_next != NULL)
		{

			tail = tail->_next;
		}
		tail->_next = newnode;
	}
}
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
void SListPushFront(SListNode** pplist, SLTDataType x) //头插
{
	SListNode* newnode = BuySListNode(x);
	
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		*pplist = newnode;
		newnode->_next = tail;
		

	}
}

void SListPopBack(SListNode** pplist) //尾删
{
	SListNode* tail = *pplist;
	SListNode* prev = NULL;
	if (tail == NULL || tail->_next == NULL)
	{
		free(tail);
		tail = tail->_next;
	}
	else
	{
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		tail = NULL;
		prev->_next = NULL;
	}
	
}
SListNode* SListFind(SListNode* plist, SLTDataType x) //查找
{
	while (plist)
	{
		if (plist->_data == x)
		{
			return 1;
		}
		else
			plist = plist->_next;
	}
	return NULL;
	
}
void SListInsertAfter(SListNode* pos, SLTDataType x)// 在pos的后面进行插入
{
	SListNode* newnode = BuySListNode(x);
	newnode->_next = pos->_next;
	pos->_next = newnode;

}