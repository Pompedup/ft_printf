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

int	type_p(t_printf *dt, char c)
{
	int size;

	(void)c;
	strcpy(dt->buf_move, "Ox");
	dt->buf_move += 2;
	size = ft_ulltoa_base(dt->buf_move,
		(unsigned long long)va_arg(dt->ap, void *),
		16, 0);
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}
