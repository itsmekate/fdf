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

typedef	struct		s_ptr
{
	void			*mlx_ptr;
	void			*wdw_ptr;
	int				**matrix;
	int				size;
	double			Rx;
	double			Ry;
	double			Rz;
}					t_ptr;

typedef	struct		s_coord
{
	int				x;
	int				y;
	int				z;
	wchar_t			color;
}					t_coord;

// typedef struct 		s_lst
// {
// 	char			*str;
// 	struct s_lst	*next;
// }					t_lst;


void				read_fdf(char **argv, t_ptr *fdf);
void				draw_fdf(t_ptr fdf);
int 				exit_x(void *par);
void				free_matrix(int **matrix);
int					deal_key(int key, t_ptr *fdf);

#endif