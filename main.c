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

int		deal_key(int key, t_ptr	*fdf)
{
	fdf = (t_ptr*)fdf;
	if (key == 53)
	{
		exit(1);
		return (0);
	}
	if (key == 18)
	{
		fdf->Rz += 0.1;
		
		draw_map(*fdf);
	}
	if (key == 19)
	{
		fdf->Rx += 0.1;
		draw_map(*fdf);
	}
	if (key == 20)
	{
		fdf->Ry += 0.1;
		draw_map(*fdf);
	}
	if (key == 0)
	{
		fdf->right += 10;
		draw_map(*fdf);
	}
	else if (key == 2)
	{
		fdf->right -= 10;
		draw_map(*fdf);
	}
	else if (key == 13)
	{
		fdf->top -= 10;
		draw_map(*fdf);
	}
	else if (key == 1)
	{
		fdf->top += 10;
		draw_map(*fdf);
	}
	else if (key == 24)
	{
		fdf->zoom += 1;
		draw_map(*fdf);
	}
	else if (key == 27)
	{
		fdf->zoom -= 1;
		draw_map(*fdf);
	}
	// mlx_put_image_to_window(fdf->mlx_ptr, fdf->wdw_ptr, fdf->img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ptr	*fdf;

	if (argc != 2)
		return (0);
	fdf = (t_ptr*)malloc(sizeof(t_ptr));
	read_fdf(argv, fdf);
	// system("leaks a.out");
	draw_fdf(*fdf);
	return (0);
}
