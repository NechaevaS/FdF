/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:10:25 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/01 16:19:26 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			zoom_add(t_fdf *fdf, int inc)
{
	fdf->cam->x_zoom += (inc);
	fdf->cam->y_zoom += (inc);
	fdf->cam->z_zoom += (inc);
}

void			control_move(t_fdf *fdf, int keycode)
{
	if (keycode == 126)
		fdf->cam->y += 10;
	else if (keycode == KEY_ARROW_DOWN)
		fdf->cam->y -= 10;
	else if (keycode == KEY_ARROW_RIGHT)
		fdf->cam->x += 10;
	else if (keycode == KEY_ARROW_LEFT)
		fdf->cam->x -= 10;
	create_view(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_usage(fdf);
	draw_all(fdf);
}

void			control_zoom(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_NUM_PLUS || keycode == KEY_MAIN_PLUS ||
		keycode == MOUSE_SCROLL_UP)
		zoom_add(fdf, 1);
	else if (keycode == KEY_NUM_MINUS || keycode == KEY_MAIN_MINUS ||
		keycode == MOUSE_SCROLL_DOWN)
	{
		if (fdf->cam->x_zoom >= 1 && fdf->cam->y_zoom >= 1 &&
			fdf->cam->z_zoom >= 1)
			zoom_add(fdf, -1);
		else
		{
			fdf->cam->x_zoom = 1;
			fdf->cam->y_zoom = 1;
			fdf->cam->z_zoom = 1;
		}
	}
	create_view(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_usage(fdf);
	draw_all(fdf);
}

void			control_rotate(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_NUM_2)
		fdf->cam->x_rot += 1;
	else if (keycode == KEY_NUM_8)
		fdf->cam->x_rot -= 1;
	else if (keycode == KEY_NUM_6)
		fdf->cam->y_rot += 1;
	else if (keycode == KEY_NUM_4)
		fdf->cam->y_rot -= 1;
	create_view(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_usage(fdf);
	draw_all(fdf);
}

void			control_flat(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_PAGE_UP)
	{
		if (fdf->cam->y_zoom > 50)
			fdf->cam->y_zoom = 50;
		fdf->cam->y_zoom += 0.5;
	}
	else if (keycode == KEY_PAGE_DOWN)
	{
		if (fdf->cam->y_zoom < 0.5)
			fdf->cam->y_zoom = 0.5;
		fdf->cam->y_zoom -= 0.5;
	}
	create_view(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_usage(fdf);
	draw_all(fdf);
}
