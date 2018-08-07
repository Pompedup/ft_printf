/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:22:13 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/18 14:22:21 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iterative_power(int nb, int power)
{
	int back;

	if (power < 0)
		back = 0;
	else if (power == 0)
		back = 1;
	else
		back = nb;
	while (--power > 0)
	{
		back = back * nb;
	}
	return (back);
}
