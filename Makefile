# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snechaev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 14:47:44 by snechaev          #+#    #+#              #
#    Updated: 2019/05/07 14:52:30 by snechaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
OBJS = main.o\
		libft/libft.a\

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) lib
	gcc -o $(NAME) $(OBJS)

$(OBJS) : fdf.h

lib:
	@make -C libft

clean :
	rm -f $(OBJS)
	@make -C libft/ clean

fclean : clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

