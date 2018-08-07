/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:02:27 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/10 10:44:50 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	if (s1 == s2 || n == 0)
		return (0);
	ucs1 = ((unsigned char*)s1);
	ucs2 = ((unsigned char*)s2);
	while (--n && *ucs1 == *ucs2)
	{
		if (n)
		{
			ucs1++;
			ucs2++;
		}
	}
	return (*ucs1 - *ucs2);
}
