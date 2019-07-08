/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:40:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/03 18:01:46 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			control_view(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_MAIN_I)
		fill_camera(fdf);
	else if (keycode == KEY_MAIN_P)
	{
		fdf->cam->x_rot = 90;
		fdf->cam->y_rot = 0;
	}
	else if (keycode == KEY_MAIN_D)
	{
		fdf->cam->x_rot = 20.7 + 180;
		fdf->cam->y_rot = 22.2;
	}
	create_view(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_usage(fdf);
	draw_all(fdf);
}

int				key_controls(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
	{
		// int	i = 0;

		// while(i < fdf->map->h * fdf->map->w)
		// {
		// 	free(fdf->col->point_colour[i]);
		// 	i++;
		// }
	//free(fdf->col->point_colour);
	// free(fdf->map);
	// free(fdf->mlx);
	//free(fdf->win);
	//	while(1);
		exit(0);
	}
	if (keycode == KEY_ARROW_RIGHT || keycode == KEY_ARROW_LEFT ||
		keycode == KEY_ARROW_UP || keycode == KEY_ARROW_DOWN)
		control_move(fdf, keycode);
	else if (keycode == KEY_MAIN_P || keycode == KEY_MAIN_I ||
		keycode == KEY_MAIN_D)
		control_view(fdf, keycode);
	else if (keycode == KEY_NUM_PLUS || keycode == KEY_MAIN_PLUS
		|| keycode == MOUSE_SCROLL_UP || keycode == KEY_NUM_MINUS ||
		keycode == KEY_MAIN_MINUS || keycode == MOUSE_SCROLL_DOWN)
		control_zoom(fdf, keycode);
	else if (keycode == KEY_NUM_2 || keycode == KEY_NUM_4 ||
		keycode == KEY_NUM_8 || keycode == KEY_NUM_6)
		control_rotate(fdf, keycode);
	else if (keycode == KEY_PAGE_UP || keycode == KEY_PAGE_DOWN)
		control_flat(fdf, keycode);
	return (0);
}

int				mouse_scroll(int keycode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
		key_controls(keycode, fdf);
	return (0);
}

int				close_win(void *param)
{
	(void)param;
	exit(0);
}

void			all_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_controls, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_scroll, fdf);
	mlx_hook(fdf->win, 17, 0, close_win, fdf);
}
