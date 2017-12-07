/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:44:48 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/07 16:17:53 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_printf
{
	char		buf[256];
	int			pos_b;
	char		*str;
	int			pos_s;
	int			tot;
	va_list		ap;

}				t_printf;

int				ft_atoif(t_printf *dt);
int				ft_printf(char *str, ...);
char			*ft_apply_percent(t_printf *dt);
void			ft_nbr_percent(t_printf *dt);

#endif
