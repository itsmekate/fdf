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

void	free_matrix(t_ptr *fdf)
{
	int i;

	i = 0;
	while (i < fdf->h)
	{
		free(fdf->matrix[i]);
		i++;
	}
	// free(fdf->matrix);
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
	if (array_size(split) == 0)
	{
		ft_putendl("ERROR");
		free_split(split);
		free(tmp);
		exit(0);
	}
	fdf->matrix[c] = (int*)malloc(sizeof(int) * array_size(split));
	while (split[j])
	{
		fdf->matrix[c][j] = ft_atoi(split[j]);
		j++;
	}
	if (fdf->w && j != fdf->w)
	{
		printf("%d\n", fdf->w);
		ft_putendl("ERROR");
		free_split(split);
		free(tmp);
		free_matrix(fdf);
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
	if (fd == 0 || fd == -1)
	{
		ft_putendl("ERROR");
		exit(0);
	}
	list = (t_list*)malloc(sizeof(t_list));
	if ((get_next_line(fd, &tmp)))
	{
		list = add_to_list(tmp);
		head = list;
		free(tmp);
	}
	else
	{
		ft_putendl("ERROR");
		free(list);
		free(fdf);
		exit(0);
	}
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
	free(head);
}
