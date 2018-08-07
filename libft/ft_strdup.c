/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:16:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/01/10 22:29:28 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*back;
	int		i;

	if (!(back = (char*)malloc(ft_strlen(src) + 1)))
		return (NULL);
	i = 0;
	while (*src)
		back[i++] = *(src++);
	back[i] = 0;
	return (back);
}
