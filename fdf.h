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
	wchar_t			color;
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
void				free_matrix(t_ptr *fdf);
void				free_split(char **split);
int					array_size(char **arr);
int					add_line(char *tmp, t_ptr *fdf, int c);
void				ft_clear(t_list **list);
void				clear_map(t_ptr fdf);
void				free_and_exit(char *tmp, char **split);
int					deal_key(int key, t_ptr *fdf);
void				draw_map(t_ptr fdf);
void				put_pixel_image(t_ptr *fdf, int x, int y, int color);
t_coord				change(t_coord c, t_ptr fdf, t_coord center);
void				line(t_ptr fdf, t_coord c0, t_coord c1);
void				make_bars(t_ptr fdf);
t_coord				set_c0_1(t_ptr fdf, int i, int j, t_coord c0);
t_coord				set_c1_1(t_ptr fdf, int i, int j, t_coord c1);
t_coord				set_c0_2(t_ptr fdf, int i, int j, t_coord c0);
t_coord				set_c1_2(t_ptr fdf, int i, int j, t_coord c1);

#endif
