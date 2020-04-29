/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_behavior.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:06:17 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/29 19:33:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char *set_level(t_map *map)
{
	char	num[2];
	char	*arg;

	num[0] = map->level;
	num[1] = '\0';
	write(1, "level : ", 8);
	write(1, num, 1);
	write(1, "\n", 1);
	num[0] = map->level;
	arg = ft_strjoin("./maps/world", num);
	arg = ft_strjoin(arg, ".cub");
	return(arg);
}

void	load_map_control(void *param, t_game_engine **engine, t_player **player, t_map **map)
{
	void			*param[3];
	t_game_engine	*tmp;
	t_vector2		resolution;
	char            **arg;

	arg = (char**)malloc(sizeof(char*) * 2);
	if (arg == NULL)
		catch_error(LOAD_MAP_CONTROL_1);
	arg[1] = set_level(*map);
	tmp = malloc_game_engine();
	cube3d_parsing(tmp, 2, arg, &resolution);
	// cube3d_get_param(map, arg);
	// map->size = g_app->size;
	// cube3d_parse_map(map, player);

	tmp->player->hp = 100;
	*(tmp->player) = reset_player(tmp->player->hp);
	tmp->player->size = (int)((tmp->map->resolution.y * 0.33) /
		(tmp->map->size.y));
	if (tmp->player->size > (int)((tmp->map->resolution.x * 0.27) /
		(tmp->map->size.x)))
		tmp->player->size = (int)((tmp->map->resolution.x * 0.27) /
			(tmp->map->size.x));
	tmp->player->radius *= tmp->player->size;
	tmp->player->pos.x = (tmp->player->pos.x * tmp->player->size) -
		(tmp->player->size / 2);
	tmp->player->pos.y = (tmp->player->pos.y * tmp->player->size) +
		(tmp->player->size / 2);
	free_game_engine(*engine);
	free(arg);
	*engine = tmp;
	*player = tmp->player;
	*map = tmp->map;
	param[0] = *engine;
	param[1] = *player;
	param[2] = *map;
	return(param);
}
