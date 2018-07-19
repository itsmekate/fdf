/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 12:35:52 by kprasol           #+#    #+#             */
/*   Updated: 2018/07/19 12:35:54 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void  draw_line(t_map m, t_coord c0, t_coord c1)
{
	t_coord d;
	int  signx;
	int  signy;
	int  error;

	d.x = abs(c1.x - c0.x);
	d.y = abs(c1.y - c0.y);
	signx = c0.x < c1.x ? 1 : -1;
	signy = c0.y < c1.y ? 1 : -1;
	error = d.x - d.y;
	mlx_pixel_put(m.mlx, m.mlx_win, c1.x, c1.y, c0.color);
	while (c0.x != c1.x || c0.y != c1.y)
	{
		mlx_pixel_put(m.mlx, m.mlx_win, c0.x, c0.y, c1.color);
		if (error * 2 > -d.y)
		{
			error -= d.y;
			c0.x += signx;
		}
		else
		{
			error += d.x;
			c0.y += signy;
		}
	}
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int		array_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	add_line(char *tmp, int **matrix)
{
	int i;
	int j;
	char	**split;

	i = 0;
	j = 0;
	split = ft_strsplit(tmp, ' ');
	while (matrix[i])
		i++;
	matrix[i] = (int*)malloc(sizeof(int)*array_size(split));
	while (split[j])
	{
		matrix[i][j] = ft_atoi(split[j]);
		// printf("%d ", matrix[i][j]);
		j++;
	}
	free(split);
	// printf("\n");
}

void	read_fdf(char **argv)
{
	char	*tmp;
	int		**matrix;
	int fd;

	fd = open(argv[1], O_RDONLY);
	matrix = (int**)malloc(sizeof(int*));
	while (get_next_line(fd, &tmp))
	{
		add_line(tmp, matrix);
		free(tmp);
	}
}

void	draw_fdf(void)
{
	void	*mlx_ptr;
	void	*wdw_ptr;

	mlx_ptr = mlx_init();
	wdw_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx new");
	mlx_pixel_put(mlx_ptr, wdw_ptr, 150, 150, 0xFFFFFFF);
	mlx_loop(mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	read_fdf(argv);
	draw_fdf();
	return (0);
}
