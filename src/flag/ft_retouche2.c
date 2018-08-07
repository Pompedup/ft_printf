/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retouche2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:16:33 by abezanni          #+#    #+#             */
/*   Updated: 2018/02/09 17:17:50 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	char	*ft_add_precision(t_printf , t_flags data, int *size, char *tmp)
*/

#include "ft_printf.h"

static char	*ft_hashtag_o(char *str, int *size)
{
	(*size)++;
	return (ft_strmjoin("0", str, 2));
}

char		*ft_hashtag(t_printf *dt, t_flags *data, char *str, int *size)
{
	if (ft_strchr("oO", dt->str[dt->pos_s - 1]) && *str != '0')
		return (ft_hashtag_o(str, size));
	else if (ft_strchr("xX", dt->str[dt->pos_s - 1]) && str[1])
	{
		if (*str == '0' && data->space)
		{
			if (str[1] == '0')
				str[1] = dt->str[dt->pos_s - 1] == 'x' ? 'x' : 'X';
			else
			{
				(*size)++;
				*str = dt->str[dt->pos_s - 1] == 'x' ? 'x' : 'X';
				return (ft_strmjoin("0", str, 2));
			}
		}
		else
		{
			(*size) += 2;
			return (ft_strmjoin(dt->str[dt->pos_s - 1] == 'x' ? "0x" : "0X",
				str, 2));
		}
	}
	return (str);
}

static char	*ft_precision(t_printf *dt, char *str, char *tmp, int boul)
{
	if (ft_strchr("di", dt->str[dt->pos_s - 1])
		&& !ft_isdigit(str[0]) && *tmp == '0')
	{
		if (!boul)
		{
			tmp = ft_strmjoin("-", tmp, 2);
			*str = '0';
		}
		else
		{
			*tmp = '-';
			*str = '0';
		}
	}
	if (*tmp == '0' && dt->str[dt->pos_s - 1] == 'p')
	{
		str[1] = '0';
		tmp = ft_strmjoin("0x", tmp, 2);
	}
	return (ft_strmjoin(tmp, str, 3));
}

static void	*ft_do_precision(t_printf *dt, t_flags *data, int *size, char *tmp)
{
	tmp = ft_precision(dt, tmp, ft_strchar('0',
	data->precision - (*tmp == '-' &&
		(data->precision <= data->space || !data->space) ?
		*size - 1 : *size)), data->space >= data->precision ||
		!(data->space));
	*size = ft_strlen(tmp);
	return (tmp);
}

char		*ft_add_precision(t_printf *dt, t_flags *data, int *size, char *tmp)
{
	if (ft_strchr("pdDioOuUxX", dt->str[dt->pos_s - 1]))
	{
		if (*size < data->precision ||
			(*tmp == '-' && *size - 1 < data->precision))
			tmp = ft_do_precision(dt, data, size, tmp);
		else if (data->precision == 0 && !(ft_strcmp("0", tmp))
			&& ft_strchr("dDioOuUxX", dt->str[dt->pos_s - 1]))
		{
			*tmp = 0;
			*size = 0;
		}
		else if (data->precision == 0 && !(ft_strcmp("0x0", tmp))
			&& 'p' == dt->str[dt->pos_s - 1])
		{
			tmp[2] = 0;
			*size = 0;
		}
		tmp = ft_data(dt, data, size, tmp);
	}
	if (ft_strchr("sS", dt->str[dt->pos_s - 1]) && *size > data->precision)
	{
		tmp[data->precision] = 0;
		*size = data->precision;
	}
	return (tmp);
}
