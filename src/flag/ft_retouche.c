/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retouche.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:05:41 by abezanni          #+#    #+#             */
/*   Updated: 2018/01/20 19:53:09 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	char	*ft_space(t_printf *dt, char *str, char *tmp, int sens)
**	char	*ft_signe(t_printf *dt, t_flags *data, char *str, int *size)
**	int		ft_char_null(t_printf *dt, t_flags data, char *str)
**	char	*ft_data(t_printf *dt, t_flags *data, int *size, char *tmp)
**	int		ft_nochar(t_printf *dt)
*/

#include "ft_printf.h"

char	*ft_space(t_printf *dt, char *str, char *tmp, int sens)
{
	if (ft_strchr("di", dt->str[dt->pos_s - 1]) && !sens &&
		!ft_isdigit(str[0]) && *tmp == '0')
	{
		*tmp = *str;
		*str = '0';
	}
	if (*tmp == '0' && dt->str[dt->pos_s - 1] == 'p')
	{
		str[1] = '0';
		if (tmp[1])
			tmp[1] = 'x';
		else
			str[0] = 'x';
	}
	if (sens)
		return (ft_strmjoin(str, tmp, 3));
	else
		return (ft_strmjoin(tmp, str, 3));
}

char	*ft_signe(t_printf *dt, t_flags *data, char *str, int *size)
{
	if (!ft_strchr("dDi", dt->str[dt->pos_s - 1]))
		return (str);
	if ((*str == '0' && str[1] && *size >= data->space))
		*str = data->forme & 2 ? '+' : ' ';
	else if (ft_isdigit(*str))
	{
		str = ft_strmjoin(data->forme & 2 ? "+" : " ", str, 2);
		(*size)++;
	}
	return (str);
}

int		ft_char_null(t_printf *dt, t_flags data, char *str)
{
	char *tmp;

	if (data.space > 1)
	{
		tmp = ft_strchar(data.forme & 16 && !(data.forme & 8) ?
			'0' : ' ', data.space - 1);
		if (data.forme & 8)
			dt->tmp = ft_memjoin("\0", tmp, 1, data.space - 1);
		else
			dt->tmp = ft_memjoin(tmp, "\0", data.space - 1, 1);
		free(str);
		free(tmp);
	}
	return (data.space > 0 ? data.space : 1);
}

char	*ft_data(t_printf *dt, t_flags *data, int *size, char *tmp)
{
	if (data->forme & 2 || data->forme & 4)
		tmp = ft_signe(dt, data, tmp, size);
	if (data->forme & 32)
		tmp = ft_hashtag(dt, data, tmp, size);
	if (data->forme & 2)
		data->forme -= 1 << 1;
	if (data->forme & 4)
		data->forme -= 1 << 2;
	if (data->forme & 32)
		data->forme -= 1 << 5;
	return (tmp);
}

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
