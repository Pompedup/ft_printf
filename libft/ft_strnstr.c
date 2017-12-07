/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:52:28 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/08 22:07:31 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
			while (str[i + j] != '\0' && to_find[j] != '\0' && i + j < len)
			{
				if (to_find[j + 1] == '\0' && str[i + j] == to_find[j])
					return ((char*)(str + i));
				j++;
			}
		i++;
	}
	return (0);
}
