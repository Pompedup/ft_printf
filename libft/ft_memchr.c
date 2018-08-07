/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:27:26 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/13 00:26:38 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *ucsrc;

	ucsrc = ((unsigned char*)src);
	while (n--)
		if ((unsigned char)c == *(ucsrc++))
			return (--ucsrc);
	return (NULL);
}
