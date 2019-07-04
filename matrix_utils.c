/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:36:49 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/03 16:47:43 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix		*init_matrix(int row, int col)
{
	t_matrix	*mtrx;
	double		size;

	mtrx = (t_matrix *)malloc(sizeof(t_matrix));
	mtrx->n_col = col;
	mtrx->n_row = row;
	size = sizeof(double) * (mtrx->n_col * mtrx->n_row);
	mtrx->data = (double *)malloc(size);
	mtrx->data = ft_memset(mtrx->data, 0, size);
	return (mtrx);
}

void			free_matrix(t_matrix *m)
{
	free(m->data);
	free(m);
}

t_matrix		*mtrx_mltpl(t_matrix *a, t_matrix *b)
{
	t_matrix	*res;
	t_help		h;
	double		t;

	res = init_matrix(a->n_row, b->n_col);
	h.j = 0;
	while (h.j < a->n_row)
	{
		h.i = 0;
		while (h.i < b->n_col)
		{
			t = 0;
			h.k = 0;
			while (h.k < b->n_row)
			{
				t = t + ELEM(a, h.j, h.k) * ELEM(b, h.k, h.i);
				h.k++;
			}
			ELEM(res, h.j, h.i) = t;
			h.i++;
		}
		h.j++;
	}
	return (res);
}

void			mtrx_mltpl_acc(t_matrix *a, t_matrix *b)
{
	t_matrix	*tmp;

	tmp = mtrx_mltpl(a, b);
	free(a->data);
	a->data = tmp->data;
	a->n_col = tmp->n_col;
	a->n_row = tmp->n_row;
	free(tmp);
}

