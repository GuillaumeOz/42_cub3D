/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_floor_ceiling_texture_render_bonus.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:11:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:11:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	set_floor_calc(t_floor_calc *floor_calc, t_player *player,
	t_engine *engine, int y)
{
	floor_calc->p = y - engine->resolution.y / 2;
	floor_calc->row_distance = floor_calc->middle_screen / floor_calc->p;
	floor_calc->floor_step = create_float_vector2(floor_calc->row_distance
			* (floor_calc->right_most.x - floor_calc->left_most.x)
			/ engine->resolution.x, floor_calc->row_distance
			* (floor_calc->right_most.y - floor_calc->left_most.y)
			/ engine->resolution.x);
	floor_calc->floor = create_float_vector2(player->pos.x
			+ floor_calc->row_distance * floor_calc->left_most.x, player->pos.y
			+ floor_calc->row_distance * floor_calc->left_most.y);
}

static	void	set_floor_fog_war(t_floor_calc *floor_calc)
{
	if (floor_calc->screen_div < floor_calc->p)
	{
		floor_calc->screen_div += floor_calc->screen_div;
		if (floor_calc->fog_war > 0)
			floor_calc->fog_war -= 2.55;
	}
}

void	floor_ceiling_texture_render_bonus(t_engine *engine,
	t_player *player, t_floor_calc floor_calc)
{
	int		x;
	int		y;

	y = engine->resolution.y / 2 + 1;
	while (y < engine->resolution.y)
	{
		set_floor_calc(&floor_calc, player, engine, y);
		set_floor_fog_war(&floor_calc);
		x = 0;
		while (x < engine->resolution.x)
		{
			floor_calc.cell = create_int_vector2(floor_calc.floor.x,
					floor_calc.floor.y);
			if (engine->floor_texture != NULL)
				floor_texture_render_bonus(floor_calc, engine, x, y);
			if (engine->ceiling_texture != NULL)
				ceiling_texture_render_bonus(floor_calc, engine, x, y);
			floor_calc.floor.x += floor_calc.floor_step.x;
			floor_calc.floor.y += floor_calc.floor_step.y;
			x++;
		}
		y++;
	}
}
