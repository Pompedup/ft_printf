/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexes3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:32:32 by abezanni          #+#    #+#             */
/*   Updated: 2018/01/25 19:27:43 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** char		*ft_minid(t_printf *dt, char c);
** char		*ft_majdo(t_printf *dt, char c);
** char		*ft_minu(t_printf *dt, char c);
** char		*ft_maju(t_printf *dt, char c);
** char		*ft_minox_majx(t_printf *dt, char c);
*/

#include "ft_printf.h"

/*
** Gestion des %i et %d.
*/

char	*ft_minid(t_printf *dt, char c)
{
	(void)c;
	return (ft_lltoa_base((long long)(va_arg(dt->ap, int)), 10, 0));
}

/*
** Gestion des %D et %O.
*/

char	*ft_majdo(t_printf *dt, char c)
{
	(void)c;
	return (ft_lltoa_base((va_arg(dt->ap, long long)),
		10, 0));
}

/*
** Gestion des %u.
*/

char	*ft_minu(t_printf *dt, char c)
{
	(void)c;
	return (ft_ulltoa_base((unsigned long long)(va_arg(dt->ap, unsigned int)),
		10, 0));
}

/*
** Gestion des %U.
*/

char	*ft_maju(t_printf *dt, char c)
{
	(void)c;
	return (ft_ulltoa_base((unsigned long long)(va_arg(dt->ap, unsigned long)),
		c == 'U' ? 10 : 8, 0));
}

/*
** Gestion des %o %x et %X.
*/

char	*ft_minox_majx(t_printf *dt, char c)
{
	return (ft_lltoa_base((long long)(va_arg(dt->ap, unsigned int)),
		c == 'o' ? 8 : 16, c == 'X'));
}
