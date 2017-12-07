/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:23:10 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/07 16:06:58 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	va_list ap;
	int i;
	int back;

	i = 0;
	back = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
	/*	else
			ft_nbr_percent(str, &i, &ap, &back);*/
		i++;
		back++;
	}
	va_end(ap);
	return (back);
}
