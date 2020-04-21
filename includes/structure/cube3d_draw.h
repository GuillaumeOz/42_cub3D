/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_draw.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:17:15 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/20 19:03:31 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H

typedef struct	s_draw
{
	t_vector2	start;
	t_vector2	end;
	void		*info;
	t_map		map;
	float		alpha;
	t_player	hero;
}				t_draw;

t_draw		create_draw(t_map p_map, t_player p_hero, void *p_info,
																	int type);
void		detroy_draw(t_draw p_to_destroy);
void		set_draw_point(t_draw *p_to_set, float pixel_h, float pixel_b,
																float column);

void		test_check(t_ray *info, t_player hero, t_map map,
													t_sprites **lst_sprite);
void		check_ray(t_ray info, t_player hero,
											t_map map, t_sprites **lst_sprite);
void		type_initializer(int *x, int *y, t_ray info, t_player hero);
t_vector2	calc_inter(t_vector2 point1, t_vector2 direction1,
									t_vector2 point2, t_vector2 direction2);								
int			type_condition(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero);
void		draw_column_block(t_draw inf_draw, int type);
void		draw_column_sprite(t_draw inf_draw);

void		draw_column_sprite(t_draw inf_draw);
void		draw_many_sprite(t_map map, t_sprites **lst_sprite,
			t_player hero, t_ray info);

#endif
