/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_minimap_circle_informations_bonus        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:07:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:17:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_minimap_circle_informations_bonus(t_application *app,
	float *radius, t_float_vector2	*circle)
{
	*circle = create_float_vector2((app->resolution.x / 14),
			(app->resolution.y / 14));
	if (circle->x >= circle->y)
		*radius = circle->y;
	else
		*radius = circle->x;
}
