/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satadjin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:56:57 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/13 22:11:26 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_fd_unsigned(unsigned int n, int fd, int *ret)
{
	if (n < 10)
		ft_putchar_fd_printf(n + '0', fd, ret);
	else if (n >= 10)
	{
		ft_putnbr_fd_unsigned(n / 10, fd, ret);
		ft_putchar_fd_printf(n % 10 + '0', fd, ret);
	}
}

int	ft_flags(char *str, t_check *check, int *i)
{
	while (str[*i] == '-' || str[*i] == ' ' || str[*i] == '0' || str[*i] == '+')
	{
		if (str[*i] == '-')
			check->flagdash = 1;
		if (str[*i] == '+')
			check->flagplus = 1;
		if (str[*i] == '0')
			check->flagzero = 1;
		if (str[*i] == ' ')
			check->flagspace = 1;
		*i += 1;
	}
	if (check->flagplus == 1 && check->flagspace == 1)
		check->flagspace = 0;
	if (check->flagdash == 1 && check->flagzero)
		check->flagzero = 0;
	return (*i);
}

void	ft_width(char *str, t_check *check, int *i)
{
	if (ft_isdigit(str[*i]))
		check->width = ft_atoi(str + *i);
	while (ft_isdigit(str[*i]))
		(*i)++;
}

void	ft_precision(char *str, t_check *check, int *i)
{
	if (str[*i] == '.')
	{
		(*i)++;
		if (ft_isdigit(str[*i]))
			check->precision = ft_atoi(&str[*i]);
	}
	while (ft_isdigit(str[*i]) || str[*i] == '*')
		(*i)++;
}

void	ft_type(va_list *args, char *str, int i, int *ret)
{
	if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr_fd_printf(va_arg(*args, int), 1, ret);
	if (str[i] == 'c')
		ft_putchar_fd_printf(va_arg(*args, int), 1, ret);
	if (str[i] == 's')
		ft_putstr_fd_printf(va_arg(*args, char *), 1, ret);
	if (str[i] == 'p')
		ft_itoa_free(args, ret, str[i]);
	if (str[i] == 'u')
		ft_putnbr_fd_unsigned(va_arg(*args, unsigned int), 1, ret);
	if (str[i] == 'x')
		ft_itoa_free(args, ret, str[i]);
	if (str[i] == 'X')
		ft_itoa_free(args, ret, str[i]);
	if (str[i] == '%')
		ft_putchar_fd_printf('%', 1, ret);
}
