/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_engine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:42:02 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/14 20:21:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_ENGINE_H
# define CUB3D_T_ENGINE_H

enum				e_bonus_engine
{
	NO_BONUS = 0,
	RESOLUTION_BONUS = (1 << 0),
	SPRITE_BONUS = (1 << 1),
	CEILING_TEX_BONUS = (1 << 2),
	FLOOR_TEX_BONUS = (1 << 3),
	FPS_BONUS = (1 << 4),
	SAVE_BONUS = (1 << 5),
	MINIMAP_BONUS = (1 << 6),
	SECRET_DOOR_TEX_BONUS = (1 << 7),
};

typedef struct s_engine
{
	t_application	*app;
	t_int_vector2	resolution;
	t_texture		**texture;
	t_sprite		*sprite_basic;
	t_list			*sprite_list;
	t_color			*floor;
	t_color			*ceiling;
	t_texture		*floor_texture;
	t_texture		*ceiling_texture;
	t_texture		*secret_door;
	t_player		*player;
	t_list			*map;
	double			*wall_limit;
	char			*allow_charset;
	int				sprites_num;
	t_uint8			bonus;
}				t_engine;

t_engine		*malloc_engine(void);
t_engine		create_engine(void);
void			destroy_engine(t_engine to_destroy);
void			free_engine(t_engine *to_free);

void			set_engine_texture(t_engine *engine);
void			set_engine_wall_limit(t_engine *engine);
void			set_allow_charset(t_engine *engine, char *charset);

#endif