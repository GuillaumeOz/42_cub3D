/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 12:20:08 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/11 12:20:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

static void		calc_value(t_vector2 *error, t_vector2 *income,
						t_vector2 start, t_vector2 end)
{
	error->x = end.x - start.x;
	error->y = end.y - start.y;
	income->x = (error->x >= 0) ? 1 : -1;
	income->y = (error->y >= 0) ? 1 : -1;
	error->x = (error->x >= 0) ? error->x : -error->x;
	error->y = (error->y >= 0) ? error->y : -error->y;
}

static void		calc_line_x_major(t_vector2_list *result,
					t_vector2 *error, t_vector2 *income, t_vector2 start)
{
	int cumul;
	int	j;

	j = 1;
	cumul = error->x / 2;
	while (j <= error->x)
	{
		start.x += income->x;
		cumul += error->y;
		if (cumul >= error->x)
		{
			cumul -= error->x;
			start.y += income->y;
		}
		t_vector2_list_push_back(result, start);
		j++;
	}
}

static void		calc_line_y_major(t_vector2_list *result,
					t_vector2 *error, t_vector2 *income, t_vector2 start)
{
	int cumul;
	int	j;

	j = 1;
	cumul = error->y / 2;
	while (j <= error->y)
	{
		start.y += income->y;
		cumul += error->x;
		if (cumul >= error->y)
		{
			cumul -= error->y;
			start.x += income->x;
		}
		t_vector2_list_push_back(result, start);
		j++;
	}
}

t_vector2_list	calc_line(t_vector2 start, t_vector2 end)
{
	t_vector2_list		result;
	t_vector2			error;
	t_vector2			income;

	calc_value(&error, &income, start, end);
	result = create_t_vector2_list(500);
	t_vector2_list_push_back(&result, start);
	if (error.x >= error.y)
		calc_line_x_major(&result, &error, &income, start);
	else
		calc_line_y_major(&result, &error, &income, start);
	return (result);
}
