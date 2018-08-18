/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:49:32 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/17 16:54:49 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	verif_char(t_printf *dt)
{
	dt->format++;
	if (*(dt->format - 1) == '{')
		return (color(dt));
	else if (*(dt->format - 1) == '[')
		return (color_back(dt));
	else if (ft_strchr(CONV, *dt->format) != NULL)
		return (value_flag(dt));
	else if (ft_strchr(FLAG, *dt->format) != NULL
		|| ft_isdigit(*dt->format))
		return (present_flag(dt));
	return (0);
}

void		get_lst(t_printf *dt)
{
	while (*dt->format)
	{
		if (!ft_strchr("%{[", *dt->format))
		{
			while (*dt->format && !ft_strchr("%{[", *dt->format))
			{
				*(dt->buf_move++) = *(dt->format++);
				dt->back++;
			}
		}
		else
			dt->back += verif_char(dt);
	}
}
/*
void		concatenate(t_printf *dt, t_list *lst)
{
	t_list	*next;
	int		i;

	i = 0;
	va_end(dt->ap);
	dt->str = (char*)malloc(dt->tot + 1);
	while (lst)
	{
		next = lst->next;
		ft_memcpy(dt->str + i, lst->content, lst->content_size);
		i += lst->content_size;
		free(lst->content);
		free(lst);
		lst = next;
	}
	dt->str[i] = 0;
	free(dt->buf);
}
*/
void		ft_init(t_printf *dt, char *str, char option)
{
	dt->format = str;
	dt->buf_move = dt->buf;
	dt->to_print = 0;
	dt->back = 0;
	dt->option = option;
}
