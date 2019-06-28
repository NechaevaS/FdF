/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:40:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/06/27 15:37:27 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_scroll(int keycode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
		key_controls(keycode, fdf);
	return (0);
}

int		close_win(void *param)
{
	(void)param;
	exit(0);
}

void	all_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_controls, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_scroll, fdf);
	mlx_hook(fdf->win, 17, 0, close_win, fdf);
}
