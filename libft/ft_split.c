/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satadjin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:05:24 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/13 21:05:26 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
}

char	*ft_strndup(char const *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, (char *)s, n);
	return (str);
}

static int	ft_count_s(char const *s, char c)
{
	int	i;
	int	nb_s;

	i = 0;
	nb_s = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nb_s++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (nb_s);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count_s(str, c) + 1));
	if (!tab)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(str + j, i - j);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
