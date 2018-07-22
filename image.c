
#include "fdf.h"

void	put_pixel_image(t_ptr *fdf, int x, int y, int color)
{
	int				bpp;
	int				sl;
	int				e;
	// unsigned int	rgb;
	
	fdf->res = (int*)mlx_get_data_addr(fdf->img_ptr, &bpp, &sl, &e);
	fdf->rgb = mlx_get_color_value(fdf->mlx_ptr, color);
	if (x > 0 && x < 1800 && y > 0 && y < 1200)
		fdf->res[y * 1800 + x] = color;
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
