/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:05:49 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/10 20:18:23 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			while(!is_wsps(str[i]) && str[i] != '\0')
			{
				i++;
			}
		}
		i++;
	}

}
void	**convert_to_int(t_list *res, int **int_arr, int n, t_size map)
{
	int		i;
	int		j;
	int		k;
	char	*tmp[256];
	char	*str;

	j = 0;
	while(res)
	{
		int_arr[j] = (int *)malloc(sizeof(int) * map.w);
		str = res->s;
		k = 0;
		while(*str)
		{
			if (!ft_iswsps(*str))
			{
				i = 0;
				while(!is_wsps(*str) && *str != '\0')
				{
					tmp[i] = *str;
					i++;
					str++;
				}
				tmp[i] = '\0';
				int_arr[j][k] = ft_atoi(**tmp);
				k++;
			}
			str++;
		}
		j++;
		res = res->next;
	}
}

int	**read_file(t_size map )
{
	int		i;
	int		n;
	t_list	*res;
	int		**int_arr;
	char	*line;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		n = ft_strlen(line);
		res = to_list(res, line, n, i);
		ft_strdel(&line);
		i++;
	}
	map.h = i;
	int_arr = (int **)malloc(sizeof(int*) * i);
}