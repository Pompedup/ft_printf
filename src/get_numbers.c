/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompedup <pompedup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:20:44 by pompedup          #+#    #+#             */
/*   Updated: 2018/08/31 13:58:51 by pompedup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	addnbr(char *buf, uintmax_t nbr, char *str_base, int base)
{
	if (!nbr)
		*buf = '0';
	while (nbr)
	{
		*buf = str_base[nbr % base];
		nbr /= base;
		buf--;
	}
}

void	get_len(t_flags *dt_flags, uintmax_t nbr)
{
	dt_flags->len = !nbr && !(dt_flags->flags & DOT) ? 1 : 0;
	while (nbr)
	{
		nbr /= dt_flags->base;
		dt_flags->len++;
	}
}

void	ull_lltoa(t_printf *dt, t_flags *dt_flags, intmax_t nbr, t_bool signe)
{
	get_len(dt_flags, signe && nbr < 0 ? -nbr : nbr);
	apply_flags(dt_flags, signe && nbr < 0, signe, nbr);
	if (!(dt_flags->flags & MINUS))
		padding(dt, dt_flags, FALSE);
	if (dt_flags->c || dt_flags->hash)
	{
		rotative_buf(dt, signe ? &dt_flags->c : dt_flags->hash, signe ? 1 : ft_strlen(dt_flags->hash));
		dt_flags->len -= signe ? 1 : ft_strlen(dt_flags->hash);
	}
	padding(dt, dt_flags, TRUE);
	dt->buf_move += dt_flags->len - 1;
	dt->less -= dt_flags->len - 1;
	if (dt_flags->len)
		addnbr(dt->buf_move, signe && nbr < 0 ? -nbr : nbr, dt_flags->type == 'X'
			? HEXAMAX : HEXAMIN, dt_flags->base);
	dt->buf_move++;
	dt->less--;
	if (dt_flags->flags & MINUS)
		padding(dt, dt_flags, FALSE);
}

void	get_signed(t_printf *dt, t_flags *dt_flags, char type)
{
	intmax_t tmp;

	(void)type;
	dt_flags->base = 10;
	if (dt_flags->flags & HH && type != 'D')
		tmp = (intmax_t)(char)va_arg(dt->ap, int);
	else if (dt_flags->flags & H && type != 'D')
		tmp = (intmax_t)(short)va_arg(dt->ap, int);
	else if (dt_flags->flags & L || type == 'D')
		tmp = (intmax_t)va_arg(dt->ap, long);
	else if (dt_flags->flags & LL)
		tmp = (intmax_t)va_arg(dt->ap, long long);
	else if (dt_flags->flags & J)
		tmp = va_arg(dt->ap, intmax_t);
	else if (dt_flags->flags & Z)
		tmp = (intmax_t)va_arg(dt->ap, size_t);
	else
		tmp = (intmax_t)va_arg(dt->ap, int);
	ull_lltoa(dt, dt_flags, tmp, TRUE);
}

void	get_unsigned(t_printf *dt, t_flags *dt_flags, char type)
{
	uintmax_t	tmp;

	if (type == 'o' || type == 'O')
		dt_flags->base = 8;
	else if (type == 'x' || type == 'X' || type == 'p')
		dt_flags->base = 16;
	else if (type == 'b')
		dt_flags->base = 2;
	else
		dt_flags->base = 10;
	if (dt_flags->flags & L || (ft_strchr("pUO", type)))
		tmp = (uintmax_t)va_arg(dt->ap, unsigned long);
	else if (dt_flags->flags & Z)
		tmp = (uintmax_t)va_arg(dt->ap, size_t);
	else if (dt_flags->flags & HH)
		tmp = (uintmax_t)(unsigned char)va_arg(dt->ap, unsigned int);
	else if (dt_flags->flags & H)
		tmp = (uintmax_t)(unsigned short)va_arg(dt->ap, unsigned int);
	else if (dt_flags->flags & LL)
		tmp = (uintmax_t)va_arg(dt->ap, unsigned long long);
	else if (dt_flags->flags & J)
		tmp = va_arg(dt->ap, uintmax_t);
	else
		tmp = (uintmax_t)va_arg(dt->ap, unsigned int);
	ull_lltoa(dt, dt_flags, tmp, FALSE);
}
