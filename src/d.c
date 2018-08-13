/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:53 by adibou            #+#    #+#             */
/*   Updated: 2018/08/12 10:29:02 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pas de #
// ' ' && . && + && Espaces && 0 && - (- prio)

#include "ft_printf.h"

static char	*negative_number(char *begin, char *end, int size_begin)
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

static char	*precision(char *str, int size, t_flags data)
{
	char *tmp;

	if (!(data.forme & DOT) || !(data.precision > size))
		return (str);
	if (!(tmp = ft_strnewset('0', data.precision - size)))
		return (NULL);
	if (*str == '-')
		str = negative_number(tmp, str, ft_strlen(tmp));
	else
		str = ft_strmjoin(tmp, str, 3);
	return (str);
}

static char	*signe(char *str, int size, t_flags data)
{
	if (!(data.forme & SPACE || data.forme & PLUS))
		return (str);
	if (*str == '0' && data.space > 1 && !(data.forme & DOT
		&& data.precision == size) && size >= data.space)
		*str = data.forme & PLUS ? '+' : ' ';
	else if (data.forme & PLUS && !ft_strchr("- +", *str))
		str = ft_strmjoin("+", str, 2);
	else if (data.forme & SPACE && !ft_strchr("- +", *str))
		str = ft_strmjoin(" ", str, 2);
	return (str);
}
#include <stdio.h>
static char	*space(char *str, int size, t_flags data)
{
	char *tmp;

	if (data.space <= size || data.space - size -
		((data.forme & PLUS || data.forme & SPACE) && *str != '-'
		&& !(data.forme & DOT || data.forme & ZERO)) < 1)
		return (str);
	if (data.forme & ZERO && !(data.forme & 8 || data.forme & 1))
	{
		tmp = ft_strnewset('0', data.space - size -
			 ((data.forme & PLUS || data.forme & SPACE) && *str != '-'
		&& !(data.forme & DOT || data.forme & ZERO)));
		if (*str == '-')
			str = negative_number(tmp, str, ft_strlen(tmp));
		else
			str = ft_strmjoin(tmp, str, 3);
		return (str);
	}
	else
		tmp = ft_strnewset(' ', data.space - size);
	if (!tmp)
		return (NULL);
	return (data.forme & 8 ? ft_strmjoin(str, tmp, 3) : ft_strmjoin(tmp, str, 3));
}

char	*flags_decimal(char *str, int size, t_flags data)
{
	if (data.forme & ZERO && (data.forme & DOT || data.forme & MINUS))
		data.forme -= ZERO;
	if (*str == '0' && data.forme & DOT && data.precision == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	str = precision(str, *str == '-' ? size - 1 : size, data);
	if (data.forme & DOT || !(data.forme & ZERO))
		str = signe(str, ft_strlen(str), data);
	str = space(str, ft_strlen(str), data);
	str = signe(str, ft_strlen(str), data);
	return (str);
}
