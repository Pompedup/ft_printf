/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:10:58 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/12 23:46:22 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *back;
	t_list *tmp;
	t_list *elem;

	if (!lst)
		return (NULL);
	elem = f(lst);
	if (!(back = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	tmp = back;
	lst = lst->next;
	while (lst)
	{
		elem = f(lst);
		if (!(tmp->next = ft_lstnew(elem->content, elem->content_size)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (back);
}
