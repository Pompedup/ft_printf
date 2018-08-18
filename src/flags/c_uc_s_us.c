/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_uc_s_us.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompedup <pompedup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:53 by adibou            #+#    #+#             */
/*   Updated: 2018/08/18 14:23:39 by pompedup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pas de . + #
** Espaces && 0 && - (- prio)
*/

#include "ft_printf.h"

int			flags_char(t_printf *dt, int size, t_flags data, char c)
{
	if (data.space <= size)
		return (size);
	if (data.forme & ZERO && !(data.forme & MINUS))
		back = ft_memset(dt->buf_move, '0', data.space - size);
	else if (!(data.forme & MINUS))
		back = ft_memset(dt->buf_move, ' ', data.space - size);
	//recuperation du contenu
	if (data.forme & MINUS)
		back = ft_memset(dt->buf_move, ' ', data.space - size);
	return (data.space);
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
