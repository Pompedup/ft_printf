/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:54:25 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/18 18:20:55 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_s(t_printf *dt, t_flags *dt_flags, char type)
{
	char	*str;
	int		len;

	(void)type;
	if (!(str = va_arg(dt->ap, char*)))
		rotative_buf(dt, str, dt_flags->flags & DOT && dt_flags->precision < 6
			? dt_flags->precision : 6);
	else
	{
		len = (int)ft_strlen(str);
		dt_flags->flags & DOT ? len = smallest(len, dt_flags->precision) : 0;
		dt_flags->space = dt_flags->space - len > 0 ? dt_flags->space - len : 0;
		padding(dt, dt_flags, TRUE);
		rotative_buf(dt, str, len);
		padding(dt, dt_flags, FALSE);
	}

}
