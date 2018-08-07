# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 18:57:57 by abezanni          #+#    #+#              #
#    Updated: 2018/08/07 22:02:49 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.c=.o)

CC = @gcc

SRC_NAME =	conv/ft_annexes.c\
			conv/ft_annexes2.c\
			conv/ft_annexes3.c\
			conv/ft_annexes4.c\
			conv/ft_annexes5.c\
			color/ft_color.c\
			flag/ft_present_flag.c\
			ft_printf.c\
			flag/ft_retouche.c\
			flag/ft_retouche2.c\
			flag/ft_value_flag.c\

SRC = $(addprefix src/,$(SRC_NAME))

NAME = libftprintf.a

LIB_PATH = libft

LIB = libft/libft.a

INCLUDE = -I ./includes

CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

all : $(NAME)

$(NAME) : libftcomp $(LIB) $(OBJ)
	@libtool -static -o $@ $(LIB) $(OBJ)
	@echo "\033[1;32mSucced libftprintf.a\033[0m"

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
