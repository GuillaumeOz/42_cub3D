/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_vector2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:14:05 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/18 12:25:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_double_vector2	*malloc_double_vector2(double x, double y)
{
	t_double_vector2	*double_vector2;

	double_vector2 = (t_double_vector2 *)malloc(sizeof(t_double_vector2));
	if (double_vector2 == NULL)
		ft_error("A double_vector2 can't be malloc");
	*double_vector2 = create_double_vector2(x, y);
	return (double_vector2);
}

t_double_vector2	create_double_vector2(double x, double y)
{
	t_double_vector2	double_vector2;

	double_vector2.x = x;
	double_vector2.y = y;
	return (double_vector2);
}

void	destroy_double_vector2(t_double_vector2 to_destroy)
{
	to_destroy.x = 0;
	to_destroy.y = 0;
	(void)to_destroy;
}

void	free_double_vector2(t_double_vector2 *to_free)
{
	destroy_double_vector2(*to_free);
	free(to_free);
}
