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
	dt->pos_s++;
	if (dt->str[dt->pos_s - 1] == '{')
		return (color(dt));
	else if (dt->str[dt->pos_s - 1] == '[')
		return (color_back(dt));
	else if (ft_strchr(CONV, dt->str[dt->pos_s]) != NULL)
		return (value_flag(dt));
	else if (ft_strchr(FLAG, dt->str[dt->pos_s]) != NULL
		|| ft_isdigit(dt->str[dt->pos_s]))
		return (present_flag(dt));
	dt->tmp = (char*)malloc(1);
	return (0);
}

void		get_lst(t_printf *dt, t_list **lst)
{
	int		size;

	while (*dt->format)
	{
		size = 0;
		if (!ft_strchr("%{[", *dt->format))
		{
			while (*dt->format && !ft_strchr("%{[", *dt->format)
				&& size < 99)
				*(dt->buf)++ = *(dt->format)++;
			buf[size] = 0;
		}
		else
			size = verif_char(dt);
		dt->tot += size;
		ft_listpushback(lst, ft_listnew(dt->tmp, size));
	}
}

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

void		ft_init(t_printf *dt, char *str, t_list **lst)
{
	dt->format = str;
	dt->str = NULL;
	dt->pos_s = 0;
	dt->tot = 0;
	dt->tmp = NULL;
	*lst = NULL;
}
