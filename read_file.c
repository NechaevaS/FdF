/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:05:49 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/08 12:38:43 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

t_list			*to_list(t_list *list, char *str, int count)
{
	t_list		*head;
	t_list		*current;
	t_list		*elem;
	int			n;

	n = ft_strlen(str) + 1;
	str[n - 1] = '\0';
	if (count == 0)
	{
		head = ft_lstnew(str, n);
	}
	else
	{
		elem = ft_lstnew(str, n);
		current = list;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = elem;
		head = list;
	}
	return (head);
}

void			count_size_line(t_list *list, t_size *map)
{
	int			i;
	char		*str;

	i = 0;
	map->w = 0;
	str = list->content;
	while (str[i] != '\0')
	{
		if (!ft_iswsps(str[i]))
		{
			while (!ft_iswsps(str[i]) && str[i] != '\0')
			{
				i++;
			}
			map->w++;
			i--;
		}
		i++;
	}
}

void			get_colour(char *str, t_colour *col, int pos)
{
	char		*tmp;

	tmp = str;
	col->point_colour[pos] = (char *)malloc(sizeof(char) * 7);
	if (ft_strchr(tmp, ',') == NULL)
		ft_strcpy(col->point_colour[pos], "FFFFFF");
	else
	{
		while (*str != 'x')
		{
			str++;
		}
		str++;
		ft_strncpy(col->point_colour[pos], str, 7);
	}
}

void			convert_to_matrix(t_fdf *fdf, t_list *list, t_matrix *net)
{
	char		**arr;
	t_help		h;
	t_list		*t;

	h.i = 0;
	h.k = -1;
	while (list && ++h.i)
	{
		arr = ft_strsplit(list->content, ' ');
		free(list->content);
		h.j = -1;
		while (++h.j < fdf->map->w && ++h.k >= 0)
		{
			ELEM(net, h.k, 0) = h.j;
			ELEM(net, h.k, 1) = ft_atoi(arr[h.j]);
			ELEM(net, h.k, 2) = h.i;
			ELEM(net, h.k, 3) = 1;
			get_colour(arr[h.j], fdf->col, h.k);
			free(arr[h.j]);
		}
		t = list->next;
		free(list);
		free(arr);
		list = t;
	}
}

t_matrix		*read_file(t_fdf *fdf, const int fd)
{
	int			i;
	t_list		*list;
	t_matrix	*net;
	char		*line;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		list = to_list(list, line, i);
		ft_strdel(&line);
		i++;
	}
	count_size_line(list, fdf->map);
	net = init_matrix((i * fdf->map->w), 4);
	fdf->map->h = i;
	fdf->col->point_colour = (char **)malloc(sizeof(char *) *
		fdf->map->h * fdf->map->w);
	convert_to_matrix(fdf, list, net);
	return (net);
}
