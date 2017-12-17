/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:38:37 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/16 18:32:27 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_printf
{
	char		*buf;
	char		*str;
	int			pos_s;
	int			tot;
	va_list		ap;

}				t_printf;

int				ft_atoif(t_printf *dt);
int				ft_printf(char *str, ...);
char			*ft_apply_percent(t_printf *dt);
void			ft_nbr_percent(t_printf *dt);

void	ft_go_print(char *str);
char	*ft_value_flag(t_printf *dt, unsigned char conv);
char	*ft_present_flag(t_printf *dt);
char	*ft_value_sspddioo(t_printf *dt, int type);
char	*ft_value_uuxxcc(t_printf *dt, int type, unsigned char conv);

char	*ft_verif_char(t_printf *dt);
char	*ft_ctoa(int c);
char	*ft_ptoa(long long n);
char	*ft_check_flag(t_printf *dt, int type, char *cmp);
char	*ft_lltoa_base(long long value, int base, int maj);
char	*ft_ulltoa_base(unsigned long long value, int base, int maj);




#endif
