/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompedup <pompedup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:49:32 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/19 15:47:26 by pompedup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_data(t_printf *dt, t_flags *dt_flags, char type)
{
	if (type == 's')
		type_s(dt, dt_flags, type);
	//else if (type == 'S')
	//	type_us(dt, dt_flags, type);
	//else if (type == 'p')
	//	type_p(dt, dt_flags, type);
	//else if (type == 'b')
	//	type_b(dt, dt_flags, type);
	else if (type == 'd')
		get_signed(dt, dt_flags, type);
	//else if (type == 'D')
	//	type_ud(dt, dt_flags, type);
	//else if (type == 'i')
	//	type_d(dt, dt_flags, type);
	//else if (type == 'o')
	//	type_o(dt, dt_flags, type);
	//else if (type == 'O')
	//	type_uo(dt, dt_flags, type);
	//else if (type == 'u')
	//	type_u(dt, dt_flags, type);
	//else if (type == 'U')
	//	type_uu(dt, dt_flags, type);
	//else if (type == 'x')
	//	type_x(dt, dt_flags, type);
	//else if (type == 'X')
	//	type_ux(dt, dt_flags, type);
	else if (type == 'c')
		type_c(dt, dt_flags, type);
	else
		get_unsigned(dt, dt_flags, type);
	//else if (type == 'C')
	//	type_uc(dt, dt_flags, type);
	//else
	//	no_type(dt, dt_flags, type);
}

static int	process_data(t_printf *dt)
{
	t_flags dt_flags;

	dt_flags.space = 0;
	dt_flags.flags = 0;
	dt_flags.precision = 0;
	if (ft_strchr(FLAG, *dt->format) != NULL || ft_isdigit(*dt->format))
		dt->format = get_flags(dt->format, &dt_flags);
	get_data(dt, &dt_flags, *dt->format);
	dt->format++;
	return (0);
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
			write(1, dt->buf, BUFF_PRF);
			dt->buf_move = dt->buf;
			dt->less = BUFF_PRF;
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
			dt->back += process_data(dt);
		}
		else
		{
			size = ft_strposchrs(dt->format, "%");
			rotative_buf(dt, dt->format, size == -1 ? ft_strlen(dt->format) : size);
			dt->format += size == -1 ? ft_strlen(dt->format) : size;
		}
	}
}

void		padding(t_printf *dt, t_flags *dt_flags, t_bool before)
{
	char c;

	if (!dt_flags->space)
		return ;
	c = dt_flags->flags & ZERO ? '0' : ' ';
	if (before && !(dt_flags->flags & MINUS))
	{
		ft_memset(dt->buf_move, c, dt_flags->space);
		dt->buf_move += dt_flags->space;
		dt->less -= dt_flags->space;
		dt_flags->space = 0;
	}
	else if (!before && dt_flags->flags & MINUS)
	{
		ft_memset(dt->buf_move, c, dt_flags->space);
		dt->buf_move += dt_flags->space;
		dt->less -= dt_flags->space;
	}
}
/*
void	padding(t_printf *p, int n)
{
	if (!p->padding)
		return ;
	p->c = 32 | (p->f & F_ZERO);
	if (!n && !(p->f & F_MINUS))
		while (p->padding--)
			buffer(p, &p->c, 1);
	else if (n && (p->f & F_MINUS))
		while (p->padding--)
			buffer(p, &p->c, 1);
}
*/
