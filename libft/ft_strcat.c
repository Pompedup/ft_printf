/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:36:49 by abezanni          #+#    #+#             */
/*   Updated: 2018/01/10 22:43:20 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int i;

	i = 0;
	while (dst[i])
		i++;
	while (*src)
		dst[i++] = *(src++);
	dst[i] = '\0';
	return (dst);
}
