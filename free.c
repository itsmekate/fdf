/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:51:08 by kprasol           #+#    #+#             */
/*   Updated: 2018/07/26 13:51:09 by kprasol          ###   ########.fr       */
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
	free(fdf->matrix);
}

int		array_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_clear(t_list **list)
{
	while (*list)
	{
		free((*list)->content);
		free(*list);
		*list = (*list)->next;
	}
	free(*list);
}

void	free_and_exit(char *tmp, char **split)
{
	ft_putendl("ERROR");
	free_split(split);
	free(tmp);
	system("leaks a.out");
	exit(0);
}
