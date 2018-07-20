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
	if (key == 12)
	{
		fdf->Rz = 0.3;
	}
	return (0);
}

// int exit_x(void *par)
// {
// 	par = NULL;
// 	exit(1);
// 	return (0);
	// if (n == )
	// {
	// 	exit(1);
	// 	return (0);
	// }
	// else if (n == )
	// {
	// 	/* code */
	// }
	
// }

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
