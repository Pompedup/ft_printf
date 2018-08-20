/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompedup <pompedup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:54:25 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/19 01:20:12 by pompedup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_c(t_printf *dt, t_flags *dt_flags, char type)
{
	char	c;

	(void)type;
	c = (char)va_arg(dt->ap, wchar_t);
	dt_flags->space = dt_flags->space > 1 ? dt_flags->space - 1 : 0;
	padding(dt, dt_flags, TRUE);
	rotative_buf(dt, &c, 1);
	padding(dt, dt_flags, FALSE);
}

void	type_s(t_printf *dt, t_flags *dt_flags, char type)
{
	char	*str;
	int		len;

	(void)type;
	if (!(str = va_arg(dt->ap, char*)))
		len = 6;
	else
		len = (int)ft_strlen(str);
	dt_flags->flags & DOT ? len = smallest(len, dt_flags->precision) : 0;
	dt_flags->space = dt_flags->space - len > 0 ? dt_flags->space - len : 0;
	padding(dt, dt_flags, TRUE);
	rotative_buf(dt, str ? str : "(null)", len);
	padding(dt, dt_flags, FALSE);
}
