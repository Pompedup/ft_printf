/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:53 by adibou            #+#    #+#             */
/*   Updated: 2018/08/14 01:42:41 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pas de + &&  ' '
// . && # && Espaces && 0 && - (- prio)

#include "ft_printf.h"

static char	*precision(char *str, int size, t_flags data)
{
	char *tmp;

	if (!(data.forme & DOT) || !(data.precision > size))
		return (str);
	if (!(tmp = ft_strnewset('0', data.precision - size)))
		return (NULL);
	str = ft_strmjoin(tmp, str, 3);
	return (str);
}

static char	*hash(char *str, t_flags data, char c)
{
	if (!(data.forme & HASH))
		return (str);
	return (ft_strmjoin(c == 'x' ? "0x" : "0X", str, 2));
}

static char	*space(char *str, int size, t_flags data)
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

char	*flags_hexa(char *str, int size, t_flags data, char c)
{
	if (data.forme & ZERO && (data.forme & DOT || data.forme & MINUS))
		data.forme -= ZERO;
	if (*str == '0')
	{
		if (data.forme & HASH)
			data.forme -= HASH;
		if (data.forme & DOT && data.precision == 0)
		{
			free(str);
			str = ft_strdup("");
		}
	}
	if (data.forme & HASH && data.space > 1 && data.forme & ZERO)
		data.space -= 2;
	str = precision(str, *str == '-' ? size - 1 : size, data);
	if (data.forme & DOT || !(data.forme & ZERO))
	{
		str = hash(str, data, c);
		if (data.forme & HASH)
			data.forme -= HASH;
	}
	str = space(str, ft_strlen(str), data);
	str = hash(str, data, c);
	return (str);
}
