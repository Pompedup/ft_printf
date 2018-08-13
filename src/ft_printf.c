/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:38:10 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/11 17:57:59 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_go_print(t_printf dt, t_list *lst)
{
	char	*final;
	t_list	*next;
	int		i;

	i = 0;
	va_end(dt.ap);
	final = (char*)malloc(dt.tot + 1);
	while (lst)
	{
		next = lst->next;
		ft_memcpy(final + i, lst->content, lst->content_size);
		i += lst->content_size;
		free(lst->content);
		free(lst);
		lst = next;
	}
	final[i] = 0;
	write(1, final, dt.tot);
	free(dt.buf);
	free(final);
	return (dt.tot);
}

static int	ft_verif_char(t_printf *dt)
{
	dt->pos_s++;
	if (dt->str[dt->pos_s - 1] == '{')
		return (ft_color(dt));
	else if (dt->str[dt->pos_s - 1] == '[')
		return (ft_color_back(dt));
	else if (ft_strchr(CONV, dt->str[dt->pos_s]) != NULL)
		return (ft_value_flag(dt));
	else if (ft_strchr(FLAG, dt->str[dt->pos_s]) != NULL
		|| ft_isdigit(dt->str[dt->pos_s]))
		return (ft_present_flag(dt));
	dt->tmp = (char*)malloc(1);
	return (0);
}

static void	ft_init(t_printf *dt, char *str, char *buf, t_list **lst)
{
	dt->str = str;
	dt->pos_s = 0;
	dt->buf = NULL;
	dt->tot = 0;
	dt->ft = NULL;
	dt->tmp = NULL;
	*lst = NULL;
	ft_bzero(buf, 100);
}

int			ft_printf(char *str, ...)
{
	static t_printf	dt;
	char			buf[100];
	int				size;
	t_list			*lst;

	ft_init(&dt, str, buf, &lst);
	va_start(dt.ap, str);
	while (dt.str[dt.pos_s])
	{
		size = 0;
		if (!ft_strchr("%{[", dt.str[dt.pos_s]))
		{
			while (dt.str[dt.pos_s] && !ft_strchr("%{[", dt.str[dt.pos_s])
				&& size < 99)
				buf[size++] = dt.str[dt.pos_s++];
			buf[size] = 0;
			dt.tmp = ft_strdup(buf);
		}
		else
			size = ft_verif_char(&dt);
		dt.tot += size;
		ft_listpushback(&lst, ft_listnew(dt.tmp, size));
	}
	return (ft_go_print(dt, lst));
}
