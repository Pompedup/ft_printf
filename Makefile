# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 18:57:57 by abezanni          #+#    #+#              #
#    Updated: 2018/08/14 18:59:28 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.c=.o)

CC = @gcc

SRC_NAME =	ft_annexes.c\
			ft_annexes2.c\
			ft_annexes3.c\
			ft_annexes4.c\
			ft_annexes5.c\
			ft_color.c\
			ft_present_flag.c\
			ft_printf.c\
			ft_value_flag.c\
			c.c\
			d.c\
			o.c\
			p.c\
			s.c\
			u.c\
			x.c\
			fonctions_communes.c\

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
