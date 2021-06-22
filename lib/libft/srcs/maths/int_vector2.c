/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vector2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:23:56 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/18 12:24:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int_vector2	*malloc_int_vector2(int x, int y)
{
	t_int_vector2	*vector2;

	vector2 = (t_int_vector2 *)malloc(sizeof(t_int_vector2));
	if (vector2 == NULL)
		ft_error("A int_vector2 can't be malloc");
	*vector2 = create_int_vector2(x, y);
	return (vector2);
}

t_int_vector2	create_int_vector2(int x, int y)
{
	t_int_vector2	vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}

void	destroy_int_vector2(t_int_vector2 to_destroy)
{
	to_destroy.x = 0;
	to_destroy.y = 0;
	(void)to_destroy;
}

void	free_int_vector2(t_int_vector2 *to_free)
{
	destroy_int_vector2(*to_free);
	free(to_free);
}
