/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_present_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:30:21 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/16 18:06:26 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char	*ft_apply_flag(t_printf *dt, unsigned char c, unsigned char d, int i)
{
	char	*space;
	char	*tmp;
	int		size;

	if (!(tmp = ft_value_flag(dt, d)))//A FAIRE
	{
		tmp = malloc(10);
	}
	if (c & 1)
	{
		if ((dt->str[dt->pos_s - 1] == 'd' || dt->str[dt->pos_s - 1] == 'i'
			|| dt->str[dt->pos_s - 1] == 'D') && ft_isdigit(tmp[0]))
			tmp = ft_strmjoin("+", tmp, 2);
	}
	if (c & 2)
	{
		if ((dt->str[dt->pos_s - 1] == 'd' || dt->str[dt->pos_s - 1] == 'i'
			|| dt->str[dt->pos_s - 1] == 'D') && ft_isdigit(tmp[0]))
			tmp = ft_strmjoin(" ", tmp, 2);
	}
	if (i > (size = ft_strlen(tmp)))
	{
		space = (char*)malloc(i - size + 1);
		space[i - size] = 0;
		while (i-- >= size)
			space[i - size] = ' ';
		if (c & 4)
			tmp = ft_strmjoin(tmp, space, 3);
		else
			tmp = ft_strmjoin(space, tmp, 3);
	}
	return (tmp);
}

int	ft_iterative_power(int nb, int power)
{
	int back;

	if (power < 0)
		back = 0;
	else if (power == 0)
		back = 1;
	else
		back = nb;
	while (--power > 0)
	{
		back = back * nb;
	}
	return (back);
}

static char	ft_what_type(t_printf *dt, unsigned char m, int type)
{
	if (type < 5)
	{
		if (m ^ (ft_iterative_power(2, type)))
			m += 1 << type;
	}
	else if (type == 5)
	{
		if (dt->str[dt->pos_s] == 'h' && m ^ 2)
			m += 1 << 1;
		else if (m ^ 1)
			m += 1 << 0;
	}
	else if (type == 6)
	{
		if (dt->str[dt->pos_s] == 'l' && m ^ 8)
			m += 1 << 3;
		else if (m ^ 4)
			m += 1 << 2;
	}
	else if (type == 7 && m ^ 16)
		m += 1 << 4;
	else if (type == 8 && m ^ 32)
		m += 1 << 5;
	return (m);
}

char	*ft_present_flag(t_printf *dt)
{
	unsigned char	c;
	unsigned char	d;
	int				i;
	char			*tmp;
	char			*tmp1;

	i = 0;
	c = 0;
	d = 0;
	while ((tmp = ft_strchr(tmp1 = "+ -0#hljz", dt->str[dt->pos_s])) || ft_isdigit(dt->str[dt->pos_s]))
	{
		if (tmp)
		{
			dt->pos_s++;
			if (tmp - tmp1 > 4)
				d = ft_what_type(dt, d, tmp - tmp1);
			else
				c = ft_what_type(dt, c, tmp - tmp1);
			tmp = NULL;
		}
		else
		{
			i = ft_atoi(dt->str + dt->pos_s);
			dt->pos_s += ft_nbr_len(i);
		}
	}
	return (ft_apply_flag(dt, c, d, i));
}
