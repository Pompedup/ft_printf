# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 17:32:49 by abezanni          #+#    #+#              #
#    Updated: 2018/02/26 18:04:32 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_islower.c\
		ft_isprint.c\
		ft_isspace.c\
		ft_isupper.c\
		ft_iterative_power.c\
		ft_itoa.c\
		ft_lltoa_base.c\
		ft_lst_push_back.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstremoveone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memjoin.c\
		ft_memmove.c\
		ft_memset.c\
		ft_nbr_len.c\
		ft_putchar_fd.c\
		ft_putchar.c\
		ft_putendl_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_putstr_fd.c\
		ft_putstr.c\
		ft_str_is_lowercase.c\
		ft_str_is_uppercase.c\
		ft_strcat.c\
		ft_strchar.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strmjoin.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strndup.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_uitoa_base.c\
		ft_ulltoa_base.c\
		get_next_line.c\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = @gcc

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[1;32mSucced libft.a\033[0m"

clean :
	@/bin/rm -f $(OBJ)
	@echo "\033[1;32mSucced clean of '*.o' from libft.a\033[0m"

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;32mSucced clean of libft.a\033[0m"

re : fclean	all
	@echo "\033[1;32mSucced recompilation libft.a\033[0m"
