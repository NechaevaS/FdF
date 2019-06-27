/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:05:49 by snechaev          #+#    #+#             */
/*   Updated: 2019/06/27 10:33:46 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list		*to_list(t_list *list, char *str, int count)
{
	t_list	*head;
	t_list	*current;
	t_list	*elem;
	int		n;

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

void		count_size_line(t_list *list, t_size *map)
{
	int		i;
	char	*str;

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
	if (ft_strchr(tmp,',') == NULL)
		col->point_colour[pos] = "FFFFFF";
	else
	{
		while(*str != 'x')
		{
			str++;
		}
		str++;
		col->point_colour[pos] = ft_strncpy(col->point_colour[pos], str, 7);
	}
}

void			convert_to_matrix(t_fdf *fdf, t_list *list, t_matrix *net)
{
	char		**arr;
	int			k;
	int			z;
	char		*str;
	int			count;
	t_list		*t;

	z = 0;
	count = 0;
	while (list)
	{
		str = list->content;
		arr = ft_strsplit(str, ' ');
		k = 0;
		while (k < fdf->map->w)
		{
			ELEM(net, count, 0) = k;
			ELEM(net, count, 1) = ft_atoi(arr[k]);
			ELEM(net,count, 2) = z;
			ELEM(net,count, 3) = 1;
			get_colour(arr[k], fdf->col, count);
			k++;
			count++;
		}
		z++;
		t = list->next;
		free(list);
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
	fdf->col->point_colour = (char **)malloc(sizeof(char *) * fdf->map->h * fdf->map->w);
	convert_to_matrix(fdf, list, net);
	return (net);
}
