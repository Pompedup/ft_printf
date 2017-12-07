/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 01:04:26 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/13 15:30:31 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_cnt_wrd(const char *s, char c, unsigned int *cnt_wrd)
{
	size_t	i;

	i = 0;
	*cnt_wrd = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			(*cnt_wrd)++;
		while (s[i] != c && s[i])
			i++;
	}
}

static size_t	ft_cnt_c(const char *s, char c)
{
	size_t back;

	back = 0;
	while (s[back] != c && s[back])
		back++;
	return (back);
}

char			**ft_strsplit(const char *s, char c)
{
	char			**back;
	unsigned int	cnt_wrd;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	ft_cnt_wrd(s, c, &cnt_wrd);
	if (!(back = (char**)malloc(sizeof(char*) * (cnt_wrd + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < cnt_wrd)
	{
		while (s[j] == c)
			j++;
		if (s[j])
			if (!(back[i] = ft_strsub(s, j, ft_cnt_c(&s[j], c))))
				return (NULL);
		j += ft_cnt_c(&s[j], c);
	}
	back[i] = 0;
	return (back);
}
