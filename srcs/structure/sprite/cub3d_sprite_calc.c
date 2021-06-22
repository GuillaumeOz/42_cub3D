/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:11:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:29:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite_calc	*malloc_sprite_calc(t_engine *engine)
{
	t_sprite_calc	*sprite_calc;

	sprite_calc = (t_sprite_calc *)malloc(sizeof(t_sprite_calc));
	if (sprite_calc == NULL)
		cub3d_error(ERROR_SPRITE_CALC1, "t_sprite_calc* cannot be malloc");
	*sprite_calc = create_sprite_calc(engine);
	return (sprite_calc);
}

t_sprite_calc	create_sprite_calc(t_engine *engine)
{
	t_sprite_calc	sprite_calc;

	sprite_calc.sprite_list = (t_sprite_list **)malloc(sizeof(t_sprite_list *)
			* engine->sprites_num);
	if (sprite_calc.sprite_list == NULL)
		cub3d_error(ERROR_SPRITE_CALC2,
			"t_sprite_list** cannot be malloc in create_sprite_calc");
	sprite_calc.sprite_dist = (double *)malloc(sizeof(double)
			* engine->sprites_num);
	if (sprite_calc.sprite_dist == NULL)
		cub3d_error(ERROR_SPRITE_CALC3,
			"double* cannot be malloc in create_sprite_calc");
	sprite_calc.sprite_order = (int *)malloc(sizeof(int)
			* engine->sprites_num);
	if (sprite_calc.sprite_list == NULL)
		cub3d_error(ERROR_SPRITE_CALC4,
			"int* cannot be malloc in create_sprite_calc");
	sprite_calc.i = 0;
	sprite_calc.sprite_pos = create_float_vector2(0.0f, 0.0f);
	sprite_calc.draw_y_axis = create_int_vector2(0, 0);
	sprite_calc.draw_x_axis = create_int_vector2(0, 0);
	sprite_calc.tex_pos = create_int_vector2(0, 0);
	sprite_calc.screen_pos = create_int_vector2(0, 0);
	return (sprite_calc);
}

void	destroy_sprite_calc(t_sprite_calc to_destroy)
{
	free(to_destroy.sprite_list);
	free(to_destroy.sprite_dist);
	free(to_destroy.sprite_order);
}

void	free_sprite_calc(t_sprite_calc *to_free)
{
	destroy_sprite_calc(*to_free);
	free(to_free);
}
