/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_behavior.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:06:17 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/30 20:17:02 by gozsertt         ###   ########.fr       */
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

static void	set_new_world(t_game_engine *engine)
{
	t_player	*player;
	t_map		*map;

	player = engine->player;
	map = engine->map;
	// map->resolution = g_app->size;
	player->hp = 100;
	*(player) = reset_player(player->hp);
	player->size = (int)((map->resolution.y * 0.33) / (map->size.y));
	if (player->size > (int)((map->resolution.x * 0.27) / (map->size.x)))
		player->size = (int)((map->resolution.x * 0.27) / (map->size.x));
	player->radius *= player->size;
	player->pos.x = (player->pos.x * player->size) - (player->size / 2);
	player->pos.y = (player->pos.y * player->size) + (player->size / 2);
}

void	*load_map_control(void *param)
{
	void			**new_param;//free this parame
	t_game_engine	*engine;
	t_game_engine	*new_engine;
	t_vector2		resolution;
	char            **arg;

	engine = (t_game_engine*)(((void**)param)[2]);
	arg = (char**)malloc(sizeof(char*) * 2);
	new_param = NULL;
	if (arg == NULL)
		catch_error(LOAD_MAP_CONTROL_1);
	arg[1] = set_level(engine->map);
	new_engine = malloc_game_engine();
	cube3d_parsing(new_engine, 2, arg, &resolution);
	resize_application((int)resolution.x, (int)resolution.y);
	set_new_world(new_engine);
	new_param = malloc_param_tab(new_param);
	new_param[0] = new_engine->map;
	new_param[1] = new_engine->player;
	new_param[2] = new_engine;
	set_player_status(new_engine->player, new_engine->map);
	free(param);
	free_game_engine(engine);
	free(arg);
	return (new_param);
}
