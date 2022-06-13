#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	char		*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (s < d && d > s + len)
	{
		while (i < len)
		{
			i++;
			d[i] = s[i];
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
