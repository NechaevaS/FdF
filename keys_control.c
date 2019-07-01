/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:10:25 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/01 10:49:30 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define ZOOM_ADD(cam, inc) \
{ \
	(cam)->x_zoom += (inc); \
	(cam)->y_zoom += (inc); \
	(cam)->z_zoom += (inc); \
}

void			control_move_view(t_fdf *fdf, int keycode)
{
	t_matrix	*res;

	if (keycode == 126)
		fdf->cam->y += 10;
	else if (keycode == KEY_ARROW_DOWN)
		fdf->cam->y -= 10;
	else if (keycode == KEY_ARROW_RIGHT)
		fdf->cam->x += 10;
	else if (keycode == KEY_ARROW_LEFT)
		fdf->cam->x -= 10;
	else if (keycode == KEY_MAIN_I)
		fill_camera(fdf);
	else if (keycode == KEY_MAIN_P)
	{
		fdf->cam->x_rot = 90;
		fdf->cam->y_rot = 0;
	}
	else if (keycode == KEY_MAIN_O)
	{
		fdf->cam->x_rot = 45 + 180;
		fdf->cam->y_rot = 0;
	}
	res = create_view(fdf);
	fdf->draw_points = res;
	mlx_clear_window(fdf->mlx, fdf->win);
	print_usage(fdf);
	draw_all(fdf);
}

void			control_zoom(t_fdf *fdf, int keycode)
{
	t_matrix	*res;

	if (keycode == KEY_NUM_PLUS || keycode == KEY_MAIN_PLUS ||
		keycode == MOUSE_SCROLL_UP)
	{
		ZOOM_ADD(fdf->cam, 1)
	}
	else if (keycode == KEY_NUM_MINUS || keycode == KEY_MAIN_MINUS ||
		keycode == MOUSE_SCROLL_DOWN)
	{
		if (fdf->cam->x_zoom >= 1 && fdf->cam->y_zoom >= 1 &&
			fdf->cam->z_zoom >= 1)
			ZOOM_ADD(fdf->cam, -1)
		else
		{
			fdf->cam->x_zoom = 1;
			fdf->cam->y_zoom = 1;
			fdf->cam->z_zoom = 1;
		}
	}
	res = create_view(fdf);
	fdf->draw_points = res;
	mlx_clear_window(fdf->mlx, fdf->win);
	print_usage(fdf);
	draw_all(fdf);
}

void			control_rotate(t_fdf *fdf, int keycode)
{
	t_matrix	*res;

	if (keycode == KEY_NUM_2)
		fdf->cam->x_rot += 1;
	else if (keycode == KEY_NUM_8)
		fdf->cam->x_rot -= 1;
	else if (keycode == KEY_NUM_6)
		fdf->cam->y_rot += 1;
	else if (keycode == KEY_NUM_4)
		fdf->cam->y_rot -= 1;
	res = create_view(fdf);
	fdf->draw_points = res;
	mlx_clear_window(fdf->mlx, fdf->win);
	print_usage(fdf);
	draw_all(fdf);
}

void			control_flat(t_fdf *fdf, int keycode)
{
	t_matrix	*res;

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
	res = create_view(fdf);
	fdf->draw_points = res;
	mlx_clear_window(fdf->mlx, fdf->win);
	print_usage(fdf);
	draw_all(fdf);
}

int				key_controls(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	if (keycode == KEY_ARROW_RIGHT || keycode == KEY_ARROW_LEFT ||
		keycode == KEY_ARROW_UP || keycode == KEY_ARROW_DOWN ||
		keycode == KEY_MAIN_P || keycode == KEY_MAIN_I || keycode == KEY_MAIN_O)
		control_move_view(fdf, keycode);
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
