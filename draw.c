/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:01:35 by kprasol           #+#    #+#             */
/*   Updated: 2018/07/23 18:01:36 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	change_coords(t_coord c, t_ptr fdf)
{
	t_coord	c0;
	t_coord	c1;
	t_coord	c2;

	c0.x = c.x;
	c0.y = c.y * cos(fdf.rx) + c.z * sin(fdf.rx);
	c0.z = c.z * cos(fdf.rx) - c.y * sin(fdf.rx);
	c1.x = c0.x * cos(fdf.ry) - c0.z * sin(fdf.ry);
	c1.y = c0.y;
	c1.z = c0.z * cos(fdf.ry) + c0.x * sin(fdf.ry);
	c2.x = c1.x * cos(fdf.rz) + c1.y * sin(fdf.rz);
	c2.y = c1.y * cos(fdf.rz) - c1.x * sin(fdf.rz);
	c2.color = 0xFFFFFF;
	return (c2);
}

void	draw_line(t_ptr fdf, t_coord c0, t_coord c1)
{
	t_coord d;
	int		signx;
	int		signy;
	int		error;

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

void	draw_fdf(t_ptr fdf)
{
	fdf.rx = 0.2;
	fdf.ry = 0.3;
	fdf.rz = -0.8;
	fdf.right = 800;
	fdf.top = 200;
	fdf.zoom = 10;
	fdf.z = 0;
	fdf.mlx_ptr = mlx_init();
	fdf.wdw_ptr = mlx_new_window(fdf.mlx_ptr, 1800, 1200, "FdF");
	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, 1800, 1200);
	draw_map(fdf, 0);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.wdw_ptr, fdf.img_ptr, 0, 0);
	mlx_key_hook(fdf.wdw_ptr, deal_key, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
