
#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>


int		ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	return (0);
}


void	print_map(t_size map, int **int_arr)
{

	int	i;
	int	j;

	j = 0;
	while (j < map.h)
	{
		i = 0;
		while(i < map.w)
		{
			ft_putnbr(int_arr[j][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int	main(int argc, char **argv)
{

	t_size		map;
	int			**res;
	int			fd;

	map.h = 0;
	map.w = 0;
	if (argc < 2)
		return (ft_error("Usage: ./fdf [File]"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error("Could not open file"));
	if (!read_file(map, fd))
		return (ft_error("Wrong inputs"));
	else
	{
		res = read_file(map, fd);
		printf("h %d w %d\n", map.h, map.w);
		print_map(map, res);
	}
	return (0);
}
