/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:34:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/09 15:58:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_vector2	add_vector2_to_vector2(t_vector2 a, t_vector2 b)
{
	return (create_vector2(a.x + b.x, a.y + b.y));
}

t_vector2	substract_vector2_to_vector2(t_vector2 a, t_vector2 b)
{
	return (create_vector2(a.x - b.x, a.y - b.y));
}

t_vector2	mult_vector2_by_vector2(t_vector2 a, t_vector2 b)
{
	return (create_vector2(a.x * b.x, a.y * b.y));
}

t_vector2	divide_vector2_by_vector2(t_vector2 a, t_vector2 b)
{
	if (b.x == 0 || b.y == 0)
		ggl_error("Error 1\n Can't divide a vector2 by 0");
	return (create_vector2(a.x / b.x, a.y / b.y));
}

float		vector2_distance(t_vector2 p_a, t_vector2 p_b)
{
	float tmp;
	float tmp2;

	tmp = pow(p_b.x - p_a.x, 2);
	tmp2 = pow(p_b.y - p_a.y, 2);
	return ((float)sqrt(tmp + tmp2));
}
