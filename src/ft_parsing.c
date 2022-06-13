#include "../include/ft_printf.h"
#include <stdio.h>

void	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
//	if (n == -2147483647)
//		ft_putstr_fd("-2147483648", fd);
//	if (n < 0)
//	{
//		ft_putchar_fd('-', fd);
//		ft_putnbr_fd(-n, fd);
//	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else if (n > 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
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

void	ft_type(va_list *args, char *str, int i)
{
	if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr_fd(va_arg(*args, int), 1);
	if (str[i] == 'c')
		ft_putchar_fd(va_arg(*args, int), 1);
	if (str[i] == 's')
		ft_putstr_fd(va_arg(*args, char *), 1);
	if (str[i] == 'p')
		ft_putstr_fd(ft_strjoin("0x",
				ft_itoa_base_ad(va_arg(*args, unsigned long long),
					"0123456789abcdef")), 1);
	if (str[i] == 'u')
		ft_putnbr_fd_unsigned(va_arg(*args, unsigned int), 1);
	if (str[i] == 'x')
		ft_putstr_fd(
			ft_itoa_base(va_arg(*args, unsigned int), "0123456789abcdef"), 1);
	if (str[i] == 'X')
		ft_putstr_fd(
			ft_itoa_base(va_arg(*args, unsigned int), "0123456789ABCDEF"), 1);
	if (str[i] == '%')
		ft_putchar_fd('%', 1);
}
