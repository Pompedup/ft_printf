/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:56:33 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/17 15:44:39 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *uc_dest;
	unsigned char *uc_src;

	uc_dest = (unsigned char*)dest;
	uc_src = (unsigned char *)src;
	while (n--)
	{
		*(uc_dest++) = *(uc_src++);
		if (*(uc_src - 1) == (unsigned char)c)
			return ((void*)uc_dest);
	}
	return (NULL);
}
