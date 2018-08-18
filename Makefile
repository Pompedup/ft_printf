# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 18:57:57 by abezanni          #+#    #+#              #
#    Updated: 2018/08/18 18:18:30 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	ft_printf.c\
			get_flags.c\
			get_strings.c\
			process_format.c\
			bordel.c\
			#$(addprefix bonus/,$(BONUS))\
			$(addprefix get_data/,$(GET_DATA))\
			$(addprefix get_lst/,$(GET_LST))\
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
