/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:23:09 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/10 20:24:36 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct
{
	int				w;
	int				h;
	int				z;
}					t_size;

t_list		*to_list(t_list *res,char *str, int n, int count);
void		count_size_line(t_list *res, t_size map);
void	convert_to_int(t_list *res, int **int_arr, t_size map);
int	**read_file(t_size map );
void	print_map(t_size map, int **int_arr);

#endif