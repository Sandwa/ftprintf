#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *)s;
	if (n != 0)
	{
		while (i < n)
		{
			t[i] = 0;
			i++;
		}
	}
}
