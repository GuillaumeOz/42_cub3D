/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:38:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:21:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

t_color		*malloc_color(t_uchar p_r, t_uchar p_g, t_uchar p_b, t_uchar p_a)
{
	t_color	*color;

	color = (t_color*)malloc(sizeof(t_color));
	if (color == NULL)
		ggl_error("Error 1\n Can't malloc t_color in constructor");
	*color = create_color(p_r, p_g, p_b, p_a);
	return (color);
}

t_color		create_color(t_uchar p_r, t_uchar p_g, t_uchar p_b, t_uchar p_a)
{
	t_color	result;

	result.r = p_r;
	result.g = p_g;
	result.b = p_b;
	result.a = p_a;
	return (result);
}

void		destroy_color(t_color to_destroy)
{
	(void)to_destroy;
}

void		free_color(t_color *to_free)
{
	destroy_color(*to_free);
	free(to_free);
}

t_color		fuze_color(t_color actual, t_color to_add)
{
	t_color result;
	float	new_alpha;
	float	inv_alpha;

	new_alpha = to_add.a / 255.0f;
	inv_alpha = 1.0f - new_alpha;
	result = create_color(
		actual.r * inv_alpha + to_add.r * new_alpha,
		actual.g * inv_alpha + to_add.g * new_alpha,
		actual.b * inv_alpha + to_add.b * new_alpha,
		255);
	return (result);
}
