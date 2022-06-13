/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandratadjine <sandratadjine@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:16:28 by satadjin          #+#    #+#             */
/*   Updated: 2019/12/25 18:46:41 by sandratadji      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_check
{
	int				flagzero;
	int				flagspace;
	int				flagplus;
	int				flagdash;
	int				width;
	int				precision;
}					t_check;


int					ft_flags(char *str, t_check *check, int *i);
void				ft_precision(char *str, t_check *check, int *i);
void				ft_type(va_list *args, char *str, int i);
void				ft_width(char *str, t_check *check, int *i);
int					ft_printf(const char *format, ...);
void				ft_printmod(va_list *args, char *str, int *i);
void				ft_initialize_check(t_check *check);

#endif
