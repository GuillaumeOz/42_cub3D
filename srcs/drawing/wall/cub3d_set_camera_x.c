/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_camera_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:22:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:08:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_camera_x(t_wall_calc *wall_calc, t_engine *engine, int x)
{
	wall_calc->camera_x = 2 * x / (double)engine->resolution.x - 1;
}
