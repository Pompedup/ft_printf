/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:30:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 18:11:24 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	value_flag(t_printf *dt)
{
	static t_basic	tab_func[] = {
		{"di", type_i_d}, {"D", type_ud}, {"u", type_u},
		{"UO", type_uu_uo}, {"oxX", type_o_x_ux}, {"s", type_s},
		{"S", type_us}, {"p", type_p}, {"c", type_c}, {"C", type_uc},
		{"%", type_percent}, {"b", type_b}, {NULL, NULL},
	};
	t_basic			*ptr;

	ptr = tab_func;
	while (ptr->str)
	{
		if (ft_strchr(ptr->str, dt->str[dt->pos_s]))
		{
			dt->pos_s++;
			dt->tmp = ptr->fct(dt, dt->str[dt->pos_s - 1] == 'S' ? 0 :
				dt->str[dt->pos_s - 1]);
			if (dt->tmp &&!(*dt->tmp) && ft_strchr("cC", dt->str[dt->pos_s - 1]))
				return (1);
			return (dt->tmp ? ft_strlen(dt->tmp) : 0);
		}
		ptr++;
	}
	return (0);
}

int	value_flag_conv(t_printf *dt, t_flags data)
{
	static t_conv	tab_func[] = {
		{"di", conv_i_d},
		{"bouxX", conv_b_o_u_x_ux},
		{"c", conv_c_uc},
		{"sS", conv_s_us},
		{NULL, NULL},
	};
	t_conv			*ptr;

	ptr = tab_func;
	if (dt->str[dt->pos_s] == 'S')
		data.convert = 4;
	while (ptr->str)
	{
		if (ft_strchr(ptr->str, dt->str[dt->pos_s]))
		{
			dt->pos_s++;
			dt->tmp =
				ptr->fct(dt, ft_strchr("sS",
					dt->str[dt->pos_s - 1]) ? data.precision
					: dt->str[dt->pos_s - 1], data.convert);
			return (dt->tmp ? ft_strlen(dt->tmp) : 0);
		}
		ptr++;
	}
	return (0);
}
