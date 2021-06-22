/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_draw_start_end.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:37:58 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:23:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_draw_start_end(t_wall_calc *wall_calc, t_engine *engine)
{
	wall_calc->draw_start = -wall_calc->line_height
		/ 2 + engine->resolution.y / 2;
	if (wall_calc->draw_start < 0)
		wall_calc->draw_start = 0;
	wall_calc->draw_end = wall_calc->line_height
		/ 2 + engine->resolution.y / 2;
	if (wall_calc->draw_end >= engine->resolution.y)
		wall_calc->draw_end = engine->resolution.y - 1;
}
