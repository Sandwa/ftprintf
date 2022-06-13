#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa_base(-n, base));
	}
	else if (n >= (int)ft_strlen(base))
		str = ft_strjoin(ft_itoa_base(n / ft_strlen(base), base), 
		ft_itoa_base(n % ft_strlen(base), base));
	else if (n < (int)ft_strlen(base) && n >= 0)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
