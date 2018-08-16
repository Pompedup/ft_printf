/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_uc_s_us.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:53 by adibou            #+#    #+#             */
/*   Updated: 2018/08/16 14:29:48 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pas de . + #
** Espaces && 0 && - (- prio)
*/

#include "ft_printf.h"

static char	*char_null(char *str, t_flags data)
{
	free(str);
	if (data.forme & ZERO && !(data.forme & MINUS))
		str = ft_strnewset('0', data.space);
	else
		str = ft_strnewset(' ', data.space);
	str[data.forme & MINUS ? 0 : data.space - 1] = 0;
	return (str);
}

char		*flags_char(char *str, int size, t_flags data, char c)
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

static char	*precision_s(char *str, int size, t_flags data)
{
	char *tmp;

	if (size <= data.precision)
		return (str);
	tmp = ft_strndup(str, data.precision);
	free(str);
	return (tmp);
}

char		*flags_string(char *str, int size, t_flags data, char c)
{
	char *back;

	(void)c;
	if (str == NULL)
		str = ft_strdup("");
	if (data.forme & ZERO && data.forme & MINUS)
		data.forme -= ZERO;
	if (data.forme & DOT)
		str = precision_s(str, size, data);
	if (data.space <= (size = ft_strlen(str)))
		return (str);
	if (data.forme & ZERO)
		back = ft_strnewset('0', data.space - size);
	else
		back = ft_strnewset(' ', data.space - size);
	if (!back)
		return (NULL);
	return (data.forme & MINUS ? ft_strmjoin(str, back, 3)
		: ft_strmjoin(back, str, 3));
}
