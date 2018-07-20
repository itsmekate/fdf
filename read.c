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

void	free_matrix(int **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int		array_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_list	*add_to_list(char *str)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	tmp->content = ft_strdup(str);
	tmp->next = NULL;
	return (tmp);
}

int		add_line(char *tmp, t_ptr *fdf)
{
	int 	i;
	int 	j;
	char	**split;

	i = 0;
	j = 0;
	split = ft_strsplit(tmp, ' ');
	while (fdf->matrix[i])
		i++;
	fdf->matrix[i] = (int*)malloc(sizeof(int)*array_size(split));
	while (split[j])
	{
		fdf->matrix[i][j] = ft_atoi(split[j]);
		j++;
	}
	if (fdf->size && j != fdf->size)
	{
		ft_putendl("ERROR");
		free_split(split);
		free(tmp);
		free_matrix(fdf->matrix);
		exit(0);
	}
	free_split(split);
	return (j);
}

void	from_list_to_fdf(t_ptr *fdf, t_list *list)
{
	t_list	*tmp;

	tmp = list;
	fdf->size = 0;
	fdf->matrix = (int**)malloc(sizeof(int*)* ft_list_size(tmp));
	while (tmp)
	{
		fdf->size = add_line((char*)tmp->content, fdf);
		tmp = tmp->next;
	}
}

void	read_fdf(char **argv, t_ptr *fdf)
{
	char	*tmp;
	t_list	*list;
	t_list	*head;
	int 	fd;

	fd = open(argv[1], O_RDONLY);
	list = (t_list*)malloc(sizeof(t_list));
	
	get_next_line(fd, &tmp);
	list = add_to_list(tmp);
	head = list;
	free(tmp);
	while (get_next_line(fd, &tmp))
	{
		list->next = add_to_list(tmp);
		list = list->next;
		free(tmp);
	}
	fdf->size = 0;
	from_list_to_fdf(fdf, head);
	// ft_list_clear(head);
}