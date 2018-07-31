/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:45:37 by kprasol           #+#    #+#             */
/*   Updated: 2018/07/30 14:45:38 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
