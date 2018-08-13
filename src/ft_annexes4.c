/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexes4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:59:58 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/13 03:02:25 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	char	*ft_binary(t_printf *dt, char c);
**	char		*ft_percent(t_printf *dt, char c);
**	char		*ft_conv_int(t_printf *dt, char c, unsigned char conv);
**	char		*ft_conv_other(t_printf *dt, char c, unsigned char conv);
*/

#include "ft_printf.h"

/*
** Gestion des %d %i avec conversion.
*/

char	*ft_conv_int(t_printf *dt, char c, unsigned char conv)
{
	long long			var;

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
	return (ft_lltoa_base(var, 10, 0));
}

/*
** Gestion des %o %u %x %X avec conversion.
*/

char	*ft_conv_other(t_printf *dt, char c, unsigned char conv)
{
	unsigned long long	var;
	int					base;

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
	if (c == 'x' || c == 'X')
		base = 16;
	else if (c == 'b')
		base = 2;
	else
		base = (c == 'o' || c == 'O') ? 8 : 10;
	return (ft_ulltoa_base(var, base, c == 'X'));
}

char	*ft_conv_c(t_printf *dt, char c, unsigned char conv)
{
	return (conv & 4 ? ft_majc(dt, c) : ft_minc(dt, c));
}

char	*ft_test(t_printf *dt)
{
	char *back;

	back = va_arg(dt->ap, char*);
	if (!back)
		back = ft_strdup("(null)");
	else
		back = ft_strdup(back);
	return (back);
}

char	*ft_conv_s(t_printf *dt, char c, unsigned char conv)
{
	if (conv & 4)
		return (ft_majs(dt, c));
	return (conv & 8 ? ft_test(dt) : ft_mins(dt, c));
}

char	*ft_bigs(t_printf *dt, char c, unsigned char conv)
{
	(void)conv;
	return (ft_majs(dt, c));
}
