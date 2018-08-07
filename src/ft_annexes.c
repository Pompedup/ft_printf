/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:35:14 by abezanni          #+#    #+#             */
/*   Updated: 2018/02/26 18:22:57 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** char		*ft_adress(t_printf *dt, char c);
** char		*ft_wctoa(int c);
*/

#include "ft_printf.h"

/*
** Gestion des %p.
*/

char			*ft_adress(t_printf *dt, char c)
{
	(void)c;
	return (ft_strmjoin("0x", ft_ulltoa_base(
		(unsigned long long)va_arg(dt->ap, void *), 16, 0), 2));
}

/*
**	Initialise le tableau des unicodes
*/

static void		ft_create_tab(unsigned char *str, int size)
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

static void		ft_sort_char(unsigned char *back, int c, int size)
{
	int				i;
	int				j;

	back[size] = 0;
	ft_create_tab(back, size);
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

char			*ft_wctoa(int c)
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
		ft_sort_char((unsigned char*)back, c, size);
	}
	return (back);
}
