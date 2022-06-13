/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satadjin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:07:17 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/13 21:07:19 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (dstsize != 0 && (ft_strlen(dst) < dstsize))
	{
		while (dst[i] != '\0')
			i++;
		while (i < dstsize && src[j] != '\0')
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (ft_strlen(dst));
}
