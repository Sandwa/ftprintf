#include "libft.h"

void	ft_striteri(char *s, char (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, s + i);
		i++;
	}
	s[i] = '\0';
}
