#include <stdio.h>
#include <string.h>

int main()
{
	//기존 문자열의 '\0'문자까지 덮어쓰기 가능
	//함수 정상 실행되어 출력 시, 문자열의 끝을 인식하지 못한채 쓰레기값까지 출력 
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	memmove(str + 23, str + 19, 4);
	printf("Result: %s\n", str);
	return 0;
}
