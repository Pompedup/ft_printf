/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:50:52 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/12 17:48:21 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*back;

	i = -1;
	if (!s)
		return (NULL);
	if (!(back = (char *)malloc(len + 1)))
		return (NULL);
	while (++i < len)
		back[i] = s[start++];
	back[i] = 0;
	return (back);
}
