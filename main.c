
#include "fdf.h"

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

int	main()
{
	t_size map;
	int **res;

	map.h = 0;
	map.w = 0;
	res = read_file(map);
	print_map(map, res);
	return (0);
}
