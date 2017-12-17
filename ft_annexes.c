/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:35:14 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/16 16:22:41 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_nbr_len_pbase(long long n, int base)
{
	int back;

	back = 0;
	while (n)
	{
		n /= base;
		back++;
	}
	return (back);
}

char	*ft_ptoa(long long n)
{
	char	*to_join;
	int		i;
	if (n == 0)
		return (ft_strdup("0x0"));
	i = ft_nbr_len_pbase(n, 16);
	if (!(to_join = (char*)malloc(i + 1)))
		return (0);
	to_join[i] = 0;
	while (--i >= 0)
	{
		if (n % 16 > 9)
			to_join[i] = n % 16 + 87;
		else
			to_join[i] = n % 16 + 48;
		n /= 16;
	}
	return (ft_strmjoin("0x", to_join, 2));
}

char	*ft_ctoa(int c)
{
	char back[2];

	back[0] = c;
	back[1] = 0;
	return (ft_strdup(back));
}
