/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_behavior.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 19:25:32 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/16 19:46:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	load_map_control(int32_t control, void *param)
{
    t_game_engine   *engine;
	char            *arg;
	char            num[2];

    engine = (t_game_engine*)param;
    engine->player->hp = 100;
	engine->player = reset_player(hero->hp);
	num[0] = map->level + 1;
	num[1] = '\0';
	write(1, "level :", 7);
	write(1, num, 1);
	write(1, "\n", 1);
	num[0] = map->level;
	arg = ft_strjoin("maps/start", num);
	arg = ft_strjoin(arg, ".cub");
	cub3d_get_param(map, arg);
	map->resolution = g_app->size;
	cub3d_parse_map(map, hero);
	hero->size = (int)((map->resolution.y * 0.33) / (map->size.y));
	if (hero->size > (int)((map->resolution.x * 0.27) / (map->size.x)))
		hero->size = (int)((map->resolution.x * 0.27) / (map->size.x));
	hero->radius *= hero->size;
	hero->pos.x = (hero->pos.x * hero->size) - (hero->size / 2);
	hero->pos.y = (hero->pos.y * hero->size) + (hero->size / 2);
}
