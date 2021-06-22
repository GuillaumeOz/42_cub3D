/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_casting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:38:44 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:29:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_render_bonus(t_engine *engine, t_player *player)
{
	t_sprite_calc	sprite_calc;
	int				i;

	if (engine->bonus & SPRITE_BONUS)
	{
		sprite_calc = create_sprite_calc(engine);
		set_dist_order(&sprite_calc, engine);
		i = 0;
		while (i < engine->sprites_num)
		{
			if (get_sprite_list_enable(engine->sprite_list, i) == true)
			{
				sprite_calc.i = i;
				sprite_calculation(&sprite_calc, engine, player, i);
				i++;
			}
			else
				i++;
		}
		destroy_sprite_calc(sprite_calc);
	}
}
