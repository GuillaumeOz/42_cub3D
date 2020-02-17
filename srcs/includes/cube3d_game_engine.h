/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_game_engine.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:31:25 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/17 19:37:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_GAME_ENGINE_H
# define CUBE3D_GAME_ENGINE_H

#define CEILING 0
#define FLOOR 1

typedef struct		s_game_engine
{
	t_image			**texture;
	t_image			*sprite;

	t_color			*ceiling;
	t_color			*floor;

	t_tile			*empty_tile;
	t_tile			*wall_tile;

	t_list			*map_content;
	t_map			*map_content;
	t_actor			*player;
}					t_game_engine;

t_game_engine	*malloc_game_engine();
t_game_engine	create_game_engine();
void 			destroy_game_engine(t_game_engine to_destroy);
void 			free_game_engine(t_game_engine *to_free)

bool set_texture_image(t_game_engine *engine, t_direction dir, char *path);
bool set_sprite_image(t_game_engine *engine, char *path);
bool set_color_type(t_game_engine *engine, int type, char *content);
bool is_engine_full(t_game_engine *engine);

#endif
