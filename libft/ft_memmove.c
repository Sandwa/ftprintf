/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satadjin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:03:39 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/13 21:03:41 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
