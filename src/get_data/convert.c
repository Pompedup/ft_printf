/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:59:58 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 14:58:42 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des %d %i avec conversion.
*/

int		conv_i_d(t_printf *dt, char c, unsigned char conv)
{
	long long			var;
	int					size;

	(void)c;
	var = 0;
	if (conv & 32)
		var = (long long)(va_arg(dt->ap, size_t));
	else if (conv & 16)
		var = (unsigned long long)(va_arg(dt->ap, intmax_t));
	else if (conv & 8)
		var = (long long)(va_arg(dt->ap, long long));
	else if (conv & 4)
		var = (long long)(va_arg(dt->ap, long));
	else if (conv & 2)
		var = (long long)((char)(va_arg(dt->ap, int)));
	else
		var = (long long)((short)(va_arg(dt->ap, int)));
	size = ft_lltoa_base(dt->buf_move, var, 10, 0);
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}

/*
** Gestion des %o %u %x %X avec conversion.
*/

int		conv_b_o_u_x_ux(t_printf *dt, char c, unsigned char conv)
{
	unsigned long long	var;
	int					base;
	int					size;

	var = 0;
	if (conv & 32)
		var = (unsigned long long)(va_arg(dt->ap, size_t));
	else if (conv & 16)
		var = (unsigned long long)(va_arg(dt->ap, uintmax_t));
	else if (conv & 8)
		var = va_arg(dt->ap, unsigned long long);
	else if (conv & 4)
		var = (unsigned long long)(va_arg(dt->ap, unsigned long));
	else if (conv & 2)
		var = (unsigned long long)((unsigned char)
			(va_arg(dt->ap, unsigned int)));
	else
		var = (unsigned long long)((unsigned short)
			(va_arg(dt->ap, unsigned int)));
	if (c == 'x' || c == 'X' || c == 'b')
		base = c == 'b' ? 2 : 16;
	else
		base = (c == 'o' || c == 'O') ? 8 : 10;
	size = ft_ulltoa_base(dt->buf_move, var, base, c == 'X');
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}

int		conv_c_uc(t_printf *dt, char c, unsigned char conv)
{
	return (conv & 4 ? type_uc(dt, c) : type_c(dt, c));
}

int		conv_s_us(t_printf *dt, char c, unsigned char conv)
{
	return (conv & 4 ? type_us(dt, c) : type_s(dt, c));
}
