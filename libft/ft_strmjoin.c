/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:26:45 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/15 15:44:29 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmjoin(char *s1, char *s2, int tofree)
{
	char	*back;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s1 || s2))
		return (NULL);
	back = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1 && *s1)
		back[i++] = *(s1++);
	s1 = s1 - i;
	while (s2 && *s2)
		back[i + j++] = *(s2++);
	s2 = s2 - j;
	back[i + j] = 0;
	if (s1 && tofree % 2)
		free(s1);
	if (s2 && tofree / 2)
		free(s2);
	return (back);
}
