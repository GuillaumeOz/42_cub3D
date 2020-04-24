/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_behavior.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:06:17 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/24 16:54:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char *set_level(t_map *map)
{
	char	num[2];
	char	*arg;

	num[0] = map->level + 1;
	num[1] = '\0';
	write(1, "level :", 7);
	write(1, num, 1);
	write(1, "\n", 1);
	num[0] = map->level;
	arg = ft_strjoin("maps/world", num);
	arg = ft_strjoin(arg, ".cub");
	return(arg);
}

void	load_map_control(int32_t control, void *param)
{
	t_game_engine   *engine;
	t_map           *map;
	t_player        *player;
	t_vector2		resolution;
	char            *arg;

	engine = (t_game_engine*)param;
	map = (t_map*)engine->map;
	player = (t_player*)engine->player;
	(void)control;
	player->hp = 100;
	*(player) = reset_player(player->hp);
	arg = set_level(map);
	free_map(map);
	free_game_engine(engine);
	cube3d_parsing(engine, 2, &arg, &resolution);

	// cube3d_get_param(map, arg);
	// map->size = g_app->size;
	// cube3d_parse_map(map, player);

	player->size = (int)((map->resolution.y * 0.33) / (map->size.y));
	if (player->size > (int)((map->resolution.x * 0.27) / (map->size.x)))
		player->size = (int)((map->resolution.x * 0.27) / (map->size.x));
	player->radius *= player->size;
	player->pos.x = (player->pos.x * player->size) - (player->size / 2);
	player->pos.y = (player->pos.y * player->size) + (player->size / 2);
}
