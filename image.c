/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:04:04 by kprasol           #+#    #+#             */
/*   Updated: 2018/07/23 18:04:10 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_image(t_ptr *fdf, int x, int y, int color)
{
	int	bpp;
	int	sl;
	int	e;

	fdf->res = (int*)mlx_get_data_addr(fdf->img_ptr, &bpp, &sl, &e);
	fdf->rgb = mlx_get_color_value(fdf->mlx_ptr, color);
	if (x > 0 && x < 1800 && y > 0 && y < 1200)
		fdf->res[y * 1800 + x] = color;
}

void	clear_map(t_ptr fdf)
{
	int k;
	int l;

	k = 0;
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

void	draw_map(t_ptr fdf, int z)
{
	int		i;
	int		j;
	t_coord c0;
	t_coord c1;

	i = 0;
	clear_map(fdf);
	while (i < fdf.h - 1)
	{
		j = 0;
		printf("%d %d\n", i, j);
		while (j < fdf.w - 1)
		{
			c0.z = fdf.matrix[i][j];
			if (fdf.matrix[i][j + 1] != 0)
				c1.z = fdf.matrix[i][j + 1] + z;
			else
				c1.z = fdf.matrix[i][j + 1];
			c0.x = i * fdf.zoom + fdf.right;
			c1.x = i * fdf.zoom + fdf.right;
			c0.y = j * fdf.zoom + fdf.top;
			c1.y = (j * fdf.zoom) + fdf.zoom + fdf.top;
			if (fdf.w - 1 != j)
				draw_line(fdf, change_coords(c0, fdf), change_coords(c1, fdf));
			c0.z = fdf.matrix[i][j];
			if (fdf.h - 1 != i && fdf.matrix[i + 1][j] != 0)
				c1.z = fdf.matrix[i + 1][j] + z;
			else
				c1.z = fdf.matrix[i + 1][j];
			c0.x = i * fdf.zoom + fdf.right;
			c1.x = (i * fdf.zoom) + fdf.zoom + fdf.right;
			c0.y = j * fdf.zoom + fdf.top;
			c1.y = j * fdf.zoom + fdf.top;
			if (fdf.h - 1 != i)
				draw_line(fdf, change_coords(c0, fdf), change_coords(c1, fdf));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.wdw_ptr, fdf.img_ptr, 0, 0);
}
