/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:53 by adibou            #+#    #+#             */
/*   Updated: 2018/08/15 17:34:52 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pas de + &&  ' '
** . && # && Espaces && 0 && - (- prio)
*/

#include "ft_printf.h"

static char	*hash(char *str, t_flags data)
{
	if (!(data.forme & HASH))
		return (str);
	if (*str == '0')
		return (str);
	return (ft_strmjoin("0", str, 2));
}

/*
**static char	*space(char *str, int size, t_flags data)
**{
**	char *tmp;
**
**	if (data.space <= size)
**		return (str);
**	if (data.forme & 16 && !(data.forme & 8 || data.forme & 1))
**	{
**		tmp = ft_strnewset('0', data.space - size);
**		if (*str == '-')
**			str = negative_number(tmp, str, ft_strlen(tmp));
**		else
**			str = ft_strmjoin(tmp, str, 3);
**		return (str);
**	}
**	else
**		tmp = ft_strnewset(' ', data.space - size);
**	if (!tmp)
**		return (NULL);
**	return (data.forme & 8 ? ft_strmjoin(str, tmp, 3)
**		: ft_strmjoin(tmp, str, 3));
**}
*/

char		*flags_octal(char *str, int size, t_flags data, char c)
{
	(void)c;
	if (data.forme & ZERO && (data.forme & DOT || data.forme & MINUS))
		data.forme -= ZERO;
	if (*str == '0' && data.forme & DOT && data.precision == 0
		&& !(data.forme & HASH))
	{
		free(str);
		str = ft_strdup("");
	}
	if (*str == '0' && data.forme & HASH)
		data.forme -= HASH;
	if (data.forme & HASH && data.space > 1 && data.forme & ZERO)
		data.space -= 0/*1*/;
	str = precision(str, *str == '-' ? size - 1 : size, data);
	if ((data.forme & DOT && *str != '0') || !(data.forme & ZERO))
	{
		str = hash(str, data);
		if (data.forme & HASH)
			data.forme -= HASH;
	}
	str = space(str, ft_strlen(str), data);
	str = hash(str, data);
	return (str);
}


//d || D || s ||
