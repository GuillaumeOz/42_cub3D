/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_dist_order.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:31:25 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 18:58:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_dist(t_sprite_calc *sprite_calc, int i)
{
	double	dist_tmp;

	dist_tmp = sprite_calc->sprite_dist[i];
	sprite_calc->sprite_dist[i] = sprite_calc->sprite_dist[i + 1];
	sprite_calc->sprite_dist[i + 1] = dist_tmp;
}

void	swap_order(t_sprite_calc *sprite_calc, int i)
{
	int			order_tmp;

	order_tmp = sprite_calc->sprite_order[i];
	sprite_calc->sprite_order[i] = sprite_calc->sprite_order[i + 1];
	sprite_calc->sprite_order[i + 1] = order_tmp;
}

void	sort_dist_order(t_sprite_calc *sprite_calc, t_engine *engine)
{
	int			i;
	int			j;

	j = 0;
	while (j < engine->sprites_num)
	{
		i = 0;
		while (i < engine->sprites_num - 1)
		{
			if (sprite_calc->sprite_dist[i] < sprite_calc->sprite_dist[i + 1])
			{
				swap_dist(sprite_calc, i);
				swap_order(sprite_calc, i);
				j = -1;
			}
			i++;
		}
		j++;
	}
}

void	set_dist_order(t_sprite_calc *sprite_calc, t_engine *engine)
{
	t_player	*player;
	int			i;

	i = 0;
	player = engine->player;
	while (i < engine->sprites_num)
	{
		sprite_calc->sprite_order[i] = i;
		sprite_calc->sprite_list[i]
			= (t_sprite_list *)list_at(engine->sprite_list, i);
		sprite_calc->sprite_dist[i] = ((player->pos.x
					- sprite_calc->sprite_list[i]->coord.x)
				* (player->pos.x - sprite_calc->sprite_list[i]->coord.x)
				+ (player->pos.y - sprite_calc->sprite_list[i]->coord.y)
				* (player->pos.y - sprite_calc->sprite_list[i]->coord.y));
		sprite_calc->sprite_list[i]->dist = sprite_calc->sprite_dist[i];
		i++;
	}
	sort_dist_order(sprite_calc, engine);
}
