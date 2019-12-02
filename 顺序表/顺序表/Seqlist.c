#define _CRT_SECURE_NO_WARNINGS 1


#include"Seqlist.h"


void SeqListInit(SeqList* ps)//初始化
{
	ps->_a = NULL;
	ps->_size = 0;
	ps->_capacity = 0;

}
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_size = ps->_capacity = 0;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}
void SeqListCheckCapacity(SeqList* ps)//检查空间大小
{
	assert(ps);
	if (ps->_size >= ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a=realloc(ps->_a, ps->_capacity * sizeof(SLDataType));
		ps->_capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* ps, SLDataType x) //尾插
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->_a[ps->_size++] = x;
}
void SeqListPopBack(SeqList* ps)//尾删
{
	assert(ps&&ps->_size>0);
	ps->_size--;
}
void SeqListPushFront(SeqList* ps, SLDataType x)//头插
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int end = ps->_size;
	for (; end >= 0; --end)
	{
		ps->_a[end + 1] = ps->_a[end];
	}
	ps->_a[0] = x;
	ps->_size++;
}
void SeqListPopFront(SeqList* ps)//头删
{
	assert(ps && ps->_size>0);
	for (size_t i = 1; i < ps->_size; ++i)
	{
		ps->_a[i - 1] = ps->_a[i];
	}
	ps->_size--;

}
int SeqListFind(SeqList* ps, SLDataType x)//查找
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_a[i] == x)
		{
			return i;
		}
		
	}
	return -1;

}
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)//插入
{
	assert(ps&&pos<ps->_size);
	SeqListCheckCapacity(ps);
	size_t end = ps->_size+1;
	while (end > pos)
	{
		ps->_a[end] = ps->_a[end - 1];
		--end;
	}
	ps->_a[pos] = x;
	ps->_size++;
}
void SeqListErase(SeqList* ps, size_t pos)//删除
{
	assert(ps && pos < ps->_size);
	size_t i = pos + 1;
	while (i < ps->_size)
	{
		ps->_a[i - 1] = ps->_a[i];
		++i;
	}
	ps->_size--;

}
void SeqListRemove(SeqList* ps, SLDataType x)
{
	int pos = SeqListFind(ps, x);
	if (pos >= 0)
	{
		SeqListErase(ps, pos);
	}
}

void SeqListBubbleSort(SeqList* ps)
{
	for (size_t end = ps->_size; end > 0; --end)
	{
		for (size_t i = 0; i < ps->_size; ++i)
		{
			if (ps->_a[i]>ps->_a[i + 1])
			{
				SLDataType tmp = ps->_a[i];
				ps->_a[i] = ps->_a[i + 1];
				ps->_a[i + 1] = tmp;
			}
		}
	}
	
}