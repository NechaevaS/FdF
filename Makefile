# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 14:47:44 by snechaev          #+#    #+#              #
#    Updated: 2019/07/08 11:33:52 by snechaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJS = main.o\
       		read_file.o\
			draw.o\
			matrix_utils.o\
			matrix_transform.o\
			matrix_combination.o\
			colours_utils.o\
			init_structures.o\
			keys_control.o\
			all_controls.o\


MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror -g 
#-fsanitize=address

all : $(NAME)

$(NAME) : $(OBJS) lib
	gcc $(CFLAGS) libft/libft.a -L ./minilibx_macos $(MLXFLAGS) $(OBJS) -o $(NAME)

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

re: fclean all
