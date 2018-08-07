/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:08:49 by abezanni          #+#    #+#             */
/*   Updated: 2018/02/14 17:41:00 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_color(t_printf *dt)
{
	static t_color	src_clr[] = {
		{"black}", "30m"}, {"red}", "31m"}, {"green}", "32m"},
		{"yellow}", "33m"}, {"blue}", "34m"}, {"magenta}", "35m"},
		{"cyan}", "36m"}, {"white}", "37m"}, {"eoc}", "0m"}, {NULL, NULL},
	};
	int				i;

	i = 0;
	while (src_clr[i].color && ft_strncmp(dt->str + dt->pos_s,
		src_clr[i].color, ft_strlen(src_clr[i].color)))
		i++;
	if (src_clr[i].color)
	{
		while (dt->str[dt->pos_s] != '}')
			dt->pos_s++;
		dt->pos_s++;
		dt->tmp = ft_strjoin("\033[0;", src_clr[i].color_code);
		return (ft_strlen(dt->tmp));
	}
	dt->tmp = ft_strdup("{");
	return (1);
}

int		ft_color_back(t_printf *dt)
{
	static t_color	src_clr[] = {
		{"black]", "40m"}, {"red]", "41m"}, {"green]", "42m"},
		{"yellow]", "43m"}, {"blue]", "44m"}, {"magenta]", "45m"},
		{"cyan]", "46m"}, {"white]", "47m"}, {"eoc]", "0m"}, {NULL, NULL},
	};
	int				i;

	i = 0;
	while (src_clr[i].color && ft_strncmp(dt->str + dt->pos_s,
		src_clr[i].color, ft_strlen(src_clr[i].color)))
		i++;
	if (src_clr[i].color)
	{
		while (dt->str[dt->pos_s] != ']')
			dt->pos_s++;
		dt->pos_s++;
		dt->tmp = ft_strjoin("\033[0;", src_clr[i].color_code);
		return (ft_strlen(dt->tmp));
	}
	dt->tmp = ft_strdup("[");
	return (1);
}

void	ft_free_tmp(void **first, void **second)
{
	if (first && *first)
	{
		free(*first);
		*first = NULL;
	}
	if (second && *second)
	{
		free(*second);
		*second = NULL;
	}
}
