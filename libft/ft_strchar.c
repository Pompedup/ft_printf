/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:49:33 by abezanni          #+#    #+#             */
/*   Updated: 2018/01/14 14:53:43 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchar(int c, int size)
{
	char *back;

	if (!(back = (char*)malloc(size + 1)))
		return (NULL);
	back[size] = 0;
	while (size)
		back[--size] = c;
	return (back);
}
