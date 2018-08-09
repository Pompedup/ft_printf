/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:38:37 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/08 12:30:30 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/inc/libft.h"

# define CONV "sSpbdDioOuUxXcC%"
# define FLAG ".+ -0#hljz"

typedef struct s_printf	t_printf;

typedef struct	s_ft
{
	char*		str;
	char*		(*fct)(t_printf *dt, char c);
}				t_ft;

typedef struct	s_ft_conv
{
	char*		str;
	char*		(*fct)(t_printf *dt, char c, unsigned char conv);
}				t_ft_conv;

typedef struct	s_color
{
	char		*color;
	char		*color_code;
}				t_color;

struct			s_printf
{
	char		*buf;
	char		*str;
	int			pos_s;
	char		*tmp;
	int			tot;
	t_ft		*ft;
	va_list		ap;
};

typedef struct	s_flags
{
	unsigned char	convert;
	unsigned char	forme;
	int				space;
	int				precision;
}				t_flags;

/*
** ft_annexes.c
*/
char			*ft_adress(t_printf *dt, char c);
char			*ft_wctoa(int val);

/*
** ft_annexes2.c
*/
char			*ft_minid(t_printf *dt, char c);
char			*ft_majdo(t_printf *dt, char c);
char			*ft_minu(t_printf *dt, char c);
char			*ft_maju(t_printf *dt, char c);
char			*ft_minox_majx(t_printf *dt, char c);

/*
** ft_annexes3.c
*/
char			*ft_mins(t_printf *dt, char c);
char			*ft_majs(t_printf *dt, char c);
char			*ft_minc(t_printf *dt, char c);
char			*ft_majc(t_printf *dt, char c);

/*
** ft_annexes4.c
*/
char			*ft_conv_int(t_printf *dt, char c, unsigned char conv);
char			*ft_conv_other(t_printf *dt, char c, unsigned char conv);
char			*ft_conv_c(t_printf *dt, char c, unsigned char conv);
char			*ft_conv_s(t_printf *dt, char c, unsigned char conv);

/*
** ft_annexes5.c
*/
char			*ft_binary(t_printf *dt, char c);
char			*ft_percent(t_printf *dt, char c);

/*
**	ft_color.c
*/
int				ft_color(t_printf *dt);
int				ft_color_back(t_printf *dt);
void			ft_free_tmp(void **first, void **second);

/*
** ft_present_flag.c
*/
int				ft_present_flag(t_printf *dt);

/*
** ft_printf.c
*/
int				ft_printf(char *str, ...);

/*
**	ft_retouche.c
*/
char			*ft_space(t_printf *dt, char *str, char *tmp, int sens);
char			*ft_signe(t_printf *dt, t_flags *data, char *str, int *size);
int				ft_char_null(t_printf *dt, t_flags data, char *str);
char			*ft_data(t_printf *dt, t_flags *data, int *size, char *tmp);
int				ft_nochar(t_printf *dt);

/*
**	ft_retouche2.c
*/
char			*ft_hashtag(t_printf *dt, t_flags *data, char *str, int *size);
char			*ft_add_precision(t_printf *dt, t_flags *data,
					int *size, char *tmp);

/*
** ft_value_flag.c
*/
int				ft_value_flag(t_printf *dt);
int				ft_value_flag_conv(t_printf *dt, t_flags data);

#endif
