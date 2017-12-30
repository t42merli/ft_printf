# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/29 15:49:17 by tmerli            #+#    #+#              #
#    Updated: 2017/12/29 21:37:43 by tmerli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
	  ft_flags.c\
	  ft_put.c\
	  checkformat.c\
	  ft_getlength.c\

HEADER = ft_printf.h\

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : lib $(NAME)

lib :
	make -C libft

$(NAME) : $(SRC) $(HEADER)
	gcc -c $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ) libft/*.o

clean :
	make clean -C libft
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
