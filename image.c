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
	if (x > 0 && x < 1800 && y > 0 && y < 1050)
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
		while (l < 1050)
		{
			put_pixel_image(&fdf, k, l, 0);
			l++;
		}
		k++;
	}
}

t_coord	draw_map_more(t_ptr fdf, int i, t_coord center)
{
	int		j;
	t_coord c0;
	t_coord c1;

	j = 0;
	while (j < fdf.w)
	{
		c0 = set_c0_1(fdf, i, j, c0);
		c1 = set_c1_1(fdf, i, j, c1);
		if (fdf.w - 1 != j)
			line(fdf, change(c0, fdf, center), change(c1, fdf, center));
		c0 = set_c0_2(fdf, i, j, c0);
		c1 = set_c1_2(fdf, i, j, c1);
		if (fdf.h - 1 != i)
			line(fdf, change(c0, fdf, center), change(c1, fdf, center));
		j++;
	}
	return (c0);
}

void	draw_map(t_ptr fdf)
{
	int		i;
	t_coord	center;
	t_coord c0;

	i = 0;
	center.x = 0;
	center.y = 0;
	center.z = 0;
	if (fdf.zoom < 0)
		fdf.zoom = 0;
	while (i < fdf.h)
	{
		c0 = draw_map_more(fdf, i, center);
		i++;
	}
	line(fdf, change(c0, fdf, center), change(c0, fdf, center));
	put_pixel_image(&fdf, c0.x, c0.y, c0.color);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.wdw_ptr, fdf.img_ptr, 0, 0);
}
