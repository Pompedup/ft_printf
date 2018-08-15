/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:53 by adibou            #+#    #+#             */
/*   Updated: 2018/08/15 15:05:55 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pas de . + #
** Espaces && 0 && - (- prio)
*/

#include "ft_printf.h"

char	*char_null(char *str, t_flags data)
{
	free(str);
	if (data.forme & ZERO && !(data.forme & MINUS))
		str = ft_strnewset('0', data.space);
	else
		str = ft_strnewset(' ', data.space);
	str[data.forme & MINUS ? 0 : data.space - 1] = 0;
	return (str);
}

char	*flags_char(char *str, int size, t_flags data, char c)
{
	char *back;

	if (data.space <= size)
		return (str);
	if (*str == '\0' && ft_strchr("%cC", c))
		return (char_null(str, data));
	if (data.forme & ZERO && !(data.forme & MINUS))
		back = ft_strnewset('0', data.space - size);
	else
		back = ft_strnewset(' ', data.space - size);
	if (!back)
		return (NULL);
	return (data.forme & 8 ? ft_strmjoin(str, back, 3)
		: ft_strmjoin(back, str, 3));
}
