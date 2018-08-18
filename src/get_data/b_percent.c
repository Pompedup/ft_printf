/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_percent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:10:42 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 14:48:29 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des %b
*/

int	type_b(t_printf *dt, char c)
{
	int size;
	(void)c;
	
	size = ft_ulltoa_base(dt->buf_move, va_arg(dt->ap, unsigned int), 2, 0);
	dt->buf_move += size;
	dt->to_print += size;
	return (size);
}

/*
** Gestion des %%
*/

int	type_percent(t_printf *dt, char c)
{
	(void)c;
	*(dt->buf_move++) = '%';
	dt->to_print++;
	return (1);
}
