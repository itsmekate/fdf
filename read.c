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

void	read_fdf_more(t_ptr *fdf, t_list *head, t_list **list, int fd)
{
	char	*tmp;

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

void	free_and_error(t_ptr *fdf, t_list **list)
{
	ft_putendl("ERROR");
	free(list);
	free(fdf);
	exit(0);
}

void	read_fdf(char **argv, t_ptr *fdf)
{
	char	*tmp;
	t_list	**list;
	t_list	*head;
	int		fd;

	list = NULL;
	head = NULL;
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
		free_and_error(fdf, list);
	read_fdf_more(fdf, head, list, fd);
}
