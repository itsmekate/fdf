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

t_coord	change(t_coord c, t_ptr fdf, t_coord ctr)
{
	t_coord	c0;
	t_coord	c1;
	t_coord	c2;

	c0.x = c.x;
	c0.y = (c.y - ctr.y) * cos(fdf.rx) - (c.z - ctr.z) * sin(fdf.rx) + ctr.y;
	c0.z = (c.z - ctr.z) * cos(fdf.rx) - (c.y - ctr.y) * sin(fdf.rx) + ctr.z;
	c1.x = (c0.x - ctr.x) * cos(fdf.ry) - (c0.z - ctr.z) * sin(fdf.ry) + ctr.x;
	c1.y = c0.y;
	c1.z = (c0.z - ctr.z) * cos(fdf.ry) + (c0.x - ctr.x) * sin(fdf.ry) + ctr.z;
	c2.x = (c1.x - ctr.x) * cos(fdf.rz) + (c1.y - ctr.y) * sin(fdf.rz) + ctr.x;
	c2.y = (c1.y - ctr.y) * cos(fdf.rz) - (c1.x - ctr.x) * sin(fdf.rz) + ctr.y;
	c2.color = fdf.color;
	return (c2);
}

void	line(t_ptr fdf, t_coord c0, t_coord c1)
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
	put_pixel_image(&fdf, c0.x, c0.y, c0.color);
	while (c0.x != c1.x || c0.y != c1.y)
	{
		put_pixel_image(&fdf, c0.x, c0.y, c0.color);
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

void	make_bars(t_ptr fdf)
{
	int		k;
	int		l;
	void	*wp;
	void	*mp;

	k = 0;
	mp = fdf.mlx_ptr;
	wp = fdf.wdw_ptr;
	while (k++ < 1800)
	{
		l = 1049;
		while (l++ < 1200)
			mlx_pixel_put(fdf.mlx_ptr, fdf.wdw_ptr, k, l, fdf.color);
	}
	mlx_string_put(mp, wp, 10, 1061, 0xFFFFFF, "To zoom use: +/-");
	mlx_string_put(mp, wp, 10, 1081, 0xFFFFFF, "To move use:");
	mlx_string_put(mp, wp, 150, 1081, 0xFFFFFF, "W/S by X");
	mlx_string_put(mp, wp, 150, 1101, 0xFFFFFF, "D/A by Y");
	mlx_string_put(mp, wp, 1550, 1081, 0xFFFFFF, "Use 1 to rotate by X");
	mlx_string_put(mp, wp, 1550, 1101, 0xFFFFFF, "Use 2 to rotate by Y");
	mlx_string_put(mp, wp, 1550, 1121, 0xFFFFFF, "Use 3 to rotate by Z");
	mlx_string_put(mp, wp, 1550, 1141, 0xFFFFFF, "Use Z to change color");
	mlx_string_put(mp, wp, 1190, 1081, 0xFFFFFF, "Use X to increase height");
	mlx_string_put(mp, wp, 1190, 1101, 0xFFFFFF, "Use C to decrease height");
}

void	draw_fdf(t_ptr fdf)
{
	fdf.rx = 8.3;
	fdf.ry = 0.7;
	fdf.rz = -0.4;
	fdf.right = 700;
	fdf.top = 0;
	fdf.zoom = 33;
	fdf.z = 0;
	fdf.color = 0x123456;
	fdf.mlx_ptr = mlx_init();
	fdf.wdw_ptr = mlx_new_window(fdf.mlx_ptr, 1800, 1200, "FdF");
	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, 1800, 1050);
	draw_map(fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.wdw_ptr, fdf.img_ptr, 0, 0);
	make_bars(fdf);
	mlx_hook(fdf.wdw_ptr, 2, 5, deal_key, &fdf);
	mlx_hook(fdf.wdw_ptr, 17, 1L << 17, exit_fdf, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
