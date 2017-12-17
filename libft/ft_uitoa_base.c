/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:45:19 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/16 15:45:30 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_uitoa_insert(char *back, long long base, long long val, int maj)
{
	while (val)
	{
		if (val % base > 9 && !maj)
			*(back--) = val % base + 87;
		else if (val % base > 9 && maj)
			*(back--) = val % base + 55;
		else
			*(back--) = val % base + 48;
		val /= base;
	}
}

char		*ft_uitoa_base(unsigned int value, int base, int maj)
{
	char		*back;
	int			i;
	long long	lvalue;
	long long	lsave;
	long long	lbase;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	i = 0;
	lsave = (long long)value;
	lvalue = lsave;
	lbase = (long long)base;
	while (lsave)
	{
		lsave /= lbase;
		i++;
	}
	if (!(back = (char *)malloc(i + 1)))
		return (0);
	back[i] = 0;
	i--;
	ft_uitoa_insert(back + i, lbase, lvalue, maj);
	return (back);
}
