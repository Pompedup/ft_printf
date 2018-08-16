/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_uo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:22:10 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 14:23:01 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hash(char *str, t_flags data)
{
	if (!(data.forme & HASH))
		return (str);
	if (*str == '0')
		return (str);
	return (ft_strmjoin("0", str, 2));
}

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
