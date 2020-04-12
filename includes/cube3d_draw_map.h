/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_draw_map.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:19:23 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/12 22:35:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_DRAW_MAP_H
# define CUBE3D_DRAW_MAP_H

// void    draw_minimap(t_map *map);
void    draw_wall(t_game_engine *engine, t_vector2 impact, int i);
void    draw_texture(t_game_engine *engine, t_vector2 pos, int index);
int     draw_map(void *param);

#endif