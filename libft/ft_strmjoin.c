/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:26:45 by abezanni          #+#    #+#             */
/*   Updated: 2018/01/10 21:01:38 by abezanni         ###   ########.fr       */
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
	if (!(back = ft_strjoin(s1, s2)))
		return (NULL);
	if (s1 && tofree % 2)
		free(s1);
	if (s2 && tofree / 2)
		free(s2);
	return (back);
}
