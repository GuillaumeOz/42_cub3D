/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_sprite_calc.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:19:16 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 18:10:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_SPRITE_CALC_H
# define CUB3D_T_SPRITE_CALC_H

typedef struct s_sprite_calc
{
	t_sprite_list		**sprite_list;
	double				*sprite_dist;
	int					*sprite_order;
	int					i;
	t_float_vector2		sprite_pos;
	t_double_vector2	inv_transform;
	int					sprite_screen_x;
	t_int_vector2		draw_y_axis;
	t_int_vector2		draw_x_axis;
	t_int_vector2		tex_pos;
	t_int_vector2		screen_pos;
}					t_sprite_calc;

t_sprite_calc	*malloc_sprite_calc(t_engine *engine);
t_sprite_calc	create_sprite_calc(t_engine *engine);
void			destroy_sprite_calc(t_sprite_calc to_destroy);
void			free_sprite_calc(t_sprite_calc *to_free);

#endif