#include "get_next_line_bonus.h"

char	*free_and_null(char **memory)
{
	free(*memory);
	*memory = NULL;
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*ch;

	ch = s;
	while (*ch != '\0')
	{
		if (*ch == (char)c)
			return ((char *)ch);
		ch++;
	}
	if (c == '\0')
		return ((char *)ch);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*buff;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	buff = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (buff == NULL)
		return (NULL);
	while (*s1)
	{
		buff[i++] = *s1++;
	}
	while (*s2)
	{
		buff[i++] = *s2++;
	}
	buff[i] = '\0';
	return (buff);
}
