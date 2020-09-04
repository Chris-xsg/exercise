#include <string.h>

// 清除字符串右边的空格
void rtrim(char *str)
{
	if ( str == NULL )
		return ;
	int len = strlen(str);
	
	while ( len > 0 && str[len-1] == ' ' ) {
		str[--len] = 0;
	}
}

// 清除字符串左边的空格
void ltrim(char *str)
{
	if ( str == NULL )
		return ;
	int len = strlen(str);
	char *ptmp = str;
	if ( *ptmp != ' ')
		return;

	while ( *ptmp != '\0' ) {
		if ( *ptmp != ' ' )
			break;
		ptmp++;
	}
	
	char *ptmp2 = str;
	while ( *ptmp != '\0' ) {
		*ptmp2++ = *ptmp++;
	}
	*ptmp2 = '\0';
}

