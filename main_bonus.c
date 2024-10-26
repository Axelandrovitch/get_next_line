#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("You must provide at least one file name\n");
		return (1);
	}
	int fd1 = open(av[1], O_RDONLY);
	int fd2 = open(av[2], O_RDONLY);
	int fd3 = open(av[3], O_RDONLY);
	int fd4 = open(av[4], O_RDONLY);
	char	*next_line;
	int	line_count;

	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		printf("Invalid file descriptor\n");
		return (1);
	}
	next_line = get_next_line(fd1);
	line_count = 1;
	while (next_line != NULL)
	{
		printf("line %i: %s", line_count, next_line);
		free(next_line);
		next_line = get_next_line(fd2);
		printf("line %i: %s", line_count, next_line);
		free(next_line);
		next_line = get_next_line(fd3);
		printf("line %i: %s", line_count, next_line);
		free(next_line);
		next_line = get_next_line(fd4);
		printf("line %i: %s", line_count, next_line);
		free(next_line);
		next_line = get_next_line(fd1);
		line_count++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
