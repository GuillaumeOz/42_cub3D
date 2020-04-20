/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 16:19:23 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 16:43:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	condition_interact(t_game_engine *engine, t_map *map, t_player *hero)
{
	if (map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type == '3')
	{
		map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type = 'D';
	}
	else if (map->board
		[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type == 'D'
		&& ((int)((hero->pos.y) / (hero->size)) != (int)((hero->pos.y +
		hero->movement.y) / (hero->size)) || (int)((hero->pos.x) /
		(hero->size)) != (int)((hero->pos.x + hero->movement.x) /
		(hero->size))))
	{
		map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type = '3';
	}
	else if (map->board
		[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type == '4')
	{
		map->level++;
        load_map_control(hero->control, (void*)engine);
	}
	hero->control = (hero->control ^ INTERACT_KEYPRESS) ^ INTERACT_MAKER;
}
