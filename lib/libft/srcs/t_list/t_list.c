/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:51:40 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 16:00:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*malloc_list(size_t p_push_size)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (result == NULL)
		ft_error("Error\n A t_list can't be malloc");
	*result = create_list(p_push_size);
	return (result);
}

t_list	create_list(size_t p_push_size)
{
	t_list	result;

	result.content = NULL;
	result.size = 0;
	result.push_size = p_push_size;
	result.nb_line = 0;
	result.max_size = 0;
	return (result);
}

void	clear_list(t_list *to_clear, t_list_destroy_funct funct)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (funct != NULL && i < to_clear->nb_line)
	{
		j = 0;
		while (j < to_clear->push_size)
		{
			funct(to_clear->content[i][j]);
			j++;
		}
		i++;
	}
	to_clear->size = 0;
}

void	destroy_list(t_list to_destroy, t_list_destroy_funct funct)
{
	size_t	i;

	i = 0;
	clear_list(&to_destroy, funct);
	while (i < to_destroy.nb_line)
		free(to_destroy.content[i++]);
	free(to_destroy.content);
}

void	free_list(t_list *to_free, t_list_destroy_funct funct)
{
	destroy_list(*to_free, funct);
	free(to_free);
}
