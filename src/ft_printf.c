/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:38:10 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/18 17:26:50 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init(t_printf *dt, char *str, char option)
{
	dt->format = str;
	dt->buf_move = dt->buf;
	dt->less = BUFF_SIZE;
	dt->back = 0;
	dt->option = option;
}

int			ft_printf(char *format, ...)
{
	static t_printf	dt;

	ft_init(&dt, format, FT_PRINTF);
	va_start(dt.ap, format);
	process_format(&dt);
	write(1, dt.buf, BUFF_PRF - dt.less);
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
