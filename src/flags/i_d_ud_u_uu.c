/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_d_ud_u_uu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:53 by adibou            #+#    #+#             */
/*   Updated: 2018/08/16 14:31:36 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pas de #
** ' ' && . && + && Espaces && 0 && - (- prio)
*/

#include "ft_printf.h"

static char	*precision_d(char *str, int size, t_flags data)
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

static char	*space_d(char *str, int size, t_flags data)
{
	char	*tmp;
	int		signe;

	signe = 0;
	if (*str != '-' && !(data.forme & DOT || data.forme & ZERO))
		signe = data.forme & PLUS || data.forme & SPACE;
	if (data.space <= size + signe)
		return (str);
	if (data.forme & ZERO)
	{
		tmp = ft_strnewset('0', data.space - size);
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
	return (data.forme & MINUS ? ft_strmjoin(str, tmp, 3)
		: ft_strmjoin(tmp, str, 3));
}

char		*flags_decimal(char *str, int size, t_flags data, char c)
{
	(void)c;
	if (data.forme & ZERO && (data.forme & DOT || data.forme & MINUS))
		data.forme -= ZERO;
	if (*str == '0' && data.forme & DOT && data.precision == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	str = precision_d(str, *str == '-' ? size - 1 : size, data);
	if (data.forme & DOT || !(data.forme & ZERO))
		str = signe(str, ft_strlen(str), data);
	str = space_d(str, ft_strlen(str), data);
	str = signe(str, ft_strlen(str), data);
	return (str);
}

char		*flags_unsigned(char *str, int size, t_flags data, char c)
{
	(void)c;
	if (data.forme & ZERO && (data.forme & DOT || data.forme & MINUS))
		data.forme -= ZERO;
	if (*str == '0' && data.forme & DOT && data.precision == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	str = precision(str, size, data);
	str = space(str, ft_strlen(str), data);
	return (str);
}
