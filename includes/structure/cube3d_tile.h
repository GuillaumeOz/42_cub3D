/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_tile.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:40:56 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/22 12:40:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_TILE_H
# define CUBE3D_TILE_H

typedef enum	e_direction
{
	east = 0,
	north = 1,
	west = 2,
	south = 3
}				t_direction;

typedef enum e_tile_type
{
	empty = 0,
	wall = 1,
	sprite = 2,
	door = 3,
	level = 4,
	medikit = 5,
	monster = 6,
	dead_monster = 7

}				t_tile_type;

typedef struct s_tile
{
	t_tile_type type;
	t_texture	sprite;
	t_texture	door;
	t_texture	level_tex;
	t_medikit	medikit;
	t_monster	monster;
	t_color		ceiling;
	t_color		floor;
	t_texture	**texture;
}				t_tile;

t_tile	*malloc_tile(t_game_engine engine, t_tile_type p_type);
t_tile	create_tile(t_game_engine engine, t_tile_type p_type);
void 	destroy_tile(t_tile to_destroy);
void 	free_tile(t_tile *to_free);

void 	set_tile_texture(t_tile *tile, t_direction dir, t_texture *p_image);

#endif
