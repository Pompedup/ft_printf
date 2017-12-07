/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:16:51 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/09 21:40:00 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
