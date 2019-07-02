/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:05:05 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/01 15:50:59 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			m_scale(t_matrix *t, t_fdf *fdf)
{
	t_matrix	*scale;

	scale = init_matrix(4, 4);
	uni_matrix(scale);
	ELEM(scale, 0, 0) = fdf->cam->x_zoom;
	ELEM(scale, 1, 1) = fdf->cam->y_zoom;
	ELEM(scale, 2, 2) = fdf->cam->z_zoom;
	ELEM(scale, 3, 3) = 1;
	mtrx_mltpl_acc(t, scale);
	free_matrix(scale);
}

void			m_rotate_z(t_matrix *t, double a)
{
	t_matrix	*rotate;
	double		s;
	double		c;

	s = sin(M_PI * a / 180);
	c = cos(M_PI * a / 180);
	rotate = init_matrix(4, 4);
	uni_matrix(rotate);
	ELEM(rotate, 0, 0) = c;
	ELEM(rotate, 1, 1) = c;
	ELEM(rotate, 0, 1) = s;
	ELEM(rotate, 1, 0) = -s;
	mtrx_mltpl_acc(t, rotate);
	free_matrix(rotate);
}

void			m_rotate_y(t_matrix *t, double a)
{
	t_matrix	*rotate;
	double		s;
	double		c;

	s = sin(M_PI * a / 180);
	c = cos(M_PI * a / 180);
	rotate = init_matrix(4, 4);
	uni_matrix(rotate);
	ELEM(rotate, 0, 0) = c;
	ELEM(rotate, 0, 2) = -s;
	ELEM(rotate, 2, 0) = s;
	ELEM(rotate, 2, 2) = c;
	mtrx_mltpl_acc(t, rotate);
	free_matrix(rotate);
}

void			m_rotate_x(t_matrix *t, double a)
{
	t_matrix	*rotate;
	double		s;
	double		c;

	s = sin(M_PI * a / 180);
	c = cos(M_PI * a / 180);
	rotate = init_matrix(4, 4);
	uni_matrix(rotate);
	ELEM(rotate, 1, 1) = c;
	ELEM(rotate, 1, 2) = s;
	ELEM(rotate, 2, 1) = -s;
	ELEM(rotate, 2, 2) = c;
	mtrx_mltpl_acc(t, rotate);
	free_matrix(rotate);
}

void			m_move(t_matrix *t, double dx, double dy, double dz)
{
	t_matrix	*move;

	move = init_matrix(4, 4);
	uni_matrix(move);
	ELEM(move, 3, 0) = dx;
	ELEM(move, 3, 1) = dy;
	ELEM(move, 3, 2) = dz;
	mtrx_mltpl_acc(t, move);
	free_matrix(move);
}
