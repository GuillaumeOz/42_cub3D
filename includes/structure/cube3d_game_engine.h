/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_game_engine.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:31:25 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/21 19:04:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_GAME_ENGINE_H
# define CUBE3D_GAME_ENGINE_H

#define CEILING 0
#define FLOOR 1

typedef struct  s_map
{
    t_vector2   size;
    t_tile      ***board;
	//t_object  ***content; medikit; del this part
	//t_monster ***monster; del this part ?
	char		*comp;
	char		*valid;
	char		level;
}               t_map;

typedef struct		s_game_engine
{
	t_vector2		resolution;

	t_texture		**texture;
	t_texture		*sprite;
	t_texture		door;

	t_color			*ceiling;
	t_color			*floor;

	t_tile			*empty_tile;
	t_tile			*wall_tile;

	t_list			*map_content;
	t_map			*map;

	t_player		*player;
	t_monster		monster;
	t_medikit		medikit;

	char			*comp;
	char			*valid;
	char			level;
	bool			save;
}					t_game_engine;

t_game_engine	*malloc_game_engine();
t_game_engine	create_game_engine();
void 			destroy_game_engine(t_game_engine to_destroy);
void 			free_game_engine(t_game_engine *to_free);

#endif
