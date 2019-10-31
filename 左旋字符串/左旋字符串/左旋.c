#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Turn_left(char* s, int k) 
{
	int len = strlen(s);
	char* p = (char*)malloc((2 * len + 1)*sizeof(char));
	strcpy(p, s);
	strcat(p, s);
	strncpy(s, p + k, len);
	free(p);
}

int main()
{
	char str1[] = "ABCDEF";
	int k=2;
	printf("请输入要左旋的字符个数:");
	scanf("%d", &k);
	Turn_left(str1, k);
	printf("%s\n", str1);
	return 0;
}