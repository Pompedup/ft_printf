/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompedup <pompedup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:55:07 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/19 16:41:57 by pompedup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_convert(char *format, t_flags *dt_flags, int conv)
{
	if ((conv == 6 && *format == 'h') || (conv == 8 && *format == 'l'))
	{
		conv++;
		format++;
	}
	if (dt_flags->flags < (1 << conv))
		dt_flags->flags += 1 << conv;
	return (format);
}

char		*get_flags(char *format, t_flags *dt_flags)
{
	int		tmp;

	while ((*format && (tmp = ft_strposchr(FLAG, *format)) > -1)
		|| ft_isdigit(*format))
	{
		if (tmp == -1)
		{
			dt_flags->space = ft_atoi(format);
			format += ft_nbr_len(dt_flags->space) - 1;
		}
		format++;
		if (1 << tmp == DOT)
		{
			dt_flags->precision = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		if (tmp > 5)
			format = get_convert(format, dt_flags, tmp);
		else if (tmp > -1)
			dt_flags->flags |= 1 << tmp;
	}
	if ((dt_flags->flags & DOT || dt_flags->flags & MINUS)
		&& dt_flags->flags & ZERO)
		dt_flags->flags -= ZERO;
	return (format);
}
