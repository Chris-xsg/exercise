#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Printarray(int* a, int n)
{
	for (size_t i = 0; i < n; ++i)
	{
		printf("%d", a[i]);
	}
}


void Insertsort(int* a, int n)
{
	
	for (int i = 0; i < n; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
	
	

}



void ShellSort(int* a,int n)
{
	//�������� ���Ϊgap�Ĳ�������
	//��gap > 1ʱ Ԥ����
	//��gap = 1ʱ ��������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = 0; i < n - gap; ++i)//ͬʱ��gap���������
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
	
	

}


void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		swap(&a[end], &a[maxi]);
		--end;
		++begin;
	}
	
}

void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child + 1] > a[child] && child+1<n)
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n) 
{
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
	
}


void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1]>a[i])
			{
				swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
		--end;
	}
	

}

//�������� 
//���������� O(N*N)  ÿ��ѡ��key������λ����� O(N*logN) 
//ʹ������ȡ�з��Ż�������������������
//С�����Ż�

//�ؼ��ַ�
//ѡ��һ��ֵΪ�ؼ��֣�end����
//ѡ���һ��ֵΪ�ؼ��֣�begin����

int PartSrot1(int* a, int begin, int end)//����
{
	int mid = GetMidIndex(a, begin, end);
	swap(&a[mid], a[begin]);

	int key = begin;//���Ϊkey
	while (begin < end)
	{
		//end����,��С
		while (begin < end && a[end] >= a[key])
		{
			--end;
		}
		//begin��,�Ҵ�
		while (begin < end && a[begin] <= a[key])
		{
			++begin;
		}
		swap(&a[begin], &a[end]);
	}
	swap(&a[key], &a[begin]);
	return begin;
}
//int PartSort2(int* a, int begin, int end)
//{
//	int mid = GetMidIndex(a, begin, end);
//	swap(&a[mid], a[end]);
//	int key = end;//�ұ�Ϊkey
//	while (begin < end)
//	{
//		//begin���ߣ��Ҵ�
//		while (begin < end && a[begin] <= a[key])
//		{
//			++begin;
//		}
//		//end���ߣ���С
//		while (begin < end && a[end] >= a[key])
//		{
//			--end;
//		}
//		swap(&a[begin], &a[end]);
//
//	}
//	swap(&a[key], &a[begin]);
//	return begin;
//}

//�ڿӷ�
int PartSrot3(int* a, int begin, int end)//����
{
	int mid = GetMidIndex(a, begin, end);
	swap(&a[mid], a[begin]);
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[begin] = a[end];
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[end] = a[begin];
	}
	a[begin] = key;
	return begin;
}

//ǰ��ָ��汾
int PartSort4(int* a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = end;
	while (cur < end)
	{
		/*if (a[cur] < a[key])
		{
			++prev;
			swap(&a[cur], &a[prev]);
			++cur;
		}
		else
		{
			++cur;
		}*/
		if (a[cur] < a[key] && ++prev != cur)
			swap(&a[cur], &a[prev]);
		++cur;
	}
	swap(&a[++prev], &a[key]);
	return prev;
}



int GetMidIndex(int* a, int begin, int end) //����ȡ��
{
	//int mid = (begin+end)
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin]>a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else //a[begin] > a[mid]
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}
void QuickSort(int*a, int left,int right)//�ݹ�
{  
	if (left >= right)
	{
		return;
	}
	if (right - left + 1 < 10) //С�����Ż�
	{
		Insertsort(a + left, right - left + 1);
	}
	else
	{
		int keyindex = PartSrot1(a, left, right);//keyindex--��key����λ��
		//[left,keyindex-1] keyindex [keyindex+1,right]
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	}
	
}

void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		int 

	}

}

//�鲢����
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	MergeSort(a, 0, n - 1, tmp);
	free(tmp);


}
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	int mid = (begin + end) / 2;
	//������������[begin,mid] [mid+1,end]�ݹ�����
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);


	//�鲢
	int begin1 = begin, begin2 = mid + 1;
	int end1 = mid, end2 = end;
	int index = begin;
	

}




