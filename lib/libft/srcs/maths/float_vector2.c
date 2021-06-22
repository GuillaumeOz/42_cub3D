/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_vector2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:25:28 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/18 12:25:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_float_vector2	*malloc_float_vector2(float x, float y)
{
	t_float_vector2	*float_vector2;

	float_vector2 = (t_float_vector2 *)malloc(sizeof(t_float_vector2));
	if (float_vector2 == NULL)
		ft_error("A float_vector2 can't be malloc");
	*float_vector2 = create_float_vector2(x, y);
	return (float_vector2);
}

t_float_vector2	create_float_vector2(float x, float y)
{
	t_float_vector2	float_vector2;

	float_vector2.x = x;
	float_vector2.y = y;
	return (float_vector2);
}

void	destroy_float_vector2(t_float_vector2 to_destroy)
{
	to_destroy.x = 0;
	to_destroy.y = 0;
	(void)to_destroy;
}

void	free_float_vector2(t_float_vector2 *to_free)
{
	destroy_float_vector2(*to_free);
	free(to_free);
}
