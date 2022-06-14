/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satadjin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:56:57 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/13 22:11:26 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_fd_printf(int n, int fd, int *ret)
{
	if (n == -2147483648)
		ft_putstr_fd_printf("-2147483648", fd, ret);
	else if (n < 0)
	{
		ft_putchar_fd_printf('-', fd, ret);
		ft_putnbr_fd_printf(-n, fd, ret);
	}
	else if (n < 10)
		ft_putchar_fd_printf(n + '0', fd, ret);
	else if (n >= 10)
	{
		ft_putnbr_fd_printf(n / 10, fd, ret);
		ft_putchar_fd_printf(n % 10 + '0', fd, ret);
	}
}

void	ft_putchar_fd_printf(char c, int fd, int *ret)
{
	write(fd, &c, 1);
	(*ret)++;
}

void	ft_putstr_fd_printf(char *s, int fd, int *ret)
{
	int	i;

	i = 0;
	if (s == NULL)
		ft_putstr_fd_printf("(null)", fd, ret);
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd_printf(s[i], fd, ret);
			i++;
		}
	}
}

void	ft_itoa_free(va_list *args, int *ret, char c)
{
	char	*str;
	char	*s1;

	str = NULL;
	if (c == 'p')
	{
		s1 = ft_itoa_base_ad(va_arg(*args, unsigned long long),
				"0123456789abcdef");
		str = ft_strjoin("0x", s1);
		free(s1);
		ft_putstr_fd_printf(str, 1, ret);
	}
	if (c == 'x')
	{
		str = ft_itoa_base(va_arg(*args, unsigned int), "0123456789abcdef");
		ft_putstr_fd_printf(str, 1, ret);
	}
	if (c == 'X')
	{
		str = ft_itoa_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
		ft_putstr_fd_printf(str, 1, ret);
	}
	if (str)
		free(str);
}
