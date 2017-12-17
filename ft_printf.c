/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:38:10 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/16 16:58:29 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_go_print(char *str)
{
	write(1, str, ft_strlen(str));
	free(str);
}

char	*ft_verif_char(t_printf *dt)
{
	if (ft_strchr("sSpdDioOuUxXcC%",dt->str[dt->pos_s]) != NULL)
		return (ft_value_flag(dt, 0));
	else if (ft_strchr("+-0# hljz",dt->str[dt->pos_s]) != NULL
		|| ft_isdigit(dt->str[dt->pos_s]))
		return (ft_present_flag(dt));
	return (NULL);
}

int		ft_printf(char *str, ...)
{
	t_printf	dt;
	char		buf[50];
	int			i;
	char		*tmp;

	dt.str = str;
	dt.pos_s = 0;
	dt.buf = NULL;
	dt.tot = 0;
	ft_bzero(buf, 50);
	va_start(dt.ap, str);
	while (dt.str[dt.pos_s])
	{
		i = 0;
		while (dt.str[dt.pos_s] && dt.str[dt.pos_s] != '%' && i < 48)
		{
			buf[i++] = dt.str[dt.pos_s++];
			dt.tot++;
		}
		if (buf[0])
		{
			if (dt.buf)
				dt.buf = ft_strmjoin(dt.buf, buf, 1);
			else
				dt.buf = ft_strdup(buf);
			ft_bzero(buf, 50);
		}
		if (dt.str[dt.pos_s] == '%')
		{
			dt.pos_s++;
			tmp = ft_verif_char(&dt);
			if (dt.buf)
				dt.buf = ft_strmjoin(dt.buf, tmp, 3);
			else
				dt.buf = tmp;
			dt.tot += ft_strlen(tmp);
		}
	}
	va_end(dt.ap);
	ft_go_print(dt.buf);
	return (dt.tot);
}

//	va_arg(dt.ap, int);
//	va_arg(dt->ap, int);
