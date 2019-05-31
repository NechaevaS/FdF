/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:57:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/30 17:12:33 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**to_coord(int **arr, t_size *map)
{
	t_point	**net;
	int		i;
	int		j;

	j = 0;
	net = (t_point **)malloc(sizeof(t_point) * map->h);
	while (j < map->h)
	{
		net[j] = (t_point *)malloc(sizeof(t_point) * map->w);
		i = 0;
		while (i < map->w)
		{
			net[j][i].posx = i;
			net[j][i].posy = j;
			net[j][i].z = arr[i][j];
			net[j][i].x = i * SCALE + OFFSET;
			net[j][i].y = j * SCALE + OFFSET;
			i++;
		}
		j++;
	}
	return (net);
}

void	create_lines(void *mlx_ptr, void *mlx_win, t_point **net, t_size *map)
{
	int	i;
	int	j;
	int k;
	int	n;

	j = 0;
	int	color = 0xFFFFFF;

	while (j < map->h)
	{
		i = 0;
		while (i < map->w)
		{
			k = net[j][i].x;
			n = net[j][i].y;
			if (i != map->w - 1)
			{
				while (k < net[j][i + 1].x)
				{
					mlx_pixel_put(mlx_ptr, mlx_win, k, n, color);
					k++;
				}
			}
			k = net[j][i].x;
			if (j != map->h - 1)
			{
				while (n < net[j+1][i].y)
				{
					mlx_pixel_put(mlx_ptr, mlx_win, k, n, color);
					n++;
				}
			}
			i++;

		}
		j++;
	}
}
