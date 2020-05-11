/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_list_creators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 10:52:33 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/09 11:43:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_vector2		**t_vector2tab_new(size_t nb)
{
	t_vector2	**tab;
	size_t		i;

	tab = (t_vector2 **)malloc(sizeof(t_vector2 *) * (nb + 1));
	if (tab == NULL)
		ggl_error("Allocation failed in t_vector2tab_new");
	i = 0;
	while (i <= nb)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

t_vector2		*t_vector2array_new(size_t nb)
{
	t_vector2 *array;

	array = (t_vector2 *)malloc(sizeof(t_vector2) * nb);
	if (array == NULL)
		ggl_error("Allocation failed in t_vector2array_new");
	return (array);
}

t_vector2_list	create_t_vector2_list(size_t p_push_size)
{
	t_vector2_list result;

	result.size = 0;
	result.push_size = p_push_size;
	result.max_size = result.push_size;
	result.data = t_vector2tab_new(1);
	result.data[0] = t_vector2array_new(result.push_size);
	return (result);
}

t_vector2_list	*malloc_t_vector2_list(size_t p_push_size)
{
	t_vector2_list *t_vector2_result;

	t_vector2_result = (t_vector2_list *)malloc(sizeof(t_vector2_list));
	if (t_vector2_result == NULL)
		ggl_error("Allocation failed in t_vector2array_new");
	*t_vector2_result = create_t_vector2_list(p_push_size);
	return (t_vector2_result);
}
