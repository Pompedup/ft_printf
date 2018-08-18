# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 18:57:57 by abezanni          #+#    #+#              #
#    Updated: 2018/08/17 16:14:36 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS =		ft_color.c\

FLAGS =		c_uc_s_us.c\
			i_d_ud_u_uu.c\
			mutual_change.c\
			o_uo.c\
			p_x_ux.c\
			present_flags.c\

GET_DATA =	b_percent.c\
			c_uc.c\
			convert.c\
			i_d_ud_o_uo_u_uu_x_ux.c\
			p.c\
			s_us.c\
			value_flag.c\

GET_LST =	get_lst.c\

SRC_NAME =	ft_printf.c\
			$(addprefix get_data/,$(GET_DATA))\
			$(addprefix get_lst/,$(GET_LST))\
			#$(addprefix bonus/,$(BONUS))\
			$(addprefix flags/,$(FLAGS))\

SRC = $(addprefix src/,$(SRC_NAME))

OBJ = $(SRC:.c=.o)

INC = -I ./inc

NAME = libftprintf.a

LIB_PATH = libft

LIB = libft/libft.a

CC = @gcc

CFLAGS = -Wall -Wextra -Werror $(INC)


all : libftcomp $(NAME)

$(NAME) : $(LIB) $(OBJ)
	@libtool -static -o $@ $(LIB) $(OBJ)
	@echo "\033[1;32mSucced libftprintf.a\033[0m"

$(OBJ) : inc/ft_printf.h

libftcomp :
	@make -C $(LIB_PATH)

clean :
	@make clean -C $(LIB_PATH)
	@/bin/rm -f $(OBJ)
	@echo "\033[1;32mSucced clean of '*.o' ftom libftprintf.a\033[0m"

fclean : clean
	@/bin/rm -f $(LIB)
	@echo "\033[1;32mSucced clean of libft.a\033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[1;32mSucced clean libftprintf.a\033[0m"

re : fclean	all
	@echo "\033[1;32mSucced recompilation libftprintf.a\033[0m"
