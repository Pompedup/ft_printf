/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:38:10 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 18:57:36 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *format, ...)
{
	static t_printf	dt;

	ft_init(&dt, format, FT_PRINTF);
	va_start(dt.ap, format);
	get_lst(&dt);
	return (dt.back);
}


/*
int			ft_fprintf(int fd, char *format, ...)
{
	static t_printf	dt;

	ft_init(&dt, format, FT_FPRINTF);
	va_start(dt.ap, format);
	get_lst(&dt, &lst);
	concatenate(&dt, lst);
	write(fd, dt.str, dt.tot);
	free(dt.str);
	return (dt.tot);
}

int			ft_sprintf(char **str, char *format, ...)
{
	static t_printf	dt;

	ft_init(&dt, format, FT_SPRINTF);
	va_start(dt.ap, format);
	get_lst(&dt, &lst);
	concatenate(&dt, lst);
	*str = dt.str;
	return (dt.tot);
}
*/