/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexes2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:02:20 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/16 18:33:56 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_lltoa_insert(char *back, int base, long long val, int maj)
{
	*(back--) = 0;
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

char		*ft_lltoa_base(long long value, int base, int maj)
{
	char		*back;
	int			i;
	long long	save;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	i = 0;
	save = value;
	while (save)
	{
		save /= base;
		i++;
	}
	if (value < 0)
	{
		value = -value;
		i = base == 10 ? i + 1 : i;
	}
	if (!(back = (char *)malloc(i + 1)))
		return (0);
	back[0] = '-';
	ft_lltoa_insert(back + i, base, value, maj);
	return (back);
}

static void	ft_ulltoa_insert(char *back, int base, unsigned long long val, int maj)
{
	*(back--) = 0;
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

char		*ft_ulltoa_base(unsigned long long value, int base, int maj)
{
	char		*back;
	int			i;
	unsigned long long	save;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	i = 0;
	save = value;
	while (save)
	{
		save /= base;
		i++;
	}
	if (!(back = (char *)malloc(i + 1)))
		return (0);
	back[0] = '-';
	ft_ulltoa_insert(back + i, base, value, maj);
	return (back);
}
