#include "fdf.h"

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int		array_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		add_line(char *tmp, t_ptr fdf)
{
	int 	i;
	int 	j;
	char	**split;

	i = 0;
	j = 0;
	split = ft_strsplit(tmp, ' ');
	while (fdf.matrix[i])
		i++;
	fdf.matrix[i] = (int*)malloc(sizeof(int)*array_size(split));
	while (split[j])
	{
		fdf.matrix[i][j] = ft_atoi(split[j]);
		j++;
	}
	if (fdf.size && j != fdf.size)
	{
		ft_putendl("ERROR");
		exit(0);
	}
	free(split);
	return (j);
}

t_ptr	read_fdf(char **argv, t_ptr fdf)
{
	char	*tmp;
	int 	fd;

	fd = open(argv[1], O_RDONLY);
	fdf.size = 0;
	fdf.matrix = (int**)malloc(sizeof(int*));
	while (get_next_line(fd, &tmp))
	{
		fdf.size = add_line(tmp, fdf);
		free(tmp);
	}
	return (fdf);
}