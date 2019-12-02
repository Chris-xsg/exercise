#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"


void test1()
{
	SeqList ps;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPrint(&ps);
	SeqListPushFront(&ps, 0);
	SeqListPrint(&ps);
	SeqListPopFront(&ps);
	SeqListPrint(&ps);

}
int main()
{
	test1();

	return 0;
}