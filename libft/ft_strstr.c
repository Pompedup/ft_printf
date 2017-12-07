/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:23:30 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/08 22:08:22 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != 0)
	{
		j = 0;
		if (str[i] == to_find[j])
			while (str[i + j] != '\0' && to_find[j] != '\0')
			{
				if (to_find[j + 1] == '\0' && str[i + j] == to_find[j])
					return ((char*)(str + i));
				j++;
			}
		i++;
	}
	return (0);
}
