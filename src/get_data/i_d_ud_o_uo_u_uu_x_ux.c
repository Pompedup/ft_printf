/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_d_ud_o_uo_u_uu_x_ux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:32:32 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 14:51:59 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des %i et %d.
*/

int	type_i_d(t_printf *dt, char c)
{
	int size;

	(void)c;
	size = ft_lltoa_base(dt->buf_move, (long long)(va_arg(dt->ap, int)), 10, 0);
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}

/*
** Gestion des %D et %O.
*/

int	type_ud(t_printf *dt, char c)
{
	int size;
	
	(void)c;
	size = ft_lltoa_base(dt->buf_move, va_arg(dt->ap, long long), 10, 0);
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}

/*
** Gestion des %u.
*/

int	type_u(t_printf *dt, char c)
{
	int size;

	(void)c;
	size = ft_ulltoa_base(dt->buf_move, (unsigned long long)(va_arg(dt->ap,
		unsigned int)), 10, 0);
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}

/*
** Gestion des %U.
*/

int	type_uu_uo(t_printf *dt, char c)
{
	int size;

	(void)c;
	size = ft_ulltoa_base(dt->buf_move,
		(unsigned long long)(va_arg(dt->ap, unsigned long)),
		c == 'U' ? 10 : 8, 0);
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}

/*
** Gestion des %o %x et %X.
*/

int	type_o_x_ux(t_printf *dt, char c)
{
	int size;

	size = ft_lltoa_base(dt->buf_move, (long long)(va_arg(dt->ap, unsigned int)),
		c == 'o' ? 8 : 16, c == 'X');
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}
