/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_tex_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:00:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:17:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tex_pos(t_wall_calc *wall_calc, t_engine *engine)
{
	wall_calc->tex_pos = (wall_calc->draw_start - engine->resolution.y
			/ 2 + wall_calc->line_height / 2) * wall_calc->tex_step;
}
