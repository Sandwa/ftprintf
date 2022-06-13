/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandratadjine <sandratadjine@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:36:26 by satadjin          #+#    #+#             */
/*   Updated: 2019/12/25 18:50:20 by sandratadji      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void	ft_initialize_check(t_check *check)
{
	check->flagzero = 0;
	check->flagspace = 0;
	check->flagplus = 0;
	check->flagdash = 0;
	check->width = 0;
	check->precision = 0;
}

void	ft_printmod(va_list *args, char *str, int *i)
{
	t_check		*check;

	check = (t_check *)malloc(sizeof(t_check));
	ft_initialize_check(check);
	(*i)++;
	ft_flags(str, check, i);
	ft_width(str, check, i);
	ft_precision(str, check, i);
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd'
		|| str[*i] == 'i' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'x'
		|| str[*i] == 'X' || str[*i] == '%')
		ft_type(args, str, *i);
	else
		ft_putchar_fd(str[*i], 1);
}

int	ft_printf(const char *format, ...)
{
	char		*str;
	int			i;
	int			ret;
	va_list		args;

	i = 0;
	va_start(args, format);
	str = (char *)format;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_printmod(&args, str, &i);
		else
		{
			ft_putchar_fd(str[i], 1);
			ret = ft_strlen(str);
		}
		
	//	printf(" str = %c\n", str[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
