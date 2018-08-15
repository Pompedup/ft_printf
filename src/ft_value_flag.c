/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:30:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/15 16:54:31 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_value_flag(t_printf *dt)
{
	static t_ft	tab_ft[] = {
		{"di", ft_minid}, {"D", ft_majdo}, {"u", ft_minu},
		{"UO", ft_maju}, {"oxX", ft_minox_majx}, {"s", ft_mins},
		{"S", ft_majs}, {"p", ft_adress}, {"c", ft_minc}, {"C", ft_majc},
		{"%", ft_percent}, {"b", ft_binary}, {NULL, NULL},
	};
	t_ft		*ptr;

	ptr = tab_ft;
	while (ptr->str)
	{
		if (ft_strchr(ptr->str, dt->str[dt->pos_s]))
		{
			dt->pos_s++;
			dt->tmp = ptr->fct(dt, dt->str[dt->pos_s - 1] == 'S' ? 0 :
				dt->str[dt->pos_s - 1]);
			if (!(*dt->tmp) && ft_strchr("cC", dt->str[dt->pos_s - 1]))
				return (1);
			return (ft_strlen(dt->tmp));
		}
		ptr++;
	}
	return (0);
}

int	ft_value_flag_conv(t_printf *dt, t_flags data)
{
	static t_ft_conv	tab_ft[] = {
		{"di", ft_conv_int},
		{"bouxX", ft_conv_other},
		{"c", ft_conv_c},
		{"sS", ft_conv_s},
		{NULL, NULL},
	};
	t_ft_conv			*ptr;

	ptr = tab_ft;
	if (dt->str[dt->pos_s] == 'S')
		data.convert = 4;
	while (ptr->str)
	{
		if (ft_strchr(ptr->str, dt->str[dt->pos_s]))
		{
			dt->pos_s++;
			return (ft_strlen((dt->tmp =
				ptr->fct(dt, ft_strchr("sS",
					dt->str[dt->pos_s - 1]) ? data.precision
					: dt->str[dt->pos_s - 1], data.convert))));
		}
		ptr++;
	}
	return (0);
}
