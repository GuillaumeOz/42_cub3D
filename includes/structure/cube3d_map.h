/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:49:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 16:44:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_MAP_H
# define CUBE3D_MAP_H

typedef struct  s_map
{
    t_vector2   size;
    t_tile      ***board;
	//t_object  ***content; medikit;
	//t_monster ***monster;
	char		*comp;
	char		*valid;
	char		level;//check the constructor
}               t_map;

t_tile  ***malloc_tile_tab(t_vector2 size);
t_map   *malloc_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content);
t_map   create_map(t_game_engine *engine, t_vector2 p_size, t_list *p_content);
void    destroy_map(t_map to_destroy);
void    free_map(t_map *to_free);

void	load_map_control(int32_t control, void *param);

#endif