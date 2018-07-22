
#include "fdf.h"

void	put_pixel_image(t_ptr *fdf, int x, int y, int color)
{
	int				bpp;
	int				sl;
	int				e;
	// unsigned int	rgb;
	
	fdf->res = (int*)mlx_get_data_addr(fdf->img_ptr, &bpp, &sl, &e);
	fdf->rgb = mlx_get_color_value(fdf->mlx_ptr, color);
	if (x > 0 && x < 1800 && y > 0 && y < 1200)
		fdf->res[y * 1800 + x] = color;
}