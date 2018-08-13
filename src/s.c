/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:40:17 by adibou            #+#    #+#             */
/*   Updated: 2018/08/13 02:15:44 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pas de + #
// . && Espaces && 0 && - (- prio)

#include "ft_printf.h"

static char	*precision(char *str, int size, t_flags data)
{
	char *tmp;

	if (size <= data.precision)
		return (str);
	tmp = ft_strndup(str, data.precision);
	free(str);
	return (tmp);
}
#include <stdio.h>
char	*flags_string(char *str, int size, t_flags data)
{
	char *back;

	if (str == NULL)
		str = ft_strdup("");
	if (data.forme & ZERO && data.forme & MINUS)
		data.forme -= ZERO;
	if (data.forme & DOT)
		str = precision(str, size, data);
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