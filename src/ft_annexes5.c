/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexes5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:10:42 by abezanni          #+#    #+#             */
/*   Updated: 2018/02/26 18:19:39 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des %b
*/

char	*ft_binary(t_printf *dt, char c)
{
	(void)c;
	return (ft_ulltoa_base(va_arg(dt->ap, unsigned int), 2, 0));
}

/*
** Gestion des %%
*/

char	*ft_percent(t_printf *dt, char c)
{
	(void)c;
	(void)dt;
	return (ft_strdup("%"));
}
