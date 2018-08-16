/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_uc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:35:14 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 18:59:12 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Initialise le tableau des unicodes
*/

static void	create_tab(unsigned char *str, int size)
{
	int j;
	int i;

	i = size;
	j = 0;
	while (j < size)
	{
		if (j == 0)
		{
			str[j] = 0;
			while (i)
				str[j] += 1 << (8 - i--);
		}
		else
			str[j] = 128;
		j++;
	}
}

/*
**	Rempli les valeurs dans le tableau
*/

static void	sort_char(unsigned char *back, int c, int size)
{
	int				i;
	int				j;

	back[size] = 0;
	create_tab(back, size);
	i = 1;
	j = 0;
	i = 0;
	i = 1;
	while (j < 4 + 4 * size)
	{
		if (i & c)
			back[size - 1 - (j / 6)] += 1 << (j % 6);
		i *= 2;
		j++;
	}
}

/*
**	Gestion des unicodes
*/

char		*wctoa(wchar_t c)
{
	char			*back;
	unsigned int	bin;
	int				i;
	int				size;

	i = 0;
	bin = 2147483648;
	i = 32;
	if (i == 0)
		return (ft_strdup("\0"));
	while (!(bin & c) && bin)
	{
		bin /= 2;
		i--;
	}
	if (i < 8)
		back = ft_strdup((char *)&c);
	else
	{
		size = (i - 2) / 5 + 1;
		if (!(back = (char *)malloc(size + 1)))
			return (NULL);
		sort_char((unsigned char*)back, c, size);
	}
	return (back);
}

/*
** Gestion des caractères unicode.
*/

char		*type_uc(t_printf *dt, char c)
{
	(void)c;
	return (wctoa(va_arg(dt->ap, wchar_t)));
}

/*
** Gestion des caractères simple.
*/

char		*type_c(t_printf *dt, char c)
{
	char	back[2];

	(void)c;
	back[0] = (char)va_arg(dt->ap, int);
	back[1] = 0;
	return (ft_strdup(back));
}
