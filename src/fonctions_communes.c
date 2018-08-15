/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_communes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:46:35 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/15 13:01:51 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*negative_number(char *begin, char *end, int size_begin)
{
	char *back;

	if (!(back = malloc(sizeof(char) * (size_begin + ft_strlen(end) + 1))))
		return (NULL);
	back[0] = '-';
	ft_strcpy(back + 1, begin);
	free(begin);
	ft_strcpy(back + size_begin + 1, end + 1);
	free(end);
	return (back);
}

/*
**p && x && o && u
*/

char	*precision(char *str, int size, t_flags data)
{
	char *tmp;

	if (!(data.forme & DOT) || !(data.precision > size))
		return (str);
	if (!(tmp = ft_strnewset('0', data.precision - size)))
		return (NULL);
	str = ft_strmjoin(tmp, str, 3);
	return (str);
}

/*
**o && u && x
*/

char	*space(char *str, int size, t_flags data)
{
	char *tmp;

	if (data.space <= size)
		return (str);
	if (data.forme & ZERO)
		tmp = ft_strnewset('0', data.space - size);
	else
		tmp = ft_strnewset(' ', data.space - size);
	if (!tmp)
		return (NULL);
	return (data.forme & MINUS ? ft_strmjoin(str, tmp, 3)
		: ft_strmjoin(tmp, str, 3));
}
