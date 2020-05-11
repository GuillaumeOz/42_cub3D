/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_list_behavior.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 12:08:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:23:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void		t_vector2tab_cpy(t_vector2 **old, t_vector2 **new)
{
	size_t i;

	i = 0;
	while (old[i] != NULL)
	{
		new[i] = old[i];
		i++;
	}
}

size_t		t_vector2_list_calc_line(t_vector2_list *list, size_t index)
{
	size_t result;

	result = index / list->push_size;
	return (result);
}

size_t		t_vector2_list_calc_elem(t_vector2_list *list, size_t index)
{
	size_t result;
	size_t nb_line;

	nb_line = t_vector2_list_calc_line(list, index);
	result = index - (nb_line * list->push_size);
	return (result);
}

void		t_vector2_list_push_back(t_vector2_list *list, t_vector2 to_add)
{
	size_t		nb_line;
	size_t		nb_elem;
	t_vector2	**tmp;

	if (list->size + 1 >= list->max_size)
	{
		tmp = list->data;
		nb_line = list->max_size / list->push_size;
		list->data = t_vector2tab_new(nb_line + 1);
		t_vector2tab_cpy(tmp, list->data);
		list->data[nb_line] = t_vector2array_new(list->push_size);
		list->max_size += list->push_size;
		free(tmp);
	}
	nb_line = t_vector2_list_calc_line(list, list->size);
	nb_elem = t_vector2_list_calc_elem(list, list->size);
	list->data[nb_line][nb_elem] = to_add;
	list->size++;
}

t_vector2	t_vector2_list_at(t_vector2_list *list, size_t index)
{
	size_t nb_line;
	size_t nb_elem;

	if (list->size == 0)
		return (create_vector2(0, 0));
	nb_line = t_vector2_list_calc_line(list, index);
	nb_elem = t_vector2_list_calc_elem(list, index);
	if (list->size > index)
		return (list->data[nb_line][nb_elem]);
	nb_line = t_vector2_list_calc_line(list, list->size);
	nb_elem = t_vector2_list_calc_elem(list, list->size);
	return (list->data[nb_line][nb_elem]);
}
