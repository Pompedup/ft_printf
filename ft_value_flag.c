/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:30:51 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/16 18:35:06 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_value_flag(t_printf *dt, unsigned char conv)
{
	char *tmp;
	char *tmp1;

	if ((tmp = ft_strchr(tmp1 = "sSpcC%",dt->str[dt->pos_s])) != NULL)
	{
		dt->pos_s++;
		return (ft_value_sspddioo(dt, tmp - tmp1));
	}
	else if ((tmp = ft_strchr(tmp1 = "dDioOuUxX",dt->str[dt->pos_s])) != NULL)
	{
		dt->pos_s++;
		return (ft_value_uuxxcc(dt, tmp - tmp1, conv));
	}
	return (NULL);
}

char	*ft_value_sspddioo(t_printf *dt, int type)
{
	char *tmp;

	if (type == 0)//Valide
		tmp = ft_strdup(va_arg(dt->ap, char*));
	else if (type == 1)//S
		tmp = va_arg(dt->ap, char*);
	else if (type == 2)//Valide
		tmp = ft_ptoa((long long)va_arg(dt->ap, void *));
	else if (type == 3)//Valide/c
		tmp = ft_ctoa(va_arg(dt->ap, int));
	else if (type == 6)//C
		tmp = va_arg(dt->ap, char*);
	else//Valide
		tmp = ft_strdup("%");
	return (tmp);
}

char	*ft_value_uuxxcc(t_printf *dt, int type, unsigned char conv)
{
	long long	var;
	unsigned long long var2;
	int			base;
//TYPE 3 ?
	var = 0;
	var2 = 0;
	if (conv & 32)
		var = (long long)(va_arg(dt->ap, size_t));
	else if (conv & 16 && (type == 0 || type == 2))
		var2 = (unsigned long long)(va_arg(dt->ap, intmax_t));
	else if (conv & 16 && (type == 3 || type == 5 || type == 7 || type == 8))
		var2 = (unsigned long long)(va_arg(dt->ap, uintmax_t));
	else if (conv & 8 && (type == 0 || type == 2))
		var = (long long)(va_arg(dt->ap, long long));
	else if (conv & 8 && (type == 3 || type == 5 || type == 7 || type == 8))
		var = (long long)(va_arg(dt->ap, unsigned long long));
	else if (conv & 4 && (type == 0 || type == 2))
		var = (long long)(va_arg(dt->ap, long));
	else if (conv & 4 && (type == 3 || type == 5 || type == 7 || type == 8))
		var = (long long)(va_arg(dt->ap, unsigned long));
	else if (conv & 2 && (type == 0 || type == 2))
		var = (long long)((char)(va_arg(dt->ap, int)));
	else if (conv & 2 && (type == 3 || type == 5 || type == 7 || type == 8))
		var = (long long)((unsigned char)(va_arg(dt->ap, unsigned int)));
	else if (conv & 1 && (type == 0 || type == 2))
		var = (long long)((short)(va_arg(dt->ap, int)));
	else if (conv & 1 && (type == 3 || type == 5 || type == 7 || type == 8))
		var = (long long)((unsigned short)(va_arg(dt->ap, unsigned int)));
	else if (type == 0 || type == 2)//Valide/di
		var = (long long)(va_arg(dt->ap, int));
	else if (type == 3)//Valide/o
		var = (long long)(va_arg(dt->ap, unsigned int));
	else if (type == 4)//O
		var = (long long)(va_arg(dt->ap, unsigned int));
	else if (type == 5)//Valide/u
		var = (long long)(va_arg(dt->ap, unsigned int));
	else if (type == 6)//U
		var = (long long)(va_arg(dt->ap, unsigned int));
	else if (type == 7)//Valide/x
		var = (long long)va_arg(dt->ap, unsigned int);
	else //(type == 8)//X
		var = (long long)va_arg(dt->ap, unsigned int);
	if (type == 0 || type == 2 || type == 5)
		base = 10;
	else if (type == 3)
		base = 8;
	else
		base = 16;
	return (var != 0 ? ft_lltoa_base(var, base, type == 8) : ft_ulltoa_base(var2, base, type == 8));
}
