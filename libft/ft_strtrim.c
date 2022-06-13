#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	int		start;
	int		end;
	char	*newstr;

	start = 0;
	end = ft_strlen(str) - 1;
	newstr = 0;
	if (set && str)
	{
		while (str[start] && ft_strchr(set, str[start]))
			start++;
		while (str[end] && ft_strchr(set, str[end]) && end > start)
			end++;
		newstr = (char *)malloc(sizeof(char) * end - start + 1);
		if (newstr)
			ft_strlcpy(newstr, &str[start], end - start + 1);
	}
	return(newstr);
}
