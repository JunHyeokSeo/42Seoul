#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

int main()
{
	int	fd;
	int result;

	char buff[BUFFER_SIZE];
	char *path2 = "example.txt";
	fd = open(path2, O_RDWR);
	result = read(fd, buff, BUFFER_SIZE);
	printf("rv : %d\n", result);
	printf("str : %s\n", buff);
	close(fd);
}