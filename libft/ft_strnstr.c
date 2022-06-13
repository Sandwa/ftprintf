#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_nd;

	i = 0;
	len_nd = ft_strlen(nd);
	if (len_nd > len)
		return (NULL);
	if (len_nd == 0)
		return ((char *)hs);
	while (hs[i] != '\0' && i < len)
	{
		j = 0;
		while (hs[i + j] == nd[j] && nd[j] != '\0' && hs[i + j] != '\0'
			&& i + j < len)
			j++;
		if (nd[j] == '\0')
			return ((char *)hs + i);
		i++;
	}
	return (NULL);
}
