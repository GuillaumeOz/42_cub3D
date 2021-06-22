/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_line_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:34:35 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:18:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_line_height(t_wall_calc *wall_calc, t_engine *engine)
{
	wall_calc->line_height = (int)(engine->resolution.y
			/ wall_calc->wall_dist);
}
