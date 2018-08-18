/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_us.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:59:34 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 18:55:09 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des chaines de caractères simple.
*/

int	type_s(t_printf *dt, char c)
{
	char	*tmp;
	int		size;

	(void)c;
	tmp = va_arg(dt->ap, char*);
	if (!tmp)
	{
		ft_strcpy(dt->buf_move, "(null)");
		size = 6;
	}
	else
	{
		ft_strcpy(dt->buf_move, tmp);
		size = ft_strlen(tmp);
	}
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}

/*
** Gestion des chaines de caractères unicode.
*/

int	type_us(t_printf *dt, char c)
{
	char			tmp[10];
	wchar_t			*tab;
	int				i;
	int				size;
	int				max;

	tab = va_arg(dt->ap, wchar_t*);
	size = 0;
	max = c;
	if (!tab)
	{
		ft_strcpy(dt->buf_move, "(null)");
		size = 6;
	}
	i = -1;
	while (tab && tab[++i] != 0)
	{
		size += wctoa(tmp, tab[i]);
		if (max && size > max)
			return (size - ft_strlen(tmp));
		ft_strcpy(dt->buf_move, tmp);
		dt->buf_move += ft_strlen(tmp);
		dt->to_print += ft_strlen(tmp);
	}
	return (size);
}
