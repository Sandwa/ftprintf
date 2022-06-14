/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandratadjine <sandratadjine@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:16:28 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/13 21:56:16 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

void				ft_type(va_list *args, char *str, int i, int *ret);
int					ft_printf(const char *format, ...);
void				ft_putnbr_fd_printf(int n, int fd, int *ret);
void				ft_itoa_free(va_list *args, int *ret, char c);
void				ft_putchar_fd_printf(char c, int fd, int *ret);
void				ft_putstr_fd_printf(char *s, int fd, int *ret);
void				ft_printmod(va_list *args, char *str, int *i, int *ret);

#endif
