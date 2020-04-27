/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_tile.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:40:56 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/27 17:57:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_TILE_H
# define CUBE3D_TILE_H

t_tile	*malloc_tile(t_game_engine engine, t_tile_type p_type);
t_tile	create_tile(t_game_engine engine, t_tile_type p_type);
void 	destroy_tile(t_tile to_destroy);
void 	free_tile(t_tile *to_free);

void 	set_tile_texture(t_tile *tile, t_direction dir, t_texture *p_image);

#endif
