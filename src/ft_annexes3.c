/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexes3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:59:34 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/15 15:08:09 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	char		*ft_mins(t_printf *dt, char c);
**	char		*ft_majs(t_printf *dt, char c);
**	char		*ft_minc(t_printf *dt, char c);
**	char		*ft_majc(t_printf *dt, char c);
*/

#include "ft_printf.h"

/*
** Gestion des chaines de caractères simple.
*/

char	*ft_mins(t_printf *dt, char c)
{
	char *tmp;

	(void)c;
	tmp = va_arg(dt->ap, char*);
	return (tmp ? ft_strdup(tmp) : ft_strdup("(null)"));
}

/*
** Gestion des chaines de caractères unicode.
*/

char	*ft_majs(t_printf *dt, char c)
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
		tmp = ft_wctoa(tab[i]);
		if (c && (ft_strlen(tmp) + ft_strlen(back) > (unsigned long)c))
		{
			free(tmp);
			return (back);
		}
		back = ft_strmjoin(back, tmp, 3);
	}
	return (back);
}

/*
** Gestion des caractères simple.
*/

char	*ft_minc(t_printf *dt, char c)
{
	char	back[2];

	(void)c;
	back[0] = (char)va_arg(dt->ap, int);
	back[1] = 0;
	return (ft_strdup(back));
}

/*
** Gestion des caractères unicode.
*/

char	*ft_majc(t_printf *dt, char c)
{
	(void)c;
	return (ft_wctoa(va_arg(dt->ap, int)));
}
