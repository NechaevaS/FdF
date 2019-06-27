#include "fdf.h"

void uni_matrix(t_matrix *u)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < u->n_row && i < u->n_col)
	{
		ELEM(u, j, i) = 1;
		i++;
		j++;
	}
}

void    m_iso_project(t_matrix *t)
{
    t_matrix	*project;

	project = init_matrix(4,4);
	uni_matrix(project);
	ELEM(project, 2, 2) = 0;
	mtrx_mltpl_acc(t, project);
	free(project);
}
void    m_persp__project(t_matrix *t)
{
    t_matrix	*project;
	int			r;

	r = 1 / -10;
	project = init_matrix(4,4);
	uni_matrix(project);
	ELEM(project, 0, 0) = 1;
	ELEM(project, 1, 1) = 1;
	ELEM(project, 3, 3) = 1;
	ELEM(project, 2, 3) = r;
	mtrx_mltpl_acc(t, project);
	free(project);
}
t_matrix    *create_view(t_fdf *fdf)
{
    t_matrix    *transform;
    t_matrix    *new_points;

    transform = init_matrix(4, 4);
    uni_matrix(transform);
	m_scale(transform, fdf->cam->x_zoom, fdf->cam->y_zoom, fdf->cam->z_zoom);
    m_rotate_y(transform, fdf->cam->y_rot);
    m_rotate_x(transform, fdf->cam->x_rot);
	m_move(transform, (fdf->cam->x + (WIN_W / 2) - (fdf->map->w / 2)),
	 (fdf->cam->y + (WIN_H / 2) - (fdf->map->h / 2)), 0);
  //  m_iso_project(transform);
	m_persp__project(transform);
    new_points = mtrx_mltpl(fdf->points, transform);
    free_matrix(transform);
    return (new_points);
}
