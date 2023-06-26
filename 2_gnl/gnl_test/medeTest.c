#include "get_next_line.h"

char *create_buff(int fd, char **buff)
{
	int rv;

	if (*buff)
		return (*buff);
	*buff = (char *)malloc(BUFFER_SIZE + 1);
	if (*buff == NULL)
		return (NULL);
	rv = read(fd, *buff, BUFFER_SIZE);
	if (rv < 0)
	{
		free(*buff);
		return (NULL);
	}
	else if (rv == 0)
	{
		free(*buff);
		*buff = (char *)malloc(1);
		**buff = '\0';
		return (*buff);
	}
	*(*buff + BUFFER_SIZE) = '\0';
	return (*buff);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t total_len;
	char *str;
	char *new;

	total_len = 0;
	str = s1;
	while (*str++)
		total_len++;
	str = s2;
	while (*str++)
		total_len++;
	new = (char *)malloc(total_len + 1);
	if (new == NULL)
		return (NULL);
	str = new;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (new);
}

char *get_str(int index, char **bbuff)
{
	char *new;
	char *buff;
	int input_index;

	new = (char *)malloc(index + 2);
	if (!new)
	{
		free(new);
		free(*bbuff);
		return (NULL);
	}
	*(new + index) = '\n';
	*(new + index + 1) = '\0';
	input_index = -1;
	while (++input_index < index)
		*(new + input_index) = *(*bbuff + input_index);
	buff = ft_strjoin("", (*bbuff + index + 1));
	free(*bbuff);
	*bbuff = buff;
	return (new);
}

char *get_last(int index, char **bbuff)
{
	char *new;
	int input_index;

	new = (char *)malloc(index + 1);
	if (!new)
	{
		free(new);
		free(*bbuff);
		return (NULL);
	}
	*(new + index) = '\0';
	input_index = -1;
	while (++input_index < index)
		*(new + input_index) = *(*bbuff + input_index);
	free(*bbuff);
	*bbuff = NULL;
	return (new);
}

char *decision_rv(int fd, char **bbuff, int index)
{
	char *buff;
	char *tmp;

	if (*(*bbuff + index) == '\n')
		return (get_str(index, bbuff));
	buff = NULL;
	create_buff(fd, &buff);
	if (!buff)
	{
		free(*bbuff);
		return (NULL);
	}
	if (*buff == '\0')
	{
		free(buff);
		return (get_last(index, bbuff));
	}
	tmp = ft_strjoin(*bbuff, buff);
	free(buff);
	free(*bbuff);
	*bbuff = tmp;
	return (get_next_line(fd));
}

char *get_next_line(int fd)
{
	static char *bbuff;
	int index;

	if (!create_buff(fd, &bbuff))
		return (NULL);
	index = 0;
	while (*(bbuff + index) != '\n' && *(bbuff + index) != '\0')
		index++;
	return (decision_rv(fd, &bbuff, index));
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *str;

	char path1[] = "example.txt";
	fd = open(path1, O_RDWR);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}