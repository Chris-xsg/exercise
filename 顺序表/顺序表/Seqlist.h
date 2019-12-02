//#pragma once
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType*   _a; //ָ��̬���ٵ�����
	size_t _size;     //��Ч���ݵĸ���
	size_t _capacity; //�ռ������Ĵ�С
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);
void SeqListPrint(SeqList* ps);

void SeqListCheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopFront(SeqList* ps);

int SeqListFind(SeqList* ps, SLDataType x);//����
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//����
void SeqListErase(SeqList* ps, size_t pos);//ɾ��
void SeqListRemove(SeqList* ps, SLDataType x);

void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, SLDataType x);

#endif //__SEQLIST_H__