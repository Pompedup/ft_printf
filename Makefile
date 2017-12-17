# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 18:57:57 by abezanni          #+#    #+#              #
#    Updated: 2017/12/16 13:53:45 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c\
		ft_value_flag.c\
		ft_present_flag.c\
		ft_annexes.c\
		ft_annexes2.c\
		ft_annexes3.c\

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

LIB = -L ./libft/ -lft

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft/
	ar rc $@ $^ ./libft/*.o

$(OBJ) : $(SRC)
	gcc $(FLAG) -c $(SRC) -I.

clean :
	make clean -C ./libft/
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f libft/libft.a
	/bin/rm -f $(NAME)

re : fclean	all
