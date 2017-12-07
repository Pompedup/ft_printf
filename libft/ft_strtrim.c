/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:10:52 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/17 15:34:57 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*back;
	size_t	i;
	size_t	end;
	size_t	bgn;

	bgn = 0;
	if (!s)
		return (NULL);
	while (s[bgn] == ' ' || s[bgn] == '\n' || s[bgn] == '\t')
		bgn++;
	end = ft_strlen(s);
	while ((s[end] == ' ' || s[end] == '\n' ||
	s[end] == '\t' || s[end] == '\0') && end)
		end--;
	if (s[bgn] == '\0')
		return (ft_strdup(""));
	else if (bgn <= end)
		if (!(back = (char*)malloc(end - bgn + 2)))
			return (NULL);
	i = 0;
	while (bgn <= end)
		back[i++] = s[bgn++];
	back[i] = 0;
	return (back);
}
