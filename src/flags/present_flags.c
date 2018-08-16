/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:30:21 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 17:59:55 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_flag(t_printf *dt, t_flags data, int size)
{
	static t_applyflags	tab_ft[] = {
		{"idD", flags_decimal},
		{"uU", flags_unsigned},
		{"xX", flags_hexa},
		{"p", flags_address},
		{"oO", flags_octal},
		{"sS", flags_string},
		{NULL, NULL},
	};
	t_applyflags		*ptr;

	ptr = tab_ft;
	if (dt->str[dt->pos_s - 1] == 'S')
		data.convert = 4;
	while (ptr->str)
	{
		if (ft_strchr(ptr->str, dt->str[dt->pos_s - 1]))
			dt->tmp = ptr->fct(dt->tmp, size, data, dt->str[dt->pos_s - 1]);
		ptr++;
	}
	if (!ft_strchr("idDuUxXpoOsS", dt->str[dt->pos_s - 1]))
		dt->tmp = flags_char(dt->tmp, size, data, dt->str[dt->pos_s - 1]);
	return (ft_strlen(dt->tmp));
}

static int	get_str(t_printf *dt, t_flags data)
{
	int		size;

	if ((data.convert && ft_strchr("bdiouxXcsS", dt->str[dt->pos_s]))
		|| (ft_strchr("sS", dt->str[dt->pos_s]) && data.forme & DOT))
		size = value_flag_conv(dt, data);
	else
	{
		if (!dt->str[dt->pos_s] || !(ft_strchr(CONV, dt->str[dt->pos_s])))
		{
			dt->tmp = ft_strnewset(dt->str[dt->pos_s], 1);
			if (dt->str[dt->pos_s])
				dt->pos_s++;
			size = !(*(dt->tmp)) ? 0 : 1;
		}
		else
			size = value_flag(dt);
	}
	if (!dt->tmp)
		return (0);
	if (*(dt->tmp) == 0 && ft_strchr("%cC", dt->str[dt->pos_s - 1]))
	{
		dt->tmp = flags_char(dt->tmp, size, data, dt->str[dt->pos_s - 1]);
		if (data.space)
			return (data.space);
		return (1);
	}
	return (apply_flag(dt, data, size));
}

/*
** A retoucher apres ??
*/

static char	what_type(t_printf *dt, unsigned char m, int type)
{
	if (type < 6)
	{
		if (!(m & 1 << type))
			m += 1 << type;
	}
	else if (type == 6)
	{
		if (dt->str[dt->pos_s] == 'h' && m < 2)
			m = 1 << 1;
		else if (m < 1)
			m = 1 << 0;
	}
	else if (type == 7)
	{
		if (dt->str[dt->pos_s] == 'l' && m < 8)
			m = 1 << 3;
		else if (m < 4)
			m = 1 << 2;
	}
	else if (type == 8 && m < 16)
		m = 1 << 4;
	else if (type == 9 && m < 32)
		m = 1 << 5;
	return (m);
}

static void	manage_flag(t_printf *dt, t_flags *data, int type)
{
	dt->pos_s++;
	if (type > 5)
		data->convert = what_type(dt, data->convert, type);
	else
		data->forme = what_type(dt, data->forme, type);
	if (type == 0)
	{
		data->precision = ft_atoi(dt->str + dt->pos_s);
		while (ft_isdigit(dt->str[dt->pos_s]))
			dt->pos_s++;
	}
}

int			present_flag(t_printf *dt)
{
	t_flags	data;
	char	*tmp;

	data.space = 0;
	data.forme = 0;
	data.convert = 0;
	data.precision = 0;
	while (((tmp = ft_strchr(FLAG, dt->str[dt->pos_s])) && dt->str[dt->pos_s])
		|| ft_isdigit(dt->str[dt->pos_s]))
	{
		if (tmp)
			manage_flag(dt, &data, tmp - FLAG);
		else
		{
			data.space = ft_atoi(dt->str + dt->pos_s);
			dt->pos_s += ft_nbr_len(data.space);
		}
	}
	return (get_str(dt, data));
}
