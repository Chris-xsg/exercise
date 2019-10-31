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
	char* p = (char*)dest + (count - 1);//指针强制转换成char*类型,再向后移动到最后一个元素
	const char*p1 = (char*)src + (count - 1);//指针强制转换成char*类型,再向后移动到最后一个元素
	while (count--) 
	{
		*p = *p1;
		--p;      //从后往前拷贝
		--p1;
	}
	return dest;//返回值为目标字符串
}
int main() 
{
	char buf1[] = "hello world";
	char buf2[50] = { 0 };
	My_memcpy(buf2, buf1, 7);
	printf("%s\n", buf2);
	return 0;
}


int My_strcmp(const char* str1, const char* str2)//比较两个字符串的大小
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


const char* My_strchr(const char* str, char c)//查找字符串中某个字符首次出现的位置
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


char* My_strstr(const char* str1, const char* str2)//查找字符串中某个字符串出现的位置
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


char* my_strcat(char* dest, const char* src)//把某个字符串拼接到字符串数组后面
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



//char* my_strcpy(char* dst, const char* src)//拷贝字符串
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

int My_strlen(const char* s)//求字符串的长度
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