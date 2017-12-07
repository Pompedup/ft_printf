/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:58:59 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/12 17:49:14 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*back;
	size_t	i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(back = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		back[++j] = s1[i];
	i = -1;
	while (s2[++i])
		back[++j] = s2[i];
	back[++j] = 0;
	return (back);
}
