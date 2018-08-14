/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:53 by adibou            #+#    #+#             */
/*   Updated: 2018/08/14 18:56:52 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pas de + &&  ' '
// . && # && Espaces && 0 && - (- prio)

#include "ft_printf.h"


static char	*hash(char *str, t_flags data, char c)
{
	if (!(data.forme & HASH))
		return (str);
	return (ft_strmjoin(c == 'x' ? "0x" : "0X", str, 2));
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
