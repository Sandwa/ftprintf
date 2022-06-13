#include "libft.h"

char	*ft_itoa_base_ad(unsigned long long n, char *base)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	else if (n >= ft_strlen(base))
		str = ft_strjoin(ft_itoa_base_ad(n / ft_strlen(base), base), 
		ft_itoa_base_ad(n % ft_strlen(base), base));
	else if (n < ft_strlen(base) && n >= 0)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
