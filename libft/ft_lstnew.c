/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:25:51 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/24 15:01:40 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *back;

	if (!(back = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(back->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(back->content, content, content_size);
		back->content_size = content_size;
	}
	else
	{
		back->content = NULL;
		back->content_size = 0;
	}
	back->next = NULL;
	return (back);
}
