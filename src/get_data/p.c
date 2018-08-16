/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:06:10 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 14:56:28 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des %p.
*/

char	*type_p(t_printf *dt, char c)
{
	(void)c;
	return (ft_strmjoin("0x", ft_ulltoa_base(
		(unsigned long long)va_arg(dt->ap, void *), 16, 0), 2));
}
