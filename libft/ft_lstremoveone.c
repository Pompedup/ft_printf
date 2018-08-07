/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:27:14 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/08 15:16:06 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **alst, size_t content_size)
{
	t_list *pre;
	t_list *tmp;
	t_list *next;

	if (!(*alst))
		return ;
	pre = NULL;
	tmp = *alst;
	next = tmp->next;
	while (tmp && tmp->content_size != content_size)
	{
		pre = tmp;
		tmp = tmp->next;
		next = tmp->next;
	}
	if (pre == NULL)
		*alst = next;
	else
		pre->next = next;
	if (tmp->content)
		free(tmp->content);
	tmp->content = NULL;
	free(tmp);
	tmp = NULL;
}
