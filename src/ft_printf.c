/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompedup <pompedup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:38:10 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/31 14:06:36 by pompedup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init(t_printf *dt, int fd, char *str, char option)
{
	dt->format = str;
	dt->buf_move = dt->buf;
	dt->less = BUFF_PRF;
	dt->option = option;
	if (option == FT_SPRINTF)
		dt->str = ft_strdup("");
	dt->tot = 0;
	dt->fd = fd;
}

int			ft_printf(char *format, ...)
{
	static t_printf	dt;

	ft_init(&dt, 1, format, FT_PRINTF);
	va_start(dt.ap, format);
	process_format(&dt);
	write(1, dt.buf, BUFF_PRF - dt.less);
	return (dt.tot + BUFF_PRF - dt.less);
}



int			ft_fprintf(int fd, char *format, ...)
{
	static t_printf	dt;

	if (write(fd, "", 0) == -1)
		return (-1);
	ft_init(&dt, fd, format, FT_FPRINTF);
	va_start(dt.ap, format);
	process_format(&dt);
	write(fd, dt.buf, BUFF_PRF - dt.less);
	return (dt.tot + BUFF_PRF - dt.less);
}

int			ft_sprintf(char **str, char *format, ...)
{
	static t_printf	dt;

	if (!str)
		return (-1);
	ft_init(&dt, -1, format, FT_SPRINTF);
	if (dt.str == NULL)
		return (-1);
	va_start(dt.ap, format);
	process_format(&dt);
	if (BUFF_PRF - dt.less)
		*str = ft_memjoin(dt.str, dt.buf, dt.tot, BUFF_PRF - dt.less);
	else
		*str = dt.str;
	return (dt.tot + BUFF_PRF - dt.less);
	//get_lst(&dt, &lst);
	//concatenate(&dt, lst);
	//*str = dt.str;
//
	//return (dt.tot);
}
