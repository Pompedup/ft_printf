/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:50:18 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/12 17:50:02 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*back;

	if (!s || !(back = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		back[i] = f(i, s[i]);
	back[i] = 0;
	return (back);
}
