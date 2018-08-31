/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompedup <pompedup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:49:32 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/31 14:04:11 by pompedup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_data(t_printf *dt, t_flags *dt_flags, char type)
{
	dt_flags->type = type;
	if (dt_flags->flags & MINUS && dt_flags->flags & ZERO)
		dt_flags->flags -= ZERO;
	if (ft_strchr("diDpboOuUxX", type))
	{
		if (dt_flags->flags & DOT && dt_flags->flags & ZERO)
			dt_flags->flags -= ZERO;
		if (ft_strchr("diD", type))
			get_signed(dt, dt_flags, type);
		else
			get_unsigned(dt, dt_flags, type);
	}
	else if (ft_strchr("sS", type))
		type_s(dt, dt_flags, type);
	else
		type_c(dt, dt_flags, type);
}

static void	process_data(t_printf *dt)
{
	t_flags dt_flags;

	dt_flags.space = 0;
	dt_flags.flags = 0;
	dt_flags.precision = 0;
	if (ft_strchr(FLAG, *dt->format) != NULL || ft_isdigit(*dt->format))
		dt->format = get_flags(dt->format, &dt_flags);
	if (*dt->format)
	{
		get_data(dt, &dt_flags, *dt->format);
		dt->format++;
	}
}

void		rotative_buf(t_printf *dt, char *src, int to_cpy)
{
	int size;

	while (to_cpy)
	{
		size = to_cpy > dt->less ? dt->less : to_cpy;
		ft_memcpy(dt->buf_move, src, size);
		dt->buf_move += size;
		dt->less -= size;
		to_cpy -= size;
		if (dt->less == 0)
		{
			if (dt->option == FT_SPRINTF)
				dt->str = ft_memjoin(dt->str, dt->buf,
					dt->tot, BUFF_PRF - dt->less);
			else
				write(dt->fd, dt->buf, BUFF_PRF);
			dt->buf_move = dt->buf;
			dt->less = BUFF_PRF;
			dt->tot += BUFF_PRF;
		}
	}
}

void		process_format(t_printf *dt)
{
	int size;

	while (*dt->format)
	{
		if (ft_strchr("%", *dt->format))
		{
			dt->format++;
			if (*(dt->format))
				process_data(dt);
		}
		else
		{
			size = ft_strposchrs(dt->format, "%");
			rotative_buf(dt, dt->format, size == -1 ? ft_strlen(dt->format) : size);
			dt->format += size == -1 ? ft_strlen(dt->format) : size;
		}
	}
}

void		padding(t_printf *dt, t_flags *dt_flags, t_bool precision)
{
	char	c;
	int		size;

	size = precision ? dt_flags->precision : dt_flags->space;
	if (!size)
		return ;
	c = precision ? '0' : ' ';
	ft_memset(dt->buf_move, c, size);
	dt->buf_move += size;
	dt->less -= size;
}
