/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_sprites.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:55:20 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/24 12:37:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#ifndef CUBE3D_SPRITES_H
# define CUBE3D_SPRITES_H

typedef struct		s_sprites
{
	t_ray				ray;
	t_vector2			pos;
	t_tile_type			type;
	struct s_sprites	*next;
}					t_sprites;

// typedef enum e_tile_type
// {
// 	empty = 0, 0
// 	wall = 1, 1
// 	sprite = 2, 2
// 	door = 3, 3
// 	level = 4, 4
// 	medikit = 5, H
// 	monster = 6, M
// 	dead_monster = 7 M dead tex

// }				t_tile_type;

typedef struct	s_sprite_data
{
	t_texture	act;
	t_sprites	sprite;
	float		x;
	float		y;
	int			column;
	float		percent;
	int			num;
	int			i;
	t_vector2	pos;
	t_color		color;
	t_color		dark;
}				t_sprite_data;

t_sprites	create_sprites(t_ray ray, t_vector2 pos, t_tile_type p_type);
t_sprites	*malloc_sprites(t_ray ray, t_vector2 pos, t_tile_type p_type);
void		destroy_sprites(t_sprites sprites);
void		free_sprites(t_sprites *sprites);
void		clear_sprites(t_sprites **sprites);

#endif
