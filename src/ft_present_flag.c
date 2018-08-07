/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_present_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:30:21 by abezanni          #+#    #+#             */
/*   Updated: 2018/02/14 18:26:35 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static void	ft_do_space(t_printf *dt, t_flags *data, int *size, char **tmp)
{
	if (data->forme & 16 && !data->precision && *size < data->space &&
		!(data->forme & 8) && (!(data->forme & 1) ||
		!ft_strchr("pdDioOuUxXcC", dt->str[dt->pos_s - 1])))
	{
		*tmp = ft_space(dt, *tmp,
			ft_strchar('0', data->space - *size), data->forme & 8);
		*size = data->space;
	}
	*tmp = ft_data(dt, data, size, *tmp);
	if (*size < data->space)
	{
		*tmp = ft_space(dt, *tmp,
			ft_strchar(' ', data->space - *size), data->forme & 8);
	}
}

static int	ft_apply_flag(t_printf *dt, t_flags data)
{
	char	*tmp;
	int		size;

	if ((data.convert && ft_strchr("bdiouxXcs", dt->str[dt->pos_s])) ||
		((dt->str[dt->pos_s] == 'S' || (dt->str[dt->pos_s] == 's'
		&& data.convert == 4)) && data.precision))
		size = ft_value_flag_conv(dt, data);
	else
	{
		if (!dt->str[dt->pos_s] ||
			!(ft_strchr("sSpbdDioOuUxXcC%", dt->str[dt->pos_s])))
			size = ft_nochar(dt);
		else
			size = ft_value_flag(dt);
	}
	tmp = dt->tmp;
	if (ft_strchr("cC", dt->str[dt->pos_s - 1]) && !(*tmp))
		return (ft_char_null(dt, data, tmp));
	if (data.forme & 1)
		tmp = ft_add_precision(dt, &data, &size, tmp);
	if (data.space)
		ft_do_space(dt, &data, &size, &tmp);
	tmp = ft_data(dt, &data, &size, tmp);
	dt->tmp = tmp;
	return (ft_strlen(tmp));
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
		else if (m ^ 4)
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
		if (data->precision || dt->str[dt->pos_s] == '0')
			dt->pos_s += ft_nbr_len(data->precision);
	}
}

int			ft_present_flag(t_printf *dt)
{
	t_flags	data;
	char	*tmp;
	char	*tmp1;

	data.space = 0;
	data.forme = 0;
	data.convert = 0;
	data.precision = 0;
	tmp1 = ".+ -0#hljz";
	while (((tmp = ft_strchr(tmp1, dt->str[dt->pos_s])) && dt->str[dt->pos_s])
		|| ft_isdigit(dt->str[dt->pos_s]))
	{
		if (tmp)
			ft_manage_flag(dt, &data, tmp - tmp1);
		else
		{
			data.space = ft_atoi(dt->str + dt->pos_s);
			dt->pos_s += ft_nbr_len(data.space);
		}
	}
	return (ft_apply_flag(dt, data));
}
