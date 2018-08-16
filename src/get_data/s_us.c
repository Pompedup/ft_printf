/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_us.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:59:34 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 18:48:49 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des chaines de caractères simple.
*/

char	*type_s(t_printf *dt, char c)
{
	char *tmp;

	(void)c;
	tmp = va_arg(dt->ap, char*);
	return (tmp ? ft_strdup(tmp) : ft_strdup("(null)"));
}

/*
** Gestion des chaines de caractères unicode.
*/

char	*type_us(t_printf *dt, char c)
{
	char		*tmp;
	char		*back;
	wchar_t		*tab;
	int			i;

	(void)c;
	tab = va_arg(dt->ap, wchar_t*);
	if (!tab)
		return (ft_strdup("(null)"));
	else if (!tab[0])
		return (ft_strdup(""));
	back = ft_strdup("");
	i = -1;
	while (tab[++i] != 0)
	{
		if (MB_CUR_MAX == 1 && !(0 <= tab[i] && tab[i] <= 255))
		{
			free(back);
			return (NULL);
		}
		tmp = wctoa(tab[i]);
		if (c && (ft_strlen(tmp) + ft_strlen(back) > (unsigned long)c))
		{
			free(tmp);
			return (back);
		}
		back = ft_strmjoin(back, tmp, 3);
		if (c && (ft_strlen(back) == (unsigned long)c))
			return (back);
	}
	return (back);
}
