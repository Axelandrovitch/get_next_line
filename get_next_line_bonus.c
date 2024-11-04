#include "get_next_line_bonus.h"

char	*clean_stash(char **stash)
{
	char	*new_stash;
	char	*new_line;

	new_line = ft_strchr(*stash, '\n');
	if (!new_line)
	{
		free(*stash);
		return (NULL);
	}
	new_line++;
	if (!new_line)
	{
		free(*stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(new_line) + 1));
	if (!new_stash)
	{
		free(*stash);
		return (NULL);
	}
	ft_memcpy(new_stash, new_line, ft_strlen(new_line) + 1);
	free(*stash);
	return (new_stash);
}

char	*store_next_line(char *stash)
{
	char	*buffer;
	size_t	len;

	len = 0;
	while (stash[len] != '\n' && stash[len] != '\0')
	{
		len++;
	}
	buffer = malloc(sizeof(char) * (len + 2));
	if (!buffer)
	{
		return (NULL);
	}
	if (stash[len] == '\n')
	{
		len++;
	}
	buffer[len] = '\0';
	ft_memcpy(buffer, stash, len);
	return (buffer);
}

int	get_in_stash(char *buffer, char **stash)
{
	char	*new_stash;

	new_stash = ft_strjoin(*stash, buffer);
	if (!new_stash)
	{
		free(*stash);
		return (0);
	}
	free(*stash);
	*stash = new_stash;
	return (1);
}

char	*read_from_file(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!get_in_stash(buffer, stash))
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(*stash, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read == -1)
		*stash = free_and_null(stash);
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FILES];
	char		*next_line;

	next_line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		stash[fd] = free_and_null(&stash[fd]);
		return (NULL);
	}
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char));
		if (!stash[fd])
			return (NULL);
		stash[fd][0] = '\0';
	}
	stash[fd] = read_from_file(fd, &stash[fd]);
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		stash[fd] = free_and_null(&stash[fd]);
		return (NULL);
	}
	next_line = store_next_line(stash[fd]);
	stash[fd] = clean_stash(&stash[fd]);
	return (next_line);
}
