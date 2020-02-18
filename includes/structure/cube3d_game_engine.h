/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_game_engine.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:31:25 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/18 16:41:40 by gozsertt         ###   ########.fr       */
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
void 			free_game_engine(t_game_engine *to_free);

#endif
