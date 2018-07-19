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

int	main(int argc, char **argv)
{
	t_ptr	*fdf;

	if (argc != 2)
		return (0);
	fdf = (t_ptr*)malloc(sizeof(t_ptr));
	*fdf = read_fdf(argv, *fdf);
	draw_fdf(*fdf);
	return (0);
}
