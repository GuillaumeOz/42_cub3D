/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ceiling_color_render.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:23:46 by gozsertt          #+#    #+#             */
/*   Updated: 2021/04/28 21:02:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ceiling_color_render(t_engine *engine)
{
	t_color	*ceiling_color;
	int		x;
	int		y;

	ceiling_color = engine->ceiling;
	y = 0;
	while (y < engine->resolution.y / 2)
	{
		x = 0;
		while (x < engine->resolution.x)
		{
			set_pixel_to_image(engine->app, x, y, *ceiling_color);
			x++;
		}
		y++;
	}	
}
