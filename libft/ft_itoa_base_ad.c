/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satadjin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:59:05 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/16 21:54:52 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check_ad(unsigned long long n, char *base)
{
	if (n == 0)
		return (ft_strdup("(nil)"));
	else
		return (ft_itoa_base_ad(n, base));
}

char	*ft_itoa_base_ad(unsigned long long n, char *base)
{
	char	*str;
	char	*s1;
	char	*s2;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	if (n >= (unsigned int)ft_strlen(base))
	{
		s1 = ft_itoa_base_ad(n / ft_strlen(base), base);
		s2 = ft_itoa_base_ad(n % ft_strlen(base), base);
		free(str);
		str = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
	}
	else if (n < (unsigned int)ft_strlen(base))
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
