/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 16:19:23 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/29 19:36:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	condition_interact(void *param, t_game_engine *engine, t_map *map, t_player *hero)
{
	if (map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type == door)
	{
		map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type = closed_door;
	}
	else if (map->board
		[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type == closed_door
		&& ((int)((hero->pos.y) / (hero->size)) != (int)((hero->pos.y +
		hero->movement.y) / (hero->size)) || (int)((hero->pos.x) /
		(hero->size)) != (int)((hero->pos.x + hero->movement.x) /
		(hero->size))))
	{
		map->board[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type = door;
	}
	else if (map->board
		[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)]->type == level)
	{
		map->level++;
		param = load_map_control(param, &engine, &hero, &map);
	}
	return(param)
	// hero->control = (hero->control ^ INTERACT_KEYPRESS) ^ INTERACT_MAKER;
}

bool	comp_type_check(char *str, t_tile *tile)
{
	int i;

	i = -1;
	while(str[++i])
		if (str[i] == '0' && tile->type == empty)
			return (true);
		else if (str[i] == 'D' && tile->type == door)
			return (true);
		else if (str[i] == 'M' && tile->type == monster)
			return (true);
		else if (str[i] == 'm' && tile->type == dead_monster)
			return (true);
		else if (str[i] == 'H' && tile->type == medikit)
			return (true);
		else if (str[i] == '2' && tile->type == sprite)
			return (true);
	return (false);
}
