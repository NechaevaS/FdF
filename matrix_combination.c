/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_combination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:04:31 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/01 10:37:37 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			uni_matrix(t_matrix *u)
{
	int			j;
	int			i;

	j = 0;
	i = 0;
	while (j < u->n_row && i < u->n_col)
	{
		ELEM(u, j, i) = 1;
		i++;
		j++;
	}
}

void			m_iso_project(t_matrix *t)
{
	t_matrix	*project;

	project = init_matrix(4, 4);
	uni_matrix(project);
	ELEM(project, 2, 2) = 0;
	mtrx_mltpl_acc(t, project);
	free(project);
}

t_matrix		*create_view(t_fdf *fdf)
{
	t_matrix	*transform;
	t_matrix	*new_points;

	transform = init_matrix(4, 4);
	uni_matrix(transform);
	m_scale(transform, fdf);
	m_rotate_y(transform, fdf->cam->y_rot);
	m_rotate_x(transform, fdf->cam->x_rot);
	m_move(transform, (fdf->cam->x + (WIN_W / 2) - (fdf->map->w / 2)),
		(fdf->cam->y + (WIN_H / 2) - (fdf->map->h / 2)), 0);
	m_iso_project(transform);
	new_points = mtrx_mltpl(fdf->points, transform);
	free_matrix(transform);
	return (new_points);
}
