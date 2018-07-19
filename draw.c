#include "fdf.h"

void  draw_line(t_ptr fdf, t_coord c0, t_coord c1)
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
	mlx_pixel_put(fdf.mlx_ptr, fdf.wdw_ptr, c1.x, c1.y, c0.color);
	while (c0.x != c1.x || c0.y != c1.y)
	{
		mlx_pixel_put(fdf.mlx_ptr, fdf.wdw_ptr, c0.x, c0.y, c1.color);
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

void	draw_fdf(t_ptr fdf)
{
	int i = 0;
	int j = 0;
	t_coord c0;
	t_coord c1;

	c0.color = 0xFFF000;
	c1.color = 0xFFFFFFF;
	fdf.mlx_ptr = mlx_init();
	fdf.wdw_ptr = mlx_new_window(fdf.mlx_ptr, 800, 600, "FdF");
	printf("%d\n", fdf.size);
	while (i < fdf.size - 1)
	{
		j = 0;
		c0.x = i * 50;
		c1.x = i * 50;
		while (j < fdf.size - 1)
		{
			c0.y = j * 50;
			c1.y = (j * 50) + 50;
			draw_line(fdf, c0, c1);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < fdf.size - 1)
	{
		j = 0;
		c0.y = i * 50;
		c1.y = i * 50;
		while (j < fdf.size - 1)
		{
			c0.x = j * 50;
			c1.x = (j * 50) + 50;
			draw_line(fdf, c0, c1);
			j++;
		}
		i++;
	}
	// c0.x = 10;
	// c1.x = 100;
	// c0.y = 50;
	// c1.y = 250;
	// c0.color = 0xFFFFFFF;
	// c1.color = 0xFFFFFFF;
	// draw_line(fdf, c0, c1);
	mlx_loop(fdf.mlx_ptr);
}