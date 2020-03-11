/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_cast_ray.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:05:57 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/11 19:05:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_CAST_RAY_H
# define CUBE3D_CAST_RAY_H

t_vector2	cut_aff_x(t_vector2 player_actual, t_vector2 delta, float angle);
t_vector2	cut_aff_y(t_vector2 player_actual, t_vector2 delta, float angle);
void        *calc_detection(t_map *map, t_vector2 pos, bool negatif, char var);
float		calc_dist(t_vector2 p1, t_vector2 p2);
t_vector2	cast_ray(t_map *map, t_vector2 actual, float angle);

#endif