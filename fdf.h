#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

// typedef	struct	s_coord
// {
// 	int				height;
// 	char			*color;
// 	struct	s_coord	*next;
// }					t_coord;

// typedef	struct		s_fdf
// {
// 	// struct	s_coord	c;
// 	char	*str;
// 	struct	s_fdf	*next;

// }					t_fdf;

typedef	struct	s_ptr
{
	void	*mlx_ptr;
	void	*wdw_ptr;
	int		**matrix;
}				t_ptr;

typedef	struct	s_coord
{
	int			x;
	int			y;
	int			z;
}				t_coord;

#endif