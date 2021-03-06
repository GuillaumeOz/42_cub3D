/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:49:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/08 16:54:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H

t_tile	***malloc_tile_tab(t_vector2 size);
t_map	*malloc_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content);
t_map	create_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content);
void	destroy_map(t_map to_destroy);
void	free_map(t_map *to_free);

void	load_map_control(void *param);
void	set_player_status(t_player *hero, t_map *map);

#endif
