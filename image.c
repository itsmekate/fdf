
#include "fdf.h"

void	put_pixel_image(t_ptr *fdf, int x, int y, int color)
{
	int				bpp;
	int				sl;
	int				e;
	char			*res;
	unsigned int	rgb;
	
	res = mlx_get_data_addr(fdf->img_ptr, &bpp, &sl, &e);
	rgb = mlx_get_color_value(fdf->mlx_ptr, color);
	memcpy((void *)(res + y * sl + x * bpp / 8), (void *)&rgb, 4);
	// printf("%d %d\n", bpp, sl);
}