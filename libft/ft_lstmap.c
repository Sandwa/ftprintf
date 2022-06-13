/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satadjin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:01:44 by satadjin          #+#    #+#             */
/*   Updated: 2022/06/13 21:01:47 by satadjin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = ft_lstnew((*f)(lst->content));
	if (tmp == NULL)
		return (0);
	begin = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew((*f)(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&begin, del);
			return (0);
		}
		tmp = tmp->next;
	}
	return (begin);
}
