/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_update.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:19:23 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/23 18:18:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_UPDATE_H
# define CUBE3D_UPDATE_H

// Suppr this part ?
void    draw_wall(t_player hero, t_map *map);
void    draw_texture(t_game_engine *engine, t_vector2 pos, int index);
int     draw_map(void *param);
// Suppr this part ?

void	update_player(void *param);
int		update(void *param);

#endif