#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd;
	char *result;
	int rv;

	char *path = "example.txt";
	result = (char *)calloc(20, 1);
	fd = open(path, O_RDWR);
	close(fd);
	rv = read(fd, result, 7);
	printf("str: %s\nrv : %d\n", result, rv);
	free(result);
}