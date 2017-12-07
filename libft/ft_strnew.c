/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:25:19 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/09 22:54:28 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *back;

	if (!(back = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(back, size);
	back[size] = 0;
	return (back);
}
