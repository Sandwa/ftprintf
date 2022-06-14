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
