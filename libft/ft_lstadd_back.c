/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satadjin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:00:10 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/13 21:00:13 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (alst && new)
	{
		lst = *alst;
		if (alst != NULL)
			alst = new;
		else
		{
			while (lst->next != NULL)
				lst = lst->next;
			lst->next = new;
		}
	}
}
