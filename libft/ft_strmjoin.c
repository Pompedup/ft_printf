/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:26:45 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/01 18:39:16 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmjoin(char *s1, char *s2)
{
	char	*back;
	int		i;

	i = 0;
	back = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (*s1)
		back[i++] = *(s1++);
	s1 = s1 - i;
	while (*s2)
		back[i++] = *(s2++);
	back[i] = 0;
	free(s1);
	return (back);
}
