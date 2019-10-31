#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>


# if 0
void * My_memmove(void * dest, const void * src, size_t count)
{
	void * ret = dest;
	if (dest <= src || (char *)dest >= ((char *)src + count))
	{
		while (count--)
		{
			*(char *)dest = *(char *)src;
			dest = (char *)dest + 1;
			src = (char *)src + 1;
		}
	}
	else
	{
		dest = (char *)dest + count - 1;
		src = (char *)src + count - 1;
		while (count--)
		{
			*(char *)dest = *(char *)src;
			dest = (char *)dest - 1;
			src = (char *)src - 1;
		}
	}
	return ret;
}
int main()
{
	char arr1[1024] = "";
	char arr2[1024] = "ABCDEF";
	My_memmove(arr1, arr2, 4);
	printf("%s\n", arr1);
	return 0;
}
	
	


void* My_memcpy(void* dest, const void* src, size_t count) 
{
	assert(dest != NULL);
	assert(src != NULL);
	char* p = (char*)dest + (count - 1);//ָ��ǿ��ת����char*����,������ƶ������һ��Ԫ��
	const char*p1 = (char*)src + (count - 1);//ָ��ǿ��ת����char*����,������ƶ������һ��Ԫ��
	while (count--) 
	{
		*p = *p1;
		--p;      //�Ӻ���ǰ����
		--p1;
	}
	return dest;//����ֵΪĿ���ַ���
}
int main() 
{
	char buf1[] = "hello world";
	char buf2[50] = { 0 };
	My_memcpy(buf2, buf1, 7);
	printf("%s\n", buf2);
	return 0;
}


int My_strcmp(const char* str1, const char* str2)//�Ƚ������ַ����Ĵ�С
{
	while ((*str1 != '\0') && (*str2 != '\0'))
	{
		if (*str1 < *str2)
		{
			return -1;
		}
		else if (*str1>*str2)
		{
			return 1;
		}
		else
		{
			++str1;
			++str2;
		}
	}
	if (*str1 < *str2)
	{
		return -1;
	}
	else if (*str1>*str2)
	{
		return 1;
	}
	return 0;

	
}
int main()
{
	char str1[] = "hello";
	char str2[] = "world";
	int ret = My_strcmp(str1, str2);
	printf("%d\n", ret);
	return 0;

}


const char* My_strchr(const char* str, char c)//�����ַ�����ĳ���ַ��״γ��ֵ�λ��
{
	assert(str);
	const char* s = str;
	while (*s != '\0')
	{
		if (*s == c)
		{
			return s;
		}
		++s;
	}
}
int main()
{
	char str[] = "hello world";
	const char* str1 = My_strchr(str, 'w');
	printf("%s\n", str1);
	return 0;
}


char* My_strstr(const char* str1, const char* str2)//�����ַ�����ĳ���ַ������ֵ�λ��
{
	assert(str1);
	assert(str2);
	const char* p1 = (char*)str1;
	const char* p2 = (char*)str2;
	const char* s1 = NULL;
	if (!*str2 )
	{
		return NULL;
	}
	while (*p1)
	{
		s1 = p1;
		p2 = (char*)str2;
		while (*s1 && *p2 && (*s1 == *p2))
		{
			s1++;
			p2++;

		}
		if (!*p2)
		{
			return p1;
		}
		p1++;

	}
	return NULL;
}
int main()
{
	char str[] = "This is a simple string";
	char* pch;
	pch = My_strstr(str, "simple");
	printf("%s\n", pch);
	return 0;
}


char* my_strcat(char* dest, const char* src)//��ĳ���ַ���ƴ�ӵ��ַ����������
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++);
	return ret;

}
int main()
{
	char str1[] = "hello";
	char* str2 = "world";
	printf("%s\n", my_strcat(str1, str2));
	return 0;
}



//char* my_strcpy(char* dst, const char* src)//�����ַ���
//{
//	assert(dst);
//	assert(src);
//	char* ret = dst;
//	while (*dst++ = *src++);
//	return ret;
//}
//
//int main()
//{
//	const char* str = "hello";
//	char* p[10];
//	printf("%s\n", my_strcpy(p, str));
//	return 0;
//}

int My_strlen(const char* s)//���ַ����ĳ���
{
	assert(s);
	int count=0;
	while (*s)
	{
		count++;
		s++;
	}
	return count;
}
int main()
{
	char str[] = "hello";
	printf("%d\n", My_strlen(str));
	return 0;
}
# endif