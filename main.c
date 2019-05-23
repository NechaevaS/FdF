
#include "fdf.h"
#include <stdio.h>

int			ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	return (0);
}

void		print_row(t_size *map, int **int_arr, int j)
{
	int		i;

	i = 0;
	while (i < map->w)
	{
		ft_putnbr(int_arr[j][i]);
		if (!(i == map->w - 1))
		{
			if (int_arr[j][i + 1] < 10)
				write(1, "  ", 2);
			else
				write(1, " ", 1);
		}
		i++;
	}
	write(1, "\n", 1);
}

void		print_map(t_size *map, int **int_arr)
{
	int		j;

	j = 0;

	while (j < map->h)
	{
		print_row(map, int_arr, j);
		j++;
	}
}


int			main(int argc, char **argv)
{

	t_size	*map;
	int		**res;
	int		fd;
//	void *mlx_ptr;
//	void *mlx_win;
//	char *name = "test_w";

	map = (t_size *)malloc(sizeof(t_size));

	if (argc < 2)
		return (ft_error("Usage: ./fdf [File]"));
	else if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error("Could not open file"));
		else
		res = read_file(map, fd);
	if (!res)
		return (ft_error("Wrong inputs"));
		printf("h %d w %d\n", map->h, map->w);
	{
		print_map(map, res);
	}

	// mlx_ptr = mlx_init();
	// mlx_win = mlx_new_window(mlx_ptr, 512, 512, name);
	// res = read_file(map, fd);
	// create_line(mlx_ptr, mlx_win);
	// mlx_loop(mlx_ptr);
	return (0);
}