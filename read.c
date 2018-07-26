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

void	add_to_list_first(char *str, t_list **list)
{
	(*list) = (t_list*)malloc(sizeof(t_list));
	(*list)->content = ft_strdup(str);
	(*list)->next = NULL;
}

void	add_to_list(char *str, t_list **list)
{
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = (t_list*)malloc(sizeof(t_list));
	(*list)->next->content = ft_strdup(str);
	(*list)->next->next = NULL;
}

int		add_line(char *tmp, t_ptr *fdf, int c)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_strsplit(tmp, ' ');
	if (array_size(split) == 0)
		free_and_exit(tmp, split);
	fdf->matrix[c] = (int*)malloc(sizeof(int) * array_size(split));
	while (split[j])
	{
		fdf->matrix[c][j] = ft_atoi(split[j]);
		j++;
	}
	if (fdf->w && j != fdf->w)
		free_and_exit(tmp, split);
	free_split(split);
	return (j);
}

void	read_fdf(char **argv, t_ptr *fdf)
{
	char	*tmp;
	t_list	**list;
	t_list	*head;
	int		fd;

	list = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == 0 || fd == -1)
	{
		ft_putendl("ERROR");
		exit(0);
	}
	list = (t_list**)malloc(sizeof(t_list*));
	if (get_next_line(fd, &tmp) > 0)
	{
		add_to_list_first(tmp, list);
		head = *list;
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
		add_to_list(tmp, list);
		fdf->h++;
		free(tmp);
	}
	fdf->w = 0;
	from_list_to_fdf(fdf, head);
	ft_clear(&head);
	free(list);
	free(head);
}
