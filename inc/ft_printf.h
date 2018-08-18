/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:38:37 by abezanni          #+#    #+#             */
/*   Updated: 2018/08/16 18:57:22 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/inc/libft.h"

# define CONV		"sSpbdDioOuUxXcC%"
# define FLAG		".+ -0#hljz"
# define DOT		1
# define PLUS		2
# define SPACE		4
# define MINUS		8
# define ZERO		16
# define HASH		32
# define FT_PRINTF	0
# define FT_SPRINTF	1
# define FT_FPRINTF	2

typedef struct	s_printf
{
	char		buf[5000];
	char		*format;
	char		*buf_move;
	int			to_print;
	int			back;
	char		option;
	va_list		ap;
}				t_printf;

typedef struct	s_basic
{
	char*		str;
	int			(*fct)(t_printf *dt, char c);
}				t_basic;

typedef struct	s_conv
{
	char*		str;
	int			(*fct)(t_printf *dt, char c, unsigned char conv);
}				t_conv;

typedef struct	s_color
{
	char		*color;
	char		*color_code;
}				t_color;

typedef struct	s_flags
{
	unsigned char	convert;
	unsigned char	forme;
	int				space;
	int				precision;
}				t_flags;

typedef struct	s_applyflags
{
	char*		str;
	char*		(*fct)(char *str, int size, t_flags data, char c);
}				t_applyflags;

/*
********************************************************************************
**                                                                            **
**   ft_color.c                                                       bonus   **
**                                                                            **
********************************************************************************
*/

int				color(t_printf *dt);
int				color_back(t_printf *dt);

/*
********************************************************************************
**                                                                            **
**   c_uc_s_us.c                                                      flags   **
**                                                                            **
********************************************************************************
*/

int				flags_char(char *str, int size, t_flags data, char c);
int				flags_string(char *str, int size, t_flags data, char c);

/*
********************************************************************************
**                                                                            **
**   i_d_ud_u_uu.c                                                    flags   **
**                                                                            **
********************************************************************************
*/

int				flags_decimal(char *str, int size, t_flags data, char c);
int				flags_unsigned(char *str, int size, t_flags data, char c);

/*
********************************************************************************
**                                                                            **
**   mutual_change.c                                                  flags   **
**                                                                            **
********************************************************************************
*/

int				negative_number(char *begin, char *end, int size_begin);
int				precision(char *str, int size, t_flags data);
int				space(char *str, int size, t_flags data);

/*
********************************************************************************
**                                                                            **
**   o_uo.c                                                           flags   **
**                                                                            **
********************************************************************************
*/

int				flags_octal(char *str, int size, t_flags data, char c);

/*
********************************************************************************
**                                                                            **
**   p_x_ux.c                                                         flags   **
**                                                                            **
********************************************************************************
*/

int				flags_address(char *str, int size, t_flags data, char c);
int				flags_hexa(char *str, int size, t_flags data, char c);

/*
********************************************************************************
**                                                                            **
**   present_flags.c                                                  flags   **
**                                                                            **
********************************************************************************
*/

int				present_flag(t_printf *dt);

/*
********************************************************************************
**                                                                            **
**   b_percent.c                                                   get_data   **
**                                                                            **
********************************************************************************
*/

int				type_b(t_printf *dt, char c);
int				type_percent(t_printf *dt, char c);

/*
********************************************************************************
**                                                                            **
**   c_uc.c                                                        get_data   **
**                                                                            **
********************************************************************************
*/

int				wctoa(char *str, wchar_t c);
int				type_uc(t_printf *dt, char c);
int				type_c(t_printf *dt, char c);

/*
********************************************************************************
**                                                                            **
**   convert.c                                                     get_data   **
**                                                                            **
********************************************************************************
*/

int				conv_i_d(t_printf *dt, char c, unsigned char conv);
int				conv_b_o_u_x_ux(t_printf *dt, char c, unsigned char conv);
int				conv_c_uc(t_printf *dt, char c, unsigned char conv);
int				conv_s_us(t_printf *dt, char c, unsigned char conv);

/*
********************************************************************************
**                                                                            **
**   i_d_ud_o_uo_u_uu_x_ux.c                                       get_data   **
**                                                                            **
********************************************************************************
*/

int				type_i_d(t_printf *dt, char c);
int				type_ud(t_printf *dt, char c);
int				type_u(t_printf *dt, char c);
int				type_uu_uo(t_printf *dt, char c);
int				type_o_x_ux(t_printf *dt, char c);

/*
********************************************************************************
**                                                                            **
**   p.c                                                           get_data   **
**                                                                            **
********************************************************************************
*/

int				type_p(t_printf *dt, char c);

/*
********************************************************************************
**                                                                            **
**   s_us.c                                                        get_data   **
**                                                                            **
********************************************************************************
*/

int				type_s(t_printf *dt, char c);
int				type_us(t_printf *dt, char c);

/*
********************************************************************************
**                                                                            **
**   value_flag.c                                                  get_data   **
**                                                                            **
********************************************************************************
*/

int				value_flag(t_printf *dt);
int				value_flag_conv(t_printf *dt, t_flags data);

/*
********************************************************************************
**                                                                            **
**   get_lst.c                                                      get_lst   **
**                                                                            **
********************************************************************************
*/

void			get_lst(t_printf *dt);
void			concatenate(t_printf *dt, t_list *lst);
void			ft_init(t_printf *dt, char *str, char option);

/*
********************************************************************************
**                                                                            **
**   ft_printf.c                                                    get_lst   **
**                                                                            **
********************************************************************************
*/

int				ft_printf(char *str, ...);
int				ft_fprintf(int fd, char *format, ...);
int				ft_sprintf(char **str, char *format, ...);

#endif
