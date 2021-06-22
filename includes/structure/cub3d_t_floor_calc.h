/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_floor_calc.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:06:06 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/07 12:46:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_FLOOR_CALC_H
# define CUB3D_T_FLOOR_CALC_H

typedef struct s_floor_calc
{
	int				p;
	float			fog_war;
	int				fog_dist;
	float			row_distance;
	float			middle_screen;
	float			screen_div;
	t_float_vector2	left_most;
	t_float_vector2	right_most;
	t_float_vector2	floor_step;
	t_float_vector2	floor;
	t_int_vector2	cell;
	t_int_vector2	floor_fract;
	t_int_vector2	ceiling_fract;
}					t_floor_calc;

t_floor_calc		*malloc_floor_calc(t_engine *engine, t_double_vector2 dir,
						t_double_vector2 plane);
t_floor_calc		create_floor_calc(t_engine *engine, t_double_vector2 dir,
						t_double_vector2 plane);
void				destroy_floor_calc(t_floor_calc to_destroy);
void				free_floor_calc(t_floor_calc *to_free);

#endif