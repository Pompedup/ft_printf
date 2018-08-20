/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompedup <pompedup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:20:44 by pompedup          #+#    #+#             */
/*   Updated: 2018/08/20 13:48:27 by pompedup         ###   ########.fr       */
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

	if (!dt_flags->precision)
		return ;
	c = '0';
	ft_memset(dt->buf_move, c, dt_flags->precision);
	dt->buf_move += dt_flags->precision;
	dt->less -= dt_flags->precision;
}

void	lltoa(t_printf *dt, t_flags *dt_flags, intmax_t nbr)
{
	uintmax_t	save;
	int			len;
	//int			save_len;

	save = nbr < 0 ? -nbr : nbr;
	len = save == 0 && !(dt_flags->flags & DOT && !dt_flags->precision)? 1 : 0;
	//len = 0;
	while (save)
	{
		save /= 10;
		len++;
	}
	if (dt_flags->space && (nbr < 0 || dt_flags->flags & PLUS || dt_flags->flags & SPACE))
		--dt_flags->space;
	if (dt_flags->flags & ZERO)
	{
		dt_flags->precision = dt_flags->space > len ? dt_flags->space - len : 0;
		dt_flags->space = 0;
	}
	else
		dt_flags->precision = dt_flags->precision > len ? dt_flags->precision - len : 0;
	dt_flags->space = dt_flags->space > len + dt_flags->precision
		? dt_flags->space - len - dt_flags->precision : 0;
	padding(dt, dt_flags, TRUE);
	if (nbr < 0 || dt_flags->flags & PLUS || dt_flags->flags & SPACE)
	{
		if (nbr < 0)
			*dt->buf_move = '-';
		else
			*dt->buf_move = dt_flags->flags & PLUS ? '+' : ' ';
		dt->buf_move++;
		dt->less--;
	}
	precision(dt, dt_flags);
	//if a vider
	dt->buf_move += len - 1;
	dt->less -= len - 1;
	if (len)
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

void	ulltoa(t_printf *dt, t_flags *dt_flags, uintmax_t nbr, int base)
{
	uintmax_t	save;
	int			len;
	char		*hash;
	//int			save_len;

	save = nbr;
	len = save == 0 ? 1 : 0;
	hash = "";
	while (save)
	{
		save /= base;
		len++;
	}
	if (*dt->format == 'p')
	{
		hash = "0x";
		len += 2;
	}
	else if (dt_flags->flags & HASH && base != 10)
	{
		if (base == 16)
			hash = *dt->format == 'X' ? "0X" : "0x";
		else if (base == 2)
			hash = "0b";
		else if (base == 8)
			hash = "0";
		len += ft_strlen(hash);
	}
	if (dt_flags->flags & ZERO)
	{
		dt_flags->precision = dt_flags->space > len ? dt_flags->space - len : 0;
		dt_flags->space = 0;
	}
	else
		dt_flags->precision = dt_flags->precision > len ? dt_flags->precision - len : 0;
	dt_flags->space = dt_flags->space > len + dt_flags->precision
		? dt_flags->space - len - dt_flags->precision : 0;
	padding(dt, dt_flags, TRUE);
	rotative_buf(dt, hash, ft_strlen(hash));
	len -= ft_strlen(hash);
	precision(dt, dt_flags);
	//if a vider
	dt->buf_move += len - 1;
	dt->less -= len - 1;
	addnbr(dt->buf_move, nbr, *dt->format == 'X' ? HEXAMAX : HEXAMIN, base);
	dt->buf_move++;
	dt->less--;
	padding(dt, dt_flags, FALSE);
}

void	get_unsigned(t_printf *dt, t_flags *dt_flags, char type)
{
	uintmax_t	tmp;
	int			base;

	if (type == 'o' || type == 'O')
		base = 8;
	else if (type == 'x' || type == 'X' || type == 'p')
		base = 16;
	else if (type == 'b')
		base = 2;
	else
		base = 10;
	if (dt_flags->flags & HH)
		tmp = (uintmax_t)(char)va_arg(dt->ap, unsigned int);
	else if (dt_flags->flags & H)
		tmp = (uintmax_t)(short)va_arg(dt->ap, unsigned int);
	else if (dt_flags->flags & L)
		tmp = (uintmax_t)va_arg(dt->ap, unsigned long);
	else if (dt_flags->flags & LL)
		tmp = (uintmax_t)va_arg(dt->ap, unsigned long long);
	else if (dt_flags->flags & J)
		tmp = va_arg(dt->ap, uintmax_t);
	else if (dt_flags->flags & Z)
		tmp = (uintmax_t)va_arg(dt->ap, size_t);
	else
		tmp = (uintmax_t)va_arg(dt->ap, unsigned int);
	ulltoa(dt, dt_flags, tmp, base);
}
