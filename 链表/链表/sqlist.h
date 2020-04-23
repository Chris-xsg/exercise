#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
//typedef struct SList
//{
//	SListNode* _head;
//}SList;
void SListInit(SListNode** pplist);
void SListDestory(SListNode** pplist);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode** pplist, SLTDataType x);
void SListPushBack(SListNode** pplist, SLTDataType x);
void SListPopBack(SListNode** pplist);
SListNode* SListFind(SListNode* plist, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SListNode** pplist, SLTDataType x);
void SListPrint(SListNode* plist);