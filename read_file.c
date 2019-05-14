/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:05:49 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/14 15:07:20 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_list		*to_list(t_list *res,char *str, int n, int count)
{
	t_list	*head;
	t_list	*current;
	t_list	*elem;

	if (count == 0)
	{
		head = ft_lstnew(str, n);
		return (head);
	}
	elem = ft_lstnew(str, n);
	current = res;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = elem;
	head = res;
	return (head);
}

void		count_size_line(t_list *res, t_size map)
{
	int		i;
	char	*str;

	i = 0;
	map.w = 0;
	str = res->content;
	while(str[i] != '\0')
	{
		if (!ft_iswsps(str[i]))
		{
			map.w++;
			while(!ft_iswsps(str[i]) && str[i] != '\0')
			{
				i++;
			}
		}
		i++;
	}

}
void	convert_to_int(t_list *res, int **int_arr, t_size map)
{
	int		i;
	int		j;
	int		k;
	char	tmp[12];
	char	*str;

	j = 0;
	while(res)
	{
		str = res->content;
		k = 0;
		while(*str)
		{
			if (!ft_iswsps(*str))
			{
				count_size_line(res, map);
				int_arr[j] = (int *)malloc(sizeof(int) * map.w);
				i = 0;
				ft_memset(tmp, 0, 12);
				while(!ft_iswsps(*str) && *str != '\0')
				{
					tmp[i] = *str;
					i++;
					str++;
				}
				if (*str == '\0')
					break;
				int_arr[j][k] = ft_atoi(tmp);
				k++;
			}
			str++;
		}
		j++;
		res = res->next;
	}
}

int	**read_file(t_size map, const int fd)
{
	int		i;
	int		n;
	t_list	*res;
	int		**int_arr;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{

		n = ft_strlen(line);
		res = to_list(res, line, n, i);
		ft_strdel(&line);
		i++;
	}
	map.h = i + 1;
	int_arr = (int **)malloc(sizeof(int*) * map.h);
	convert_to_int(res, int_arr, map);
	return (int_arr);
}
