/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:41:51 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/12 17:51:20 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(const char *s)
{
	int i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		ft_putchar(s[i]);
	ft_putchar('\n');
}
