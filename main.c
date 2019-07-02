/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:54:28 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/01 16:36:08 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	return (0);
}

void			print_usage(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 5, 0xFF0000, "How to use:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 35, 0x00FF00, "Move:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 65, 0xFFFFFF, "Arrows");
	mlx_string_put(fdf->mlx, fdf->win, 10, 95, 0x00FF00, "Rotate:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 125, 0xFFFFFF,
		"up/down - NUM KEYkey 2/8");
	mlx_string_put(fdf->mlx, fdf->win, 10, 155, 0xFFFFFF,
		"right/left - NUM key 2/8");
	mlx_string_put(fdf->mlx, fdf->win, 10, 185, 0x00FF00, "Zoom:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 215, 0xFFFFFF,
		"Scroll or NUM key +/-");
	mlx_string_put(fdf->mlx, fdf->win, 10, 245, 0x00FF00, "Flatten:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 275, 0xFFFFFF,
		"PAGE UP / PAGE DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 10, 305, 0x00FF00, "Projection:");
	mlx_string_put(fdf->mlx, fdf->win, 10, 335, 0xFFFFFF, "isometric  - key I");
	mlx_string_put(fdf->mlx, fdf->win, 10, 365, 0xFFFFFF, "plan		  - key P");
	mlx_string_put(fdf->mlx, fdf->win, 10, 395, 0xFFFFFF, "dimetric	  - key D");
	mlx_string_put(fdf->mlx, fdf->win, 10, 425, 0x00FF00, "For exit");
	mlx_string_put(fdf->mlx, fdf->win, 10, 455, 0xFFFFFF, "ESC");
}

int				helper_main(t_fdf *fdf, t_matrix *m)
{
	char		*name;

	name = "FDF";
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, name);
	if (!m)
		return (ft_error("Wrong inputs"));
	fdf->points = m;
	m_move(m, -(fdf->map->w / 2), 0, -(fdf->map->h / 2));
	create_view(fdf);
	print_usage(fdf);
	draw_all(fdf);
	all_controls(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_fdf		fdf;
	t_matrix	*m;

	fd = 0;
	init_fdf(&fdf);
	fill_camera(&fdf);
	if (argc >= 2 && argc < 4)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_error("Could not open file"));
		if (argc == 3)
		{
			m = read_file(&fdf, fd);
			change_colour(&fdf, argv[2]);
			helper_main(&fdf, m);
		}
		m = read_file(&fdf, fd);
		helper_main(&fdf, m);
	}
	else
		return (ft_error("No input file"));
	free_fdf(&fdf);
	return (0);
}
