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

int			wctoa(char *str, wchar_t c)
{
	unsigned int	bin;
	int				i;
	int				size;

	size = 1;
	bin = 2147483648;
	i = 32;
	while (!(bin & c) && bin)
	{
		bin /= 2;
		i--;
	}
	if (i < 8)
		*str = c;
	else
	{
		size = (i - 2) / 5 + 1;
		sort_char((unsigned char*)str, c, size);
	}
	return (size);
}

/*
** Gestion des caractères unicode.
*/

int			type_uc(t_printf *dt, char c)
{
	int size;

	(void)c;
	size = wctoa(dt->buf_move, va_arg(dt->ap, wchar_t));
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}

/*
** Gestion des caractères simple.
*/

int			type_c(t_printf *dt, char c)
{
	(void)c;
	*(dt->buf_move++) = (char)va_arg(dt->ap, int);
	dt->to_print++;
	return (1);
}
