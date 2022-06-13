#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*m;

	i = 0;
	m = (unsigned char *)s;
	while (m[i] != '\0' && i < n)
	{
		if (m[i] == c)
			return (m + i);
		i++;
	}
	return (NULL);
}
