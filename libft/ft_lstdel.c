/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:56:51 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/12 22:37:02 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *next;

	if (!(*alst))
		return ;
	tmp = *alst;
	next = tmp->next;
	while (next)
	{
		tmp = next;
		next = tmp->next;
		ft_lstdelone(&tmp, del);
	}
	ft_lstdelone(alst, del);
}
