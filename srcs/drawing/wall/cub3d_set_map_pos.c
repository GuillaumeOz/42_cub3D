/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_map_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:34:08 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:21:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map_pos(t_wall_calc *wall_calc, t_player *player)
{
	wall_calc->map_pos = create_int_vector2((int)player->pos.x,
			(int)player->pos.y);
}
