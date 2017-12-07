/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:18:20 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/30 13:20:50 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	i;

	if (!(dest = malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = -1;
	while (++i < n)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
