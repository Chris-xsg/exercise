//#pragma once
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType*   _a; //指向动态开辟的数组
	size_t _size;     //有效数据的个数
	size_t _capacity; //空间容量的大小
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);
void SeqListPrint(SeqList* ps);

void SeqListCheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopFront(SeqList* ps);

int SeqListFind(SeqList* ps, SLDataType x);//查找
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//插入
void SeqListErase(SeqList* ps, size_t pos);//删除
void SeqListRemove(SeqList* ps, SLDataType x);

void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, SLDataType x);

#endif //__SEQLIST_H__