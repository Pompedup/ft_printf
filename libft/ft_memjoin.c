/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:26:30 by abezanni          #+#    #+#             */
/*   Updated: 2018/01/20 18:07:53 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *s1, void *s2, size_t s_s1, size_t s_s2)
{
	char *back;
	char *tmp;

	if (!(back = (char *)malloc(s_s1 + s_s2 + 1)))
		return (NULL);
	tmp = back;
	while (s_s1--)
		*(tmp++) = *((char *)(s1++));
	while (s_s2--)
		*(tmp++) = *((char *)(s2++));
	*tmp = 0;
	return ((void *)back);
}
