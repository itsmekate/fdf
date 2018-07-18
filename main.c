#include "fdf.h"

void	add_line(char *tmp, t_fdf **f)
{
	while (*f)
		(*f) = (*f)->next;
	*f = (t_fdf*)malloc(sizeof(t_fdf));
	(*f)->str = ft_strdup(tmp);
	(*f)->next = NULL;
}

void	read_fdf(char **argv, t_fdf *f)
{
	char	*tmp;
	int fd;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		add_line(tmp, &f);
		// printf("%s\n", tmp);
		free(tmp);
	}
}

// void	draw_fdf(void)
// {
// 	void	*mlx_ptr;
// 	void	*wdw_ptr;

// 	mlx_ptr = mlx_init();
// 	wdw_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx new");
// 	mlx_loop(mlx_ptr);
// }

int	main(int argc, char **argv)
{
	t_fdf	*f;

	if (argc != 2)
		return (0);
	read_fdf(argv, f);
	// draw_fdf();
	return (0);
}
