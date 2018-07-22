#include "fdf.h"

t_coord	change_coords(t_coord c, t_ptr fdf)
{
	t_coord	c0;
	t_coord	c1;
	t_coord	c2;

	c0.x = c.x;
	c0.y = c.y * cos(fdf.Rx) + c.z * sin(fdf.Rx);
	c0.z = c.z * cos(fdf.Rx) - c.y * sin(fdf.Rx);
	c1.x = c0.x * cos(fdf.Ry) - c0.z * sin(fdf.Ry);
	c1.y = c0.y;
	c1.z = c0.z * cos(fdf.Ry) + c0.x * sin(fdf.Ry);
	c2.x = c1.x * cos(fdf.Rz) + c1.y * sin(fdf.Rz);
	c2.y = c1.y * cos(fdf.Rz) - c1.x * sin(fdf.Rz);
	c2.color = 0xFFFFFF;
	return (c2);
}

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
	put_pixel_image(&fdf, c0.x, c0.y, 0xFFFFFF);
	while (c0.x != c1.x || c0.y != c1.y)
	{
		put_pixel_image(&fdf, c0.x, c0.y, 0xFFFFFF);
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

void	clear_map(t_ptr fdf)
{
	int k = 0;
	int l;
	while (k < 1800)
	{
		l = 0;
		while (l < 1200)
		{
			put_pixel_image(&fdf, k, l, 0);
			l++;
		}
		k++;
	}
}

void	draw_map(t_ptr fdf)
{
	int i;
	int j;
	t_coord c0;
	t_coord c1;

	i = 0;
	clear_map(fdf);
	while (i <= fdf.size - 1)
	{
		j = 0;
		c0.x = i * fdf.zoom + fdf.right;
		c1.x = i * fdf.zoom + fdf.right;
		while (j <= fdf.size - 1)
		{
			c0.y = j * fdf.zoom + fdf.top;
			c1.y = (j * fdf.zoom) + fdf.zoom + fdf.top;
			if (fdf.size - 1 != j)
				draw_line(fdf, change_coords(c0, fdf), change_coords(c1, fdf));
			j++;
		}
		i++;
	}
	i = 0;
	while (i <= fdf.size - 1)
	{
		j = 0;
		c0.y = i * fdf.zoom + fdf.top;
		c1.y = i * fdf.zoom + fdf.top;
		while (j <= fdf.size - 1)
		{
			c0.x = j * fdf.zoom + fdf.right;
			c1.x = (j * fdf.zoom) + fdf.zoom + fdf.right;
			if (fdf.size - 1 != j)
				draw_line(fdf, change_coords(c0, fdf), change_coords(c1, fdf));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.wdw_ptr, fdf.img_ptr, 0, 0);
}

void	draw_fdf(t_ptr fdf)
{
	fdf.Rx = 0;
	fdf.Ry = 0;
	fdf.Rz = 0.1;
	fdf.right = 200;
	fdf.top = 200;
	fdf.zoom = 3;
	fdf.mlx_ptr = mlx_init();
	fdf.wdw_ptr = mlx_new_window(fdf.mlx_ptr, 1800, 1200, "FdF");
	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, 1800, 1200);
	draw_map(fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.wdw_ptr, fdf.img_ptr, 0, 0);
	mlx_key_hook(fdf.wdw_ptr, deal_key, &fdf);
	mlx_loop(fdf.mlx_ptr);
}