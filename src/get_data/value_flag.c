/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:30:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 19:00:12 by abezanni         ###   ########.fr       */
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
		if (ft_strchr(ptr->str, *dt->format))
		{
			dt->format++;
			return (ptr->fct(dt, *(dt->format - 1) == 'S' ? 0 :
				*(dt->format - 1)));
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
	if (*dt->format == 'S')
		data.convert = 4;
	while (ptr->str)
	{
		if (ft_strchr(ptr->str, *dt->format))
		{
			dt->format++;
			return (ptr->fct(dt, ft_strchr("sS", *(dt->format - 1))
				? data.precision : *(dt->format - 1), data.convert));
		}
		ptr++;
	}
	return (0);
}
