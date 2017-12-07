# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 18:57:57 by abezanni          #+#    #+#              #
#    Updated: 2017/12/03 18:58:18 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

LIB = -L ./libft/ -lft

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^

$(OBJ) : $(SRC)
	gcc $(FLAG) -c $< -I.

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean	all
