/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:41:43 by abezanni          #+#    #+#             */
/*   Updated: 2018/02/26 17:47:31 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Insersion des données dans la variable de retour avec
** une variable de type long long
*/

static void	ft_lltoa_insert(char *back, int base,
	unsigned long long val, int maj)
{
	*(back--) = 0;
	while (val)
	{
		if (val % base > 9)
			*(back--) = val % base + (maj ? 55 : 87);
		else
			*(back--) = val % base + 48;
		val /= base;
	}
}

/*
** Gestion d'une variable de type long long a convertir en tableau de
** charactères avec une conversion possible selon la base et des majuscules
** (selon la base)
*/

char		*ft_lltoa_base(long long value, int base, int maj)
{
	char				*back;
	int					i;
	unsigned long long	save;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	save = value < 0 ? -((unsigned long long)value) : (unsigned long long)value;
	i = 0;
	while (save)
	{
		save /= base;
		i++;
	}
	save = value < 0 ? -((unsigned long long)value) : (unsigned long long)value;
	if (value < 0)
		i = base == 10 ? i + 1 : i;
	if (!(back = (char *)malloc(i + 1)))
		return (0);
	back[0] = '-';
	ft_lltoa_insert(back + i, base, save, maj);
	return (back);
}
