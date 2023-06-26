#include<string.h>
#include<stdio.h>

char *ft_strrchr(const char *s, int c)
{
	//마지막 문자의 위치를 저장하기 위해 포인터 생성
	//c와 같은 문자 발견 시 최신화
	char *local_s;

	local_s = NULL;
	while (*s)
	{
		//최신화
		if (*s == c)
			local_s = (char *)s;
		s++;
	}
	if (c == '\0')
		local_s = (char *)s;
	
	// 반환 경우의 수 세가지
	// 1. 못 찾음
	// 2-1. 찾음
	// 2-2. 찾았는데 그 문자가 EOF
	if (local_s == NULL)
		return (0);
	else
		return (local_s);
}

int main()
{
	char a[50] = "42seoul junhseo";
	char *b;
	b = ft_strrchr(a, 52);
	printf("%s\n", b);
	b = strrchr(a, 52);
	printf("%s\n", b);
}