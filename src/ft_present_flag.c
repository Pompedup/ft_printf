/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_present_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:30:21 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/14 01:36:05 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//sSpbDiOuUC%
//sSb

int		ft_nochar(t_printf *dt)
{
	int back;

	back = 0;
	if (dt->str[dt->pos_s])
	{
		if (!(dt->tmp = (char *)malloc(2)))
			return (0);
		dt->tmp[0] = dt->str[dt->pos_s++];
		dt->tmp[1] = 0;
		back = 1;
	}
	else
		dt->tmp = ft_strdup("");
	return (back);
}

static int	ft_apply_flag(t_printf *dt, t_flags data)
{
	//char	*tmp;
	int		size;

	if ((data.convert && ft_strchr("bdiouxXcs", dt->str[dt->pos_s])) ||
		((dt->str[dt->pos_s] == 'S' || (dt->str[dt->pos_s] == 's'
		&& data.convert == 4)) && data.precision))
		size = ft_value_flag_conv(dt, data);
	else
	{
		if (!dt->str[dt->pos_s] ||
			!(ft_strchr(CONV, dt->str[dt->pos_s])))
			size = ft_nochar(dt);
		else
			size = ft_value_flag(dt);
	}
	if (ft_strchr("%cC", dt->str[dt->pos_s - 1]) || !ft_strchr("%idDuUxXpoOsS", dt->str[dt->pos_s - 1]))
	{
		if (*(dt->tmp) == 0 && ft_strchr("%cC", dt->str[dt->pos_s - 1]))
		{
			dt->tmp = flags_char(dt->tmp, size, data, dt->str[dt->pos_s - 1]);
			if (data.space)
				return (data.space);
			return (1);
		}
		dt->tmp = flags_char(dt->tmp, size, data, dt->str[dt->pos_s - 1]);
	}
	if (ft_strchr("idD", dt->str[dt->pos_s - 1]))
		dt->tmp = flags_decimal(dt->tmp, size, data);
	if (ft_strchr("uU", dt->str[dt->pos_s - 1]))
		dt->tmp = flags_unsigned(dt->tmp, size, data);
	if (ft_strchr("xX", dt->str[dt->pos_s - 1]))
		dt->tmp = flags_hexa(dt->tmp, size, data, dt->str[dt->pos_s - 1]);
	if (ft_strchr("p", dt->str[dt->pos_s - 1]))
		dt->tmp = flags_address(dt->tmp, size, data);
	if (ft_strchr("oO", dt->str[dt->pos_s - 1]))
		dt->tmp = flags_octal(dt->tmp, size, data);
	if (ft_strchr("sS", dt->str[dt->pos_s - 1]))
		dt->tmp = flags_string(dt->tmp, size, data);
	return (ft_strlen(dt->tmp));
}

/*
** A retoucher apres ??
*/

static char	ft_what_type(t_printf *dt, unsigned char m, int type)
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

static void	ft_manage_flag(t_printf *dt, t_flags *data, int type)
{
	dt->pos_s++;
	if (type > 5)
		data->convert = ft_what_type(dt, data->convert, type);
	else
		data->forme = ft_what_type(dt, data->forme, type);
	if (type == 0)
	{
		data->precision = ft_atoi(dt->str + dt->pos_s);
		while (ft_isdigit(dt->str[dt->pos_s]))
			dt->pos_s++;
	}
}

int			ft_present_flag(t_printf *dt)
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
			ft_manage_flag(dt, &data, tmp - FLAG);
		else
		{
			data.space = ft_atoi(dt->str + dt->pos_s);
			dt->pos_s += ft_nbr_len(data.space);
		}
	}
	return (ft_apply_flag(dt, data));
}
