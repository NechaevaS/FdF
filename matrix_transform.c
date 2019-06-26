#include "fdf.h"

void			m_scale(t_matrix *t, double x, double y, double z)
{
	t_matrix	*scale;

	scale = init_matrix(4,4);
	uni_matrix(scale);
	ELEM(scale, 0, 0) = x;
	ELEM(scale, 1, 1) = y;
	ELEM(scale, 2, 2) = z;
	ELEM(scale, 3, 3) = 1;
	mtrx_mltpl_acc(t, scale);
	free(scale);
}

void			m_rotate_z(t_matrix *t, double a)
{
	t_matrix	*rotate;
	double		s;
	double		c;

	s = sin(M_PI * a / 180);
	c = cos(M_PI * a / 180);
	rotate = init_matrix(4,4);
	uni_matrix(rotate);
	ELEM(rotate, 0, 0) = c;
	ELEM(rotate, 1, 1) = c;
	ELEM(rotate, 0, 1) = s;
	ELEM(rotate, 1, 0) = -s;
	mtrx_mltpl_acc(t, rotate);
	free(rotate);
}
void			m_rotate_y(t_matrix *t, double a)
{
	t_matrix	*rotate;
	double		s;
	double		c;

	s = sin(M_PI * a / 180);
	c = cos(M_PI * a / 180);
	rotate = init_matrix(4,4);
	uni_matrix(rotate);
	ELEM(rotate, 0, 0) = c;
	ELEM(rotate, 0, 2) = -s;
	ELEM(rotate, 2, 0) = s;
	ELEM(rotate, 2, 2) = c;
	mtrx_mltpl_acc(t, rotate);
	free(rotate);
}

void		m_rotate_x(t_matrix *t, double a)
{
	t_matrix	*rotate;
	double		s;
	double		c;

	s = sin(M_PI * a / 180);
	c = cos(M_PI * a / 180);
	rotate = init_matrix(4,4);
	uni_matrix(rotate);
	ELEM(rotate, 1, 1) = c;
	ELEM(rotate, 1, 2) = s;
	ELEM(rotate, 2, 1) = -s;
	ELEM(rotate, 2, 2) = c;
	mtrx_mltpl_acc(t, rotate);
	free(rotate);
}
void			m_move(t_matrix *t, double dx, double dy, double dz)
{
	t_matrix	*move;

	move = init_matrix(4,4);
	uni_matrix(move);
	ELEM(move, 3, 0) = dx;
	ELEM(move, 3, 1) = dy;
	ELEM(move, 3, 2) = dz;
	mtrx_mltpl_acc(t, move);
	free(move);
}