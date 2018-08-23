/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:15:38 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/23 15:06:01 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_signe(t_flags *dt_flags, t_bool neg)
{
	if (neg || dt_flags->flags & PLUS || dt_flags->flags & SPACE)
	{
		if (neg)
			dt_flags->c = '-';
		else
			dt_flags->c = dt_flags->flags & PLUS ? '+' : ' ';
		dt_flags->len++;
	}
}

void	apply_hash(t_flags *dt_flags, uintmax_t nbr)
{
	if (dt_flags->flags & HASH && !nbr)
	{
		if (dt_flags->type == 'o' || dt_flags->type == 'O')
		{
			if (dt_flags->flags & DOT && (dt_flags->precision || !(nbr || dt_flags->space)))
				dt_flags->flags -= HASH;
			if (!(dt_flags->flags & DOT))
				dt_flags->flags -= HASH;
		}
		else
			dt_flags->flags -= HASH;
	}
	if ((dt_flags->flags & HASH && dt_flags->base != 10) || dt_flags->type == 'p')
	{
		if (dt_flags->base == 16)
			dt_flags->hash = dt_flags->type == 'X' ? "0X" : "0x";
		else if (dt_flags->base == 16)
			dt_flags->hash = "0b";
		else if (!dt_flags->precision)
			dt_flags->hash = "0";
		dt_flags->len += ft_strlen(dt_flags->hash);
	}
}

void	apply_flags(t_flags *dt_flags, t_bool neg, t_bool signe, uintmax_t nbr)
{
	dt_flags->c = 0;
	dt_flags->hash = NULL;
	if (dt_flags->flags & DOT)
		dt_flags->precision = dt_flags->precision > dt_flags->len
			? dt_flags->precision - dt_flags->len : 0;
	if (signe)
		apply_signe(dt_flags, neg);
	else
		apply_hash(dt_flags, nbr);
	if (dt_flags->flags & ZERO)
	{
		dt_flags->precision = dt_flags->space > dt_flags->len
			? dt_flags->space - dt_flags->len : 0;
		dt_flags->space = 0;
	}
	dt_flags->space = dt_flags->space > dt_flags->len + dt_flags->precision
		? dt_flags->space - dt_flags->len - dt_flags->precision : 0;
}
