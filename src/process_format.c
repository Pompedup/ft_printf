/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:49:32 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/18 18:31:22 by abezanni         ###   ########.fr       */
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
	//else if (type == 'd')
	//	type_d(dt, dt_flags, type);
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
	//else if (type == 'c')
	//	type_c(dt, dt_flags, type);
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
	return (0);
}

void		rotative_buf(t_printf *dt, char *src, int to_cpy)
{
	while (to_cpy)
	{
		ft_memcpy(dt->buf_move, src, to_cpy > dt->less ? dt->less : to_cpy);
		dt->less -= to_cpy > dt->less ? dt->less : to_cpy;
		to_cpy -= to_cpy > dt->less ? dt->less : to_cpy;
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
		if (ft_strchr("%{[", *dt->format))
		{
			dt->format++;
			dt->back += process_data(dt);
		}
		else
		{
			size = ft_strchrs(dt->format, "%{[") - dt->format;
			rotative_buf(dt, dt->format, size);
			dt->format += size;
		}
	}
}

void		padding(t_printf *dt, t_flags *dt_flags, t_bool before)
{
	char c;

	if (!dt_flags->space)
		return ;
	c = dt->flags & ZERO ? '0' : ' ';
	if (before && !(dt->flags & MINUS))

}


gcl https://github.com/BenjaminSouchet/Ft_printf.git test
