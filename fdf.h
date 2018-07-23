/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:00:17 by kprasol           #+#    #+#             */
/*   Updated: 2018/07/23 18:00:18 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef	struct		s_ptr
{
	void			*mlx_ptr;
	void			*wdw_ptr;
	void			*img_ptr;
	int				**matrix;
	int				w;
	int				h;
	double			rx;
	double			ry;
	double			rz;
	int				top;
	int				right;
	int				zoom;
	int				*res;
	unsigned int	rgb;
	int				z;
}					t_ptr;

typedef	struct		s_coord
{
	int				x;
	int				y;
	int				z;
	wchar_t			color;
}					t_coord;

void				read_fdf(char **argv, t_ptr *fdf);
void				draw_fdf(t_ptr fdf);
int					exit_x(void *par);
void				free_matrix(int **matrix);
int					deal_key(int key, t_ptr *fdf);
void				draw_map(t_ptr fdf, int z);
void				put_pixel_image(t_ptr *fdf, int x, int y, int color);
t_coord				change_coords(t_coord c, t_ptr fdf);
void				draw_line(t_ptr fdf, t_coord c0, t_coord c1);

#endif
