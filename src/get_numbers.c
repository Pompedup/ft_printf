/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompedup <pompedup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:20:44 by pompedup          #+#    #+#             */
/*   Updated: 2018/08/22 20:57:46 by pompedup         ###   ########.fr       */
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

void		precision(t_printf *dt, t_flags *dt_flags)
{
	char c;

	if (dt_flags->precision < 1)
		return ;
	c = '0';
	ft_memset(dt->buf_move, c, dt_flags->precision);
	dt->buf_move += dt_flags->precision;
	dt->less -= dt_flags->precision;
}

void	apply_hash(t_printf *dt, t_flags *dt_flags, uintmax_t nbr)
{
	dt_flags->hash = "";
	if (dt_flags->flags & HASH && !nbr && (*dt->format != 'o'
		&& *dt->format != 'O' && !dt_flags->precision))
		dt_flags->flags -= HASH;
	if ((dt_flags->flags & HASH && dt_flags->base != 10) || *dt->format == 'p')
	{
		if (dt_flags->base == 16)
			dt_flags->hash = *dt->format == 'X' ? "0X" : "0x";
		else if (dt_flags->base == 16)
			dt_flags->hash = "0b";
		else if (dt_flags->precision <= dt_flags->len)
			dt_flags->hash = "0";
	}
	dt_flags->len_space = dt_flags->len + ft_strlen(dt_flags->hash);
}

void	apply_flags(t_flags *dt_flags, t_bool neg, t_bool signe)
{
	dt_flags->c = 0;
	if (signe && (neg || dt_flags->flags & PLUS || dt_flags->flags & SPACE))
	{
		if (neg)
			dt_flags->c = '-';
		else
			dt_flags->c = dt_flags->flags & PLUS ? '+' : ' ';
		if (dt_flags->space)
			--dt_flags->space;
	}
	if (dt_flags->flags & ZERO)
	{
		dt_flags->precision = dt_flags->space > dt_flags->len
			? dt_flags->space - dt_flags->len_space : 0;
		dt_flags->space = 0;
	}
	else
		dt_flags->precision = dt_flags->precision > dt_flags->len
			? dt_flags->precision - dt_flags->len : 0;
	dt_flags->space = dt_flags->space > dt_flags->len_space + dt_flags->precision
		? dt_flags->space - dt_flags->len_space - dt_flags->precision : 0;
}

void	lltoa(t_printf *dt, t_flags *dt_flags, intmax_t nbr)
{
	uintmax_t	save;
	//int			save_len;

	save = nbr < 0 ? -nbr : nbr;
	dt_flags->len = save == 0 && !(dt_flags->flags & DOT
		&& !dt_flags->precision)? 1 : 0;
	//len = 0;
	while (save)
	{
		save /= 10;
		dt_flags->len++;
	}
	dt_flags->len_space = dt_flags->len;
	apply_flags(dt_flags, nbr < 0, TRUE);
	padding(dt, dt_flags, TRUE);
	if (dt_flags->c)
	{
		*dt->buf_move = dt_flags->c;
		dt->buf_move++;
		dt->less--;
	}
	precision(dt, dt_flags);
	//if a vider
	dt->buf_move += dt_flags->len - 1;
	dt->less -= dt_flags->len - 1;
	if (dt_flags->len)
		addnbr(dt->buf_move, nbr < 0 ? -nbr : nbr, HEXAMIN, 10);
	dt->buf_move++;
	dt->less--;
	padding(dt, dt_flags, FALSE);
}

void	get_signed(t_printf *dt, t_flags *dt_flags, char type)
{
	intmax_t tmp;

	(void)type;
	if (dt_flags->flags & HH)
		tmp = (intmax_t)(char)va_arg(dt->ap, int);
	else if (dt_flags->flags & H)
		tmp = (intmax_t)(short)va_arg(dt->ap, int);
	else if (dt_flags->flags & L)
		tmp = (intmax_t)va_arg(dt->ap, long);
	else if (dt_flags->flags & LL)
		tmp = (intmax_t)va_arg(dt->ap, long long);
	else if (dt_flags->flags & J)
		tmp = va_arg(dt->ap, intmax_t);
	else if (dt_flags->flags & Z)
		tmp = (intmax_t)va_arg(dt->ap, size_t);
	else
		tmp = (intmax_t)va_arg(dt->ap, int);
	lltoa(dt, dt_flags, tmp);
}

void	ulltoa(t_printf *dt, t_flags *dt_flags, uintmax_t nbr)
{
	uintmax_t	save;

	save = nbr;
	dt_flags->len = save == 0 && !(dt_flags->flags & DOT
		&& !dt_flags->precision)? 1 : 0;
	while (save)
	{
		save /= dt_flags->base;
		dt_flags->len++;
	}
	apply_hash(dt, dt_flags, nbr);
	apply_flags(dt_flags, FALSE, FALSE);
	padding(dt, dt_flags, TRUE);
	rotative_buf(dt, dt_flags->hash, ft_strlen(dt_flags->hash));
	//dt_flags->len -= ft_strlen(dt_flags->hash);
	precision(dt, dt_flags);
	//if a vider
	dt->buf_move += dt_flags->len - 1;
	dt->less -= dt_flags->len - 1;
	if (dt_flags->len)
		addnbr(dt->buf_move, nbr, *dt->format == 'X'
			? HEXAMAX : HEXAMIN, dt_flags->base);
	dt->buf_move++;
	dt->less--;
	padding(dt, dt_flags, FALSE);
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
	if (dt_flags->flags & Z || type == 'p')
		tmp = (uintmax_t)va_arg(dt->ap, size_t);
	else if (dt_flags->flags & HH)
		tmp = (uintmax_t)(char)va_arg(dt->ap, unsigned int);
	else if (dt_flags->flags & H)
		tmp = (uintmax_t)(short)va_arg(dt->ap, unsigned int);
	else if (dt_flags->flags & L)
		tmp = (uintmax_t)va_arg(dt->ap, unsigned long);
	else if (dt_flags->flags & LL)
		tmp = (uintmax_t)va_arg(dt->ap, unsigned long long);
	else if (dt_flags->flags & J)
		tmp = va_arg(dt->ap, uintmax_t);
	else
		tmp = (uintmax_t)va_arg(dt->ap, unsigned int);
	ulltoa(dt, dt_flags, tmp);
}
