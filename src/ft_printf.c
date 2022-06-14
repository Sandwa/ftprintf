/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satadjin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:36:26 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/13 22:10:58 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printmod(va_list *args, char *str, int *i, int *ret)
{
	(*i)++;
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd'
		|| str[*i] == 'i' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'x'
		|| str[*i] == 'X' || str[*i] == '%')
		ft_type(args, str, *i, ret);
	else
	{
		ft_putchar_fd_printf('%', 1, ret);
		ft_putchar_fd_printf(str[*i], 1, ret);
	}
}

int	ft_printf(const char *format, ...)
{
	char		*str;
	int			i;
	int			ret;
	va_list		args;

	i = 0;
	ret = 0;
	va_start(args, format);
	str = (char *)format;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_printmod(&args, str, &i, &ret);
		else
			ft_putchar_fd_printf(str[i], 1, &ret);
		i++;
	}
	va_end(args);
	return (ret);
}
