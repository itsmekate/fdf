/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:02:53 by kprasol           #+#    #+#             */
/*   Updated: 2018/07/23 18:02:55 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		add_line(char *tmp, t_ptr *fdf, int c)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_strsplit(tmp, ' ');
	fdf->matrix[c] = (int*)malloc(sizeof(int) * array_size(split));
	while (split[j])
	{
		fdf->matrix[c][j] = ft_atoi(split[j]);
		j++;
	}
	if (fdf->w && j != fdf->w)
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
	int		c;

	tmp = list;
	fdf->w = 0;
	c = 0;
	fdf->matrix = (int**)malloc(sizeof(int*) * fdf->h);
	while (c != fdf->h)
	{
		fdf->w = add_line((char*)tmp->content, fdf, c);
		c++;
		tmp = tmp->next;
	}
}

void	read_fdf(char **argv, t_ptr *fdf)
{
	char	*tmp;
	t_list	*list;
	t_list	*head;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	list = (t_list*)malloc(sizeof(t_list));
	get_next_line(fd, &tmp);
	list = add_to_list(tmp);
	head = list;
	free(tmp);
	fdf->h = 1;
	while (get_next_line(fd, &tmp) > 0)
	{
		list->next = add_to_list(tmp);
		list = list->next;
		fdf->h++;
		free(tmp);
	}
	fdf->w = 0;
	from_list_to_fdf(fdf, head);
	ft_list_clear(&head);
}
