/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_wall_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:14:14 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 17:12:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_wall_calc	*malloc_wall_calc(void)
{
	t_wall_calc	*wall_calc;

	wall_calc = (t_wall_calc *)malloc(sizeof(t_wall_calc));
	if (wall_calc == NULL)
		cub3d_error(ERROR_WALL_CALC1, "t_wall_calc cannot be malloc");
	*wall_calc = create_wall_calc();
	return (wall_calc);
}

t_wall_calc	create_wall_calc(void)
{
	t_wall_calc	wall_calc;

	wall_calc.map = NULL;
	wall_calc.camera_x = 0.0f;
	wall_calc.map_pos = create_int_vector2(0, 0);
	wall_calc.ray_dir = create_double_vector2(0.0f, 0.0f);
	wall_calc.delta_dist = create_double_vector2(0.0f, 0.0f);
	wall_calc.side_dist = create_double_vector2(0.0f, 0.0f);
	wall_calc.wall_dist = 0.0f;
	wall_calc.step = create_int_vector2(0, 0);
	wall_calc.id = NONE;
	wall_calc.line_height = 0;
	wall_calc.draw_start = 0;
	wall_calc.draw_end = 0;
	wall_calc.wall_x = 0.0f;
	wall_calc.tex = create_int_vector2(0, 0);
	wall_calc.tex_step = 0.0f;
	wall_calc.tex_pos = 0.0f;
	wall_calc.fog_war = 255.0f;
	wall_calc.hit = false;
	wall_calc.hit_char = 0;
	return (wall_calc);
}

void	destroy_wall_calc(t_wall_calc to_destroy)
{
	(void)to_destroy;
}

void	free_wall_calc(t_wall_calc *to_free)
{
	destroy_wall_calc(*to_free);
	free(to_free);
}
