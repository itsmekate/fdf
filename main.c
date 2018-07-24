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

void	free_all(t_ptr *fdf)
{
	// int i;

	// i = 0;
	// while (i <= fdf->h)
	// {
	// 	printf("%d\n", i);
	// 	free(fdf->matrix[i]);
	// 	i++;
	// }
	// free_matrix(fdf);
	free(fdf->matrix);
	printf("%d\n", fdf->matrix[0][0]);
	// free(fdf);
}

wchar_t choose_color(void)
{
	wchar_t color[7];
	int r;

	r = rand() % 7;
	color[0] = 0xF56FA1;
	color[1] = 0xA40000;
	color[2] = 0xF64A8A;
	color[3] = 0x9EFD38;
	color[4] = 0x44D7A8;
	color[5] = 0xA9A9A9;
	color[6] = 0x68A0B0;
	return (color[r]);
}

int		deal_key(int key, t_ptr *fdf)
{	
	fdf = (t_ptr*)fdf;
	if (key == 53)
	{
		free_all(fdf);
		system("leaks a.out"); 
		exit(1);
		return (0);
	}
	if (key == 18)
		fdf->rz += 0.1;
	if (key == 19)
		fdf->rx += 0.1;
	if (key == 20)
		fdf->ry += 0.1;
	if (key == 0)
		fdf->right += 40;
	else if (key == 2)
		fdf->right -= 40;
	else if (key == 13)
		fdf->top -= 40;
	else if (key == 1)
		fdf->top += 40;
	else if (key == 24)
		fdf->zoom += 1;
	else if (key == 27)
		fdf->zoom -= 1;
	else if (key == 6)
		fdf->color = choose_color();
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
