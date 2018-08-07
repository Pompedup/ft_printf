/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:47:36 by abezanni          #+#    #+#             */
/*   Updated: 2018/02/26 17:48:32 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Insersion des données dans la variable de retour avec
** une variable de type unsigned long long
*/

static void	ft_ulltoa_insert(char *back, int base,
	unsigned long long val, int maj)
{
	*(back--) = 0;
	while (val)
	{
		if (val % base > 9 && !maj)
			*(back--) = val % base + 87;
		else if (val % base > 9 && maj)
			*(back--) = val % base + 55;
		else
			*(back--) = val % base + 48;
		val /= base;
	}
}

/*
** Gestion d'une variable de type unsigned long long a convertir en tableau de
** charactères avec une conversion possible selon la base et des majuscules
** si hexadecimal majuscule
*/

char		*ft_ulltoa_base(unsigned long long value, int base, int maj)
{
	char				*back;
	int					i;
	unsigned long long	save;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	i = 0;
	save = value;
	while (save)
	{
		save /= base;
		i++;
	}
	if (!(back = (char *)malloc(i + 1)))
		return (0);
	back[0] = '-';
	ft_ulltoa_insert(back + i, base, value, maj);
	return (back);
}
