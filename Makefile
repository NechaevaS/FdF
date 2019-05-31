# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 14:47:44 by snechaev          #+#    #+#              #
#    Updated: 2019/05/30 15:42:01 by snechaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c\
       		read_file.c\
			create_line.c

OBJS = main.o\
       		read_file.o\
			create_line.o

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address


all : $(NAME)

$(NAME) : $(OBJS) lib
	gcc $(CFLAGS) -I fdf.h libft/libft.a -L ./minilibx_macos $(MLXFLAGS) $(SRC) -o $(NAME)

$(OBJS) : fdf.h

lib:
	@make -C libft
	@make -C minilibx_macos

clean :
	rm -f $(OBJS)
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean : clean
	rm -f $(NAME)
	@make -C libft/ fclean
	@make -C minilibx_macos/ fclean

re: fclean all
