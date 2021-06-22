/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_floor_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:28:26 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:11:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_floor_calc	*malloc_floor_calc(t_engine *engine, t_double_vector2 dir,
	t_double_vector2 plane)
{
	t_floor_calc	*floor_calc;

	floor_calc = (t_floor_calc *)malloc(sizeof(t_floor_calc));
	if (floor_calc == NULL)
		cub3d_error(ERROR_FLOOR_CALC1, "t_floor_calc can't be malloc");
	*floor_calc = create_floor_calc(engine, dir, plane);
	return (floor_calc);
}

t_floor_calc	create_floor_calc(t_engine *engine, t_double_vector2 dir,
	t_double_vector2 plane)
{
	t_floor_calc	floor_calc;

	floor_calc.p = 0;
	floor_calc.fog_war = 255;
	floor_calc.row_distance = 0;
	floor_calc.middle_screen = engine->resolution.y * 0.5;
	floor_calc.fog_dist = (floor_calc.middle_screen / 255);
	floor_calc.left_most = create_float_vector2(dir.x
			+ plane.x, dir.y + plane.y);
	floor_calc.right_most = create_float_vector2(dir.x
			- plane.x, dir.y - plane.y);
	floor_calc.floor_step = create_float_vector2(0.0f, 0.0f);
	floor_calc.floor = create_float_vector2(0.0f, 0.0f);
	floor_calc.cell = create_int_vector2(0, 0);
	floor_calc.floor_fract = create_int_vector2(0, 0);
	floor_calc.ceiling_fract = create_int_vector2(0, 0);
	return (floor_calc);
}

void	destroy_floor_calc(t_floor_calc to_destroy)
{
	(void)to_destroy;
}

void	free_floor_calc(t_floor_calc *to_free)
{
	destroy_floor_calc(*to_free);
	free(to_free);
}
