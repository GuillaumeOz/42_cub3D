/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_seter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 14:06:41 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 18:26:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_draw_point(t_draw *p_to_set, float pixel_h, float pixel_b,
																float column)
{
	p_to_set->start = create_vector2(column, pixel_h);
	p_to_set->end = create_vector2(column, pixel_b);
}
