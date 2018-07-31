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

wchar_t	choose_color(void)
{
	wchar_t color[8];
	int		r;

	r = rand() % 8;
	color[0] = 0xF56FA1;
	color[1] = 0xA40000;
	color[2] = 0xF64A8A;
	color[3] = 0x9EFD38;
	color[4] = 0x44D7A8;
	color[5] = 0xA9A9A9;
	color[6] = 0x68A0B0;
	color[7] = 0x123456;
	return (color[r]);
}

int		exit_fdf(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		deal_key(int key, t_ptr *fdf)
{
	if (key == 53)
	{
		free_matrix(fdf);
		exit(0);
	}
	clear_map(*fdf);
	(key == 18) ? fdf->rz += 0.1 : 0;
	(key == 19) ? fdf->rx += 0.1 : 0;
	(key == 20) ? fdf->ry += 0.1 : 0;
	(key == 0) ? fdf->right += 40 : 0;
	(key == 2) ? fdf->right -= 40 : 0;
	(key == 13) ? fdf->top -= 40 : 0;
	(key == 1) ? fdf->top += 40 : 0;
	(key == 24) ? fdf->zoom += 1 : 0;
	(key == 27) ? fdf->zoom -= 1 : 0;
	(key == 6) ? fdf->color = choose_color() : 0;
	(key == 7 && fdf->z <= 40) ? fdf->z++ : 0;
	(key == 8 && fdf->z > 0) ? fdf->z-- : 0;
	make_bars(*fdf);
	draw_map(*fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->wdw_ptr, fdf->img_ptr, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_ptr	*fdf;

	if (argc != 2)
		return (0);
	fdf = (t_ptr*)malloc(sizeof(t_ptr));
	read_fdf(argv, fdf);
	draw_fdf(*fdf);
	return (0);
}
