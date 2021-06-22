/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_floor_ceiling_casting.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:34:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/09 20:07:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_ceiling_render(t_engine *engine, t_player *player)
{
	t_floor_calc	floor_calc;

	floor_calc = create_floor_calc(engine, player->dir, player->plane);
	if (engine->floor_texture != NULL || engine->ceiling_texture != NULL)
		floor_ceiling_texture_render_bonus(engine, player, floor_calc);
	if (engine->floor_texture == NULL)
		floor_color_render(engine);
	if (engine->ceiling_texture == NULL)
		ceiling_color_render(engine);
}
