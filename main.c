#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char	*next_line;
	int	line_count;
    
	if (ac != 2)
	{
		printf("You must add one and only one file as an argument\n");
		return (1);
	}
	if (fd < 0)
	{
		printf("Invalid file descriptor\n");
		return (1);
	}
	next_line = get_next_line(fd);
	line_count = 1;
	while (next_line != NULL)
	{
		printf("line %i: %s", line_count, next_line);
		free(next_line);
		next_line = get_next_line(fd);
		line_count++;
	}
	close(fd);
	return (0);
}
