/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:53 by adibou            #+#    #+#             */
/*   Updated: 2018/08/12 18:53:00 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pas de + &&  ' ' #
// . && Espaces && 0 && - (- prio)

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

static char	*space(char *str, int size, t_flags data, char c)
{
	char *tmp;

	if (data.space <= size)
		return (str);
	if (!(tmp = ft_strnewset(c, data.space - size)))
		return (NULL);
	return (data.forme & MINUS ? ft_strmjoin(str, tmp, 3) : ft_strmjoin(tmp, str, 3));
}

char	*flags_address(char *str, int size, t_flags data)
{
	char *tmp;

	if (data.forme & ZERO && (data.forme & DOT || data.forme & MINUS))
		data.forme -= ZERO;
	tmp = ft_strdup(str + 2);
	free(str);
	str = tmp;
	size -= 2;
	if (*str == '0' && data.forme & DOT && data.precision == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	str = precision(str, size, data);
	if (data.forme & ZERO)
		str = space(str, ft_strlen(str) + 2, data, '0');
	str = ft_strmjoin("0x", str, 2);
	str = space(str, ft_strlen(str), data, ' ');
	return (str);
}
