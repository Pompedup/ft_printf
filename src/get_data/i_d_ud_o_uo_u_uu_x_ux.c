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

char	*type_i_d(t_printf *dt, char c)
{
	(void)c;
	return (ft_lltoa_base((long long)(va_arg(dt->ap, int)), 10, 0));
}

/*
** Gestion des %D et %O.
*/

char	*type_ud(t_printf *dt, char c)
{
	(void)c;
	return (ft_lltoa_base((va_arg(dt->ap, long long)),
		10, 0));
}

/*
** Gestion des %u.
*/

char	*type_u(t_printf *dt, char c)
{
	(void)c;
	return (ft_ulltoa_base((unsigned long long)(va_arg(dt->ap, unsigned int)),
		10, 0));
}

/*
** Gestion des %U.
*/

char	*type_uu_uo(t_printf *dt, char c)
{
	(void)c;
	return (ft_ulltoa_base((unsigned long long)(va_arg(dt->ap, unsigned long)),
		c == 'U' ? 10 : 8, 0));
}

/*
** Gestion des %o %x et %X.
*/

char	*type_o_x_ux(t_printf *dt, char c)
{
	return (ft_lltoa_base((long long)(va_arg(dt->ap, unsigned int)),
		c == 'o' ? 8 : 16, c == 'X'));
}
