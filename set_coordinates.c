/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:24:26 by kprasol           #+#    #+#             */
/*   Updated: 2018/07/26 16:30:17 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	set_c0_1(t_ptr fdf, int i, int j, t_coord c0)
{
	c0.z = fdf.matrix[i][j];
	c0.x = i * fdf.zoom + fdf.right;
	c0.y = j * fdf.zoom + fdf.top;
	if (c0.z != 0)
		c0.z += fdf.z;
	return (c0);
}

t_coord	set_c1_1(t_ptr fdf, int i, int j, t_coord c1)
{
	if (fdf.w - 1 != j)
		c1.z = fdf.matrix[i][j + 1];
	if (c1.z != 0)
		c1.z += fdf.z;
	c1.x = i * fdf.zoom + fdf.right;
	c1.y = (j * fdf.zoom) + fdf.zoom + fdf.top;
	return (c1);
}

t_coord	set_c0_2(t_ptr fdf, int i, int j, t_coord c0)
{
	c0.z = fdf.matrix[i][j];
	c0.x = i * fdf.zoom + fdf.right;
	c0.y = j * fdf.zoom + fdf.top;
	if (c0.z != 0)
		c0.z += fdf.z;
	return (c0);
}

t_coord	set_c1_2(t_ptr fdf, int i, int j, t_coord c1)
{
	if (fdf.h - 1 != i)
		c1.z = fdf.matrix[i + 1][j];
	c1.x = (i * fdf.zoom) + fdf.zoom + fdf.right;
	c1.y = j * fdf.zoom + fdf.top;
	if (c1.z != 0)
		c1.z += fdf.z;
	return (c1);
}
