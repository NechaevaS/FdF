# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 14:47:44 by snechaev          #+#    #+#              #
#    Updated: 2019/05/10 20:25:23 by snechaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
OBJS = main.o\
		libft/libft.a\
		minilibx_macos/libmlx.a\

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) lib
	gcc -o $(NAME) $(OBJS)

$(OBJS) : fdf.h

lib:
	@make -C libft
	@make -C libmlx

clean :
	rm -f $(OBJS)
	@make -C libft/ clean
	@make -C libmlx/ clean

fclean : clean
	rm -f $(NAME)
	@make -C libft/ fclean
	@make -C libmlx/ fclean

re: fclean all
